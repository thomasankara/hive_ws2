#pragma once
#include <rclcpp/rclcpp.hpp>
#include <std_srvs/srv/trigger.hpp>

#include "hive_interface2/msg/lanelet_mini2_array.hpp"
#include "hive_interface2/msg/poi_array.hpp"
#include "hive_interface2/msg/free_zone_array.hpp"
#include "hive_interface2/msg/nav_brain_command.hpp"

#include "hive_nav_brain/params.hpp"
#include "hive_nav_brain/data_store.hpp"

class HiveNavBrainNode : public rclcpp::Node {
public:
  HiveNavBrainNode();
  void blocking_startup(); // bloque jusqu’à réception des données requises

private:
  // Callbacks
  void onLanelets(const hive_interface2::msg::LaneletMini2Array::SharedPtr msg);
  void onPois(const hive_interface2::msg::PoiArray::SharedPtr msg);
  void onFreeZones(const hive_interface2::msg::FreeZoneArray::SharedPtr msg);
  void onCommand(const hive_interface2::msg::NavBrainCommand::SharedPtr cmd);

  bool have_all_required_data(bool need_poi, bool need_fz) const;

private:
  HiveNavParams P_;
  DataStore store_;

  // ROS
  rclcpp::Subscription<hive_interface2::msg::LaneletMini2Array>::SharedPtr sub_lanelets_;
  rclcpp::Subscription<hive_interface2::msg::PoiArray>::SharedPtr          sub_pois_;
  rclcpp::Subscription<hive_interface2::msg::FreeZoneArray>::SharedPtr     sub_freezones_;
  rclcpp::Subscription<hive_interface2::msg::NavBrainCommand>::SharedPtr   sub_cmd_;
  rclcpp::Client<std_srvs::srv::Trigger>::SharedPtr                        trigger_client_;
};
