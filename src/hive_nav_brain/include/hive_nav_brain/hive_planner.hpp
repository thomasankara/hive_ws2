#pragma once
// hive_planner.hpp
//
// Construit un nav_msgs/Path depuis une chaîne de LaneletMini2.
// Deux overloads :
//  - historique (sans pose robot) ;
//  - recommandé (avec pose robot) : on TRIM le chemin en supprimant
//    tous les points *avant* le point le plus proche du robot,
//    mais on NE remplace pas la tête par la pose robot.
//
// Le but : éviter que le contrôleur reçoive des points "derrière"
// le robot et qu'il refuse la trajectoire (plan vide / pruning total).

#include <string>
#include <vector>
#include <optional>

#include <nav_msgs/msg/path.hpp>
#include <geometry_msgs/msg/pose_stamped.hpp>
#include "hive_interface2/msg/lanelet_mini2.hpp"

namespace hive_planner {

// Statistiques pour logs / debug
struct PathBuildStats {
  size_t lanelet_count        = 0;   // nb de lanelets en entrée
  size_t raw_points           = 0;   // nb de points échantillonnés (avant lissage)
  size_t smoothed_points      = 0;   // nb de points après lissage + trim
  unsigned skipped_degenerate = 0;   // segments trop courts
  unsigned dedup_dropped      = 0;   // points ignorés (doublon XY)
  unsigned reversed_segments  = 0;   // segments inversés pour continuité
  unsigned link_mismatches    = 0;   // jointures imparfaites
  double  step_m              = 0.1; // pas d’échantillonnage
  int     window_half         = 10;  // demi-fenêtre du lissage
};

// --- Overload historique (pas de trim) ---
nav_msgs::msg::Path build_nav2_path(
  const std::vector<hive_interface2::msg::LaneletMini2>& lanelets,
  const std::string& frame_id,
  double step_m,
  int window_half,
  PathBuildStats& stats);

// --- Overload recommandé (trim derrière le robot) ---
// Si robot_start est fourni : on supprime tous les points strictement
// avant l’indice du point lissé le plus proche du robot ; on conserve
// les points d’origine (on n’insère pas la pose robot).
nav_msgs::msg::Path build_nav2_path(
  const std::vector<hive_interface2::msg::LaneletMini2>& lanelets,
  const std::string& frame_id,
  double step_m,
  int window_half,
  const std::optional<geometry_msgs::msg::PoseStamped>& robot_start,
  PathBuildStats& stats);

} // namespace hive_planner
