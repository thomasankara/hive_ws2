#pragma once

#include <vector>
#include <mutex>

#include <rclcpp/rclcpp.hpp>
#include <rclcpp_action/rclcpp_action.hpp>
#include <std_srvs/srv/trigger.hpp>

// TF2
#include <tf2_ros/transform_listener.h>
#include <tf2_ros/buffer.h>
#include <tf2/transform_datatypes.h>

// Messages & services
#include "hive_interface2/msg/lanelet_mini2_array.hpp"
#include "hive_interface2/msg/poi_array.hpp"
#include "hive_interface2/msg/free_zone_array.hpp"
#include "hive_interface2/msg/nav_brain_command.hpp"
#include "hive_interface2/srv/compute_route.hpp"

#include <geometry_msgs/msg/point_stamped.hpp>
#include <visualization_msgs/msg/marker.hpp>
#include <nav_msgs/msg/path.hpp>
#include <nav_msgs/msg/goals.hpp>  // Jazzy+: wrapper des poses
#include <nav2_msgs/action/compute_path_through_poses.hpp>

#include "hive_nav_brain/hive_planner.hpp"
#include "hive_nav_brain/params.hpp"
#include "hive_nav_brain/data_store.hpp"
#include "hive_nav_brain/global_state.hpp"

class HiveNavBrainNode : public rclcpp::Node {
public:
  HiveNavBrainNode();
  void blocking_startup();

private:
  // Callbacks topics
  void onLanelets(const hive_interface2::msg::LaneletMini2Array::SharedPtr msg);
  void onPois(const hive_interface2::msg::PoiArray::SharedPtr msg);
  void onFreeZones(const hive_interface2::msg::FreeZoneArray::SharedPtr msg);
  void onCommand(const hive_interface2::msg::NavBrainCommand::SharedPtr cmd);

  // Helpers
  bool have_all_required_data(bool need_poi, bool need_fz) const;

  // Boucle 10 Hz
  void onLoop();

  // Demande de global path (lanelets)
  void try_request_global_path();

  // --- Distance au path lanelets ---
  double compute_distance_to_current_path_xy(double x, double y, std::string &note) const;

  // --- Yaw local aligné avec le lanelet sous-jacent (start->end) au point (x,y) ---
  bool heading_on_path_at(double x, double y, double &yaw) const;

private:
  // Params / store / état global
  HiveNavParams P_;
  DataStore     store_;
  hive_nav::GlobalState gs_;

  // ROS comms
  rclcpp::Subscription<hive_interface2::msg::LaneletMini2Array>::SharedPtr sub_lanelets_;
  rclcpp::Subscription<hive_interface2::msg::PoiArray>::SharedPtr          sub_pois_;
  rclcpp::Subscription<hive_interface2::msg::FreeZoneArray>::SharedPtr     sub_freezones_;
  rclcpp::Subscription<hive_interface2::msg::NavBrainCommand>::SharedPtr   sub_cmd_;
  rclcpp::Client<std_srvs::srv::Trigger>::SharedPtr                        trigger_client_;

  // Timer 10 Hz
  rclcpp::TimerBase::SharedPtr loop_timer_;
  uint64_t                     loop_tick_ = 0;

  // TF
  std::shared_ptr<tf2_ros::Buffer> tf_buffer_;
  std::shared_ptr<tf2_ros::TransformListener> tf_listener_;
  std::string map_frame_ = "map";
  std::string base_footprint_frame_; // <ns>/base_footprint

  // Service route planner (lanelets)
  rclcpp::Client<hive_interface2::srv::ComputeRoute>::SharedPtr route_client_;

  // Stockage du dernier global path (lanelets)
  std::vector<hive_interface2::msg::LaneletMini2> current_path_;
  mutable std::mutex path_mtx_;

  // Publishers target locale
  rclcpp::Publisher<geometry_msgs::msg::PointStamped>::SharedPtr target_pub_;
  rclcpp::Publisher<visualization_msgs::msg::Marker>::SharedPtr  target_marker_pub_;

  // Chemins nav2 (visualisation unique, on y publie aussi bien hive/astar)
  rclcpp::Publisher<nav_msgs::msg::Path>::SharedPtr hive_path_pub_;

  // Hive planner (éviter builds concurrents)
  bool building_hive_path_{false};

  // Action Nav2: ComputePathThroughPoses (pour ASTAR_PLANNER)
  using CPTP = nav2_msgs::action::ComputePathThroughPoses;
  rclcpp_action::Client<CPTP>::SharedPtr path_action_client_;
  bool waiting_astar_{false};

  // Constante lookahead (m) pour hive_planner
  static constexpr double kLookaheadM = 6.0;
};
