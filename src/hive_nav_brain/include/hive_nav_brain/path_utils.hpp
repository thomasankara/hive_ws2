#pragma once
#include <vector>
#include <string>
#include <cmath>
#include <limits>
#include "hive_interface2/msg/lanelet_mini2.hpp"
#include "hive_nav_brain/global_state.hpp" // MovementMode

namespace hive_nav_utils {

// Projection géométrique d’un point sur le poly-segment des lanelets
struct PathProjection {
  bool   ok{false};
  size_t seg_idx{0};
  double t{0.0};      // 0..1 le long du segment
  double px{0.0}, py{0.0};
};

// Distance la plus proche (XY) d’un point au chemin lanelets.
// note = "(no global path yet)" ou "(path invalid)" si applicable, sinon vide.
double distance_to_path_xy(
  const std::vector<hive_interface2::msg::LaneletMini2> &path,
  double x, double y, std::string &note);

// Projection robot -> chemin
PathProjection project_on_path(
  const std::vector<hive_interface2::msg::LaneletMini2> &path,
  double x, double y);

// Calcul de la target locale (voir règles plus haut).
// - Retourne false si pas de chemin.
// - En cas de clamp à la fin, note contient "(at_end)".
// - En cas d’inversion sur le dernier lanelet (pour robustesse), note ajoute "(reversed_last)".
bool compute_local_target(
  const std::vector<hive_interface2::msg::LaneletMini2> &path,
  double rx, double ry,                 // robot position (map)
  double goal_x, double goal_y,         // but (map)
  hive_nav::MovementMode mode,
  double lookahead_m,                   // ex: 6.0
  double &tx, double &ty,               // OUT: target (map)
  std::string &note);

} // namespace hive_nav_utils
