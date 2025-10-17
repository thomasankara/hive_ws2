#include "hive_nav_brain/path_utils.hpp"
#include <algorithm>

namespace {
inline double seg_len(double ax, double ay, double bx, double by) {
  const double dx = bx - ax, dy = by - ay;
  return std::sqrt(dx*dx + dy*dy);
}
inline double dist2(double ax, double ay, double bx, double by) {
  const double dx = bx - ax, dy = by - ay;
  return dx*dx + dy*dy;
}
inline double point_segment_distance(double px, double py, double ax, double ay, double bx, double by)
{
  const double vx = bx - ax, vy = by - ay;
  const double wx = px - ax, wy = py - ay;
  const double vv = vx*vx + vy*vy;
  if (vv <= 1e-12) return std::hypot(px-ax, py-ay);
  double t = (wx*vx + wy*vy) / vv;
  t = std::max(0.0, std::min(1.0, t));
  const double qx = ax + t*vx, qy = ay + t*vy;
  return std::hypot(px - qx, py - qy);
}
} // anon

namespace hive_nav_utils {

double distance_to_path_xy(
  const std::vector<hive_interface2::msg::LaneletMini2> &path,
  double x, double y, std::string &note)
{
  if (path.empty()) { note = "(no global path yet)"; return 0.0; }
  double best = std::numeric_limits<double>::infinity();
  for (const auto &ll : path) {
    best = std::min(best, point_segment_distance(
      x, y, ll.start_point_x, ll.start_point_y, ll.end_point_x, ll.end_point_y));
  }
  if (!std::isfinite(best)) { note = "(path invalid)"; return 0.0; }
  note.clear(); return best;
}

PathProjection project_on_path(
  const std::vector<hive_interface2::msg::LaneletMini2> &path,
  double x, double y)
{
  PathProjection P;
  if (path.empty()) return P;

  double best_d2 = std::numeric_limits<double>::infinity();
  for (size_t i = 0; i < path.size(); ++i) {
    const auto &ll = path[i];
    const double ax = ll.start_point_x, ay = ll.start_point_y;
    const double bx = ll.end_point_x,   by = ll.end_point_y;

    const double vx = bx - ax, vy = by - ay;
    const double wx = x - ax,  wy = y - ay;
    const double vv = vx*vx + vy*vy;

    double t = 0.0;
    if (vv > 1e-12) {
      t = (wx*vx + wy*vy) / vv;
      t = std::max(0.0, std::min(1.0, t));
    }
    const double px = ax + t*vx, py = ay + t*vy;
    const double d2 = dist2(x,y,px,py);
    if (d2 < best_d2) {
      best_d2 = d2;
      P.ok = true; P.seg_idx = i; P.t = t; P.px = px; P.py = py;
    }
  }
  return P;
}

bool compute_local_target(
  const std::vector<hive_interface2::msg::LaneletMini2> &path,
  double rx, double ry,
  double goal_x, double goal_y,
  hive_nav::MovementMode mode,
  double lookahead_m,
  double &tx, double &ty,
  std::string &note)
{
  if (path.empty()) { note = "(no global path yet)"; return false; }

  const auto proj = project_on_path(path, rx, ry);
  if (!proj.ok) { note = "(projection failed)"; return false; }

  double rem = 0.0;
  if (mode == hive_nav::MovementMode::ASTAR_PLANNER) {
    const double d_robot_proj = std::hypot(rx - proj.px, ry - proj.py);
    if (d_robot_proj > lookahead_m) { tx = proj.px; ty = proj.py; note.clear(); return true; }
    rem = lookahead_m - d_robot_proj;
    if (rem <= 1e-6) { tx = proj.px; ty = proj.py; note.clear(); return true; }
  } else {
    rem = lookahead_m; // hive_planner
  }

  size_t i = proj.seg_idx;
  while (i < path.size()) {
    const auto &ll = path[i];
    const double ax = ll.start_point_x, ay = ll.start_point_y;
    const double bx = ll.end_point_x,   by = ll.end_point_y;
    const double L  = seg_len(ax, ay, bx, by);
    if (L < 1e-6) { ++i; continue; }

    // Choix du sens (continuité ou goal)
    bool forward_to_B = true;
    if (i + 1 < path.size()) {
      const auto &nxt = path[i+1];
      const double dA = std::min(dist2(ax,ay,nxt.start_point_x,nxt.start_point_y),
                                 dist2(ax,ay,nxt.end_point_x,  nxt.end_point_y));
      const double dB = std::min(dist2(bx,by,nxt.start_point_x,nxt.start_point_y),
                                 dist2(bx,by,nxt.end_point_x,  nxt.end_point_y));
      forward_to_B = (dB <= dA);
    } else {
      const double dA = dist2(ax,ay, goal_x,goal_y);
      const double dB = dist2(bx,by, goal_x,goal_y);
      forward_to_B = (dB <= dA);
    }

    double ux = forward_to_B ? (bx - ax)/L : (ax - bx)/L;
    double uy = forward_to_B ? (by - ay)/L : (ay - by)/L;

    if (i == proj.seg_idx) {
      const double rem_on_seg = forward_to_B ? ((1.0 - proj.t) * L) : (proj.t * L);
      if (rem <= rem_on_seg) {
        tx = proj.px + ux * rem; ty = proj.py + uy * rem; note.clear(); return true;
      } else {
        rem -= rem_on_seg; ++i; continue;
      }
    } else {
      double sx = forward_to_B ? ax : bx;
      double sy = forward_to_B ? ay : by;
      if (rem <= L) { tx = sx + ux*rem; ty = sy + uy*rem; note.clear(); return true; }
      rem -= L; ++i;
    }
  }

  // Clamp fin
  if (!path.empty()) { tx = path.back().end_point_x; ty = path.back().end_point_y; note = "(clamped at path end)"; return true; }
  note = "(unexpected empty path)"; return false;
}

} // namespace hive_nav_utils
