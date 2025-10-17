#pragma once
#include <vector>
#include <string>
#include <nav_msgs/msg/path.hpp>
#include "hive_interface2/msg/lanelet_mini2.hpp"

namespace hive_planner {

// Stats simples pour le log
struct PathBuildStats {
  size_t lanelet_count{0};
  size_t raw_points{0};
  size_t smoothed_points{0};
  double step_m{0.0};
  int window_half{0};
};

/// Construit un nav_msgs/Path depuis une suite de LaneletMini2.
/// - Échantillonnage `step_m` (0.001 = 0.1 cm)
/// - Lissage moyenne glissante sur ±window_half (10)
/// - Orientation = direction (i -> i+window_half) (bord géré)
nav_msgs::msg::Path build_nav2_path(
  const std::vector<hive_interface2::msg::LaneletMini2>& lanelets,
  const std::string& frame_id,
  double step_m,
  int window_half,
  PathBuildStats& out_stats);

} // namespace hive_planner
