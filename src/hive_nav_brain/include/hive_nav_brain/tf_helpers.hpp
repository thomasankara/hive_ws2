#pragma once
#include <tf2_ros/transform_listener.h>
#include <tf2_ros/buffer.h>
#include <geometry_msgs/msg/pose_stamped.hpp>
#include <rclcpp/rclcpp.hpp>

namespace hive_tf {

inline bool try_get_pose_map(
  tf2_ros::Buffer &buffer,
  const std::string &map_frame,
  const std::string &base_footprint_frame,
  geometry_msgs::msg::PoseStamped &out_pose,
  rclcpp::Logger logger,
  rclcpp::Clock &clock)
{
  try {
    const auto tf = buffer.lookupTransform(map_frame, base_footprint_frame, tf2::TimePointZero);
    out_pose.header = tf.header;
    out_pose.pose.position.x = tf.transform.translation.x;
    out_pose.pose.position.y = tf.transform.translation.y;
    out_pose.pose.position.z = tf.transform.translation.z;
    out_pose.pose.orientation = tf.transform.rotation;
    return true;
  } catch (const tf2::TransformException &ex) {
    RCLCPP_WARN_THROTTLE(logger, clock, 2000,
      "[tf] cannot lookup %s -> %s : %s",
      map_frame.c_str(), base_footprint_frame.c_str(), ex.what());
    return false;
  }
}

} // namespace hive_tf
