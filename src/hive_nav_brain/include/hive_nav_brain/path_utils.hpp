#pragma once
#include <vector>
#include <string>
#include <cmath>
#include <limits>
#include "hive_interface2/msg/lanelet_mini2.hpp"
#include "hive_nav_brain/global_state.hpp" // MovementMode

namespace hive_nav_utils {

struct PathProjection {
  bool ok{false};
  size_t seg_idx{0};
  double t{0.0};      // 0..1 le long du segment
  double px{0.0}, py{0.0};
};

double distance_to_path_xy(
  const std::vector<hive_interface2::msg::LaneletMini2> &path,
  double x, double y, std::string &note);

PathProjection project_on_path(
  const std::vector<hive_interface2::msg::LaneletMini2> &path,
  double x, double y);

bool compute_local_target(
  const std::vector<hive_interface2::msg::LaneletMini2> &path,
  double rx, double ry,
  double goal_x, double goal_y,
  hive_nav::MovementMode mode,
  double lookahead_m,     // ex: 6.0
  double &tx, double &ty,
  std::string &note);

} // namespace hive_nav_utils
