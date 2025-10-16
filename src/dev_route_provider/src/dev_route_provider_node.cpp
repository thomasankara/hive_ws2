#include <rclcpp/rclcpp.hpp>
#include <std_srvs/srv/trigger.hpp>

#include <chrono>
#include <string>
#include <vector>
#include <unordered_set>
#include <sstream>
#include <memory>

#include "hive_interface2/msg/lanelet_mini2.hpp"
#include "hive_interface2/msg/lanelet_mini2_array.hpp"
#include "hive_interface2/msg/poi.hpp"
#include "hive_interface2/msg/poi_array.hpp"
#include "hive_interface2/msg/free_zone.hpp"
#include "hive_interface2/msg/free_zone_array.hpp"

#include "dev_route_provider/db_mysql.hpp"

using namespace std::chrono_literals;

static constexpr const char* GREEN = "\033[32m";
static constexpr const char* YELL  = "\033[33m";
static constexpr const char* RESET = "\033[0m";

class DevRouteProviderNode : public rclcpp::Node
{
public:
  DevRouteProviderNode()
  : Node("dev_route_provider")
  {
    // --- Params ROS
    ns_ = this->declare_parameter<std::string>("robot_namespace", "robot1");

    // --- Params DB
    db_host_ = this->declare_parameter<std::string>("db_host", "127.0.0.1");
    db_port_ = this->declare_parameter<int>("db_port", 3306);
    db_user_ = this->declare_parameter<std::string>("db_user", "hive");
    db_pass_ = this->declare_parameter<std::string>("db_password", "change_me_str0ng!");
    db_name_ = this->declare_parameter<std::string>("db_name", "local_robot_db");

    // --- Filtres hiérarchiques
    filter_.enterprise_full_id_str   = this->declare_parameter<std::string>("enterprise_full_id_str", "enterprise_001");
    filter_.deployment_full_id_str   = this->declare_parameter<std::string>("deployment_full_id_str", "0001__les_trois_forets");
    filter_.slam_session_full_id_str = this->declare_parameter<std::string>("slam_session_full_id_str", "slam_2025_01");

    // --- Noms topics & services
    topic_lanelets_   = "/" + ns_ + "/route_data";
    topic_pois_       = "/" + ns_ + "/poi_data";
    topic_freezones_  = "/" + ns_ + "/free_zone_data";

    srv_lanelets_only_name_ = "/" + ns_ + "/get_route_data";    // lanelets ONLY
    srv_all_name_           = "/" + ns_ + "/refresh_all_data";  // ALL (lanelets + pois + freezones)

    // --- Publishers (latched)
    auto qos_latched = rclcpp::QoS(1).reliable().transient_local();
    pub_lanelets_ = this->create_publisher<hive_interface2::msg::LaneletMini2Array>(topic_lanelets_, qos_latched);
    pub_pois_     = this->create_publisher<hive_interface2::msg::PoiArray>(topic_pois_, qos_latched);
    pub_fz_       = this->create_publisher<hive_interface2::msg::FreeZoneArray>(topic_freezones_, qos_latched);

    // --- Services
    srv_lanelets_only_ = this->create_service<std_srvs::srv::Trigger>(
      srv_lanelets_only_name_,
      std::bind(&DevRouteProviderNode::onTriggerLaneletsOnly, this, std::placeholders::_1, std::placeholders::_2));

    srv_all_ = this->create_service<std_srvs::srv::Trigger>(
      srv_all_name_,
      std::bind(&DevRouteProviderNode::onTriggerAll, this, std::placeholders::_1, std::placeholders::_2));

    // --- Timers
    db_connect_timer_    = this->create_wall_timer(5s, std::bind(&DevRouteProviderNode::tryConnect, this));
    initial_fetch_timer_ = this->create_wall_timer(2s, std::bind(&DevRouteProviderNode::tryInitialFetch, this));

    RCLCPP_INFO(this->get_logger(),
      "%s[dev_route_provider] ready. pubs: %s | %s | %s  srvs: %s | %s%s",
      GREEN, topic_lanelets_.c_str(), topic_pois_.c_str(), topic_freezones_.c_str(),
      srv_lanelets_only_name_.c_str(), srv_all_name_.c_str(), RESET);
  }

private:
  // ----------------- DB lifecycle -----------------
  void tryConnect()
  {
    if (db_connected_) return;
    if (!db_) {
      db_ = std::make_unique<dev_route_provider::DBMySQL>(
        db_host_, static_cast<unsigned>(db_port_), db_user_, db_pass_, db_name_);
    }
    std::string err;
    db_connected_ = db_->connect(err);
    if (db_connected_) {
      RCLCPP_INFO(this->get_logger(), "%s[db] Connected to %s:%d/%s%s",
        GREEN, db_host_.c_str(), db_port_, db_name_.c_str(), RESET);
    } else {
      RCLCPP_WARN(this->get_logger(), "%s[db] Connect FAILED: %s (retry in 5s)%s", YELL, err.c_str(), RESET);
    }
  }

  void tryInitialFetch()
  {
    if (!db_connected_ || data_loaded_) return;

    std::string err;

    // lanelets
    std::vector<hive_interface2::msg::LaneletMini2> v_lanelets;
    const bool ok_ll = db_->fetch_lanelets(filter_, v_lanelets, err);
    if (ok_ll) {
      lanelets_ = std::move(v_lanelets);
      RCLCPP_INFO(this->get_logger(), "%s[fetch] lanelets: %zu%s", GREEN, lanelets_.size(), RESET);
    } else {
      RCLCPP_WARN(this->get_logger(), "%s[fetch] lanelets: none (%s)%s", YELL, err.c_str(), RESET);
    }

    // pois
    std::vector<hive_interface2::msg::Poi> v_pois;
    const bool ok_poi = db_->fetch_pois(filter_, v_pois, err);
    if (ok_poi) {
      pois_ = std::move(v_pois);
      RCLCPP_INFO(this->get_logger(), "%s[fetch] POIs: %zu%s", GREEN, pois_.size(), RESET);
    } else {
      RCLCPP_WARN(this->get_logger(), "%s[fetch] POIs: none (%s)%s", YELL, err.c_str(), RESET);
    }

    // free zones
    std::vector<hive_interface2::msg::FreeZone> v_fz;
    const bool ok_fz = db_->fetch_free_zones(filter_, v_fz, err);
    if (ok_fz) {
      free_zones_ = std::move(v_fz);
      RCLCPP_INFO(this->get_logger(), "%s[fetch] FreeZones: %zu%s", GREEN, free_zones_.size(), RESET);
    } else {
      RCLCPP_WARN(this->get_logger(), "%s[fetch] FreeZones: none (%s)%s", YELL, err.c_str(), RESET);
    }

    data_loaded_ = (ok_ll || ok_poi || ok_fz);
    if (data_loaded_) {
      publishAll();
    }
  }

  // ----------------- Publish helpers -----------------
  void publishLanelets()
  {
    if (lanelets_.empty()) return;
    hive_interface2::msg::LaneletMini2Array msg;
    msg.lanelets = lanelets_;
    pub_lanelets_->publish(msg);
    RCLCPP_INFO(this->get_logger(), "%s[publish] Lanelets -> %s (%zu)%s",
      GREEN, topic_lanelets_.c_str(), lanelets_.size(), RESET);
  }

  void publishPois()
  {
    if (pois_.empty()) return;
    hive_interface2::msg::PoiArray msg;
    msg.items = pois_;
    pub_pois_->publish(msg);
    RCLCPP_INFO(this->get_logger(), "%s[publish] POIs -> %s (%zu)%s",
      GREEN, topic_pois_.c_str(), pois_.size(), RESET);
  }

  void publishFreeZones()
  {
    if (free_zones_.empty()) return;
    hive_interface2::msg::FreeZoneArray msg;
    msg.items = free_zones_;
    pub_fz_->publish(msg);
    RCLCPP_INFO(this->get_logger(), "%s[publish] FreeZones -> %s (%zu)%s",
      GREEN, topic_freezones_.c_str(), free_zones_.size(), RESET);
  }

  void publishAll()
  {
    publishLanelets();
    publishPois();
    publishFreeZones();
  }

  // ----------------- Services -----------------
  void onTriggerLaneletsOnly(const std::shared_ptr<std_srvs::srv::Trigger::Request> /*req*/,
                             std::shared_ptr<std_srvs::srv::Trigger::Response> res)
  {
    if (!db_connected_) { res->success = false; res->message = "DB not connected"; return; }
    if (!data_loaded_)  { res->success = false; res->message = "No data loaded yet"; return; }
    publishLanelets();
    res->success = true;
    res->message = "Republished lanelets only";
  }

  void onTriggerAll(const std::shared_ptr<std_srvs::srv::Trigger::Request> /*req*/,
                    std::shared_ptr<std_srvs::srv::Trigger::Response> res)
  {
    if (!db_connected_) { res->success = false; res->message = "DB not connected"; return; }
    if (!data_loaded_)  { res->success = false; res->message = "No data loaded yet"; return; }
    publishAll();
    res->success = true;
    res->message = "Republished lanelets, POIs and free zones";
  }

private:
  // noms / params
  std::string ns_;
  std::string db_host_, db_user_, db_pass_, db_name_;
  int db_port_{3306};
  dev_route_provider::DBFilter filter_;

  // topics / services
  std::string topic_lanelets_, topic_pois_, topic_freezones_;
  std::string srv_lanelets_only_name_, srv_all_name_;

  // ROS
  rclcpp::Publisher<hive_interface2::msg::LaneletMini2Array>::SharedPtr pub_lanelets_;
  rclcpp::Publisher<hive_interface2::msg::PoiArray>::SharedPtr          pub_pois_;
  rclcpp::Publisher<hive_interface2::msg::FreeZoneArray>::SharedPtr     pub_fz_;
  rclcpp::Service<std_srvs::srv::Trigger>::SharedPtr                    srv_lanelets_only_;
  rclcpp::Service<std_srvs::srv::Trigger>::SharedPtr                    srv_all_;
  rclcpp::TimerBase::SharedPtr                                          db_connect_timer_;
  rclcpp::TimerBase::SharedPtr                                          initial_fetch_timer_;

  // DB
  std::unique_ptr<dev_route_provider::DBMySQL> db_;
  bool db_connected_{false};
  bool data_loaded_{false};

  // caches
  std::vector<hive_interface2::msg::LaneletMini2> lanelets_;
  std::vector<hive_interface2::msg::Poi>          pois_;
  std::vector<hive_interface2::msg::FreeZone>     free_zones_;
};

int main(int argc, char** argv)
{
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<DevRouteProviderNode>());
  rclcpp::shutdown();
  return 0;
}
