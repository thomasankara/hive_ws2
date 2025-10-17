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

  // 1) TF -> pose robot (10 Hz)
  geometry_msgs::msg::PoseStamped pose_map;
  if (hive_tf::try_get_pose_map(*tf_buffer_, map_frame_, base_footprint_frame_,
                                pose_map, this->get_logger(), *this->get_clock())) {
    gs_.set_robot_pose_map(pose_map);
  }

  // 2) Distance au global path (log 1 Hz)
  double dist_to_path_m = 0.0;
  std::string dist_note;
  const auto rob = gs_.robot();

  if (rob.has_pose) {
    std::vector<hive_interface2::msg::LaneletMini2> path_copy;
    { std::lock_guard<std::mutex> lk(path_mtx_); path_copy = current_path_; }

    dist_to_path_m = hive_nav_utils::distance_to_path_xy(
      path_copy,
      rob.pose_map.pose.position.x,
      rob.pose_map.pose.position.y,
      dist_note
    );
  } else {
    dist_note = "(no robot pose / TF)";
  }

  // 3) Hystérésis du MovementMode (si path présent)
  if (dist_note.empty()) {
    constexpr double THRESH_LOW  = 0.9; // < 0.9  -> hive_planner
    constexpr double THRESH_HIGH = 1.1; // > 1.1  -> astar_planner
    auto mode = gs_.movement_mode();

    if (mode == hive_nav::MovementMode::HIVE_PLANNER && dist_to_path_m > THRESH_HIGH) {
      gs_.set_movement_mode(hive_nav::MovementMode::ASTAR_PLANNER);
    } else if (mode == hive_nav::MovementMode::ASTAR_PLANNER && dist_to_path_m < THRESH_LOW) {
      gs_.set_movement_mode(hive_nav::MovementMode::HIVE_PLANNER);
    }
  }

  // 4) Target locale (10 Hz) + marker
  if (rob.has_pose) {
    std::vector<hive_interface2::msg::LaneletMini2> path_copy;
    { std::lock_guard<std::mutex> lk(path_mtx_); path_copy = current_path_; }

    double tx = 0.0, ty = 0.0;
    std::string tgt_note;
    const auto goal = gs_.mission().destination.pose.position;

    if (hive_nav_utils::compute_local_target(
          path_copy,
          rob.pose_map.pose.position.x, rob.pose_map.pose.position.y,
          goal.x, goal.y,
          gs_.movement_mode(),
          /*lookahead_m=*/6.0,
          tx, ty, tgt_note))
    {
      geometry_msgs::msg::PointStamped pmsg;
      pmsg.header.stamp = this->now();
      pmsg.header.frame_id = map_frame_;
      pmsg.point.x = tx; pmsg.point.y = ty; pmsg.point.z = 0.0;
      target_pub_->publish(pmsg);

      // Marker sphère (position)
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

      // Marker flèche (orientation) — alignée lanelet start->end
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
        // longueur/épaisseur
        a.scale.x = 0.9;  // longueur
        a.scale.y = 0.25; // largeur
        a.scale.z = 0.25; // hauteur
        a.color.a = 0.9;
        a.color.r = 1.0; a.color.g = 0.7; a.color.b = 0.2;
        target_marker_pub_->publish(a);
      }
    } else {
      // delete markers
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

  // 5) Heartbeat (1 Hz)
  if ((loop_tick_ % 10) == 0) {
    const auto mode = gs_.movement_mode();
    if (rob.has_pose) {
      RCLCPP_INFO(this->get_logger(),
        "%s[loop]%s heartbeat — data: route=%s%s%s poi=%s%s%s free_zone=%s%s%s  status=%s%s%s  mode=%s%s%s  pose(map)=%s%.2f%s,%s%.2f%s,%s%.2f%s  dist_to_path=%s%.2f%s m %s%s%s",
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
        VAR, dist_note.c_str(), FIX
      );
    } else {
      RCLCPP_INFO(this->get_logger(),
        "%s[loop]%s heartbeat — data: route=%s%s%s poi=%s%s%s free_zone=%s%s%s  status=%s%s%s  mode=%s%s%s  pose(map)=%sN/A%s  dist_to_path=%s%.2f%s m %s%s%s",
        FIX, color::RESET,
        VAR, (store_.has_lanelets() ? "OK" : "—"), FIX,
        VAR, (store_.has_pois() ? "OK" : "—"), FIX,
        VAR, (store_.has_free_zones() ? "OK" : "—"), FIX,
        VAR, hive_nav::to_string(gs_.status()), FIX,
        VAR, hive_nav::to_string(gs_.movement_mode()), FIX,
        VAR, FIX,
        VAR, dist_to_path_m, FIX,
        VAR, dist_note.c_str(), FIX
      );
    }
  }

  // 6) Demande du global path (lanelets)
  if (gs_.status() == hive_nav::MissionStatus::READY_TO_GET_GLOBAL_PATH) {
    try_request_global_path();
  }

  // 7) Si READY_FOR_PATH :
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

    // ASTAR_PLANNER -> envoyer une CPTP au point local avec orientation alignée lanelet
    if (gs_.movement_mode() == hive_nav::MovementMode::ASTAR_PLANNER &&
        !waiting_astar_)
    {
      // Construire la cible locale (règle ASTAR déjà gérée)
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
        CPTP::Goal goal;
        goal.use_start = true;
        goal.start.header.frame_id = map_frame_;
        goal.start.header.stamp = this->now();
        goal.start.pose = gs_.robot().pose_map.pose;

        geometry_msgs::msg::PoseStamped g;
        g.header.frame_id = map_frame_;
        g.header.stamp = this->now();
        g.pose.position.x = tx;
        g.pose.position.y = ty;
        g.pose.position.z = 0.0;

        // Orientation alignée lanelet start->end au point (tx,ty)
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

        // Jazzy+ : wrapper Goals -> goal.goals.goals
        goal.goals.goals.clear();
        goal.goals.goals.push_back(g);

        waiting_astar_ = true;
        gs_.set_status(hive_nav::MissionStatus::WAITING_FOR_HIVE_PLANNER); // "en attente d'un planner"

        RCLCPP_INFO(this->get_logger(),
          "%s[astar]%s send CPTP: start(%s%.2f%s,%s%.2f%s) -> local(%s%.2f%s,%s%.2f%s) yaw=%s%.2f%s rad",
          FIX, color::RESET,
          VAR, goal.start.pose.position.x, FIX, VAR, goal.start.pose.position.y, FIX,
          VAR, g.pose.position.x, FIX, VAR, g.pose.position.y, FIX,
          VAR, yaw_path, FIX);

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

            auto path_copy = path;
            path_copy.header.stamp = this->now();
            hive_path_pub_->publish(path_copy);
            gs_.set_mission_path(path_copy);
            gs_.set_status(hive_nav::MissionStatus::READY_TO_RUN);

            const double tplan = res.result->planning_time.sec + res.result->planning_time.nanosec*1e-9;
            RCLCPP_INFO(this->get_logger(),
              "%s[astar]%s path received: poses=%s%zu%s planning_time=%s%.3f%s s -> status=%s%s%s",
              FIX, color::RESET,
              VAR, path_copy.poses.size(), FIX,
              VAR, tplan, FIX,
              VAR, hive_nav::to_string(gs_.status()), FIX);
          };

        path_action_client_->async_send_goal(goal, send_goal_options);
      }
    }
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
      // Segment dégénéré
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
