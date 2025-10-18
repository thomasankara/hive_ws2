// path_utils.cpp
#include "hive_nav_brain/path_utils.hpp"

#include <algorithm>
#include <cmath>
#include <limits>

namespace {

// ———————————————————————————————————————————————————————
// Petits helpers & seuils
inline double sqr(double v) { return v * v; }
inline double dist2(double ax, double ay, double bx, double by) { return sqr(ax - bx) + sqr(ay - by); }
inline double dist(double ax, double ay, double bx, double by) { return std::sqrt(dist2(ax, ay, bx, by)); }

inline double seg_len(double ax, double ay, double bx, double by) { return dist(ax, ay, bx, by); }

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

// seuils : tolérance de joint et pince à la fin
constexpr double kJoinEps2     = 0.20 * 0.20;  // 20 cm² : pour matcher les sommets adjacents
constexpr double kEndClampEps  = 0.25;         // 25 cm : clamp de la target sur la vraie fin

inline bool near_xy(double x1, double y1, double x2, double y2, double eps2 = kJoinEps2) {
  return dist2(x1,y1,x2,y2) <= eps2;
}

// Retourne la **vraie** extrémité de la chaîne : l’extrémité du dernier lanelet
// qui n’est PAS partagée avec l’avant-dernier. Fallback: extrémité la plus proche du goal.
inline bool true_last_endpoint(
  const std::vector<hive_interface2::msg::LaneletMini2>& path,
  double goal_x, double goal_y,
  double &ex, double &ey)
{
  if (path.empty()) return false;
  const auto &last = path.back();

  if (path.size() >= 2) {
    const auto &prev = path[path.size()-2];

    const bool start_shared =
      near_xy(last.start_point_x, last.start_point_y, prev.start_point_x, prev.start_point_y) ||
      near_xy(last.start_point_x, last.start_point_y, prev.end_point_x,   prev.end_point_y);

    const bool end_shared =
      near_xy(last.end_point_x, last.end_point_y, prev.start_point_x, prev.start_point_y) ||
      near_xy(last.end_point_x, last.end_point_y, prev.end_point_x,   prev.end_point_y);

    if (start_shared && !end_shared) { ex = last.end_point_x; ey = last.end_point_y; return true; }
    if (end_shared   && !start_shared) { ex = last.start_point_x; ey = last.start_point_y; return true; }
    // ambigu => fallback ci-dessous
  }

  // Fallback: extrémité la plus proche du goal
  const double dS = dist(last.start_point_x, last.start_point_y, goal_x, goal_y);
  const double dE = dist(last.end_point_x,   last.end_point_y,   goal_x, goal_y);
  if (dE <= dS) { ex = last.end_point_x; ey = last.end_point_y; }
  else          { ex = last.start_point_x; ey = last.start_point_y; }
  return true;
}

// Décide le sens d’avancement sur le lanelet i.
// - Cas général: continuité avec i+1 (on suit le *vrai* joint si détecté).
// - Dernier lanelet: aller vers la **vraie** extrémité non partagée.
inline bool choose_forward_to_B_on_segment(
  const std::vector<hive_interface2::msg::LaneletMini2> &path,
  size_t i,
  double goal_x, double goal_y)
{
  const auto &ll = path[i];
  const double ax = ll.start_point_x, ay = ll.start_point_y;
  const double bx = ll.end_point_x,   by = ll.end_point_y;

  if (i + 1 < path.size()) {
    const auto &nxt = path[i+1];
    const double asx = nxt.start_point_x, asy = nxt.start_point_y;
    const double bex = nxt.end_point_x,   bey = nxt.end_point_y;

    const double d_B_A = dist2(bx,by, asx,asy);
    const double d_B_B = dist2(bx,by, bex,bey);
    const double d_A_A = dist2(ax,ay, asx,asy);
    const double d_A_B = dist2(ax,ay, bex,bey);
    const double best  = std::min(std::min(d_B_A, d_B_B), std::min(d_A_A, d_A_B));

    // Si un vrai joint (≤ kJoinEps2) est détecté, on le suit strictement
    if (best <= kJoinEps2) {
      if (best == d_B_A || best == d_B_B) return true;   // sens vers B
      else                                 return false;  // sens vers A
    }

    // Sinon, fallback: on choisit la config qui minimise la rupture
    if (best == d_B_A || best == d_B_B) return true;
    if (best == d_A_A || best == d_A_B) return false;
  }

  // Dernier lanelet (ou fallback) : aller vers la vraie fin
  double ex=0.0, ey=0.0;
  if (true_last_endpoint(path, goal_x, goal_y, ex, ey)) {
    const bool end_is_B = near_xy(bx,by, ex,ey);
    return end_is_B; // true => vers B, false => vers A
  }

  // Ultime fallback (ne devrait pas arriver)
  const double dA = dist2(ax, ay, goal_x, goal_y);
  const double dB = dist2(bx, by, goal_x, goal_y);
  return (dB <= dA);
}

} // anon

// ===================================================================
//  Implémentations publiques
// ===================================================================
namespace hive_nav_utils {

// ———————————————————————————————————————————————————————
// Distance point -> chemin
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
  note.clear();
  return best;
}

// ———————————————————————————————————————————————————————
// Projection
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
    const double d2p = dist2(x,y,px,py);

    if (d2p < best_d2) {
      best_d2 = d2p;
      P.ok = true; P.seg_idx = i; P.t = t; P.px = px; P.py = py;
    }
  }
  return P;
}

// ———————————————————————————————————————————————————————
// Target locale (lookahead) — évite le wrap au dernier lanelet
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

  auto proj = project_on_path(path, rx, ry);
  if (!proj.ok) { note = "(projection failed)"; return false; }

  // Règle ASTAR : si la projection est plus loin que lookahead, on vise la proj.
  double rem = 0.0;
  if (mode == hive_nav::MovementMode::ASTAR_PLANNER) {
    const double d_robot_proj = dist(rx, ry, proj.px, proj.py);
    if (d_robot_proj > lookahead_m) {
      tx = proj.px; ty = proj.py; note.clear(); return true;
    }
    rem = lookahead_m - d_robot_proj;
    if (rem <= 1e-6) {
      tx = proj.px; ty = proj.py; note.clear(); return true;
    }
  } else {
    rem = lookahead_m; // HIVE: avancer d'un lookahead complet
  }

  // Avancer le long des segments en respectant la continuité
  size_t i = proj.seg_idx;
  double cur_x = proj.px, cur_y = proj.py;

  while (i < path.size()) {
    const auto &ll = path[i];
    const double ax = ll.start_point_x, ay = ll.start_point_y;
    const double bx = ll.end_point_x,   by = ll.end_point_y;
    const double L  = seg_len(ax, ay, bx, by);
    if (L < 1e-9) { ++i; continue; }

    // sens “logique” sur ce segment (orienté vers le joint ou la vraie fin)
    const bool toB = choose_forward_to_B_on_segment(path, i, goal_x, goal_y);
    // vecteur unitaire selon ce sens
    const double ux = toB ? (bx - ax)/L : (ax - bx)/L;
    const double uy = toB ? (by - ay)/L : (ay - by)/L;

    if (i == proj.seg_idx) {
      const double rem_on_seg = toB ? ((1.0 - proj.t) * L) : (proj.t * L);

      if (rem <= rem_on_seg) {
        // cible au sein du segment courant
        tx = cur_x + ux * rem;
        ty = cur_y + uy * rem;

        // 🔒 pince à la vraie fin si on est très proche
        double ex=0.0, ey=0.0;
        if (true_last_endpoint(path, goal_x, goal_y, ex, ey) &&
            dist(tx,ty, ex,ey) <= kEndClampEps) {
          tx = ex; ty = ey;
          note = "(at_end)";
        } else {
          note.clear();
        }
        return true;
      }

      // consommer ce segment et passer au suivant
      rem -= rem_on_seg;
      cur_x = toB ? bx : ax;
      cur_y = toB ? by : ay;
      ++i;
      continue;
    }

    // Segments suivants
    // Choisir pour robustesse le “start” de i comme l’extrémité la plus proche de (cur_x,cur_y)
    double sx = ax, sy = ay, ex = bx, ey = by;
    if (dist2(cur_x,cur_y, bx,by) < dist2(cur_x,cur_y, ax,ay)) {
      std::swap(sx, ex); std::swap(sy, ey);
    }

    const double Ls = seg_len(sx, sy, ex, ey);
    if (Ls < 1e-9) { ++i; continue; }

    const double ux2 = (ex - sx) / Ls;
    const double uy2 = (ey - sy) / Ls;

    if (rem <= Ls) {
      tx = sx + ux2 * rem;
      ty = sy + uy2 * rem;

      // 🔒 pince à la vraie fin si on est très proche
      double endx=0.0, endy=0.0;
      if (true_last_endpoint(path, goal_x, goal_y, endx, endy) &&
          dist(tx,ty, endx,endy) <= kEndClampEps) {
        tx = endx; ty = endy;
        note = "(at_end)";
      } else {
        note.clear();
      }
      return true;
    }

    // Consommer ce segment et continuer
    rem -= Ls;
    cur_x = ex; cur_y = ey;
    ++i;
  }

  // Fin de boucle : clamp explicite à la vraie fin
  double end_x=0.0, end_y=0.0;
  if (true_last_endpoint(path, goal_x, goal_y, end_x, end_y)) {
    tx = end_x; ty = end_y;
    note = "(at_end)";
    return true;
  }

  note = "(unexpected empty path)";
  return false;
}

} // namespace hive_nav_utils
