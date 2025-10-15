#include <rclcpp/rclcpp.hpp>
#include <sensor_msgs/msg/point_cloud2.hpp>
#include "sensor_msgs/point_cloud2_iterator.hpp"
#include <grid_map_core/GridMap.hpp>
#include <grid_map_ros/GridMapRosConverter.hpp>
#include <nav_msgs/msg/occupancy_grid.hpp>
#include <tf2_ros/buffer.h>
#include <tf2_ros/transform_listener.h>
#include <tf2_geometry_msgs/tf2_geometry_msgs.hpp>
#include <limits>
#include <vector>
#include <chrono>
#include <cmath>

class SimpleCostmapNode : public rclcpp::Node {
public:
  SimpleCostmapNode()
  : Node("simple_costmap_node"),
    tf_buffer_(this->get_clock()),
    tf_listener_(tf_buffer_)
  {
    /* === Paramètres internes === */
    this->set_parameter(rclcpp::Parameter("use_sim_time", true));

    map_frame_   = "robot1/odom";
    robot_frame_ = "robot1/base_footprint";
    front_topic_ = "/robot1/airy_front_pc2";
    back_topic_  = "/robot1/airy_back_pc2";

    map_size_    = 20.0;   // m
    resolution_  = 0.05;   // m
    publish_hz_  = 10.0;   // Hz
    min_height_  = 0.15;    // m
    max_height_  = 2.5;    // m
    min_pts_cell_ = 2;     // minimum points par cellule
    decay_s_     = 0.5;   // persistance obstacles
    footprint_flat_ = {0.25,0.42, 0.25,-0.42, -1.05,-0.42, -1.05,0.42};

    /* === Configuration de la GridMap === */
    map_.setFrameId(map_frame_);
    map_.setGeometry(grid_map::Length(map_size_, map_size_), resolution_);
    map_.add("zmax");
    map_.add("count");
    map_.add("obst");
    map_.add("last_seen");
    resetLayers_();

    /* === ROS I/O === */
    sub_front_ = create_subscription<sensor_msgs::msg::PointCloud2>(
      front_topic_, rclcpp::SensorDataQoS(),
      std::bind(&SimpleCostmapNode::cloudCbFront_, this, std::placeholders::_1));

    sub_back_ = create_subscription<sensor_msgs::msg::PointCloud2>(
      back_topic_, rclcpp::SensorDataQoS(),
      std::bind(&SimpleCostmapNode::cloudCbBack_, this, std::placeholders::_1));

    pub_occ_ = create_publisher<nav_msgs::msg::OccupancyGrid>(
      "/robot1/hive_costmap/occupancy", 1);

    const auto period = std::chrono::milliseconds(int(1000.0 / publish_hz_));
    timer_ = create_wall_timer(period, std::bind(&SimpleCostmapNode::onTimer_, this));

    RCLCPP_INFO(get_logger(),
      "✅ HiveCostmap lancé : frame=%s, taille=%.1fm, res=%.2fm",
      map_frame_.c_str(), map_size_, resolution_);
  }

private:
  /* === Membres === */
  tf2_ros::Buffer tf_buffer_;
  tf2_ros::TransformListener tf_listener_;
  grid_map::GridMap map_;

  std::string map_frame_, robot_frame_, front_topic_, back_topic_;
  double map_size_, resolution_, publish_hz_;
  double min_height_, max_height_;
  int min_pts_cell_;
  double decay_s_;
  std::vector<double> footprint_flat_;

  sensor_msgs::msg::PointCloud2::SharedPtr last_front_, last_back_;
  rclcpp::Subscription<sensor_msgs::msg::PointCloud2>::SharedPtr sub_front_, sub_back_;
  rclcpp::Publisher<nav_msgs::msg::OccupancyGrid>::SharedPtr pub_occ_;
  rclcpp::TimerBase::SharedPtr timer_;

  /* === Réinitialise les couches === */
  void resetLayers_() {
    map_["zmax"].setConstant(std::numeric_limits<float>::quiet_NaN());
    map_["count"].setConstant(0.0f);
    map_["obst"].setConstant(std::numeric_limits<float>::quiet_NaN());
    map_["last_seen"].setConstant(std::numeric_limits<float>::quiet_NaN());
  }

  bool lookupTF_(const std::string &target, const std::string &source,
                 geometry_msgs::msg::TransformStamped &tf) {
    try {
      tf = tf_buffer_.lookupTransform(target, source, tf2::TimePointZero,
                                      tf2::durationFromSec(0.1));
      return true;
    } catch (...) { return false; }
  }

  /* === Callback capteurs === */
  void cloudCbFront_(sensor_msgs::msg::PointCloud2::SharedPtr msg) { last_front_ = msg; }
  void cloudCbBack_ (sensor_msgs::msg::PointCloud2::SharedPtr msg) { last_back_ = msg; }

  void integrateCloud_(const sensor_msgs::msg::PointCloud2::SharedPtr &msg) {
    if (!msg) return;
    geometry_msgs::msg::TransformStamped tf;
    if (!lookupTF_(map_frame_, msg->header.frame_id, tf)) return;

    sensor_msgs::PointCloud2ConstIterator<float> it_x(*msg, "x"), it_y(*msg, "y"), it_z(*msg, "z");
    for (; it_x != it_x.end(); ++it_x, ++it_y, ++it_z) {
      if (!std::isfinite(*it_x) || !std::isfinite(*it_y) || !std::isfinite(*it_z)) continue;

      geometry_msgs::msg::PointStamped pin, pout;
      pin.header = msg->header;
      pin.point.x = *it_x;
      pin.point.y = *it_y;
      pin.point.z = *it_z;
      try { tf2::doTransform(pin, pout, tf); } catch (...) { continue; }

      float z = pout.point.z;
      if (z < min_height_ || z > max_height_) continue;

      grid_map::Position pos(pout.point.x, pout.point.y);
      if (!map_.isInside(pos)) continue;

      float &zmax = map_.atPosition("zmax", pos);
      float &cnt = map_.atPosition("count", pos);
      zmax = std::isfinite(zmax) ? std::max(zmax, z) : z;
      cnt += 1.0f;
    }
  }

  static bool pointInPoly_(double x, double y,
                           const std::vector<std::pair<double, double>> &poly) {
    bool in = false; size_t n = poly.size();
    for (size_t i = 0, j = n - 1; i < n; j = i++) {
      const auto &pi = poly[i];
      const auto &pj = poly[j];
      bool c = ((pi.second > y) != (pj.second > y)) &&
               (x < (pj.first - pi.first) * (y - pi.second) /
                     (pj.second - pi.second + 1e-12) + pi.first);
      if (c) in = !in;
    }
    return in;
  }

  void clearFootprint_(double rx, double ry, double yaw) {
    if (footprint_flat_.size() < 6 || footprint_flat_.size() % 2 != 0) return;

    std::vector<std::pair<double, double>> poly;
    poly.reserve(footprint_flat_.size() / 2);
    double c = std::cos(yaw), s = std::sin(yaw);

    for (size_t i = 0; i < footprint_flat_.size(); i += 2) {
      double xb = footprint_flat_[i], yb = footprint_flat_[i + 1];
      poly.push_back({c * xb - s * yb + rx, s * xb + c * yb + ry});
    }

    for (grid_map::GridMapIterator it(map_); !it.isPastEnd(); ++it) {
      grid_map::Index id(*it);
      grid_map::Position p;
      map_.getPosition(id, p);
      if (pointInPoly_(p.x(), p.y(), poly)) {
        map_.at("obst", id) = std::numeric_limits<float>::quiet_NaN();
        map_.at("zmax", id) = std::numeric_limits<float>::quiet_NaN();
        map_.at("count", id) = 0.0f;
      }
    }
  }

  /* === Timer principal === */
  void onTimer_() {
    geometry_msgs::msg::TransformStamped tf;
    double rx = 0.0, ry = 0.0, yaw = 0.0;

    if (lookupTF_(map_frame_, robot_frame_, tf)) {
      rx = tf.transform.translation.x;
      ry = tf.transform.translation.y;
      tf2::Quaternion q;
      tf2::fromMsg(tf.transform.rotation, q);
      double roll, pitch;
      tf2::Matrix3x3(q).getRPY(roll, pitch, yaw);
      map_.move(grid_map::Position(rx, ry));  // 🧠 recentrage : efface le lointain
    } else {
      RCLCPP_WARN_THROTTLE(get_logger(), *get_clock(), 2000,
                           "TF %s->%s manquant", robot_frame_.c_str(), map_frame_.c_str());
      return;
    }

    map_["zmax"].setConstant(std::numeric_limits<float>::quiet_NaN());
    map_["count"].setConstant(0.0f);

    integrateCloud_(last_front_);
    integrateCloud_(last_back_);

    const double now_s = this->now().seconds();
    for (grid_map::GridMapIterator it(map_); !it.isPastEnd(); ++it) {
      grid_map::Index id(*it);
      float z = map_.at("zmax", id);
      float n = map_.at("count", id);
      float &f = map_.at("obst", id);
      float &t = map_.at("last_seen", id);
      bool obs_now = std::isfinite(z) && n >= min_pts_cell_;
      if (obs_now) { f = 1.0f; t = float(now_s); }
      else if (f == 1.0f && std::isfinite(t) && (now_s - t) >= decay_s_)
        f = std::numeric_limits<float>::quiet_NaN();
    }

    clearFootprint_(rx, ry, yaw);

    nav_msgs::msg::OccupancyGrid og;
    grid_map::GridMapRosConverter::toOccupancyGrid(map_, "obst", 0.0, 0.9, og);
    og.header.frame_id = map_frame_;
    og.header.stamp = this->now();
    pub_occ_->publish(og);
  }
};

int main(int argc, char **argv) {
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<SimpleCostmapNode>());
  rclcpp::shutdown();
  return 0;
}
