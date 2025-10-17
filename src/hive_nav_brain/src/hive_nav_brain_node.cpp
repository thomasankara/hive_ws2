#include "hive_nav_brain/hive_nav_brain_node.hpp"
#include "hive_nav_brain/colors.hpp"

#include <chrono>
#include <future>
#include <limits>
#include <cmath>

// Marker (gros point RViz)
#include <visualization_msgs/msg/marker.hpp>

using std::placeholders::_1;
using namespace std::chrono_literals;

// =======================
//   Helpers (file-scope)
// =======================
static inline double seg_len(double ax, double ay, double bx, double by) {
  const double dx = bx - ax, dy = by - ay;
  return std::sqrt(dx*dx + dy*dy);
}

static inline double dist2(double ax, double ay, double bx, double by) {
  const double dx = bx - ax, dy = by - ay;
  return dx*dx + dy*dy;
}

// Distance euclidienne d’un point (px,py) à un segment [A(ax,ay), B(bx,by)]
static inline double point_segment_distance(double px, double py, double ax, double ay, double bx, double by)
{
  const double vx = bx - ax;
  const double vy = by - ay;
  const double wx = px - ax;
  const double wy = py - ay;

  const double vv = vx*vx + vy*vy;
  if (vv <= 1e-12) {
    // Segment dégénéré -> distance au point A
    const double dx = px - ax;
    const double dy = py - ay;
    return std::sqrt(dx*dx + dy*dy);
  }

  double t = (wx*vx + wy*vy) / vv;
  if (t < 0.0) t = 0.0;
  else if (t > 1.0) t = 1.0;

  const double projx = ax + t * vx;
  const double projy = ay + t * vy;

  const double dx = px - projx;
  const double dy = py - projy;
  return std::sqrt(dx*dx + dy*dy);
}

// =======================
//   Constructeur
// =======================
HiveNavBrainNode::HiveNavBrainNode()
: Node("hive_nav_brain_node")
{
  // --------- Paramètres ---------
  P_.ns = this->declare_parameter<std::string>("robot_namespace", "robot1");
  P_.fetch_service_basename = this->declare_parameter<std::string>("fetch_service_basename", "refresh_all_data");
  P_.build_names();

  // Init état global
  gs_.set_robot_namespace(P_.ns);
  gs_.set_movement_mode(hive_nav::MovementMode::ASTAR_PLANNER); // défaut

  auto qos_latched = rclcpp::QoS(1).reliable().transient_local();

  // --------- Subscriptions ---------
  sub_lanelets_ = this->create_subscription<hive_interface2::msg::LaneletMini2Array>(
    P_.topic_lanelets, qos_latched, std::bind(&HiveNavBrainNode::onLanelets, this, _1));

  sub_pois_ = this->create_subscription<hive_interface2::msg::PoiArray>(
    P_.topic_pois, qos_latched, std::bind(&HiveNavBrainNode::onPois, this, _1));

  sub_freezones_ = this->create_subscription<hive_interface2::msg::FreeZoneArray>(
    P_.topic_freezones, qos_latched, std::bind(&HiveNavBrainNode::onFreeZones, this, _1));

  sub_cmd_ = this->create_subscription<hive_interface2::msg::NavBrainCommand>(
    P_.topic_cmd, rclcpp::QoS(10), std::bind(&HiveNavBrainNode::onCommand, this, _1));

  // --------- Clients de services ---------
  trigger_client_ = this->create_client<std_srvs::srv::Trigger>(P_.service_name);
  route_client_   = this->create_client<hive_interface2::srv::ComputeRoute>("/" + P_.ns + "/compute_route");

  // --------- TF2 ---------
  base_footprint_frame_ = P_.ns + std::string("/base_footprint");
  tf_buffer_   = std::make_shared<tf2_ros::Buffer>(this->get_clock());
  tf_listener_ = std::make_shared<tf2_ros::TransformListener>(*tf_buffer_, this, false);

  // --------- Publishers ---------
  const std::string target_topic = "/" + P_.ns + "/target_local";
  target_pub_ = this->create_publisher<geometry_msgs::msg::PointStamped>(target_topic, rclcpp::QoS(1));

  const std::string target_marker_topic = "/" + P_.ns + "/target_local_marker";
  target_marker_pub_ = this->create_publisher<visualization_msgs::msg::Marker>(target_marker_topic, rclcpp::QoS(1));

  // --------- Log d’initialisation ---------
  RCLCPP_INFO(this->get_logger(),
    "%s[hive_nav_brain]%s ns=%s%s%s  service=%s%s%s  cmd_topic=%s%s%s  tf=%smap->%s%s",
    color::BOLD, color::RESET,
    color::MAG, P_.ns.c_str(), color::RESET,
    color::CYAN, P_.service_name.c_str(), color::RESET,
    color::CYAN, P_.topic_cmd.c_str(), color::RESET,
    color::CYAN, base_footprint_frame_.c_str(), color::RESET);
  RCLCPP_INFO(this->get_logger(), "[init] target_local topic -> %s", target_topic.c_str());
  RCLCPP_INFO(this->get_logger(), "[init] target_local_marker topic -> %s", target_marker_topic.c_str());
}

// =======================
//   Démarrage bloquant
// =======================
void HiveNavBrainNode::blocking_startup()
{
  // 1) Attendre que le service "fetch" soit disponible
  RCLCPP_INFO(this->get_logger(), "%s[init]%s wait for service %s%s%s ...",
              color::YELLOW, color::RESET, color::CYAN, P_.service_name.c_str(), color::RESET);

  while (rclcpp::ok() && !trigger_client_->wait_for_service(1s)) {
    RCLCPP_WARN(this->get_logger(), "%s[init]%s service not available, retry...",
                color::YELLOW, color::RESET);
    rclcpp::sleep_for(500ms);
    rclcpp::spin_some(shared_from_this());
  }

  // 2) Appeler le service jusqu’à succès
  bool ok = false; int attempt = 0;
  while (rclcpp::ok() && !ok) {
    attempt++;
    RCLCPP_INFO(this->get_logger(), "%s[init]%s call %s (try #%d)",
                color::YELLOW, color::RESET, P_.service_name.c_str(), attempt);

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
                      color::GREEN, color::RESET, color::CYAN, res->message.c_str(), color::RESET);
        } else {
          RCLCPP_WARN(this->get_logger(), "%s[init]%s service false: %s\"%s\"%s (retry)",
                      color::YELLOW, color::RESET, color::CYAN, res->message.c_str(), color::RESET);
          rclcpp::sleep_for(1s);
        }
      } catch (const std::exception &e) {
        RCLCPP_ERROR(this->get_logger(), "%s[init]%s Trigger exception: %s",
                     color::RED, color::RESET, e.what());
        rclcpp::sleep_for(1s);
      }
    } else {
      RCLCPP_WARN(this->get_logger(), "%s[init]%s service timeout (retry)", color::YELLOW, color::RESET);
      rclcpp::sleep_for(1s);
    }
  }

  // 3) Attendre la réception des données topics requises
  const bool need_poi = (P_.fetch_service_basename == "refresh_all_data");
  const bool need_fz  = (P_.fetch_service_basename == "refresh_all_data");

  RCLCPP_INFO(this->get_logger(),
    "%s[init]%s waiting topics: %sroute_data%s  %s%s%s  %s%s%s",
    color::YELLOW, color::RESET,
    color::CYAN, color::RESET,
    need_poi ? color::CYAN : color::DIM, need_poi ? "poi_data" : "(poi skip)", color::RESET,
    need_fz  ? color::CYAN : color::DIM, need_fz  ? "free_zone_data" : "(free_zone skip)", color::RESET);

  auto last = std::chrono::steady_clock::now();
  while (rclcpp::ok() && !have_all_required_data(need_poi, need_fz)) {
    rclcpp::spin_some(shared_from_this());
    rclcpp::sleep_for(100ms);
    auto now = std::chrono::steady_clock::now();
    if (now - last > 2s) {
      RCLCPP_INFO(this->get_logger(), "%s[init]%s pending: route=%s poi=%s free_zone=%s",
        color::DIM, color::RESET,
        store_.has_lanelets() ? "OK" : "—",
        need_poi ? (store_.has_pois() ? "OK" : "—") : "skip",
        need_fz  ? (store_.has_free_zones() ? "OK" : "—") : "skip");
      last = now;
    }
  }

  if (!rclcpp::ok()) return;

  RCLCPP_INFO(this->get_logger(), "%s[init]%s all required data received",
              color::GREEN, color::RESET);

  // 4) Démarrer la boucle 10 Hz via un timer 100 ms
  loop_timer_ = this->create_wall_timer(
    100ms,  // => 10 Hz
    std::bind(&HiveNavBrainNode::onLoop, this)
  );

  RCLCPP_INFO(this->get_logger(), "%s[loop]%s 10 Hz loop started (log 1 Hz)",
              color::GREEN, color::RESET);
}

// =======================
//   Callbacks Topics
// =======================
void HiveNavBrainNode::onLanelets(const hive_interface2::msg::LaneletMini2Array::SharedPtr msg)
{
  store_.set_lanelets(msg->lanelets);
  if (!msg->lanelets.empty()) {
    const auto &f = msg->lanelets.front();
    RCLCPP_INFO(this->get_logger(), "%s[route_data]%s %zu lanelets (ex id=%d w=%.2f vmax=%d)",
                color::BLUE, color::RESET, msg->lanelets.size(), f.lanelet_mini_id, f.width, f.max_speed);
  } else {
    RCLCPP_WARN(this->get_logger(), "%s[route_data]%s empty", color::BLUE, color::RESET);
  }
}

void HiveNavBrainNode::onPois(const hive_interface2::msg::PoiArray::SharedPtr msg)
{
  store_.set_pois(msg->items);
  if (!msg->items.empty()) {
    const auto &p = msg->items.front();
    RCLCPP_INFO(this->get_logger(), "%s[poi_data]%s %zu pois (ex id=%d x=%.2f y=%.2f yaw=%.1f)",
                color::MAG, color::RESET, msg->items.size(), p.poi_id, p.x, p.y, p.yaw);
  } else {
    RCLCPP_WARN(this->get_logger(), "%s[poi_data]%s empty", color::MAG, color::RESET);
  }
}

void HiveNavBrainNode::onFreeZones(const hive_interface2::msg::FreeZoneArray::SharedPtr msg)
{
  store_.set_freezones(msg->items);
  if (!msg->items.empty()) {
    const auto &z = msg->items.front();
    RCLCPP_INFO(this->get_logger(), "%s[free_zone_data]%s %zu zones (ex id=%s vmax=%d)",
                color::CYAN, color::RESET, msg->items.size(), z.free_zone_id.c_str(), z.max_speed);
  } else {
    RCLCPP_WARN(this->get_logger(), "%s[free_zone_data]%s empty", color::CYAN, color::RESET);
  }
}

void HiveNavBrainNode::onCommand(const hive_interface2::msg::NavBrainCommand::SharedPtr cmd)
{
  store_.set_last_cmd(*cmd);

  // Reset du path courant à la nouvelle mission
  {
    std::lock_guard<std::mutex> lk(path_mtx_);
    current_path_.clear();
  }

  // MAJ mission + status READY_TO_GET_GLOBAL_PATH
  gs_.update_from_command(*cmd, "map");

  const auto &p = cmd->destination.pose.position;
  const auto &q = cmd->destination.pose.orientation;
  RCLCPP_INFO(this->get_logger(),
    "%s[command]%s mission=%d poi=%d free_zone=%d obj=%d  dest(x=%.2f y=%.2f z=%.2f q=%.2f,%.2f,%.2f,%.2f)  -> status=%s",
    color::GREEN, color::RESET,
    cmd->mission_id, cmd->poi_id, cmd->free_zone_id, cmd->object_tracking_id,
    p.x, p.y, p.z, q.x, q.y, q.z, q.w,
    hive_nav::to_string(gs_.status())
  );
}

// =======================
//   Helpers
// =======================
bool HiveNavBrainNode::have_all_required_data(bool /*need_poi*/, bool /*need_fz*/) const
{
  if (!store_.has_lanelets()) return false;

  if (!store_.has_pois())
    RCLCPP_WARN_THROTTLE(get_logger(), *get_clock(), 5000,
      "[init] POI data missing (continuing anyway)");
  if (!store_.has_free_zones())
    RCLCPP_WARN_THROTTLE(get_logger(), *get_clock(), 5000,
      "[init] FreeZone data missing (continuing anyway)");

  return true;
}

// =======================
//   Boucle 10 Hz
// =======================
void HiveNavBrainNode::onLoop()
{
  ++loop_tick_;

  // 10 Hz: TF -> pose robot
  try_update_robot_pose_from_tf();

  // Calcule la distance à chaque tick (log 1 Hz)
  double dist_to_path_m = 0.0;
  std::string dist_note;
  const auto rob = gs_.robot();
  if (rob.has_pose) {
    dist_to_path_m = compute_distance_to_current_path_xy(
      rob.pose_map.pose.position.x,
      rob.pose_map.pose.position.y,
      dist_note
    );
  } else {
    dist_note = "(no robot pose / TF)";
  }

  // 🧠 Hystérésis du mode si on a réellement un path (note vide)
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

  // === Calcul & publication de la target locale (10 Hz) ===
  if (rob.has_pose) {
    double tx=0.0, ty=0.0; std::string tgt_note;
    if (compute_local_target(rob.pose_map.pose.position.x,
                             rob.pose_map.pose.position.y,
                             tx, ty, tgt_note))
    {
      // PointStamped (compat minimal)
      geometry_msgs::msg::PointStamped pmsg;
      pmsg.header.stamp = this->now();
      pmsg.header.frame_id = map_frame_;
      pmsg.point.x = tx; pmsg.point.y = ty; pmsg.point.z = 0.0;
      target_pub_->publish(pmsg);

      // Marker RViz (gros point)
      visualization_msgs::msg::Marker m;
      m.header.stamp = pmsg.header.stamp;
      m.header.frame_id = pmsg.header.frame_id;
      m.ns = "target_local";
      m.id = 1;
      m.type = visualization_msgs::msg::Marker::SPHERE;
      m.action = visualization_msgs::msg::Marker::ADD;
      m.pose.position.x = tx; m.pose.position.y = ty; m.pose.position.z = 0.15;
      m.pose.orientation.w = 1.0;
      m.scale.x = 0.50;  // <<< plus gros
      m.scale.y = 0.50;
      m.scale.z = 0.50;
      // Couleur suivant le mode pour lecture rapide
      const auto mode = gs_.movement_mode();
      m.color.a = 1.0;
      if (mode == hive_nav::MovementMode::HIVE_PLANNER) { m.color.r = 0.1; m.color.g = 0.9; m.color.b = 0.1; } // vert
      else                                              { m.color.r = 0.1; m.color.g = 0.4; m.color.b = 1.0; } // bleu
      m.lifetime = rclcpp::Duration(0,0); // persistant jusqu’au prochain publish
      target_marker_pub_->publish(m);
    } else {
      // Pas de path -> effacer le marker pour éviter un fantôme
      visualization_msgs::msg::Marker m;
      m.header.stamp = this->now();
      m.header.frame_id = map_frame_;
      m.ns = "target_local";
      m.id = 1;
      m.action = visualization_msgs::msg::Marker::DELETE;
      target_marker_pub_->publish(m);
    }
  }

  // 1 Hz : heartbeat (avec status, mode, pose, dist_to_path)
  if ((loop_tick_ % 10) == 0) {
    const auto mode = gs_.movement_mode();
    if (rob.has_pose) {
      RCLCPP_INFO(this->get_logger(),
        "%s[loop]%s heartbeat — data: route=%s poi=%s free_zone=%s  status=%s  mode=%s  pose(map)=%.2f,%.2f,%.2f  dist_to_path=%.2f m %s",
        color::DIM, color::RESET,
        store_.has_lanelets() ? "OK" : "—",
        store_.has_pois() ? "OK" : "—",
        store_.has_free_zones() ? "OK" : "—",
        hive_nav::to_string(gs_.status()),
        hive_nav::to_string(mode),
        rob.pose_map.pose.position.x, rob.pose_map.pose.position.y, rob.pose_map.pose.position.z,
        dist_to_path_m, dist_note.c_str()
      );
    } else {
      RCLCPP_INFO(this->get_logger(),
        "%s[loop]%s heartbeat — data: route=%s poi=%s free_zone=%s  status=%s  mode=%s  pose(map)=N/A  dist_to_path=%.2f m %s",
        color::DIM, color::RESET,
        store_.has_lanelets() ? "OK" : "—",
        store_.has_pois() ? "OK" : "—",
        store_.has_free_zones() ? "OK" : "—",
        hive_nav::to_string(gs_.status()),
        hive_nav::to_string(gs_.movement_mode()),
        dist_to_path_m, dist_note.c_str()
      );
    }
  }

  // Déclenchement route si ready
  if (gs_.status() == hive_nav::MissionStatus::READY_TO_GET_GLOBAL_PATH) {
    try_request_global_path();
  }
}

// =======================
//   TF update (10 Hz)
// =======================
void HiveNavBrainNode::try_update_robot_pose_from_tf()
{
  try {
    const auto tf = tf_buffer_->lookupTransform(
      map_frame_, base_footprint_frame_, tf2::TimePointZero);

    geometry_msgs::msg::PoseStamped pose;
    pose.header = tf.header;
    pose.pose.position.x = tf.transform.translation.x;
    pose.pose.position.y = tf.transform.translation.y;
    pose.pose.position.z = tf.transform.translation.z;
    pose.pose.orientation = tf.transform.rotation;

    gs_.set_robot_pose_map(pose);
  } catch (const tf2::TransformException &ex) {
    RCLCPP_WARN_THROTTLE(this->get_logger(), *this->get_clock(), 2000,
      "%s[tf]%s cannot lookup %s -> %s : %s",
      color::YELLOW, color::RESET, map_frame_.c_str(), base_footprint_frame_.c_str(), ex.what());
  }
}

// =======================
//   Demande global path
// =======================
void HiveNavBrainNode::try_request_global_path()
{
  const auto rob = gs_.robot();
  const auto mis = gs_.mission();

  if (!rob.has_pose) {
    RCLCPP_ERROR(this->get_logger(),
      "%s[route]%s cannot request path: robot pose unavailable (TF)",
      color::RED, color::RESET);
    return;
  }

  if (!route_client_->service_is_ready()) {
    RCLCPP_ERROR_THROTTLE(this->get_logger(), *this->get_clock(), 1000,
      "%s[route]%s service '/%s/compute_route' not available",
      color::RED, color::RESET, P_.ns.c_str());
    return;
  }

  auto req = std::make_shared<hive_interface2::srv::ComputeRoute::Request>();
  req->start_pose = rob.pose_map.pose;            // orientation ignorée, on met celle du TF
  req->goal_pose  = mis.destination.pose;         // orientation ignorée
  req->mode       = 1;                            // 1 = temps minimal

  RCLCPP_INFO(this->get_logger(),
    "%s[route]%s request compute_route: start(%.2f,%.2f) -> goal(%.2f,%.2f) mode=TIME",
    color::GREEN, color::RESET,
    req->start_pose.position.x, req->start_pose.position.y,
    req->goal_pose.position.x,  req->goal_pose.position.y);

  // Passer en attente dès l'envoi
  gs_.set_status(hive_nav::MissionStatus::WAITING_TO_GET_GLOBAL_PATH);

  route_client_->async_send_request(
    req,
    [this](rclcpp::Client<hive_interface2::srv::ComputeRoute>::SharedFuture fut)
    {
      try {
        auto res = fut.get();
        if (res->success) {
          // ✅ Stocker le path
          {
            std::lock_guard<std::mutex> lk(path_mtx_);
            current_path_ = res->path; // peut être vide si “direct_link”
          }

          RCLCPP_INFO(this->get_logger(),
            "%s[route]%s received path: dist=%.2f m  eta=%.2f s  lanelets=%zu  -> status=ready_for_path",
            color::GREEN, color::RESET, res->total_distance_m, res->estimated_time_s, res->path.size());
          gs_.set_status(hive_nav::MissionStatus::READY_FOR_PATH);
        } else {
          RCLCPP_ERROR(this->get_logger(),
            "%s[route]%s compute_route failed: %s  (status stays ready_to_get_global_path)",
            color::RED, color::RESET, res->message.c_str());
          gs_.set_status(hive_nav::MissionStatus::READY_TO_GET_GLOBAL_PATH);
        }
      } catch (const std::exception &e) {
        RCLCPP_ERROR(this->get_logger(),
          "%s[route]%s compute_route exception: %s  (status stays ready_to_get_global_path)",
          color::RED, color::RESET, e.what());
        gs_.set_status(hive_nav::MissionStatus::READY_TO_GET_GLOBAL_PATH);
      }
    });

}

// =======================
//   Dist au path (xy)
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
    const double d = point_segment_distance(x, y, ax, ay, bx, by);
    if (d < best) best = d;
  }

  if (!std::isfinite(best)) {
    note = "(path invalid)";
    return 0.0;
  }

  note.clear();
  return best;
}

// =======================
//   Projection sur path
// =======================
HiveNavBrainNode::PathProjection
HiveNavBrainNode::project_on_current_path(double x, double y) const
{
  std::lock_guard<std::mutex> lk(path_mtx_);
  PathProjection P;
  if (current_path_.empty()) return P;

  double best_d2 = std::numeric_limits<double>::infinity();

  for (size_t i = 0; i < current_path_.size(); ++i) {
    const auto &ll = current_path_[i];
    const double ax = static_cast<double>(ll.start_point_x);
    const double ay = static_cast<double>(ll.start_point_y);
    const double bx = static_cast<double>(ll.end_point_x);
    const double by = static_cast<double>(ll.end_point_y);

    const double vx = bx - ax, vy = by - ay;
    const double wx = x - ax,  wy = y - ay;
    const double vv = vx*vx + vy*vy;

    double t = 0.0;
    if (vv > 1e-12) {
      t = (wx*vx + wy*vy) / vv;
      if (t < 0.0) t = 0.0;
      else if (t > 1.0) t = 1.0;
    }
    const double px = ax + t*vx;
    const double py = ay + t*vy;
    const double d2 = dist2(x,y,px,py);

    if (d2 < best_d2) {
      best_d2 = d2;
      P.ok = true;
      P.seg_idx = i;
      P.t = t;
      P.px = px; P.py = py;
    }
  }
  return P;
}

// =======================
//   Target locale (10 Hz)
// =======================
bool HiveNavBrainNode::compute_local_target(double rx, double ry,
                                            double &tx, double &ty, std::string &note)
{
  // 1) Faut un path
  std::vector<hive_interface2::msg::LaneletMini2> path_copy;
  {
    std::lock_guard<std::mutex> lk(path_mtx_);
    if (current_path_.empty()) {
      note = "(no global path yet)";
      return false;
    }
    path_copy = current_path_;
  }

  // 2) Projection du robot
  const auto proj = project_on_current_path(rx, ry);
  if (!proj.ok) {
    note = "(projection failed)";
    return false;
  }

  // 3) Prépare avancée selon le mode
  const auto mode = gs_.movement_mode();
  const auto goal = gs_.mission().destination.pose.position;
  constexpr double kLookahead = 6.0; // m

  double rem = 0.0; // distance à avancer le long des lanelets à partir de la projection

  if (mode == hive_nav::MovementMode::ASTAR_PLANNER) {
    // Règle: si robot -> proj > 6m, target = proj
    const double d_robot_proj = std::hypot(rx - proj.px, ry - proj.py);
    if (d_robot_proj > kLookahead) {
      tx = proj.px; ty = proj.py;
      note.clear();
      return true;
    }
    // Sinon on avance de (6m - d_robot_proj) le long des segments
    rem = kLookahead - d_robot_proj;
    if (rem <= 1e-6) {
      tx = proj.px; ty = proj.py; // quasi nul: garde la projection
      note.clear();
      return true;
    }
  } else {
    // hive_planner: avance toujours de 6m depuis la projection
    rem = kLookahead;
  }

  // 4) Avancer le long des lanelets dans le BON SENS (continuité / goal)
  size_t i = proj.seg_idx;
  while (i < path_copy.size()) {
    const auto &ll = path_copy[i];
    const double ax = static_cast<double>(ll.start_point_x);
    const double ay = static_cast<double>(ll.start_point_y);
    const double bx = static_cast<double>(ll.end_point_x);
    const double by = static_cast<double>(ll.end_point_y);
    const double L  = seg_len(ax, ay, bx, by);
    if (L < 1e-6) { ++i; continue; }

    // Orientation du segment i
    bool forward_to_B = true; // true => A->B, false => B->A
    if (i + 1 < path_copy.size()) {
      const auto &nxt = path_copy[i+1];
      const double a2x = static_cast<double>(nxt.start_point_x);
      const double a2y = static_cast<double>(nxt.start_point_y);
      const double b2x = static_cast<double>(nxt.end_point_x);
      const double b2y = static_cast<double>(nxt.end_point_y);
      const double dA = std::min((ax-a2x)*(ax-a2x)+(ay-a2y)*(ay-a2y),
                                 (ax-b2x)*(ax-b2x)+(ay-b2y)*(ay-b2y));
      const double dB = std::min((bx-a2x)*(bx-a2x)+(by-a2y)*(by-a2y),
                                 (bx-b2x)*(bx-b2x)+(by-b2y)*(by-b2y));
      forward_to_B = (dB <= dA);
    } else {
      // Dernier: oriente vers le goal
      const double dA = (ax-goal.x)*(ax-goal.x) + (ay-goal.y)*(ay-goal.y);
      const double dB = (bx-goal.x)*(bx-goal.x) + (by-goal.y)*(by-goal.y);
      forward_to_B = (dB <= dA);
    }

    // Unitaire orienté
    double ux = 0.0, uy = 0.0;
    if (forward_to_B) { ux = (bx - ax) / L; uy = (by - ay) / L; }
    else              { ux = (ax - bx) / L; uy = (ay - by) / L; }

    if (i == proj.seg_idx) {
      // Distance restante sur ce segment depuis la projection, selon l'orientation
      const double rem_on_seg = forward_to_B ? ((1.0 - proj.t) * L) : (proj.t * L);

      if (rem <= rem_on_seg) {
        // Target dans CE segment, à partir du point projeté
        tx = proj.px + ux * rem;
        ty = proj.py + uy * rem;
        note.clear();
        return true;
      } else {
        // Aller jusqu'à l'extrémité choisie, puis passer au suivant
        rem -= rem_on_seg;
        ++i;
        continue;
      }
    } else {
      // Segments suivants: on part de leur "entrée" selon l'orientation
      double sx, sy; // start du segment orienté
      if (forward_to_B) { sx = ax; sy = ay; } else { sx = bx; sy = by; }

      if (rem <= L) {
        tx = sx + ux * rem;
        ty = sy + uy * rem;
        note.clear();
        return true;
      } else {
        rem -= L;
        ++i;
        continue;
      }
    }
  }

  // 5) Dépasse la fin -> clamp sur le dernier point
  if (!path_copy.empty()) {
    const auto &last = path_copy.back();
    tx = static_cast<double>(last.end_point_x);
    ty = static_cast<double>(last.end_point_y);
    note = "(clamped at path end)";
    return true;
  }

  note = "(unexpected empty path)";
  return false;
}
