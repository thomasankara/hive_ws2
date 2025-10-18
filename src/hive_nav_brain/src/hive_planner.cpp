// hive_planner.cpp
#include "hive_nav_brain/hive_planner.hpp"

#include <algorithm>
#include <cmath>
#include <limits>
#include <optional>

#include <geometry_msgs/msg/pose_stamped.hpp>
#include <nav_msgs/msg/path.hpp>

namespace hive_planner {

// -------------------------------------------------------------
// Utilitaires (fichier-local)
// -------------------------------------------------------------

static inline double hypot2d(double dx, double dy) {
  return std::sqrt(dx * dx + dy * dy);
}
static inline double dist(double x1, double y1, double x2, double y2) {
  return hypot2d(x2 - x1, y2 - y1);
}

// Segment orienté (start -> end) pour un lanelet
struct OrientedSeg {
  double sx, sy;
  double ex, ey;
};

// Ajoute (x,y) si différent du dernier point (anti-doublon)
static void push_unique(std::vector<geometry_msgs::msg::PoseStamped>& pts,
                        double x, double y,
                        const std::string& frame_id,
                        unsigned& dedup_counter,
                        double eps = 1e-6)
{
  if (!pts.empty()) {
    const auto& last = pts.back().pose.position;
    if (std::fabs(last.x - x) <= eps && std::fabs(last.y - y) <= eps) {
      ++dedup_counter;
      return;
    }
  }
  geometry_msgs::msg::PoseStamped p;
  p.header.frame_id    = frame_id;
  p.pose.position.x    = x;
  p.pose.position.y    = y;
  p.pose.position.z    = 0.0;
  p.pose.orientation.w = 1.0; // ajusté ensuite
  pts.emplace_back(std::move(p));
}

// Oriente la chaîne pour assurer end(i) ≈ start(i+1)
static std::vector<OrientedSeg> orient_lanelets_chain(
  const std::vector<hive_interface2::msg::LaneletMini2>& in,
  double eps_len,
  double eps_link,
  PathBuildStats& stats)
{
  struct Endpoints { double ax, ay, bx, by; bool valid; };
  std::vector<Endpoints> L; L.reserve(in.size());

  for (const auto& ll : in) {
    Endpoints e;
    e.ax    = static_cast<double>(ll.start_point_x);
    e.ay    = static_cast<double>(ll.start_point_y);
    e.bx    = static_cast<double>(ll.end_point_x);
    e.by    = static_cast<double>(ll.end_point_y);
    e.valid = (dist(e.ax, e.ay, e.bx, e.by) > eps_len);
    if (!e.valid) ++stats.skipped_degenerate;
    L.push_back(e);
  }

  // Aucun segment exploitable ?
  const bool any_valid = std::any_of(L.begin(), L.end(), [](const Endpoints& e){ return e.valid; });
  if (!any_valid) return {};

  // Premier segment valide
  size_t i0 = 0; while (i0 < L.size() && !L[i0].valid) ++i0;
  if (i0 >= L.size()) return {};

  // Oriente le premier pour coller au second si possible
  OrientedSeg first{ L[i0].ax, L[i0].ay, L[i0].bx, L[i0].by };
  {
    size_t j = i0 + 1; while (j < L.size() && !L[j].valid) ++j;
    if (j < L.size()) {
      const double A0A1 = dist(L[i0].ax, L[i0].ay, L[j].ax, L[j].ay);
      const double A0B1 = dist(L[i0].ax, L[i0].ay, L[j].bx, L[j].by);
      const double B0A1 = dist(L[i0].bx, L[i0].by, L[j].ax, L[j].ay);
      const double B0B1 = dist(L[i0].bx, L[i0].by, L[j].bx, L[j].by);

      // Jointure forte prioritaire (point commun < eps_link)
      if (B0A1 <= eps_link) {
        first = { L[i0].ax, L[i0].ay, L[i0].bx, L[i0].by }; // end ~ A1
      } else if (A0A1 <= eps_link) {
        first = { L[i0].bx, L[i0].by, L[i0].ax, L[i0].ay }; // inversé pour coller A1
        ++stats.reversed_segments;
      } else if (B0B1 <= eps_link) {
        first = { L[i0].ax, L[i0].ay, L[i0].bx, L[i0].by }; // end ~ B1
      } else if (A0B1 <= eps_link) {
        first = { L[i0].bx, L[i0].by, L[i0].ax, L[i0].ay }; // inversé pour coller B1
        ++stats.reversed_segments;
      } else {
        // Fallback : orientation qui rapproche la fin du prochain start
        const double bestA0 = std::min(A0A1, A0B1);
        const double bestB0 = std::min(B0A1, B0B1);
        if (bestA0 + 1e-9 < bestB0) {
          first = { L[i0].bx, L[i0].by, L[i0].ax, L[i0].ay };
          ++stats.reversed_segments;
        }
        ++stats.link_mismatches;
      }
    }
  }

  std::vector<OrientedSeg> out;
  out.reserve(in.size());
  out.push_back(first);
  OrientedSeg prev = first;

  // Propage l’orientation
  for (size_t i = i0 + 1; i < L.size(); ++i) {
    if (!L[i].valid) continue;
    const double dA = dist(prev.ex, prev.ey, L[i].ax, L[i].ay);
    const double dB = dist(prev.ex, prev.ey, L[i].bx, L[i].by);

    OrientedSeg curr;
    if (dA <= dB) {
      curr = { L[i].ax, L[i].ay, L[i].bx, L[i].by };
      if (dA > eps_link) ++stats.link_mismatches;
    } else {
      curr = { L[i].bx, L[i].by, L[i].ax, L[i].ay };
      ++stats.reversed_segments;
      if (dB > eps_link) ++stats.link_mismatches;
    }
    out.push_back(curr);
    prev = curr;
  }

  return out;
}

// Oriente par tangente locale (quaternions)
static void set_yaw_from_tangent(std::vector<geometry_msgs::msg::PoseStamped>& v) {
  if (v.size() < 2) return;

  for (size_t i = 0; i + 1 < v.size(); ++i) {
    const double dx = v[i+1].pose.position.x - v[i].pose.position.x;
    const double dy = v[i+1].pose.position.y - v[i].pose.position.y;
    const double yaw = (std::fabs(dx) > 1e-9 || std::fabs(dy) > 1e-9) ? std::atan2(dy, dx) : 0.0;
    const double h   = 0.5 * yaw;
    v[i].pose.orientation.x = 0.0;
    v[i].pose.orientation.y = 0.0;
    v[i].pose.orientation.z = std::sin(h);
    v[i].pose.orientation.w = std::cos(h);
  }

  // Dernier = tangente arrière
  const size_t N  = v.size();
  const double dx = v[N-1].pose.position.x - v[N-2].pose.position.x;
  const double dy = v[N-1].pose.position.y - v[N-2].pose.position.y;
  const double yaw = (std::fabs(dx) > 1e-9 || std::fabs(dy) > 1e-9) ? std::atan2(dy, dx) : 0.0;
  const double h   = 0.5 * yaw;
  v[N-1].pose.orientation.x = 0.0;
  v[N-1].pose.orientation.y = 0.0;
  v[N-1].pose.orientation.z = std::sin(h);
  v[N-1].pose.orientation.w = std::cos(h);
}

// Purge des points trop rapprochés (évite oscillations)
static void purge_close_points(std::vector<geometry_msgs::msg::PoseStamped>& v,
                               double min_dist = 0.07)
{
  if (v.size() < 2) return;

  std::vector<geometry_msgs::msg::PoseStamped> keep;
  keep.reserve(v.size());
  keep.push_back(v.front());

  for (size_t i = 1; i < v.size(); ++i) {
    const double dx = v[i].pose.position.x - keep.back().pose.position.x;
    const double dy = v[i].pose.position.y - keep.back().pose.position.y;
    if (std::hypot(dx, dy) >= min_dist) {
      keep.push_back(v[i]);
    }
  }
  if (keep.size() >= 2) {
    v.swap(keep);
  } else {
    // Sécurité : garantir au moins 2 points
    v.resize(std::min<size_t>(v.size(), 2));
  }
}

// -------------------------------------------------------------
// Cœur : build + (optionnel) trim derrière le robot
// -------------------------------------------------------------
static nav_msgs::msg::Path build_nav2_path_impl(
  const std::vector<hive_interface2::msg::LaneletMini2>& lanelets,
  const std::string& frame_id,
  double step_m,
  int window_half,
  const std::optional<geometry_msgs::msg::PoseStamped>& robot_start,
  PathBuildStats& stats)
{
  // Init stats
  stats = {};
  stats.step_m        = step_m;
  stats.window_half   = window_half;
  stats.lanelet_count = lanelets.size();

  nav_msgs::msg::Path out;
  out.header.frame_id = frame_id;

  if (lanelets.empty() || step_m <= 0.0) {
    return out;
  }
  if (window_half < 0) window_half = 0;

  // 0) Orientation cohérente
  constexpr double EPS_LEN  = 1e-9;
  constexpr double EPS_LINK = 0.05;
  const auto segs = orient_lanelets_chain(lanelets, EPS_LEN, EPS_LINK, stats);
  if (segs.empty()) return out;

  // 1) Échantillonnage régulier
  std::vector<geometry_msgs::msg::PoseStamped> samples;
  samples.reserve(segs.size() * static_cast<size_t>(std::max(2.0, 1.0 / step_m)));

  for (size_t i = 0; i < segs.size(); ++i) {
    const auto& s = segs[i];
    const double vx = s.ex - s.sx;
    const double vy = s.ey - s.sy;
    const double L  = hypot2d(vx, vy);
    if (L <= EPS_LEN) { ++stats.skipped_degenerate; continue; }

    const double step_t = step_m / L;

    if (samples.empty()) {
      push_unique(samples, s.sx, s.sy, frame_id, stats.dedup_dropped, 1e-6);
    }
    if (step_t < 1.0) {
      for (double t = step_t; t < 1.0; t += step_t) {
        push_unique(samples, s.sx + t * vx, s.sy + t * vy, frame_id, stats.dedup_dropped, 1e-6);
      }
    }
    if (i == segs.size() - 1) {
      push_unique(samples, s.ex, s.ey, frame_id, stats.dedup_dropped, 1e-6);
    }
  }

  stats.raw_points = samples.size();
  if (samples.size() <= 1) {
    out.poses = std::move(samples);
    stats.smoothed_points = out.poses.size();
    return out;
  }

  // 2) Lissage (moyenne glissante tronquée)
  const int N = static_cast<int>(samples.size());
  std::vector<double> xs(N), ys(N);
  for (int i = 0; i < N; ++i) {
    xs[i] = samples[i].pose.position.x;
    ys[i] = samples[i].pose.position.y;
  }

  std::vector<geometry_msgs::msg::PoseStamped> smooth(N);
  for (int i = 0; i < N; ++i) {
    const int i0 = std::max(0, i - window_half);
    const int i1 = std::min(N - 1, i + window_half);
    double sumx = 0.0, sumy = 0.0;
    int    cnt  = 0;
    for (int k = i0; k <= i1; ++k) { sumx += xs[k]; sumy += ys[k]; ++cnt; }
    const double inv = (cnt > 0) ? (1.0 / static_cast<double>(cnt)) : 1.0;

    smooth[i].header.frame_id    = frame_id;
    smooth[i].pose.position.x    = sumx * inv;
    smooth[i].pose.position.y    = sumy * inv;
    smooth[i].pose.position.z    = 0.0;
    smooth[i].pose.orientation.w = 1.0;
  }

  // 3) TRIM derrière le robot (sans insérer la pose robot)
  if (robot_start.has_value()) {
    const double rx = robot_start->pose.position.x;
    const double ry = robot_start->pose.position.y;

    // Trouver l’indice k du point lissé le plus proche
    size_t k = 0;
    double best = std::numeric_limits<double>::infinity();
    for (size_t i = 0; i < smooth.size(); ++i) {
      const double d = std::hypot(smooth[i].pose.position.x - rx,
                                  smooth[i].pose.position.y - ry);
      if (d < best) { best = d; k = i; }
    }

    // Conserver k..fin (on supprime 0..k-1)
    std::vector<geometry_msgs::msg::PoseStamped> trimmed;
    trimmed.reserve(smooth.size() - k);
    for (size_t i = k; i < smooth.size(); ++i) {
      trimmed.push_back(smooth[i]);
    }

    // Sécurité : si le trim laisse < 2 points, garder les deux derniers d’origine
    if (trimmed.size() < 2 && smooth.size() >= 2) {
      trimmed.clear();
      trimmed.push_back(smooth[smooth.size() - 2]);
      trimmed.push_back(smooth[smooth.size() - 1]);
    }

    // Purge légère (éviter un path « vide » après trim)
    purge_close_points(trimmed, /*min_dist=*/0.05);

    // Yaws par tangente
    set_yaw_from_tangent(trimmed);

    out.poses = std::move(trimmed);
    stats.smoothed_points = out.poses.size();
    return out;
  }

  // 4) Pas de trim : purge légère + yaws
  purge_close_points(smooth, /*min_dist=*/0.05);
  set_yaw_from_tangent(smooth);
  out.poses = std::move(smooth);
  stats.smoothed_points = out.poses.size();
  return out;
}

// -------------------------------------------------------------
// API publique
// -------------------------------------------------------------

// Overload historique (pas de trim)
nav_msgs::msg::Path build_nav2_path(
  const std::vector<hive_interface2::msg::LaneletMini2>& lanelets,
  const std::string& frame_id,
  double step_m,
  int window_half,
  PathBuildStats& stats)
{
  return build_nav2_path_impl(lanelets, frame_id, step_m, window_half, std::nullopt, stats);
}

// Overload recommandé : trim derrière le robot (sans insérer la pose robot)
nav_msgs::msg::Path build_nav2_path(
  const std::vector<hive_interface2::msg::LaneletMini2>& lanelets,
  const std::string& frame_id,
  double step_m,
  int window_half,
  const std::optional<geometry_msgs::msg::PoseStamped>& robot_start,
  PathBuildStats& stats)
{
  return build_nav2_path_impl(lanelets, frame_id, step_m, window_half, robot_start, stats);
}

} // namespace hive_planner
