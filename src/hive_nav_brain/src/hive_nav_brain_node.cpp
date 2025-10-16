#include "hive_nav_brain/hive_nav_brain_node.hpp"
#include "hive_nav_brain/colors.hpp"

using std::placeholders::_1;
using namespace std::chrono_literals;

HiveNavBrainNode::HiveNavBrainNode()
: Node("hive_nav_brain_node")
{
  // Params
  P_.ns = this->declare_parameter<std::string>("robot_namespace", "robot1");
  P_.fetch_service_basename = this->declare_parameter<std::string>("fetch_service_basename", "refresh_all_data");
  P_.build_names();

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

  // Service client
  trigger_client_ = this->create_client<std_srvs::srv::Trigger>(P_.service_name);

  RCLCPP_INFO(this->get_logger(),
    "%s[hive_nav_brain]%s ns=%s%s%s  service=%s%s%s",
    color::BOLD, color::RESET, color::MAG, P_.ns.c_str(), color::RESET,
    color::CYAN, P_.service_name.c_str(), color::RESET);
}

void HiveNavBrainNode::blocking_startup()
{
  // 1) Attendre service up
  RCLCPP_INFO(this->get_logger(), "%s[init]%s wait for service %s%s%s ...",
              color::YELLOW, color::RESET, color::CYAN, P_.service_name.c_str(), color::RESET);

  while (rclcpp::ok() && !trigger_client_->wait_for_service(1s)) {
    RCLCPP_WARN(this->get_logger(), "%s[init]%s service not available, retry...",
                color::YELLOW, color::RESET);
    rclcpp::sleep_for(500ms);
    rclcpp::spin_some(shared_from_this());
  }

  // 2) Appel service jusqu’à success
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
    } else {
      RCLCPP_WARN(this->get_logger(), "%s[init]%s service timeout (retry)", color::YELLOW, color::RESET);
      rclcpp::sleep_for(1s);
    }
  }

  // 3) Attente des données requises
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
  RCLCPP_INFO(this->get_logger(), "%s✔ all required data received%s",
              color::GREEN, color::RESET);
}

// ---------- Callbacks ----------
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

  const auto &p = cmd->destination.pose.position;
  const auto &q = cmd->destination.pose.orientation;
  RCLCPP_INFO(this->get_logger(),
    "%s[command]%s mission=%d poi=%d free_zone=%d obj=%d  dest(x=%.2f y=%.2f z=%.2f q=%.2f,%.2f,%.2f,%.2f)",
    color::GREEN, color::RESET,
    cmd->mission_id, cmd->poi_id, cmd->free_zone_id, cmd->object_tracking_id,
    p.x, p.y, p.z, q.x, q.y, q.z, q.w);
}

// ---------- Helpers ----------
bool HiveNavBrainNode::have_all_required_data(bool, bool) const
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
