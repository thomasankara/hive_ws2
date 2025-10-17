#include "hive_nav_brain/hive_nav_brain_node.hpp"
#include "hive_nav_brain/logging.hpp"
#include "hive_nav_brain/tf_helpers.hpp"
#include "hive_nav_brain/path_utils.hpp"

#include <chrono>
#include <future>
#include <limits>
#include <cmath>
#include <visualization_msgs/msg/marker.hpp>

using std::placeholders::_1;
using namespace std::chrono_literals;

// ----------------------------------
// Utils
// ----------------------------------
inline double dist2d(double ax, double ay, double bx, double by) {
  const double dx = ax - bx;
  const double dy = ay - by;
  return std::sqrt(dx*dx + dy*dy);
}

constexpr double kJoinEps = 0.20; // 20 cm

inline bool near_xy(double x1, double y1, double x2, double y2, double eps = kJoinEps) {
  const double dx = x1 - x2, dy = y1 - y2;
  return std::sqrt(dx*dx + dy*dy) <= eps;
}

static bool get_true_last_endpoint(
  const std::vector<hive_interface2::msg::LaneletMini2> &path,
  double goal_x, double goal_y,
  double &ex, double &ey)
{
  if (path.empty()) return false;

  const auto &last = path.back();

  if (path.size() >= 2) {
    const auto &prev = path[path.size() - 2];

    const bool start_shared =
        near_xy(last.start_point_x, last.start_point_y, prev.start_point_x, prev.start_point_y) ||
        near_xy(last.start_point_x, last.start_point_y, prev.end_point_x,   prev.end_point_y);

    const bool end_shared =
        near_xy(last.end_point_x, last.end_point_y, prev.start_point_x, prev.start_point_y) ||
        near_xy(last.end_point_x, last.end_point_y, prev.end_point_x,   prev.end_point_y);

    if (start_shared && !end_shared) {
      // le start du dernier est commun -> la *fin* est son end
      ex = last.end_point_x; ey = last.end_point_y; return true;
    }
    if (end_shared && !start_shared) {
      // le end du dernier est commun -> la *fin* est son start
      ex = last.start_point_x; ey = last.start_point_y; return true;
    }
    // Cas rare: aucun ou les deux "communs" (données bruitées) -> fallback au goal
  }

  // Fallback (1 seul lanelet ou jonction non reconnue) : choisir l'extrémité plus proche du goal
  const double dS = std::hypot(last.start_point_x - goal_x, last.start_point_y - goal_y);
  const double dE = std::hypot(last.end_point_x   - goal_x, last.end_point_y   - goal_y);
  if (dE <= dS) { ex = last.end_point_x; ey = last.end_point_y; }
  else          { ex = last.start_point_x; ey = last.start_point_y; }
  return true;
}


// =======================
//   Constructeur
// =======================
HiveNavBrainNode::HiveNavBrainNode()
: Node("hive_nav_brain_node")
{
  // Params
  P_.ns = this->declare_parameter<std::string>("robot_namespace", "robot1");
  P_.fetch_service_basename = this->declare_parameter<std::string>("fetch_service_basename", "refresh_all_data");
  P_.build_names();

  gs_.set_robot_namespace(P_.ns);
  gs_.set_movement_mode(hive_nav::MovementMode::ASTAR_PLANNER); // défaut

  auto qos_latched = rclcpp::QoS(1).reliable().transient_local();

  // Subs
  sub_lanelets_ = this->create_subscription<hive_interface2::msg::LaneletMini2Array>(
    P_.topic_lanelets, qos_latched, std::bind(&HiveNavBrainNode::onLanelets, this, _1));
  sub_pois_ = this->create_subscription<hive_interface2::msg::PoiArray>(
    P_.topic_pois, qos_latched, std::bind(&HiveNavBrainNode::onPois, this, _1));
  sub_freezones_ = this->create_subscription<hive_interface2::msg::FreeZoneArray>(
    P_.topic_freezones, qos_latched, std::bind(&HiveNavBrainNode::onFreeZones, this, _1));
  sub_cmd_ = this->create_subscription<hive_interface2::msg::NavBrainCommand>(
    P_.topic_cmd, rclcpp::QoS(10), std::bind(&HiveNavBrainNode::onCommand, this, _1));

  // Services lanelets
  trigger_client_ = this->create_client<std_srvs::srv::Trigger>(P_.service_name);
  route_client_   = this->create_client<hive_interface2::srv::ComputeRoute>("/" + P_.ns + "/compute_route");

  // TF2
  base_footprint_frame_ = P_.ns + std::string("/base_footprint");
  tf_buffer_   = std::make_shared<tf2_ros::Buffer>(this->get_clock());
  tf_listener_ = std::make_shared<tf2_ros::TransformListener>(*tf_buffer_, this, false);

  // Target publishers
  const std::string target_topic = "/" + P_.ns + "/target_local";
  target_pub_ = this->create_publisher<geometry_msgs::msg::PointStamped>(target_topic, rclcpp::QoS(1));
  const std::string target_marker_topic = "/" + P_.ns + "/target_local_marker";
  target_marker_pub_ = this->create_publisher<visualization_msgs::msg::Marker>(target_marker_topic, rclcpp::QoS(1));

  // Path publisher (unique pour hive/astar)
  const std::string hive_path_topic = "/" + P_.ns + "/hive_planner/path";
  hive_path_pub_ = this->create_publisher<nav_msgs::msg::Path>(hive_path_topic, rclcpp::QoS(1));

  // Action client Nav2 (ASTAR_PLANNER)
  path_action_client_ = rclcpp_action::create_client<CPTP>(
    this, "/" + P_.ns + "/compute_path_through_poses");

  // Action client Nav2 (controller_server / follow_path)
  follow_action_client_ = rclcpp_action::create_client<FP>(
    this, "/" + P_.ns + "/follow_path");
  RCLCPP_INFO(this->get_logger(), "%s[init]%s follow_path action -> %s/%s%s",
    FIX, color::RESET, VAR, (P_.ns + "/follow_path").c_str(), FIX);

  // Logs init (labels blancs, valeurs vertes)
  RCLCPP_INFO(this->get_logger(),
    "%s[hive_nav_brain]%s ns=%s%s%s  service=%s%s%s  cmd_topic=%s%s%s  tf=%smap->%s%s",
    FIX, color::RESET,
    VAR, P_.ns.c_str(), FIX,
    VAR, P_.service_name.c_str(), FIX,
    VAR, P_.topic_cmd.c_str(), FIX,
    VAR, base_footprint_frame_.c_str(), FIX);
  RCLCPP_INFO(this->get_logger(), "%s[init]%s target_local topic -> %s%s%s",
    FIX, color::RESET, VAR, target_topic.c_str(), FIX);
  RCLCPP_INFO(this->get_logger(), "%s[init]%s hive_planner path topic -> %s%s%s",
    FIX, color::RESET, VAR, hive_path_topic.c_str(), FIX);
}

// =======================
//   Démarrage bloquant
// =======================
void HiveNavBrainNode::blocking_startup()
{
  RCLCPP_INFO(this->get_logger(), "%s[init]%s wait for service %s%s%s ...",
              FIX, color::RESET, VAR, P_.service_name.c_str(), FIX);

  while (rclcpp::ok() && !trigger_client_->wait_for_service(1s)) {
    RCLCPP_WARN(this->get_logger(), "%s[init]%s service not available, retry...", FIX, color::RESET);
    rclcpp::sleep_for(500ms);
    rclcpp::spin_some(shared_from_this());
  }

  bool ok = false; int attempt = 0;
  while (rclcpp::ok() && !ok) {
    attempt++;
    RCLCPP_INFO(this->get_logger(), "%s[init]%s call %s%s%s (try #%s%d%s)",
                FIX, color::RESET, VAR, P_.service_name.c_str(), FIX, VAR, attempt, FIX);

    auto req = std::make_shared<std_srvs::srv::Trigger::Request>();
    auto fut = trigger_client_->async_send_request(req);

    auto deadline = std::chrono::steady_clock::now() + 3s;
    while (rclcpp::ok() && std::chrono::steady_clock::now() < deadline &&
           fut.wait_for(50ms) != std::future_status::ready) {
      rclcpp::spin_some(shared_from_this());
    }
    if (!rclcpp::ok()) return;

    if (fut.valid()) {
      try {
        auto res = fut.get();
        if (res->success) {
          ok = true;
          RCLCPP_INFO(this->get_logger(), "%s[init]%s service OK: %s\"%s\"%s",
                      FIX, color::RESET, VAR, res->message.c_str(), FIX);
        } else {
          RCLCPP_WARN(this->get_logger(), "%s[init]%s service false: %s\"%s\"%s (retry)",
                      FIX, color::RESET, VAR, res->message.c_str(), FIX);
          rclcpp::sleep_for(1s);
        }
      } catch (const std::exception &e) {
        RCLCPP_ERROR(this->get_logger(), "%s[init]%s Trigger exception: %s%s%s",
                     FIX, color::RESET, VAR, e.what(), FIX);
        rclcpp::sleep_for(1s);
      }
    } else {
      RCLCPP_WARN(this->get_logger(), "%s[init]%s service timeout (retry)", FIX, color::RESET);
      rclcpp::sleep_for(1s);
    }
  }

  const bool need_poi = (P_.fetch_service_basename == "refresh_all_data");
  const bool need_fz  = (P_.fetch_service_basename == "refresh_all_data");
  RCLCPP_INFO(this->get_logger(),
    "%s[init]%s waiting topics: %sroute_data%s  %s%s%s  %s%s%s",
    FIX, color::RESET,
    color::CYAN, color::RESET,
    need_poi ? color::CYAN : color::DIM, need_poi ? "poi_data" : "(poi skip)", color::RESET,
    need_fz  ? color::CYAN : color::DIM, need_fz  ? "free_zone_data" : "(free_zone skip)", color::RESET);

  auto last = std::chrono::steady_clock::now();
  while (rclcpp::ok() && !have_all_required_data(need_poi, need_fz)) {
    rclcpp::spin_some(shared_from_this());
    rclcpp::sleep_for(100ms);
    auto now = std::chrono::steady_clock::now();
    if (now - last > 2s) {
      RCLCPP_INFO(this->get_logger(), "%s[init]%s pending: route=%s%s%s poi=%s%s%s free_zone=%s%s%s",
        FIX, color::RESET,
        VAR, (store_.has_lanelets() ? "OK" : "—"), FIX,
        VAR, (store_.has_pois() ? "OK" : "—"), FIX,
        VAR, (store_.has_free_zones() ? "OK" : "—"), FIX);
      last = now;
    }
  }

  if (!rclcpp::ok()) return;
  RCLCPP_INFO(this->get_logger(), "%s[init]%s all required data received", FIX, color::RESET);

  // Timer 10 Hz
  loop_timer_ = this->create_wall_timer(100ms, std::bind(&HiveNavBrainNode::onLoop, this));
  RCLCPP_INFO(this->get_logger(), "%s[loop]%s 10 Hz loop started (log 1 Hz)", FIX, color::RESET);
}

// =======================
//   Callbacks
// =======================
void HiveNavBrainNode::onLanelets(const hive_interface2::msg::LaneletMini2Array::SharedPtr msg)
{
  store_.set_lanelets(msg->lanelets);
  if (!msg->lanelets.empty()) {
    const auto &f = msg->lanelets.front();
    RCLCPP_INFO(this->get_logger(),
      "%s[route_data]%s %s%zu%s lanelets (ex id=%s%d%s w=%s%.2f%s vmax=%s%d%s)",
      FIX, color::RESET,
      VAR, msg->lanelets.size(), FIX,
      VAR, f.lanelet_mini_id, FIX,
      VAR, f.width, FIX,
      VAR, f.max_speed, FIX);
  } else {
    RCLCPP_WARN(this->get_logger(), "%s[route_data]%s empty", FIX, color::RESET);
  }
}

void HiveNavBrainNode::onPois(const hive_interface2::msg::PoiArray::SharedPtr msg)
{
  store_.set_pois(msg->items);
  if (!msg->items.empty()) {
    const auto &p = msg->items.front();
    RCLCPP_INFO(this->get_logger(),
      "%s[poi_data]%s %s%zu%s pois (ex id=%s%d%s x=%s%.2f%s y=%s%.2f%s yaw=%s%.1f%s)",
      FIX, color::RESET,
      VAR, msg->items.size(), FIX,
      VAR, p.poi_id, FIX,
      VAR, p.x, FIX, VAR, p.y, FIX, VAR, p.yaw, FIX);
  } else {
    RCLCPP_WARN(this->get_logger(), "%s[poi_data]%s empty", FIX, color::RESET);
  }
}

void HiveNavBrainNode::onFreeZones(const hive_interface2::msg::FreeZoneArray::SharedPtr msg)
{
  store_.set_freezones(msg->items);
  if (!msg->items.empty()) {
    const auto &z = msg->items.front();
    RCLCPP_INFO(this->get_logger(),
      "%s[free_zone_data]%s %s%zu%s zones (ex id=%s%s%s vmax=%s%d%s)",
      FIX, color::RESET,
      VAR, msg->items.size(), FIX,
      VAR, z.free_zone_id.c_str(), FIX,
      VAR, z.max_speed, FIX);
  } else {
    RCLCPP_WARN(this->get_logger(), "%s[free_zone_data]%s empty", FIX, color::RESET);
  }
}

void HiveNavBrainNode::onCommand(const hive_interface2::msg::NavBrainCommand::SharedPtr cmd)
{
  store_.set_last_cmd(*cmd);
  { std::lock_guard<std::mutex> lk(path_mtx_); current_path_.clear(); }
  gs_.update_from_command(*cmd, "map");
  
  // Si on suivait un path, on annule
  did_handoff_final_astar_ = false;   // reset du handoff final
  cancel_follow_if_running("new mission command");

  const auto &p = cmd->destination.pose.position;
  const auto &q = cmd->destination.pose.orientation;
  RCLCPP_INFO(this->get_logger(),
    "%s[command]%s mission=%s%d%s poi=%s%d%s free_zone=%s%d%s obj=%s%d%s  dest(x=%s%.2f%s y=%s%.2f%s z=%s%.2f%s q=%s%.2f%s,%s%.2f%s,%s%.2f%s,%s%.2f%s)  -> status=%s%s%s",
    FIX, color::RESET,
    VAR, cmd->mission_id, FIX,
    VAR, cmd->poi_id, FIX,
    VAR, cmd->free_zone_id, FIX,
    VAR, cmd->object_tracking_id, FIX,
    VAR, p.x, FIX, VAR, p.y, FIX, VAR, p.z, FIX,
    VAR, q.x, FIX, VAR, q.y, FIX, VAR, q.z, FIX, VAR, q.w, FIX,
    VAR, hive_nav::to_string(gs_.status()), FIX);
}

// =======================
//   Helpers
// =======================
bool HiveNavBrainNode::have_all_required_data(bool, bool) const
{
  if (!store_.has_lanelets()) return false;
  if (!store_.has_pois())
    RCLCPP_WARN_THROTTLE(get_logger(), *get_clock(), 5000, "[init] POI data missing (continuing anyway)");
  if (!store_.has_free_zones())
    RCLCPP_WARN_THROTTLE(get_logger(), *get_clock(), 5000, "[init] FreeZone data missing (continuing anyway)");
  return true;
}

// =======================
//   Boucle 10 Hz
// =======================
void HiveNavBrainNode::onLoop()
{
  ++loop_tick_;

  // ---------------------------
  // 0) TF -> pose robot (10 Hz)
  // ---------------------------
  geometry_msgs::msg::PoseStamped pose_map;
  if (hive_tf::try_get_pose_map(*tf_buffer_, map_frame_, base_footprint_frame_,
                                pose_map, this->get_logger(), *this->get_clock())) {
    gs_.set_robot_pose_map(pose_map);
  }

  const auto rob = gs_.robot();
  const auto mis = gs_.mission();

  // ---------------------------------------------------------
  // 1) Distances (path et goal) + détection d'arrivée (<= 0.30 m)
  // ---------------------------------------------------------
  double dist_to_path_m = 0.0;
  std::string dist_note;

  double dist_to_goal_m = 0.0;
  std::string goal_note;

  if (mis.status == hive_nav::MissionStatus::IDLE) {
    goal_note = "(idle)";
  } else if (!rob.has_pose) {
    goal_note = "(no robot pose / TF)";
  } else {
    const auto &rp = rob.pose_map.pose.position;
    const auto &gp = mis.destination.pose.position;  // en "map"
    dist_to_goal_m = std::hypot(rp.x - gp.x, rp.y - gp.y);
    goal_note.clear();

    if (dist_to_goal_m <= 0.30) {
      RCLCPP_INFO(this->get_logger(),
        "%s[arrival]%s goal reached: dist=%s%.2f%s m ≤ %s0.30%s m -> status=%sidle%s (stop follow)",
        FIX, color::RESET,
        VAR, dist_to_goal_m, FIX,
        VAR, FIX,
        VAR, FIX);
      cancel_follow_if_running("arrived at goal");
      gs_.set_status(hive_nav::MissionStatus::IDLE);
    }
  }

  if (rob.has_pose) {
    std::vector<hive_interface2::msg::LaneletMini2> path_copy_for_dist;
    { std::lock_guard<std::mutex> lk(path_mtx_); path_copy_for_dist = current_path_; }

    dist_to_path_m = hive_nav_utils::distance_to_path_xy(
      path_copy_for_dist,
      rob.pose_map.pose.position.x,
      rob.pose_map.pose.position.y,
      dist_note
    );
  } else {
    dist_note = "(no robot pose / TF)";
  }

  // -----------------------------------------------------------------
  // 2) Sélection / hystérésis du MovementMode
  //    - AVANT handoff final : hystérésis hive<->astar
  //    - APRÈS handoff final : on reste en ASTAR jusqu'à l'arrivée
  // -----------------------------------------------------------------
  if (dist_note.empty()) {
    if (!did_handoff_final_astar_) {
      constexpr double THRESH_LOW  = 0.9; // < 0.9  -> hive_planner
      constexpr double THRESH_HIGH = 1.1; // > 1.1  -> astar_planner
      auto mode = gs_.movement_mode();

      if (mode == hive_nav::MovementMode::HIVE_PLANNER && dist_to_path_m > THRESH_HIGH) {
        gs_.set_movement_mode(hive_nav::MovementMode::ASTAR_PLANNER);
      } else if (mode == hive_nav::MovementMode::ASTAR_PLANNER && dist_to_path_m < THRESH_LOW) {
        gs_.set_movement_mode(hive_nav::MovementMode::HIVE_PLANNER);
      }
    } else {
      if (gs_.movement_mode() != hive_nav::MovementMode::ASTAR_PLANNER) {
        gs_.set_movement_mode(hive_nav::MovementMode::ASTAR_PLANNER);
      }
    }
  }

  // -----------------------------------------------------------------
  // 3) Si on suit déjà un path et que le mode a changé -> replanifier
  // -----------------------------------------------------------------
  if (running_follow_ && gs_.movement_mode() != last_follow_mode_) {
    RCLCPP_INFO(this->get_logger(),
      "%s[follow]%s mode changed while running: %s%s%s -> %s%s%s, cancel & replan",
      FIX, color::RESET,
      VAR, hive_nav::to_string(last_follow_mode_), FIX,
      VAR, hive_nav::to_string(gs_.movement_mode()), FIX);
    cancel_follow_if_running("mode changed");
    gs_.set_status(hive_nav::MissionStatus::READY_FOR_PATH);
  }

  // -------------------------------------------
  // 4) Target locale + markers + handoff “fin”
  // -------------------------------------------
  if (rob.has_pose) {
    std::vector<hive_interface2::msg::LaneletMini2> path_copy;
    { std::lock_guard<std::mutex> lk(path_mtx_); path_copy = current_path_; }

    double tx = 0.0, ty = 0.0;
    std::string tgt_note;
    const auto goal = gs_.mission().destination.pose.position;

    const bool have_target = hive_nav_utils::compute_local_target(
      path_copy,
      rob.pose_map.pose.position.x, rob.pose_map.pose.position.y,
      goal.x, goal.y,
      gs_.movement_mode(),
      /*lookahead_m=*/6.0,
      tx, ty, tgt_note);

    if (have_target) {
      // --- Publier la target
      geometry_msgs::msg::PointStamped pmsg;
      pmsg.header.stamp = this->now();
      pmsg.header.frame_id = map_frame_;
      pmsg.point.x = tx; pmsg.point.y = ty; pmsg.point.z = 0.0;
      target_pub_->publish(pmsg);

      // --- Marker sphère (position)
      visualization_msgs::msg::Marker m;
      m.header = pmsg.header;
      m.ns = "target_local"; m.id = 1;
      m.type = visualization_msgs::msg::Marker::SPHERE;
      m.action = visualization_msgs::msg::Marker::ADD;
      m.pose.position.x = tx; m.pose.position.y = ty; m.pose.position.z = 0.15;
      m.pose.orientation.w = 1.0;
      m.scale.x = m.scale.y = m.scale.z = 0.50;
      m.color.a = 1.0;
      if (gs_.movement_mode() == hive_nav::MovementMode::HIVE_PLANNER) { m.color.r = 0.1; m.color.g = 0.9; m.color.b = 0.1; }
      else                                                             { m.color.r = 0.1; m.color.g = 0.4; m.color.b = 1.0; }
      target_marker_pub_->publish(m);

      // --- Marker flèche (orientation le long du lanelet sous-jacent)
      double yaw_path = 0.0;
      if (heading_on_path_at(tx, ty, yaw_path)) {
        visualization_msgs::msg::Marker a;
        a.header = pmsg.header;
        a.ns = "target_local"; a.id = 2;
        a.type = visualization_msgs::msg::Marker::ARROW;
        a.action = visualization_msgs::msg::Marker::ADD;
        a.pose.position.x = tx; a.pose.position.y = ty; a.pose.position.z = 0.20;
        const double h = yaw_path * 0.5;
        a.pose.orientation.x = 0.0;
        a.pose.orientation.y = 0.0;
        a.pose.orientation.z = std::sin(h);
        a.pose.orientation.w = std::cos(h);
        a.scale.x = 0.9;  a.scale.y = 0.25; a.scale.z = 0.25;
        a.color.a = 0.9;  a.color.r = 1.0;  a.color.g = 0.7;  a.color.b = 0.2;
        target_marker_pub_->publish(a);
      }

      // ---------- Handoff vers ASTAR final (une seule fois) ----------
      // Helper local : vrai "dernier point" du chemin (utilise N-1 si possible)
      auto get_true_last_endpoint = [](const std::vector<hive_interface2::msg::LaneletMini2>& path,
                                       double gx, double gy,
                                       double &ex, double &ey) -> bool
      {
        if (path.empty()) return false;

        // Trouver dernier lanelet non dégénéré
        int last_i = -1;
        for (int i = static_cast<int>(path.size()) - 1; i >= 0; --i) {
          const auto &ll = path[static_cast<size_t>(i)];
          const double L = std::hypot(ll.end_point_x - ll.start_point_x,
                                      ll.end_point_y - ll.start_point_y);
          if (L > 1e-6) { last_i = i; break; }
        }
        if (last_i < 0) return false;

        const auto &L = path[static_cast<size_t>(last_i)];
        const double Ax = L.start_point_x, Ay = L.start_point_y;
        const double Bx = L.end_point_x,   By = L.end_point_y;

        // Chercher un précédent non dégénéré
        int prev_i = -1;
        for (int i = last_i - 1; i >= 0; --i) {
          const auto &ll = path[static_cast<size_t>(i)];
          const double len = std::hypot(ll.end_point_x - ll.start_point_x,
                                        ll.end_point_y - ll.start_point_y);
          if (len > 1e-6) { prev_i = i; break; }
        }

        auto near2 = [](double x1,double y1,double x2,double y2){ return std::hypot(x1-x2, y1-y2) <= 0.25; };

        if (prev_i >= 0) {
          const auto &P = path[static_cast<size_t>(prev_i)];
          // Le point commun avec N-1 est le "début réel" du dernier segment;
          // le "vrai dernier point" est l'autre extrémité.
          if (near2(Ax, Ay, P.start_point_x, P.start_point_y) ||
              near2(Ax, Ay, P.end_point_x,   P.end_point_y)) {
            ex = Bx; ey = By; return true; // A est le joint -> fin = B
          }
          if (near2(Bx, By, P.start_point_x, P.start_point_y) ||
              near2(Bx, By, P.end_point_x,   P.end_point_y)) {
            ex = Ax; ey = Ay; return true; // B est le joint -> fin = A
          }
          // Pas trouvé ? fallback sur proximité du goal
        }

        // Fallback: l’extrémité la plus proche du goal est la fin
        double dA = std::hypot(Ax - gx, Ay - gy);
        double dB = std::hypot(Bx - gx, By - gy);
        if (dB <= dA) { ex = Bx; ey = By; } else { ex = Ax; ey = Ay; }
        return true;
      };

      bool at_end = false;
      if (!path_copy.empty()) {
        double ex=0.0, ey=0.0;
        if (get_true_last_endpoint(path_copy, goal.x, goal.y, ex, ey)) {
          at_end = (std::hypot(tx - ex, ty - ey) <= 0.25);
        }
      }

      // Ne déclencher le handoff FINAL que :
      // - si on touche la fin,
      // - si on ne l’a pas déjà fait,
      // - et si on n’est pas déjà en attente de planning.
      if (at_end &&
          !did_handoff_final_astar_ &&
          gs_.status() != hive_nav::MissionStatus::WAITING_FOR_HIVE_PLANNER)
      {
        if (gs_.movement_mode() != hive_nav::MovementMode::ASTAR_PLANNER) {
          gs_.set_movement_mode(hive_nav::MovementMode::ASTAR_PLANNER);
          RCLCPP_INFO(this->get_logger(),
            "%s[handoff]%s local target is at end of lanelets -> switch to %sastar_planner%s and plan to final goal",
            FIX, color::RESET, VAR, FIX);
        } else {
          RCLCPP_INFO(this->get_logger(),
            "%s[handoff]%s local target is at end of lanelets -> plan to final goal",
            FIX, color::RESET);
        }

        cancel_follow_if_running("handoff to final astar");

        // CPTP FINAL vers la destination (une seule fois)
        if (!path_action_client_->wait_for_action_server(100ms)) {
          RCLCPP_ERROR(this->get_logger(), "%s[astar]%s action server %s/%s%s not available",
                       FIX, color::RESET, VAR, ("/"+P_.ns+"/compute_path_through_poses").c_str(), FIX);
        } else {
          CPTP::Goal gmsg;
          gmsg.use_start = true;
          gmsg.start.header.frame_id = map_frame_;
          gmsg.start.header.stamp = this->now();
          gmsg.start.pose = gs_.robot().pose_map.pose;

          geometry_msgs::msg::PoseStamped g;
          g.header.frame_id = map_frame_;
          g.header.stamp = this->now();
          g.pose = gs_.mission().destination.pose; // but final (pos + yaw)

          gmsg.goals.goals.clear();
          gmsg.goals.goals.push_back(g);

          waiting_astar_ = true;
          did_handoff_final_astar_ = true; // verrou pour ne pas relancer
          gs_.set_status(hive_nav::MissionStatus::WAITING_FOR_HIVE_PLANNER);

          RCLCPP_INFO(this->get_logger(),
            "%s[astar]%s send CPTP FINAL: start(%s%.2f%s,%s%.2f%s) -> goal(%s%.2f%s,%s%.2f%s)",
            FIX, color::RESET,
            VAR, gmsg.start.pose.position.x, FIX, VAR, gmsg.start.pose.position.y, FIX,
            VAR, g.pose.position.x, FIX, VAR, g.pose.position.y, FIX);

          auto send_goal_options = rclcpp_action::Client<CPTP>::SendGoalOptions();
          send_goal_options.result_callback =
            [this](const rclcpp_action::ClientGoalHandle<CPTP>::WrappedResult &res)
            {
              waiting_astar_ = false;

              if (res.code != rclcpp_action::ResultCode::SUCCEEDED) {
                RCLCPP_ERROR(this->get_logger(),
                  "%s[astar]%s FINAL action result code != SUCCEEDED (%s%d%s)",
                  FIX, color::RESET, VAR, static_cast<int>(res.code), FIX);
                gs_.set_status(hive_nav::MissionStatus::READY_FOR_PATH);
                did_handoff_final_astar_ = false; // autorise un retry
                return;
              }

              const auto &path = res.result->path;
              const auto err   = res.result->error_code;
              if (err != nav2_msgs::action::ComputePathThroughPoses_Result::NONE || path.poses.empty()) {
                RCLCPP_ERROR(this->get_logger(),
                  "%s[astar]%s FINAL planner error_code=%s%u%s msg=%s\"%s\"%s",
                  FIX, color::RESET,
                  VAR, err, FIX,
                  VAR, res.result->error_msg.c_str(), FIX);
                gs_.set_status(hive_nav::MissionStatus::READY_FOR_PATH);
                did_handoff_final_astar_ = false; // autorise un retry
                return;
              }

              auto path_copy2 = path;
              path_copy2.header.stamp = this->now();
              hive_path_pub_->publish(path_copy2);
              gs_.set_mission_path(path_copy2);
              gs_.set_status(hive_nav::MissionStatus::READY_TO_RUN);

              const double tplan = res.result->planning_time.sec + res.result->planning_time.nanosec*1e-9;
              RCLCPP_INFO(this->get_logger(),
                "%s[astar]%s FINAL path received: poses=%s%zu%s planning_time=%s%.3f%s s -> status=%s%s%s",
                FIX, color::RESET,
                VAR, path_copy2.poses.size(), FIX,
                VAR, tplan, FIX,
                VAR, hive_nav::to_string(gs_.status()), FIX);
            };

          path_action_client_->async_send_goal(gmsg, send_goal_options);
        }
      }

    } else {
      // Pas de target -> supprimer les markers
      for (int id : {1,2}) {
        visualization_msgs::msg::Marker m;
        m.header.stamp = this->now();
        m.header.frame_id = map_frame_;
        m.ns = "target_local";
        m.id = id;
        m.action = visualization_msgs::msg::Marker::DELETE;
        target_marker_pub_->publish(m);
      }
    }
  }

  // ---------------------------------
  // 5) Heartbeat (1 Hz, logs utiles)
  // ---------------------------------
  if ((loop_tick_ % 10) == 0) {
    const auto mode = gs_.movement_mode();
    if (rob.has_pose) {
      RCLCPP_INFO(this->get_logger(),
        "%s[loop]%s heartbeat — data: route=%s%s%s poi=%s%s%s free_zone=%s%s%s  status=%s%s%s  mode=%s%s%s  pose(map)=%s%.2f%s,%s%.2f%s,%s%.2f%s  dist_to_path=%s%.2f%s m %s%s%s  dist_to_goal=%s%.2f%s m %s%s%s",
        FIX, color::RESET,
        VAR, (store_.has_lanelets() ? "OK" : "—"), FIX,
        VAR, (store_.has_pois() ? "OK" : "—"), FIX,
        VAR, (store_.has_free_zones() ? "OK" : "—"), FIX,
        VAR, hive_nav::to_string(gs_.status()), FIX,
        VAR, hive_nav::to_string(mode), FIX,
        VAR, rob.pose_map.pose.position.x, FIX,
        VAR, rob.pose_map.pose.position.y, FIX,
        VAR, rob.pose_map.pose.position.z, FIX,
        VAR, dist_to_path_m, FIX,
        VAR, dist_note.c_str(), FIX,
        VAR, dist_to_goal_m, FIX,
        VAR, goal_note.c_str(), FIX
      );
    } else {
      RCLCPP_INFO(this->get_logger(),
        "%s[loop]%s heartbeat — data: route=%s%s%s poi=%s%s%s free_zone=%s%s%s  status=%s%s%s  mode=%s%s%s  pose(map)=%sN/A%s  dist_to_path=%s%.2f%s m %s%s%s  dist_to_goal=%s%.2f%s m %s%s%s",
        FIX, color::RESET,
        VAR, (store_.has_lanelets() ? "OK" : "—"), FIX,
        VAR, (store_.has_pois() ? "OK" : "—"), FIX,
        VAR, (store_.has_free_zones() ? "OK" : "—"), FIX,
        VAR, hive_nav::to_string(gs_.status()), FIX,
        VAR, hive_nav::to_string(gs_.movement_mode()), FIX,
        VAR, FIX,
        VAR, dist_to_path_m, FIX,
        VAR, dist_note.c_str(), FIX,
        VAR, dist_to_goal_m, FIX,
        VAR, goal_note.c_str(), FIX
      );
    }
  }

  // -----------------------------------------------------
  // 6) Réception des lanelets globaux si demandé
  // -----------------------------------------------------
  if (gs_.status() == hive_nav::MissionStatus::READY_TO_GET_GLOBAL_PATH) {
    try_request_global_path();
  }

  // -----------------------------------------------------
  // 7) Construction / demande de path selon mode courant
  // -----------------------------------------------------
  if (gs_.status() == hive_nav::MissionStatus::READY_FOR_PATH) {

    // HIVE_PLANNER -> construire nav_msgs/Path depuis lanelets
    if (gs_.movement_mode() == hive_nav::MovementMode::HIVE_PLANNER &&
        !building_hive_path_)
    {
      building_hive_path_ = true;
      gs_.set_status(hive_nav::MissionStatus::WAITING_FOR_HIVE_PLANNER);

      std::vector<hive_interface2::msg::LaneletMini2> path_copy;
      { std::lock_guard<std::mutex> lk(path_mtx_); path_copy = current_path_; }

      hive_planner::PathBuildStats stats;
      auto nav2_path = hive_planner::build_nav2_path(
          path_copy, map_frame_,
          /*step_m=*/0.1, /*window_half=*/10, stats);

      RCLCPP_INFO(this->get_logger(),
        "%s[hive_planner]%s built nav2 path — lanelets=%s%zu%s raw_pts=%s%zu%s smoothed_pts=%s%zu%s step=%s%.4f%s m window=±%s%d%s",
        FIX, color::RESET,
        VAR, stats.lanelet_count,     FIX,
        VAR, stats.raw_points,        FIX,
        VAR, stats.smoothed_points,   FIX,
        VAR, stats.step_m,            FIX,
        VAR, stats.window_half,       FIX
      );

      nav2_path.header.stamp = this->now();
      hive_path_pub_->publish(nav2_path);
      gs_.set_mission_path(nav2_path);
      gs_.set_status(hive_nav::MissionStatus::READY_TO_RUN);
      building_hive_path_ = false;

      RCLCPP_INFO(this->get_logger(),
        "%s[hive_planner]%s mission status -> %s%s%s",
        FIX, color::RESET, VAR, hive_nav::to_string(gs_.status()), FIX
      );
    }

    // ASTAR_PLANNER -> CPTP vers la target locale (orientée lanelet)
    if (gs_.movement_mode() == hive_nav::MovementMode::ASTAR_PLANNER &&
        !waiting_astar_)
    {
      // Construire la cible locale
      std::vector<hive_interface2::msg::LaneletMini2> path_copy;
      { std::lock_guard<std::mutex> lk(path_mtx_); path_copy = current_path_; }

      const auto rob_pos = gs_.robot().pose_map.pose.position;
      const auto goal_pos = gs_.mission().destination.pose.position;

      double tx = 0.0, ty = 0.0;
      std::string note;
      bool have_target = hive_nav_utils::compute_local_target(
          path_copy, rob_pos.x, rob_pos.y,
          goal_pos.x, goal_pos.y,
          hive_nav::MovementMode::ASTAR_PLANNER,
          /*lookahead_m=*/6.0,
          tx, ty, note);

      if (!have_target) {
        RCLCPP_WARN(this->get_logger(), "%s[astar]%s no local target (note=%s%s%s), skip action this tick",
                    FIX, color::RESET, VAR, note.c_str(), FIX);
      } else if (!path_action_client_->wait_for_action_server(100ms)) {
        RCLCPP_ERROR(this->get_logger(), "%s[astar]%s action server %s/%s%s not available",
                     FIX, color::RESET, VAR, ("/"+P_.ns+"/compute_path_through_poses").c_str(), FIX);
      } else {
        CPTP::Goal gmsg;
        gmsg.use_start = true;
        gmsg.start.header.frame_id = map_frame_;
        gmsg.start.header.stamp = this->now();
        gmsg.start.pose = gs_.robot().pose_map.pose;

        geometry_msgs::msg::PoseStamped g;
        g.header.frame_id = map_frame_;
        g.header.stamp = this->now();
        g.pose.position.x = tx;
        g.pose.position.y = ty;
        g.pose.position.z = 0.0;

        // Orientation alignée lanelet
        double yaw_path = 0.0;
        if (heading_on_path_at(tx, ty, yaw_path)) {
          const double h = yaw_path * 0.5;
          g.pose.orientation.x = 0.0;
          g.pose.orientation.y = 0.0;
          g.pose.orientation.z = std::sin(h);
          g.pose.orientation.w = std::cos(h);
        } else {
          g.pose.orientation.w = 1.0; // fallback
        }

        gmsg.goals.goals.clear();
        gmsg.goals.goals.push_back(g);

        waiting_astar_ = true;
        gs_.set_status(hive_nav::MissionStatus::WAITING_FOR_HIVE_PLANNER);

        RCLCPP_INFO(this->get_logger(),
          "%s[astar]%s send CPTP: start(%s%.2f%s,%s%.2f%s) -> local(%s%.2f%s,%s%.2f%s)",
          FIX, color::RESET,
          VAR, gmsg.start.pose.position.x, FIX, VAR, gmsg.start.pose.position.y, FIX,
          VAR, g.pose.position.x, FIX, VAR, g.pose.position.y, FIX);

        auto send_goal_options = rclcpp_action::Client<CPTP>::SendGoalOptions();
        send_goal_options.result_callback =
          [this](const rclcpp_action::ClientGoalHandle<CPTP>::WrappedResult &res)
          {
            waiting_astar_ = false;

            if (res.code != rclcpp_action::ResultCode::SUCCEEDED) {
              RCLCPP_ERROR(this->get_logger(),
                "%s[astar]%s action result code != SUCCEEDED (%s%d%s)",
                FIX, color::RESET, VAR, static_cast<int>(res.code), FIX);
              gs_.set_status(hive_nav::MissionStatus::READY_FOR_PATH);
              return;
            }

            const auto &path = res.result->path;
            const auto err   = res.result->error_code;
            if (err != nav2_msgs::action::ComputePathThroughPoses_Result::NONE || path.poses.empty()) {
              RCLCPP_ERROR(this->get_logger(),
                "%s[astar]%s planner error_code=%s%u%s msg=%s\"%s\"%s",
                FIX, color::RESET,
                VAR, err, FIX,
                VAR, res.result->error_msg.c_str(), FIX);
              gs_.set_status(hive_nav::MissionStatus::READY_FOR_PATH);
              return;
            }

            auto path_copy2 = path;
            path_copy2.header.stamp = this->now();
            hive_path_pub_->publish(path_copy2);
            gs_.set_mission_path(path_copy2);
            gs_.set_status(hive_nav::MissionStatus::READY_TO_RUN);

            const double tplan = res.result->planning_time.sec + res.result->planning_time.nanosec*1e-9;
            RCLCPP_INFO(this->get_logger(),
              "%s[astar]%s path received: poses=%s%zu%s planning_time=%s%.3f%s s -> status=%s%s%s",
              FIX, color::RESET,
              VAR, path_copy2.poses.size(), FIX,
              VAR, tplan, FIX,
              VAR, hive_nav::to_string(gs_.status()), FIX);
          };

        path_action_client_->async_send_goal(gmsg, send_goal_options);
      }
    }
  }

  // -----------------------------------------------
  // 8) READY_TO_RUN -> envoyer au controller (MPPI)
  // -----------------------------------------------
  if (gs_.status() == hive_nav::MissionStatus::READY_TO_RUN
      && !running_follow_
      && !waiting_follow_) {
    maybe_send_follow_path();
  }
}

// =======================
//   Demande global path (lanelets)
// =======================
void HiveNavBrainNode::try_request_global_path()
{
  const auto rob = gs_.robot();
  const auto mis = gs_.mission();

  if (!rob.has_pose) {
    RCLCPP_ERROR(this->get_logger(), "%s[route]%s cannot request path: %srobot pose unavailable (TF)%s",
                 FIX, color::RESET, VAR, FIX);
    return;
  }
  if (!route_client_->service_is_ready()) {
    RCLCPP_ERROR_THROTTLE(this->get_logger(), *this->get_clock(), 1000,
      "%s[route]%s service %s'/%s/compute_route'%s not available",
      FIX, color::RESET, VAR, P_.ns.c_str(), FIX);
    return;
  }

  auto req = std::make_shared<hive_interface2::srv::ComputeRoute::Request>();
  req->start_pose = rob.pose_map.pose;
  req->goal_pose  = mis.destination.pose;
  req->mode       = 1; // temps minimal

  RCLCPP_INFO(this->get_logger(),
    "%s[route]%s request compute_route: start(%s%.2f%s,%s%.2f%s) -> goal(%s%.2f%s,%s%.2f%s) mode=%sTIME%s",
    FIX, color::RESET,
    VAR, req->start_pose.position.x, FIX, VAR, req->start_pose.position.y, FIX,
    VAR, req->goal_pose.position.x,  FIX, VAR, req->goal_pose.position.y,  FIX,
    VAR, FIX);

  gs_.set_status(hive_nav::MissionStatus::WAITING_TO_GET_GLOBAL_PATH);

  route_client_->async_send_request(
    req,
    [this](rclcpp::Client<hive_interface2::srv::ComputeRoute>::SharedFuture fut)
    {
      try {
        auto res = fut.get();
        if (res->success) {
          { std::lock_guard<std::mutex> lk(path_mtx_); current_path_ = res->path; }
          RCLCPP_INFO(this->get_logger(),
            "%s[route]%s received path: dist=%s%.2f%s m  eta=%s%.2f%s s  lanelets=%s%zu%s  -> status=%sready_for_path%s",
            FIX, color::RESET,
            VAR, res->total_distance_m, FIX,
            VAR, res->estimated_time_s, FIX,
            VAR, res->path.size(), FIX,
            VAR, FIX);
          gs_.set_status(hive_nav::MissionStatus::READY_FOR_PATH);
        } else {
          RCLCPP_ERROR(this->get_logger(),
            "%s[route]%s compute_route failed: %s%s%s  (status stays %sready_to_get_global_path%s)",
            FIX, color::RESET,
            VAR, res->message.c_str(), FIX,
            VAR, FIX);
          gs_.set_status(hive_nav::MissionStatus::READY_TO_GET_GLOBAL_PATH);
        }
      } catch (const std::exception &e) {
        RCLCPP_ERROR(this->get_logger(),
          "%s[route]%s compute_route exception: %s%s%s  (status stays %sready_to_get_global_path%s)",
          FIX, color::RESET,
          VAR, e.what(), FIX,
          VAR, FIX);
        gs_.set_status(hive_nav::MissionStatus::READY_TO_GET_GLOBAL_PATH);
      }
    });
}

// =======================
//   Distances & heading
// =======================
double HiveNavBrainNode::compute_distance_to_current_path_xy(double x, double y, std::string &note) const
{
  std::lock_guard<std::mutex> lk(path_mtx_);
  if (current_path_.empty()) {
    note = "(no global path yet)";
    return 0.0;
  }

  double best = std::numeric_limits<double>::infinity();
  for (const auto &ll : current_path_) {
    const double ax = static_cast<double>(ll.start_point_x);
    const double ay = static_cast<double>(ll.start_point_y);
    const double bx = static_cast<double>(ll.end_point_x);
    const double by = static_cast<double>(ll.end_point_y);

    const double vx = bx - ax, vy = by - ay;
    const double wx = x - ax,  wy = y - ay;
    const double vv = vx*vx + vy*vy;

    double d;
    if (vv <= 1e-12) {
      const double dx = x - ax, dy = y - ay;
      d = std::sqrt(dx*dx + dy*dy);
    } else {
      double t = (wx*vx + wy*vy) / vv;
      if (t < 0.0) t = 0.0; else if (t > 1.0) t = 1.0;
      const double projx = ax + t * vx;
      const double projy = ay + t * vy;
      const double dx = x - projx, dy = y - projy;
      d = std::sqrt(dx*dx + dy*dy);
    }
    if (d < best) best = d;
  }

  if (!std::isfinite(best)) {
    note = "(path invalid)";
    return 0.0;
  }
  note.clear();
  return best;
}

bool HiveNavBrainNode::heading_on_path_at(double x, double y, double &yaw) const
{
  std::lock_guard<std::mutex> lk(path_mtx_);
  if (current_path_.empty()) return false;

  double best = std::numeric_limits<double>::infinity();
  double best_vx = 0.0, best_vy = 0.0;

  for (const auto &ll : current_path_) {
    const double ax = static_cast<double>(ll.start_point_x);
    const double ay = static_cast<double>(ll.start_point_y);
    const double bx = static_cast<double>(ll.end_point_x);
    const double by = static_cast<double>(ll.end_point_y);

    const double vx = bx - ax, vy = by - ay;
    const double wx = x - ax,  wy = y - ay;
    const double vv = vx*vx + vy*vy;

    double d = 0.0;
    if (vv <= 1e-12) {
      const double dx = x - ax, dy = y - ay;
      d = std::sqrt(dx*dx + dy*dy);
    } else {
      double t = (wx*vx + wy*vy) / vv;
      if (t < 0.0) t = 0.0; else if (t > 1.0) t = 1.0;
      const double projx = ax + t * vx;
      const double projy = ay + t * vy;
      const double dx = x - projx, dy = y - projy;
      d = std::sqrt(dx*dx + dy*dy);
    }

    if (d < best) {
      best = d;
      best_vx = vx; best_vy = vy; // sens start -> end
    }
  }

  const double n2 = best_vx*best_vx + best_vy*best_vy;
  if (!std::isfinite(best) || n2 <= 1e-12) return false;

  yaw = std::atan2(best_vy, best_vx); // start -> end
  return true;
}

// =======================
//   Controller server
// =======================
void HiveNavBrainNode::maybe_send_follow_path()
{
  // Éviter les envois multiples
  if (waiting_follow_ || running_follow_) return;

  // Récupérer le path stocké (hive ou astar)
  if (!gs_.has_mission_path()) {
    RCLCPP_WARN_THROTTLE(this->get_logger(), *this->get_clock(), 2000,
      "%s[follow]%s no mission path available to send", FIX, color::RESET);
    return;
  }
  if (!follow_action_client_->wait_for_action_server(100ms)) {
    RCLCPP_ERROR(this->get_logger(), "%s[follow]%s action server %s/%s%s not available",
                 FIX, color::RESET, VAR, (P_.ns + "/follow_path").c_str(), FIX);
    return;
  }

  auto path = gs_.mission().general_path;      // copie
  path.header.stamp = this->now();             // fraicheur

  FP::Goal goal;
  goal.path = path;
  goal.controller_id = "";     // laisser vide -> défaut
  goal.goal_checker_id = "";   // laisser vide -> défaut

  waiting_follow_   = true;
  last_follow_mode_ = gs_.movement_mode();

  RCLCPP_INFO(this->get_logger(),
    "%s[follow]%s send path to controller: poses=%s%zu%s mode=%s%s%s",
    FIX, color::RESET,
    VAR, path.poses.size(), FIX,
    VAR, hive_nav::to_string(last_follow_mode_), FIX);

  auto send_opts = rclcpp_action::Client<FP>::SendGoalOptions();

  send_opts.goal_response_callback =
    [this](std::shared_ptr<FPGoalHandle> handle)
    {
      waiting_follow_ = false;
      if (!handle) {
        RCLCPP_ERROR(this->get_logger(), "%s[follow]%s goal was rejected by controller",
                     FIX, color::RESET);
        return;
      }
      follow_goal_handle_ = handle;
      running_follow_ = true;
      RCLCPP_INFO(this->get_logger(), "%s[follow]%s goal accepted by controller",
                  FIX, color::RESET);
    };

  send_opts.result_callback =
    [this](const rclcpp_action::ClientGoalHandle<FP>::WrappedResult &res)
    {
      running_follow_ = false;
      waiting_follow_ = false;

      if (res.code == rclcpp_action::ResultCode::SUCCEEDED) {
        RCLCPP_INFO(this->get_logger(), "%s[follow]%s result: SUCCEEDED", FIX, color::RESET);

        // ✅ ARRÊT DU CYCLE : on passe en IDLE et on annule tout suivi restant.
        gs_.set_status(hive_nav::MissionStatus::IDLE);
        cancel_follow_if_running("goal reached");
        return;
      }

      RCLCPP_ERROR(this->get_logger(),
        "%s[follow]%s result code: %s%d%s",
        FIX, color::RESET, VAR, static_cast<int>(res.code), FIX);

      // En cas d’échec : on redevient "prêt à replanifier", pas READY_TO_RUN
      gs_.set_status(hive_nav::MissionStatus::READY_FOR_PATH);
    };

  follow_action_client_->async_send_goal(goal, send_opts);
}

void HiveNavBrainNode::cancel_follow_if_running(const char* why)
{
  if (!running_follow_ && !waiting_follow_) return;

  if (follow_goal_handle_) {
    RCLCPP_INFO(this->get_logger(), "%s[follow]%s cancel current follow (reason=%s%s%s)",
                FIX, color::RESET, VAR, (why ? why : ""), FIX);
    follow_action_client_->async_cancel_goal(follow_goal_handle_);
  } else {
    RCLCPP_INFO(this->get_logger(), "%s[follow]%s cancel all goals (no handle) (reason=%s%s%s)",
                FIX, color::RESET, VAR, (why ? why : ""), FIX);
    follow_action_client_->async_cancel_all_goals();
  }
  running_follow_ = false;
  waiting_follow_ = false;
  follow_goal_handle_.reset();
}
