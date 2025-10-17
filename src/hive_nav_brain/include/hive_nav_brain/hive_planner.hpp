// hive_planner.hpp
#pragma once
#include <vector>
#include <string>
#include <optional>
#include <nav_msgs/msg/path.hpp>
#include <geometry_msgs/msg/pose_stamped.hpp>
#include "hive_interface2/msg/lanelet_mini2.hpp"

namespace hive_planner {

struct PathBuildStats {
  size_t lanelet_count        = 0;
  size_t raw_points           = 0;
  size_t smoothed_points      = 0;
  unsigned skipped_degenerate = 0;
  unsigned dedup_dropped      = 0;
  unsigned reversed_segments  = 0;
  unsigned link_mismatches    = 0;
  double  step_m              = 0.1;
  int     window_half         = 10;
};

nav_msgs::msg::Path build_nav2_path(
  const std::vector<hive_interface2::msg::LaneletMini2>& lanelets,
  const std::string& frame_id,
  double step_m,
  int window_half,
  PathBuildStats& stats);

// === Overload avec départ robot (recommandé) ===
nav_msgs::msg::Path build_nav2_path(
  const std::vector<hive_interface2::msg::LaneletMini2>& lanelets,
  const std::string& frame_id,
  double step_m,
  int window_half,
  const std::optional<geometry_msgs::msg::PoseStamped>& robot_start,
  PathBuildStats& stats);

} // namespace hive_planner
