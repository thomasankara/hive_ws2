#pragma once

#include <vector>
#include <mutex>

#include <rclcpp/rclcpp.hpp>
#include <std_srvs/srv/trigger.hpp>

// TF2
#include <tf2_ros/transform_listener.h>
#include <tf2_ros/buffer.h>
#include <tf2/transform_datatypes.h>

// Messages
#include "hive_interface2/msg/lanelet_mini2_array.hpp"
#include "hive_interface2/msg/poi_array.hpp"
#include "hive_interface2/msg/free_zone_array.hpp"
#include "hive_interface2/msg/nav_brain_command.hpp"
#include "hive_interface2/srv/compute_route.hpp"
#include <geometry_msgs/msg/point_stamped.hpp>
#include <visualization_msgs/msg/marker.hpp>

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

  // TF update (10 Hz)
  void try_update_robot_pose_from_tf();

  // Demande de global path
  void try_request_global_path();

  // ====== Target locale ======
  struct PathProjection {
    bool ok{false};
    size_t seg_idx{0};  // index du lanelet/segment dans current_path_
    double t{0.0};      // paramètre 0..1 le long du segment
    double px{0.0}, py{0.0};
  };
  PathProjection project_on_current_path(double x, double y) const;
  bool compute_local_target(double robot_x, double robot_y,
                            double &tx, double &ty, std::string &note);

private:
  // Params / store
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

  // Service route planner
  rclcpp::Client<hive_interface2::srv::ComputeRoute>::SharedPtr route_client_;
  // --- Stockage du dernier global path reçu ---
  std::vector<hive_interface2::msg::LaneletMini2> current_path_;
  mutable std::mutex path_mtx_;

  // --- Helper distance au path ---
  double compute_distance_to_current_path_xy(double x, double y, std::string &note) const;

  // Publisher de la target locale
  rclcpp::Publisher<geometry_msgs::msg::PointStamped>::SharedPtr target_pub_;
  rclcpp::Publisher<visualization_msgs::msg::Marker>::SharedPtr  target_marker_pub_;

  // Constante lookahead (m) en mode hive_planner
  static constexpr double kLookaheadM = 6.0;

};
