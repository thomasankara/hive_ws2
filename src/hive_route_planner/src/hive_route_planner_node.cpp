#include <rclcpp/rclcpp.hpp>
#include <std_srvs/srv/trigger.hpp>

#include <unordered_set>
#include <vector>
#include <string>
#include <chrono>
#include <sstream>
#include <array>
#include <cmath>
#include <algorithm>

#include "hive_interface2/msg/lanelet_mini2.hpp"
#include "hive_interface2/msg/lanelet_mini2_array.hpp"
#include "hive_interface2/srv/compute_route.hpp"

#include <visualization_msgs/msg/marker.hpp>
#include <visualization_msgs/msg/marker_array.hpp>
#include <geometry_msgs/msg/pose.hpp>
#include <geometry_msgs/msg/point.hpp>

#include "hive_route_planner/route_utils.hpp"
#include "hive_route_planner/astar_planner.hpp"

using std::placeholders::_1;
using namespace std::chrono;

using hive_route_planner::RouteDataStore;
using hive_route_planner::AStarPlanner;
using hive_route_planner::PathResult;
using hive_route_planner::CostMode;

static constexpr const char* GREEN = "\033[32m";
static constexpr const char* RESET = "\033[0m";

class HiveRoutePlannerNode : public rclcpp::Node
{
public:
  HiveRoutePlannerNode()
  : Node("hive_route_planner")
  {
    // ---------- Paramètres ----------
    robot_namespace_ = this->declare_parameter<std::string>("robot_namespace", "robot1");

    // Viz (graphe global)
    enable_graph_viz_ = this->declare_parameter<bool>("enable_graph_viz", true);
    viz_frame_id_     = this->declare_parameter<std::string>("viz_frame_id", "map");
    viz_ns_           = this->declare_parameter<std::string>("viz_ns", "route_graph");
    viz_topic_        = this->declare_parameter<std::string>("viz_topic", "route_graph_markers");
    viz_line_width_   = this->declare_parameter<double>("viz_line_width", 0.10);
    viz_point_scale_  = this->declare_parameter<double>("viz_point_scale", 0.15);

    // Viz (routes calculées)
    enable_route_plan_viz_ = this->declare_parameter<bool>("enable_route_plan_viz", true);

    // A* params
    epsilon_merge_m_               = this->declare_parameter<double>("epsilon_merge_m", 0.001);
    epsilon_endpoint_frac_         = this->declare_parameter<double>("epsilon_endpoint_frac", 1e-3);
    fallback_speed_mps_            = this->declare_parameter<double>("fallback_speed_mps", 1.0);
    direct_link_threshold_m_       = this->declare_parameter<double>("direct_link_threshold_m", 10.0);
    direct_link_nominal_speed_mps_ = this->declare_parameter<double>("direct_link_nominal_speed_mps", 1.5);

    topic_name_     = "/" + robot_namespace_ + "/route_data";
    service_name_   = "/" + robot_namespace_ + "/get_route_data";
    viz_full_topic_ = "/" + robot_namespace_ + "/" + viz_topic_;

    // ---------- Subscriptions / Clients ----------
    sub_ = this->create_subscription<hive_interface2::msg::LaneletMini2Array>(
      topic_name_, rclcpp::QoS(10),
      std::bind(&HiveRoutePlannerNode::routeDataCallback, this, _1));

    client_ = this->create_client<std_srvs::srv::Trigger>(service_name_);

    // ---------- Publishers ----------
    if (enable_graph_viz_) {
      viz_pub_ = this->create_publisher<visualization_msgs::msg::MarkerArray>(
        viz_full_topic_, rclcpp::QoS(1).transient_local().reliable());
      RCLCPP_INFO(this->get_logger(), "%s[viz] graph enabled -> %s (frame=%s)%s",
        GREEN, viz_full_topic_.c_str(), viz_frame_id_.c_str(), RESET);
    }

    if (enable_route_plan_viz_) {
      for (int i = 0; i < 4; ++i) {
        const std::string topic = "/" + robot_namespace_ + "/route_plan_markers_" + std::to_string(i+1);
        route_plan_pub_[i] = this->create_publisher<visualization_msgs::msg::MarkerArray>(
          topic, rclcpp::QoS(1).transient_local().reliable());
        RCLCPP_INFO(this->get_logger(), "%s[viz] route_plan_markers_%d -> %s%s",
          GREEN, i+1, topic.c_str(), RESET);
      }
    }

    // ---------- Services ----------
    compute_route_srv_ = this->create_service<hive_interface2::srv::ComputeRoute>(
      "/" + robot_namespace_ + "/compute_route",
      std::bind(&HiveRoutePlannerNode::handleComputeRoute, this, std::placeholders::_1, std::placeholders::_2)
    );

    // ---------- Timers ----------
    startup_timer_ = this->create_wall_timer(2s, [this]() {
      if (startup_timer_) startup_timer_->cancel();
      this->configStateTick();
      periodic_timer_ = this->create_wall_timer(
        10s, std::bind(&HiveRoutePlannerNode::configStateTick, this));
    });

    RCLCPP_INFO(this->get_logger(), "%s[hive_route_planner] ready. Sub: %s | Srv client: %s%s",
      GREEN, topic_name_.c_str(), service_name_.c_str(), RESET);
  }

private:
  // ---------- État config tant qu'on n'a pas reçu de data ----------
  void configStateTick()
  {
    if (data_received_) return;
    const bool available = client_->wait_for_service(std::chrono::seconds(0));

    if (available != last_service_available_) {
      last_service_available_ = available;
      RCLCPP_INFO(this->get_logger(), "%s[config] Service %s: %s%s",
        GREEN, available ? "dispo" : "NON dispo", service_name_.c_str(), RESET);
    } else {
      RCLCPP_INFO(this->get_logger(), "%s[config] Service toujours %s: %s%s",
        GREEN, available ? "dispo" : "NON dispo", service_name_.c_str(), RESET);
    }

    if (available && !trigger_sent_ && !trigger_inflight_) {
      auto req = std::make_shared<std_srvs::srv::Trigger::Request>();
      trigger_inflight_ = true;

      RCLCPP_INFO(this->get_logger(), "%s[config] Envoi Trigger vers %s%s",
        GREEN, service_name_.c_str(), RESET);

      client_->async_send_request(
        req,
        [this](rclcpp::Client<std_srvs::srv::Trigger>::SharedFuture fut)
        {
          trigger_inflight_ = false;
          try {
            const auto resp = fut.get();
            RCLCPP_INFO(this->get_logger(), "%s[get_route_data] réponse: success=%s, msg=\"%s\"%s",
              GREEN, resp->success ? "true" : "false", resp->message.c_str(), RESET);
            if (resp->success) {
              trigger_sent_ = true;
            }
          } catch (const std::exception &e) {
            RCLCPP_INFO(this->get_logger(), "%s[get_route_data] exception: %s%s",
              GREEN, e.what(), RESET);
          }
        });
    }
  }

  // ---------- Réception des lanelets ----------
  void routeDataCallback(const hive_interface2::msg::LaneletMini2Array::SharedPtr msg)
  {
    const auto t0 = std::chrono::steady_clock::now();
    store_.setFromMsg(*msg);
    const auto t1 = std::chrono::steady_clock::now();
    const auto dt_ms = std::chrono::duration_cast<std::chrono::milliseconds>(t1 - t0).count();
    data_received_ = true;

    auto summary = store_.summarize();
    auto join_set = [](const std::unordered_set<std::string>& s) {
      std::ostringstream oss; bool first = true;
      for (const auto& v : s) { if(!first) oss << ", "; oss << v; first = false; }
      return oss.str();
    };

    RCLCPP_INFO(this->get_logger(),
      "%s[route_data] reçu %zu éléments | transfert msg→store: %ld ms%s",
      GREEN, store_.data().size(), dt_ms, RESET);
    RCLCPP_INFO(this->get_logger(), "%s[route_data] enterprise_full_id_str: %s%s",
      GREEN, join_set(summary.enterprises).c_str(), RESET);
    RCLCPP_INFO(this->get_logger(), "%s[route_data] deployment_full_id_str: %s%s",
      GREEN, join_set(summary.deployments).c_str(), RESET);
    RCLCPP_INFO(this->get_logger(), "%s[route_data] slam_session_full_id_str: %s%s",
      GREEN, join_set(summary.sessions).c_str(), RESET);

    if (enable_graph_viz_ && viz_pub_) {
      // 1) Clear
      visualization_msgs::msg::MarkerArray clear;
      visualization_msgs::msg::Marker m;
      m.header.frame_id = viz_frame_id_;
      m.action = visualization_msgs::msg::Marker::DELETEALL;
      clear.markers.push_back(m);
      viz_pub_->publish(clear);

      // 2) Publish graph
      auto markers = store_.buildMarkerArray(
          viz_frame_id_, viz_ns_,
          static_cast<float>(viz_line_width_), static_cast<float>(viz_point_scale_));
      viz_pub_->publish(markers);

      RCLCPP_INFO(this->get_logger(), "%s[viz] MarkerArray publié sur %s%s",
          GREEN, viz_full_topic_.c_str(), RESET);
    }
  }

  // ---------- Service: /compute_route ----------
  void handleComputeRoute(
    const std::shared_ptr<hive_interface2::srv::ComputeRoute::Request> req,
    std::shared_ptr<hive_interface2::srv::ComputeRoute::Response> res)
  {
    if (store_.data().empty()) {
      res->success = false;
      res->message = "no route data";
      return;
    }

    // Clear des 4 topics avant la nouvelle publication
    if (enable_route_plan_viz_) {
      visualization_msgs::msg::MarkerArray clear;
      visualization_msgs::msg::Marker mm;
      mm.action = visualization_msgs::msg::Marker::DELETEALL;
      clear.markers.push_back(mm);
      for (int i = 0; i < 4; ++i) {
        if (route_plan_pub_[i]) route_plan_pub_[i]->publish(clear);
      }
    }

    const double sx = req->start_pose.position.x;
    const double sy = req->start_pose.position.y;
    const double gx = req->goal_pose.position.x;
    const double gy = req->goal_pose.position.y;

    AStarPlanner::Params P;
    P.epsilon_merge_m = epsilon_merge_m_;
    P.epsilon_endpoint_frac = epsilon_endpoint_frac_;
    P.fallback_speed_mps = fallback_speed_mps_;
    P.direct_link_threshold_m = direct_link_threshold_m_;
    P.direct_link_nominal_speed_mps = direct_link_nominal_speed_mps_;

    AStarPlanner planner(store_.data(), P);
    const auto mode = (req->mode == 1) ? CostMode::TIME : CostMode::DISTANCE;

    // IMPORTANT: ne pas ajouter les lanelets de projection en début/fin
    auto R = planner.compute({sx,sy}, {gx,gy}, mode, /*return_with_projection_lanelets=*/false);

    // Réponse service
    res->success = R.success;
    res->message = R.message;
    res->total_distance_m = R.total_dist_m;
    res->estimated_time_s = R.total_time_s;
    res->path.clear();
    if (R.success && !R.lanelet_indices.empty()) {
      res->path.reserve(R.lanelet_indices.size());
      for (int idx : R.lanelet_indices) {
        if (idx >= 0 && idx < (int)store_.data().size()) {
          res->path.push_back(store_.data()[idx]);
        }
      }
    }

    // Viz multi-topics
    if (enable_route_plan_viz_) {
      publishRoutePlanMarkersMulti(planner, {sx,sy}, {gx,gy}, R);
    }

    // Log récap
    // Log récap avec couleurs RViz
    const char* viz_map =
      "viz=BEST(0.10,0.90,0.10) ALT1(0.20,0.60,1.00) ALT2(0.80,0.30,0.90) ALT3(1.00,0.60,0.20)";

    RCLCPP_INFO(this->get_logger(),
      "%s[compute_route] success=%s mode=%s dist=%.2f m time=%.2f s %s msg=\"%s\"%s",
      GREEN, res->success ? "true":"false",
      (mode==CostMode::DISTANCE) ? "DIST" : "TIME",
      res->total_distance_m, res->estimated_time_s,
      viz_map,
      res->message.c_str(), RESET);

      }

  // ---------- Build une LINE_LIST depuis un PathResult (respect du sens) ----------
  visualization_msgs::msg::Marker buildLineFromResult(
      const PathResult& R,
      std::pair<double,double> sxy,
      std::pair<double,double> gxy,
      bool highlight,
      float r, float g, float b)
  {
    using visualization_msgs::msg::Marker;
    Marker m;
    m.header.frame_id = viz_frame_id_;
    m.ns = "route_plan_paths";
    m.id = 0;                          // un seul marker par topic
    m.type = Marker::LINE_LIST;        // segments indépendants -> pas de "sauts"
    m.action = Marker::ADD;
    m.scale.x = highlight ? 0.10 : 0.08;
    m.color.a = 1.0;
    if (highlight) { m.color.r = 0.1f; m.color.g = 0.9f; m.color.b = 0.1f; }  // vert vif
    else           { m.color.r = r;    m.color.g = g;    m.color.b = b;    }

    // Cas "ligne droite" : aucun segment ni indice
    if (R.segments.empty() && R.lanelet_indices.empty()) {
      geometry_msgs::msg::Point a, bpt;
      a.x = sxy.first; a.y = sxy.second; a.z = 0.05;
      bpt.x = gxy.first; bpt.y = gxy.second; bpt.z = 0.05;
      m.points.push_back(a);
      m.points.push_back(bpt);
      return m;
    }

    auto push_seg = [&](const hive_interface2::msg::LaneletMini2& ll, bool forward){
      geometry_msgs::msg::Point pA, pB;
      pA.x = ll.start_point_x; pA.y = ll.start_point_y; pA.z = 0.05;
      pB.x = ll.end_point_x;   pB.y = ll.end_point_y;   pB.z = 0.05;
      if (forward) {
        m.points.push_back(pA);
        m.points.push_back(pB);
      } else {
        m.points.push_back(pB);
        m.points.push_back(pA);
      }
    };

    if (!R.segments.empty()) {
      for (const auto& seg : R.segments) {
        if (seg.lanelet_idx < 0 || seg.lanelet_idx >= static_cast<int>(store_.data().size())) continue;
        push_seg(store_.data()[seg.lanelet_idx], seg.forward);
      }
      return m;
    }

    // Fallback : indices non orientés
    for (int idx : R.lanelet_indices) {
      if (idx < 0 || idx >= static_cast<int>(store_.data().size())) continue;
      push_seg(store_.data()[idx], /*forward=*/true);
    }
    return m;
  }

  // ---------- Publication multi-topics ----------
  void publishRoutePlanMarkersMulti(const AStarPlanner& planner,
                                    std::pair<double,double> sxy,
                                    std::pair<double,double> gxy,
                                    const PathResult& best)
  {
    using visualization_msgs::msg::Marker;
    using visualization_msgs::msg::MarkerArray;

    const auto& candidates = planner.candidate_results();

    auto eq_result = [&](const PathResult& A, const PathResult& B){
      if (A.success != B.success) return false;
      if (std::abs(A.total_dist_m - B.total_dist_m) >= 1e-6) return false;
      if (std::abs(A.total_time_s - B.total_time_s) >= 1e-6) return false;
      if (A.lanelet_indices != B.lanelet_indices) return false;
      if (A.segments.size() != B.segments.size()) return false;
      return true;
    };

    // Collecter jusqu'à 3 alternatives différentes du best
    std::vector<PathResult> alternates;
    for (const auto& c : candidates) {
      if (!c.success) continue;
      if (!best.success || !eq_result(c, best)) {
        alternates.push_back(c);
      }
      if (alternates.size() >= 3) break;
    }

    // Topic 1 : 4 points + BEST
    if (route_plan_pub_[0]) {
      MarkerArray arr;

      // Sphères des 4 points (start vert, start-proj bleu, goal rouge, goal-proj jaune)
      const auto& sp = planner.start_projection();
      const auto& gp = planner.goal_projection();

      auto add_sphere = [&](int id, double x, double y, float r, float g, float b){
        Marker m;
        m.header.frame_id = viz_frame_id_;
        m.ns = "route_plan_points";
        m.id = id;
        m.type = Marker::SPHERE;
        m.action = Marker::ADD;
        m.pose.position.x = x; m.pose.position.y = y; m.pose.position.z = 0.2;
        m.scale.x = 0.4; m.scale.y = 0.4; m.scale.z = 0.4;
        m.color.a = 1.0; m.color.r = r; m.color.g = g; m.color.b = b;
        arr.markers.push_back(m);
      };
      add_sphere(100, sxy.first, sxy.second, 0.0f, 1.0f, 0.0f); // START (vert)
      add_sphere(101, sp.px, sp.py,         0.0f, 0.3f, 1.0f); // START proj (bleu)
      add_sphere(102, gxy.first, gxy.second,1.0f, 0.0f, 0.0f); // GOAL (rouge)
      add_sphere(103, gp.px, gp.py,         1.0f, 1.0f, 0.0f); // GOAL proj (jaune)

      if (best.success) {
        auto m = buildLineFromResult(best, sxy, gxy, /*highlight=*/true, 0,0,0);
        arr.markers.push_back(m);
      }
      route_plan_pub_[0]->publish(arr);
    }

    // Topics 2..4 : alternatives
    const std::array<std::tuple<float,float,float>,3> alt_colors = {{
      {0.20f, 0.60f, 1.00f},  // bleu clair
      {0.80f, 0.30f, 0.90f},  // magenta
      {1.00f, 0.60f, 0.20f}   // orange
    }};

    for (size_t i = 0; i < 3; ++i) {
      if (!route_plan_pub_[i+1]) continue;
      MarkerArray arr;
      if (i < alternates.size()) {
        const auto& alt = alternates[i];
        auto [r,g,b] = alt_colors[i];
        auto m = buildLineFromResult(alt, sxy, gxy, /*highlight=*/false, r,g,b);
        arr.markers.push_back(m);
      }
      route_plan_pub_[i+1]->publish(arr);
    }

    // Logs combos (debug)
    for (const auto& cand : candidates) {
      RCLCPP_INFO(this->get_logger(),
        "%s[combo] success=%s dist=%.2f time=%.2f lanelets=%zu segs=%zu%s",
        GREEN, cand.success ? "true":"false",
        cand.total_dist_m, cand.total_time_s,
        cand.lanelet_indices.size(), cand.segments.size(), RESET);
    }
  }

private:
  // ---------- Params / noms ----------
  std::string robot_namespace_;
  std::string topic_name_;
  std::string service_name_;

  // Viz (graphe)
  bool        enable_graph_viz_{true};
  std::string viz_frame_id_;
  std::string viz_ns_;
  std::string viz_topic_;
  std::string viz_full_topic_;
  double      viz_line_width_{0.10};
  double      viz_point_scale_{0.15};

  // Viz (routes calculées)
  bool enable_route_plan_viz_{true};
  std::array<rclcpp::Publisher<visualization_msgs::msg::MarkerArray>::SharedPtr, 4> route_plan_pub_{};

  // A*
  double epsilon_merge_m_{0.001};
  double epsilon_endpoint_frac_{1e-3};
  double fallback_speed_mps_{1.0};
  double direct_link_threshold_m_{10.0};
  double direct_link_nominal_speed_mps_{1.5};

  // ROS handles
  rclcpp::Subscription<hive_interface2::msg::LaneletMini2Array>::SharedPtr sub_;
  rclcpp::Client<std_srvs::srv::Trigger>::SharedPtr client_;
  rclcpp::Publisher<visualization_msgs::msg::MarkerArray>::SharedPtr viz_pub_;
  rclcpp::TimerBase::SharedPtr startup_timer_;
  rclcpp::TimerBase::SharedPtr periodic_timer_;
  rclcpp::Service<hive_interface2::srv::ComputeRoute>::SharedPtr compute_route_srv_;

  // Store & états
  RouteDataStore store_;
  bool data_received_{false};
  bool last_service_available_{false};
  bool trigger_sent_{false};
  bool trigger_inflight_{false};
};

int main(int argc, char** argv)
{
  rclcpp::init(argc, argv);
  auto node = std::make_shared<HiveRoutePlannerNode>();
  rclcpp::spin(node);
  rclcpp::shutdown();
  return 0;
}
