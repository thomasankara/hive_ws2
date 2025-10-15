#ifndef HIVE_COSTMAP__GRIDMAP_FUSION_LAYER_HPP_
#define HIVE_COSTMAP__GRIDMAP_FUSION_LAYER_HPP_

#include <mutex>
#include <string>
#include <memory>

#include "rclcpp/rclcpp.hpp"
#include "pluginlib/class_list_macros.hpp"

#include "nav2_costmap_2d/layer.hpp"
#include "nav2_costmap_2d/layered_costmap.hpp"
#include "nav2_costmap_2d/costmap_layer.hpp"
#include "nav2_costmap_2d/costmap_2d.hpp"
#include "nav2_costmap_2d/costmap_math.hpp"
#include "nav2_costmap_2d/footprint.hpp"

#include "nav_msgs/msg/occupancy_grid.hpp"

#include "tf2_ros/buffer.h"
#include "tf2_ros/transform_listener.h"
#include "tf2/LinearMath/Transform.h"
#include "tf2_geometry_msgs/tf2_geometry_msgs.hpp"

namespace hive_costmap
{

class GridmapFusionLayer : public nav2_costmap_2d::Layer
{
public:
  GridmapFusionLayer();

  void onInitialize() override;

  void updateBounds(double robot_x, double robot_y, double robot_yaw,
                    double *min_x, double *min_y, double *max_x, double *max_y) override;

  void updateCosts(nav2_costmap_2d::Costmap2D & master_grid,
                   int min_i, int min_j, int max_i, int max_j) override;

  void reset() override {}
  bool isClearable() override { return true; }
  void onFootprintChanged() override { /* rien de spécial ici */ }

private:
  // Callback OccupancyGrid
  void ogCallback(const nav_msgs::msg::OccupancyGrid::SharedPtr msg);

  // Calcule le BB (bounding box) du dernier OG dans le frame global
  bool computeLastOGBounds(double &min_x, double &min_y, double &max_x, double &max_y);

  // Params
  bool enabled_ {true};
  std::string og_topic_;
  double lethal_threshold_ {95.0};           // 0..100 → au-delà = obstacle
  bool unknown_is_free_ {false};             // si true, -1 met FREE au lieu d’ignorer
  bool clear_inside_robot_footprint_ {true}; // efface l’intérieur du footprint

  // TF
  std::shared_ptr<tf2_ros::Buffer> tf_buffer_;
  std::shared_ptr<tf2_ros::TransformListener> tf_listener_;
  std::string global_frame_;

  // Données OG
  std::mutex og_mutex_;
  nav_msgs::msg::OccupancyGrid::SharedPtr last_og_;

  bool need_update_bounds_{false};
  // Abonnement
  rclcpp::Subscription<nav_msgs::msg::OccupancyGrid>::SharedPtr sub_;
};

}  // namespace hive_costmap

#endif  // HIVE_COSTMAP__GRIDMAP_FUSION_LAYER_HPP_
