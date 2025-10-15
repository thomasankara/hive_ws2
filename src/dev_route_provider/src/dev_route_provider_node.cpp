#include <rclcpp/rclcpp.hpp>
#include <std_srvs/srv/trigger.hpp>

#include <chrono>
#include <string>
#include <vector>
#include <unordered_set>
#include <sstream>

#include "hive_interface2/msg/lanelet_mini2.hpp"
#include "hive_interface2/msg/lanelet_mini2_array.hpp"

#include "dev_route_provider/db_mysql.hpp"

using namespace std::chrono_literals;
static constexpr const char* GREEN = "\033[32m";
static constexpr const char* RESET = "\033[0m";

class DevRouteProviderNode : public rclcpp::Node
{
public:
  DevRouteProviderNode()
  : Node("dev_route_provider")
  {
    // Params ROS
    robot_namespace_ = this->declare_parameter<std::string>("robot_namespace", "robot1");

    // Params DB
    db_host_ = this->declare_parameter<std::string>("db_host", "127.0.0.1");
    db_port_ = this->declare_parameter<int>("db_port", 3306);
    db_user_ = this->declare_parameter<std::string>("db_user", "hive");
    db_pass_ = this->declare_parameter<std::string>("db_password", "change_me_str0ng!");
    db_name_ = this->declare_parameter<std::string>("db_name", "local_robot_db");

    // Filtres (en dur via params)
    filter_.enterprise_full_id_str   = this->declare_parameter<std::string>("enterprise_full_id_str", "enterprise_001");
    filter_.deployment_full_id_str   = this->declare_parameter<std::string>("deployment_full_id_str", "0001__les_trois_forets");
    filter_.slam_session_full_id_str = this->declare_parameter<std::string>("slam_session_full_id_str", "slam_2025_01");

    topic_name_   = "/" + robot_namespace_ + "/route_data";
    service_name_ = "/" + robot_namespace_ + "/get_route_data";

    // Publisher: reliable + transient_local
    pub_ = this->create_publisher<hive_interface2::msg::LaneletMini2Array>(
      topic_name_, rclcpp::QoS(1).transient_local().reliable());

    // Service Trigger → force la republication
    srv_ = this->create_service<std_srvs::srv::Trigger>(
      service_name_,
      std::bind(&DevRouteProviderNode::onTrigger, this, std::placeholders::_1, std::placeholders::_2));

    // Timers de vie
    db_connect_timer_   = this->create_wall_timer(5s, std::bind(&DevRouteProviderNode::tryConnect, this));
    initial_fetch_timer_ = this->create_wall_timer(2s, std::bind(&DevRouteProviderNode::tryInitialFetch, this));

    RCLCPP_INFO(this->get_logger(), "%s[dev_route_provider] ready. Pub: %s | Srv: %s%s",
      GREEN, topic_name_.c_str(), service_name_.c_str(), RESET);
  }

private:
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
      RCLCPP_INFO(this->get_logger(), "%s[db] Connexion OK -> %s:%d/%s%s",
        GREEN, db_host_.c_str(), db_port_, db_name_.c_str(), RESET);
    } else {
      RCLCPP_INFO(this->get_logger(), "%s[db] Connexion FAILED (%s) (retry 5s)%s",
        GREEN, err.c_str(), RESET);
    }
  }

  void tryInitialFetch()
  {
    if (!db_connected_ || data_loaded_) return;

    std::vector<hive_interface2::msg::LaneletMini2> tmp;
    std::string err;
    const bool ok = db_->fetch_lanelets(filter_, tmp, err);
    if (!ok) {
      RCLCPP_INFO(this->get_logger(), "%s[fetch] Aucune donnée récupérée (%s) (réessaye).%s",
        GREEN, err.c_str(), RESET);
      return;
    }

    data_ = std::move(tmp);
    data_loaded_ = true;
    RCLCPP_INFO(this->get_logger(), "%s[fetch] %zu lanelets chargés (enterprise=%s, deployment=%s, slam=%s)%s",
      GREEN, data_.size(),
      filter_.enterprise_full_id_str.c_str(),
      filter_.deployment_full_id_str.c_str(),
      filter_.slam_session_full_id_str.c_str(), RESET);

    publishCurrent();
  }

  void publishCurrent()
  {
    if (!data_loaded_) {
      RCLCPP_INFO(this->get_logger(), "%s[publish] Skip: pas de données chargées.%s", GREEN, RESET);
      return;
    }

    hive_interface2::msg::LaneletMini2Array msg;
    msg.lanelets = data_;
    pub_->publish(msg);

    // Résumés uniques (sans répétitions)
    std::unordered_set<std::string> ents, deps, slams;
    for (const auto &ll : data_) {
      ents.insert(ll.enterprise_full_id_str);
      deps.insert(ll.deployment_full_id_str);
      slams.insert(ll.slam_session_full_id_str);
    }
    auto join = [](const std::unordered_set<std::string> &s){
      std::ostringstream oss; bool first=true;
      for (const auto &v: s){ if(!first) oss<<", "; oss<<v; first=false; }
      return oss.str();
    };

    RCLCPP_INFO(this->get_logger(), "%s[publish] %zu lanelets -> %s%s", GREEN, data_.size(), topic_name_.c_str(), RESET);
    RCLCPP_INFO(this->get_logger(), "%s[publish] enterprise_full_id_str: %s%s", GREEN, join(ents).c_str(), RESET);
    RCLCPP_INFO(this->get_logger(), "%s[publish] deployment_full_id_str: %s%s", GREEN, join(deps).c_str(), RESET);
    RCLCPP_INFO(this->get_logger(), "%s[publish] slam_session_full_id_str: %s%s", GREEN, join(slams).c_str(), RESET);
  }

  void onTrigger(const std::shared_ptr<std_srvs::srv::Trigger::Request> /*req*/,
                 std::shared_ptr<std_srvs::srv::Trigger::Response> res)
  {
    if (!db_connected_) {
      res->success = false;
      res->message = "DB not connected";
      RCLCPP_INFO(this->get_logger(), "%s[service] get_route_data -> DB NOT CONNECTED%s", GREEN, RESET);
      return;
    }
    if (!data_loaded_) {
      res->success = false;
      res->message = "No data loaded yet";
      RCLCPP_INFO(this->get_logger(), "%s[service] get_route_data -> NO DATA LOADED%s", GREEN, RESET);
      return;
    }
    publishCurrent();
    res->success = true;
    res->message = "Republished current lanelets";
    RCLCPP_INFO(this->get_logger(), "%s[service] get_route_data -> republished%s", GREEN, RESET);
  }

private:
  // Params / noms
  std::string robot_namespace_, topic_name_, service_name_;
  std::string db_host_, db_user_, db_pass_, db_name_;
  int db_port_{3306};
  dev_route_provider::DBFilter filter_;

  // ROS
  rclcpp::Publisher<hive_interface2::msg::LaneletMini2Array>::SharedPtr pub_;
  rclcpp::Service<std_srvs::srv::Trigger>::SharedPtr srv_;
  rclcpp::TimerBase::SharedPtr db_connect_timer_, initial_fetch_timer_;

  // DB
  std::unique_ptr<dev_route_provider::DBMySQL> db_;
  bool db_connected_{false};
  bool data_loaded_{false};

  // Cache
  std::vector<hive_interface2::msg::LaneletMini2> data_;
};

int main(int argc, char** argv)
{
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<DevRouteProviderNode>());
  rclcpp::shutdown();
  return 0;
}
