#include "hive_costmap/gridmap_fusion_layer.hpp"
#include <cmath>
#include <algorithm>
#include <chrono>

using nav2_costmap_2d::FREE_SPACE;
using nav2_costmap_2d::LETHAL_OBSTACLE;

namespace hive_costmap
{

GridmapFusionLayer::GridmapFusionLayer() = default;

void GridmapFusionLayer::onInitialize()
{
  auto node = node_.lock();
  declareParameter("enabled", rclcpp::ParameterValue(true));
  declareParameter("topic", rclcpp::ParameterValue(std::string("/robot1/hive_costmap/occupancy")));
  declareParameter("lethal_threshold", rclcpp::ParameterValue(95.0));
  declareParameter("unknown_is_free", rclcpp::ParameterValue(false));
  declareParameter("clear_inside_robot_footprint", rclcpp::ParameterValue(true));

  node->get_parameter(name_ + ".enabled", enabled_);
  node->get_parameter(name_ + ".topic", og_topic_);
  node->get_parameter(name_ + ".lethal_threshold", lethal_threshold_);
  node->get_parameter(name_ + ".unknown_is_free", unknown_is_free_);
  node->get_parameter(name_ + ".clear_inside_robot_footprint", clear_inside_robot_footprint_);

  global_frame_ = layered_costmap_->getGlobalFrameID();

  tf_buffer_   = std::make_shared<tf2_ros::Buffer>(node->get_clock());
  tf_listener_ = std::make_shared<tf2_ros::TransformListener>(*tf_buffer_);

    sub_ = node->create_subscription<nav_msgs::msg::OccupancyGrid>(
    og_topic_,
    std::bind(&GridmapFusionLayer::ogCallback, this, std::placeholders::_1),
    rclcpp::QoS(1).best_effort().durability_volatile());

  RCLCPP_INFO(node->get_logger(),
    "[GridmapFusionLayer] init: enabled=%s topic=%s global_frame=%s lethal>=%.1f unk_free=%s clear_fp=%s",
    enabled_ ? "true" : "false",
    og_topic_.c_str(), global_frame_.c_str(),
    lethal_threshold_,
    unknown_is_free_ ? "true" : "false",
    clear_inside_robot_footprint_ ? "true" : "false");

  need_update_bounds_ = true;
  current_ = true;   // couche active
}

void GridmapFusionLayer::ogCallback(const nav_msgs::msg::OccupancyGrid::SharedPtr msg)
{
  std::lock_guard<std::mutex> lk(og_mutex_);
  last_og_ = msg;
  need_update_bounds_ = true;
}

bool GridmapFusionLayer::computeLastOGBounds(double &min_x, double &min_y, double &max_x, double &max_y)
{
  std::lock_guard<std::mutex> lk(og_mutex_);
  if (!last_og_) return false;

  const auto & info = last_og_->info;
  const double res = info.resolution;
  const double w = static_cast<double>(info.width)  * res;
  const double h = static_cast<double>(info.height) * res;

  // 4 coins dans le frame OG
  std::array<tf2::Vector3,4> corners_og = {
    tf2::Vector3(info.origin.position.x,              info.origin.position.y,              0.0),
    tf2::Vector3(info.origin.position.x + w,          info.origin.position.y,              0.0),
    tf2::Vector3(info.origin.position.x,              info.origin.position.y + h,          0.0),
    tf2::Vector3(info.origin.position.x + w,          info.origin.position.y + h,          0.0)
  };

  geometry_msgs::msg::TransformStamped tf_stamped;
  try {
    tf_stamped = tf_buffer_->lookupTransform(
      global_frame_, last_og_->header.frame_id, tf2::TimePointZero, tf2::durationFromSec(0.1));
  } catch (const tf2::TransformException & ex) {
    RCLCPP_WARN(rclcpp::get_logger("GridmapFusionLayer"),
                "TF bounds %s->%s failed: %s",
                last_og_->header.frame_id.c_str(), global_frame_.c_str(), ex.what());
    return false;
  }

  tf2::Transform T;
  tf2::fromMsg(tf_stamped.transform, T);

  min_x =  std::numeric_limits<double>::infinity();
  min_y =  std::numeric_limits<double>::infinity();
  max_x = -std::numeric_limits<double>::infinity();
  max_y = -std::numeric_limits<double>::infinity();

  for (auto & c : corners_og) {
    tf2::Vector3 g = T * c;
    min_x = std::min(min_x, g.x());
    min_y = std::min(min_y, g.y());
    max_x = std::max(max_x, g.x());
    max_y = std::max(max_y, g.y());
  }
  return true;
}

void GridmapFusionLayer::updateBounds(
  double /*robot_x*/, double /*robot_y*/, double /*robot_yaw*/,
  double *min_x, double *min_y, double *max_x, double *max_y)
{
  if (!enabled_) return;

  double og_min_x, og_min_y, og_max_x, og_max_y;
  if (computeLastOGBounds(og_min_x, og_min_y, og_max_x, og_max_y)) {
    *min_x = std::min(*min_x, og_min_x);
    *min_y = std::min(*min_y, og_min_y);
    *max_x = std::max(*max_x, og_max_x);
    *max_y = std::max(*max_y, og_max_y);
  }
}

void GridmapFusionLayer::updateCosts(
  nav2_costmap_2d::Costmap2D & master_grid,
  int min_i, int min_j, int max_i, int max_j)
{
  static auto last_log_time = std::chrono::steady_clock::now();
  auto start = std::chrono::steady_clock::now();

  if (!enabled_) return;

  // --- Main processing ---
  if (clear_inside_robot_footprint_) {
    const auto fp = layered_costmap_->getFootprint();
    if (!fp.empty()) {
      master_grid.setConvexPolygonCost(fp, FREE_SPACE);
    }
  }

  nav_msgs::msg::OccupancyGrid::SharedPtr og;
  {
    std::lock_guard<std::mutex> lk(og_mutex_);
    og = last_og_;
  }
  if (!og || og->data.empty()) return;

  // TF OG->global
  geometry_msgs::msg::TransformStamped tf_stamped;
  try {
    tf_stamped = tf_buffer_->lookupTransform(
      global_frame_, og->header.frame_id, tf2::TimePointZero, tf2::durationFromSec(0.1));
  } catch (const tf2::TransformException & ex) {
    RCLCPP_WARN(rclcpp::get_logger("GridmapFusionLayer"),
                "TF data %s->%s failed: %s",
                og->header.frame_id.c_str(), global_frame_.c_str(), ex.what());
    return;
  }

  tf2::Transform T;
  tf2::fromMsg(tf_stamped.transform, T);
  tf2::Quaternion q = T.getRotation();
  double roll, pitch, yaw;
  tf2::Matrix3x3(q).getRPY(roll, pitch, yaw);
  const double c = std::cos(yaw), s = std::sin(yaw);
  const double tx = T.getOrigin().x();
  const double ty = T.getOrigin().y();

  const auto & info = og->info;
  const double res  = info.resolution;
  const double ox   = info.origin.position.x;
  const double oy   = info.origin.position.y;

  const unsigned int W = info.width;
  const unsigned int H = info.height;

  for (unsigned int iy = 0; iy < H; ++iy) {
    for (unsigned int ix = 0; ix < W; ++ix) {
      const int8_t occ = og->data[iy * W + ix];
      if (occ < 0) {
        if (!unknown_is_free_) continue;
        const double wx = ox + (static_cast<double>(ix) + 0.5) * res;
        const double wy = oy + (static_cast<double>(iy) + 0.5) * res;
        const double gx = c * wx - s * wy + tx;
        const double gy = s * wx + c * wy + ty;
        unsigned int mx, my;
        if (!master_grid.worldToMap(gx, gy, mx, my)) continue;
        if (mx < (unsigned int)min_i || mx >= (unsigned int)max_i ||
            my < (unsigned int)min_j || my >= (unsigned int)max_j) continue;
        master_grid.setCost(mx, my, FREE_SPACE);
        continue;
      }

      if (static_cast<double>(occ) < lethal_threshold_) continue;

      const double wx = ox + (static_cast<double>(ix) + 0.5) * res;
      const double wy = oy + (static_cast<double>(iy) + 0.5) * res;
      const double gx = c * wx - s * wy + tx;
      const double gy = s * wx + c * wy + ty;
      unsigned int mx, my;
      if (!master_grid.worldToMap(gx, gy, mx, my)) continue;
      if (mx < (unsigned int)min_i || mx >= (unsigned int)max_i ||
          my < (unsigned int)min_j || my >= (unsigned int)max_j) continue;
      master_grid.setCost(mx, my, LETHAL_OBSTACLE);
    }
  }

  // --- Mesure du temps ---
  auto end = std::chrono::steady_clock::now();
  double duration_ms =
    std::chrono::duration_cast<std::chrono::duration<double, std::milli>>(end - start).count();

  // --- Log vert toutes les 1 seconde ---
  if ((end - last_log_time) > std::chrono::seconds(1)) {
    last_log_time = end;
    RCLCPP_INFO(
      rclcpp::get_logger("GridmapFusionLayer"),
      "\033[1;32m[GridmapFusionLayer] updateCosts() ran in %.2f ms — grid %ux%u — log every 1.0s\033[0m",
      duration_ms,
      og->info.width,
      og->info.height
    );
  }
}

} // namespace hive_costmap

// Export plugin
#include "pluginlib/class_list_macros.hpp"
PLUGINLIB_EXPORT_CLASS(hive_costmap::GridmapFusionLayer, nav2_costmap_2d::Layer)
