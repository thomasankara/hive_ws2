// hive_planner.cpp
#include "hive_nav_brain/hive_planner.hpp"

#include <cmath>
#include <limits>
#include <algorithm>
#include <optional>
#include <geometry_msgs/msg/pose_stamped.hpp>

namespace hive_planner {

static inline double hypot2d(double dx, double dy) { return std::sqrt(dx*dx + dy*dy); }
static inline double dist(double x1,double y1,double x2,double y2){ return hypot2d(x2-x1, y2-y1); }

static inline bool same_xy_eps(double x1,double y1,double x2,double y2, double eps){
  return std::fabs(x1-x2) <= eps && std::fabs(y1-y2) <= eps;
}

static inline bool same_xy_pose(const geometry_msgs::msg::PoseStamped& a,
                                double x, double y, double eps = 1e-6)
{
  return std::fabs(a.pose.position.x - x) <= eps &&
         std::fabs(a.pose.position.y - y) <= eps;
}

struct OrientedSeg { double sx, sy; double ex, ey; };

static void push_unique(std::vector<geometry_msgs::msg::PoseStamped>& pts,
                        double x, double y,
                        const std::string& frame_id,
                        unsigned& dedup_counter,
                        double eps = 1e-6)
{
  if (!pts.empty() &&
      std::fabs(pts.back().pose.position.x - x) <= eps &&
      std::fabs(pts.back().pose.position.y - y) <= eps)
  {
    ++dedup_counter;
    return;
  }
  geometry_msgs::msg::PoseStamped p;
  p.header.frame_id = frame_id;
  p.pose.position.x = x;
  p.pose.position.y = y;
  p.pose.position.z = 0.0;
  p.pose.orientation.w = 1.0; // yaw fixé ensuite
  pts.emplace_back(std::move(p));
}

/**
 * Trouve l’orientation de la chaîne en cherchant un VRAI point commun entre N et N+1 :
 * on teste les 4 appariements (A-A, A-B, B-A, B-B) et si l’un est < eps_link, on force
 * end(N) = ce point commun et start(N+1) = ce point commun. Sinon, on choisit l’orientation
 * qui minimise la rupture (fallback).
 */
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
    e.ax = static_cast<double>(ll.start_point_x);
    e.ay = static_cast<double>(ll.start_point_y);
    e.bx = static_cast<double>(ll.end_point_x);
    e.by = static_cast<double>(ll.end_point_y);
    const double len = dist(e.ax, e.ay, e.bx, e.by);
    e.valid = (len > eps_len);
    if (!e.valid) ++stats.skipped_degenerate;
    L.push_back(e);
  }
  // aucun valide ?
  bool any = false; for (auto& e : L) if (e.valid) { any = true; break; }
  if (!any) return {};

  // trouve premier valide
  size_t i0 = 0; while (i0 < L.size() && !L[i0].valid) ++i0;
  if (i0 >= L.size()) return {};

  // orientation du premier : essayer d’aligner son END sur START du suivant (si lien vrai)
  auto first = OrientedSeg{L[i0].ax, L[i0].ay, L[i0].bx, L[i0].by};
  {
    size_t j = i0 + 1; while (j < L.size() && !L[j].valid) ++j;
    if (j < L.size()) {
      // distances entre endpoints
      const double A0A1 = dist(L[i0].ax, L[i0].ay, L[j].ax, L[j].ay);
      const double A0B1 = dist(L[i0].ax, L[i0].ay, L[j].bx, L[j].by);
      const double B0A1 = dist(L[i0].bx, L[i0].by, L[j].ax, L[j].ay);
      const double B0B1 = dist(L[i0].bx, L[i0].by, L[j].bx, L[j].by);

      // cas où on a un VRAI point commun
      if (B0A1 <= eps_link) {
        first = OrientedSeg{L[i0].ax, L[i0].ay, L[i0].bx, L[i0].by}; // end= B0 ~ A1
      } else if (A0A1 <= eps_link) {
        first = OrientedSeg{L[i0].bx, L[i0].by, L[i0].ax, L[i0].ay}; // inverse pour end ~ A1
        ++stats.reversed_segments;
      } else if (B0B1 <= eps_link) {
        first = OrientedSeg{L[i0].ax, L[i0].ay, L[i0].bx, L[i0].by}; // end ~ B1 (on inversera j après)
      } else if (A0B1 <= eps_link) {
        first = OrientedSeg{L[i0].bx, L[i0].by, L[i0].ax, L[i0].ay}; // inverse pour end ~ B1
        ++stats.reversed_segments;
      } else {
        // fallback: choisir l’orientation qui rapproche le END du prochain START
        const double bestA0 = std::min(A0A1, A0B1);
        const double bestB0 = std::min(B0A1, B0B1);
        if (bestA0 + 1e-9 < bestB0) {
          first = OrientedSeg{L[i0].bx, L[i0].by, L[i0].ax, L[i0].ay};
          ++stats.reversed_segments;
        }
        ++stats.link_mismatches;
      }
    }
  }

  std::vector<OrientedSeg> out; out.reserve(in.size());
  out.push_back(first);
  OrientedSeg prev = first;

  // propager l’orientation en assurant start(i) ≈ end(i-1)
  for (size_t i = i0 + 1; i < L.size(); ++i) {
    if (!L[i].valid) continue;
    // tester vrais liens sur A et B
    const double dA = dist(prev.ex, prev.ey, L[i].ax, L[i].ay);
    const double dB = dist(prev.ex, prev.ey, L[i].bx, L[i].by);

    OrientedSeg curr;
    if (dA <= dB) {
      curr = OrientedSeg{L[i].ax, L[i].ay, L[i].bx, L[i].by};
      if (dA > eps_link) ++stats.link_mismatches;
    } else {
      curr = OrientedSeg{L[i].bx, L[i].by, L[i].ax, L[i].ay};
      ++stats.reversed_segments;
      if (dB > eps_link) ++stats.link_mismatches;
    }
    out.push_back(curr);
    prev = curr;
  }
  return out;
}

// --- petits helpers ---
static void set_yaw_from_tangent(std::vector<geometry_msgs::msg::PoseStamped>& v) {
  if (v.size() < 2) return;
  for (size_t i = 0; i + 1 < v.size(); ++i) {
    const double dx = v[i+1].pose.position.x - v[i].pose.position.x;
    const double dy = v[i+1].pose.position.y - v[i].pose.position.y;
    double yaw = 0.0;
    if (std::fabs(dx) > 1e-9 || std::fabs(dy) > 1e-9) yaw = std::atan2(dy, dx);
    const double h = 0.5 * yaw;
    v[i].pose.orientation.x = 0.0;
    v[i].pose.orientation.y = 0.0;
    v[i].pose.orientation.z = std::sin(h);
    v[i].pose.orientation.w = std::cos(h);
  }
  // dernier = tangente arrière
  const auto N = v.size();
  const double dx = v[N-1].pose.position.x - v[N-2].pose.position.x;
  const double dy = v[N-1].pose.position.y - v[N-2].pose.position.y;
  double yaw = 0.0;
  if (std::fabs(dx) > 1e-9 || std::fabs(dy) > 1e-9) yaw = std::atan2(dy, dx);
  const double h = 0.5 * yaw;
  v[N-1].pose.orientation.x = 0.0;
  v[N-1].pose.orientation.y = 0.0;
  v[N-1].pose.orientation.z = std::sin(h);
  v[N-1].pose.orientation.w = std::cos(h);
}

static void purge_close_points(std::vector<geometry_msgs::msg::PoseStamped>& v, double min_dist = 0.07) {
  if (v.size() < 2) return;
  std::vector<geometry_msgs::msg::PoseStamped> keep;
  keep.reserve(v.size());
  keep.push_back(v.front());
  for (size_t i = 1; i < v.size(); ++i) {
    const double dx = v[i].pose.position.x - keep.back().pose.position.x;
    const double dy = v[i].pose.position.y - keep.back().pose.position.y;
    if (std::hypot(dx,dy) >= min_dist) keep.push_back(v[i]);
  }
  v.swap(keep);
}

// --- cœur : construction + (optionnel) trim au robot ---
static nav_msgs::msg::Path build_nav2_path_impl(
  const std::vector<hive_interface2::msg::LaneletMini2>& lanelets,
  const std::string& frame_id,
  double step_m,
  int window_half,
  const std::optional<geometry_msgs::msg::PoseStamped>& robot_start,
  PathBuildStats& stats)
{
  stats = {};
  stats.step_m      = step_m;
  stats.window_half = window_half;
  stats.lanelet_count = lanelets.size();

  nav_msgs::msg::Path out; out.header.frame_id = frame_id;
  if (lanelets.empty() || step_m <= 0.0) return out;

  const double eps_len  = 1e-9;
  const double eps_link = 0.05;
  auto segs = orient_lanelets_chain(lanelets, eps_len, eps_link, stats);
  if (segs.empty()) return out;

  // 1) Échantillonnage orienté
  std::vector<geometry_msgs::msg::PoseStamped> samples;
  samples.reserve(segs.size() * (std::max(2.0, 1.0/step_m)));
  for (size_t i = 0; i < segs.size(); ++i) {
    const auto& s = segs[i];
    const double vx = s.ex - s.sx;
    const double vy = s.ey - s.sy;
    const double L  = hypot2d(vx, vy);
    if (L <= eps_len) { ++stats.skipped_degenerate; continue; }
    const double step_t = step_m / L;

    if (samples.empty())
      push_unique(samples, s.sx, s.sy, frame_id, stats.dedup_dropped, 1e-6);

    if (step_t < 1.0) {
      for (double t = step_t; t < 1.0; t += step_t)
        push_unique(samples, s.sx + t*vx, s.sy + t*vy, frame_id, stats.dedup_dropped, 1e-6);
    }
    if (i == segs.size() - 1)
      push_unique(samples, s.ex, s.ey, frame_id, stats.dedup_dropped, 1e-6);
  }
  stats.raw_points = samples.size();
  if (samples.size() <= 1) { out.poses = samples; stats.smoothed_points = out.poses.size(); return out; }

  // 2) Lissage (moyenne glissante tronquée)
  const int N = static_cast<int>(samples.size());
  std::vector<double> xs(N), ys(N);
  for (int i = 0; i < N; ++i) { xs[i] = samples[i].pose.position.x; ys[i] = samples[i].pose.position.y; }

  std::vector<geometry_msgs::msg::PoseStamped> smooth; smooth.resize(N);
  for (int i = 0; i < N; ++i) {
    const int i0 = std::max(0, i - window_half);
    const int i1 = std::min(N - 1, i + window_half);
    double sumx = 0.0, sumy = 0.0; int cnt = 0;
    for (int k = i0; k <= i1; ++k) { sumx += xs[k]; sumy += ys[k]; ++cnt; }
    const double inv = (cnt > 0) ? (1.0 / double(cnt)) : 1.0;
    smooth[i].header.frame_id = frame_id;
    smooth[i].pose.position.x = sumx * inv;
    smooth[i].pose.position.y = sumy * inv;
    smooth[i].pose.position.z = 0.0;
    smooth[i].pose.orientation.w = 1.0;
  }

  // 3) (Optionnel) TRIM au robot / insertion de la pose robot comme 1er point
  if (robot_start.has_value()) {
    const double rx = robot_start->pose.position.x;
    const double ry = robot_start->pose.position.y;

    // trouve l’indice le plus proche sur "smooth"
    size_t k = 0; double best = std::numeric_limits<double>::infinity();
    for (size_t i = 0; i < smooth.size(); ++i) {
      const double d = std::hypot(smooth[i].pose.position.x - rx,
                                  smooth[i].pose.position.y - ry);
      if (d < best) { best = d; k = i; }
    }

    std::vector<geometry_msgs::msg::PoseStamped> trimmed;
    trimmed.reserve(smooth.size() - k + 1);

    // 3.a) mettre la pose robot comme 1er point
    auto s0 = *robot_start;
    s0.header.frame_id = frame_id; // homogénéiser
    trimmed.push_back(s0);

    // 3.b) puis garder depuis k
    for (size_t i = k; i < smooth.size(); ++i) trimmed.push_back(smooth[i]);

    // 3.c) purge des points trop proches au tout début (évite oscillations)
    purge_close_points(trimmed, /*min_dist=*/0.07);

    // 4) yaws tangents
    set_yaw_from_tangent(trimmed);

    out.poses = std::move(trimmed);
    stats.smoothed_points = out.poses.size();
    return out;
  }

  // (sinon) pas de robot_start -> juste yaws + (petite purge de tête)
  purge_close_points(smooth, 0.05);
  set_yaw_from_tangent(smooth);
  out.poses = std::move(smooth);
  stats.smoothed_points = out.poses.size();
  return out;
}

// Overload “historique” : délègue sans robot_start
nav_msgs::msg::Path build_nav2_path(
  const std::vector<hive_interface2::msg::LaneletMini2>& lanelets,
  const std::string& frame_id,
  double step_m,
  int window_half,
  PathBuildStats& stats)
{
  return build_nav2_path_impl(lanelets, frame_id, step_m, window_half, std::nullopt, stats);
}

// Overload “recommandé” avec départ robot
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
