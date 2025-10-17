#include "hive_nav_brain/path_utils.hpp"
#include <algorithm>

namespace {

// ———————————————————————————————————————————————————————
// Petits helpers
inline double sqr(double v) { return v * v; }

inline double dist2(double ax, double ay, double bx, double by) {
  return sqr(ax - bx) + sqr(ay - by);
}
inline double dist(double ax, double ay, double bx, double by) {
  return std::sqrt(dist2(ax, ay, bx, by));
}

inline double seg_len(double ax, double ay, double bx, double by) {
  return dist(ax, ay, bx, by);
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

// Seuils
constexpr double kJoinEps2   = 0.10 * 0.10;   // 10 cm² (pour matcher les sommets adjacents)
constexpr double kEndClampEps = 0.25;         // 25 cm : pour tagger "(at_end)"

// Retourne vrai si (x1,y1) et (x2,y2) sont “proches”
inline bool near_xy(double x1, double y1, double x2, double y2, double eps2 = kJoinEps2) {
  return dist2(x1,y1,x2,y2) <= eps2;
}

// Détermine le sens “logique” d’avancement sur le lanelet i.
// - Si i n’est pas le dernier, on détecte le point commun entre i et i+1
//   et on choisit le sens qui mène vers ce point commun.
// - Si i est le dernier, on choisit la borne la plus proche du goal.
// Renvoie true => avancer vers end(i), false => vers start(i).
bool choose_forward_to_B_on_segment(
  const std::vector<hive_interface2::msg::LaneletMini2> &path,
  size_t i,
  double goal_x, double goal_y)
{
  const auto &ll = path[i];
  const double ax = ll.start_point_x, ay = ll.start_point_y;
  const double bx = ll.end_point_x,   by = ll.end_point_y;

  // Cas général : on se fie à la continuité avec i+1
  if (i + 1 < path.size()) {
    const auto &nxt = path[i+1];
    const double asx = nxt.start_point_x, asy = nxt.start_point_y;
    const double bex = nxt.end_point_x,   bey = nxt.end_point_y;

    // On regarde quel couple d’extrémités est le plus proche
    const double d_B_A = dist2(bx,by, asx,asy);
    const double d_B_B = dist2(bx,by, bex,bey);
    const double d_A_A = dist2(ax,ay, asx,asy);
    const double d_A_B = dist2(ax,ay, bex,bey);
    const double best  = std::min(std::min(d_B_A, d_B_B), std::min(d_A_A, d_A_B));

    // Si la meilleure correspondance implique end(i) => on va vers B
    if (best == d_B_A || best == d_B_B) return true;
    // Si elle implique start(i) => on va vers A
    if (best == d_A_A || best == d_A_B) return false;

    // Fallback ultra rare: choisir l’extrémité la plus proche du goal
  }

  // Dernier lanelet (ou fallback) : se rapprocher du goal
  const double dA = dist2(ax, ay, goal_x, goal_y);
  const double dB = dist2(bx, by, goal_x, goal_y);
  return (dB <= dA);  // true => vers end, false => vers start
}

} // anon

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
// Target locale
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

  // Distance robot -> projection (règle ASTAR)
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
    rem = lookahead_m; // HIVE: avance toujours du lookahead
  }

  // On avance le long du chemin avec la logique de continuité
  size_t i = proj.seg_idx;
  double cur_x = proj.px, cur_y = proj.py;

  while (i < path.size()) {
    const auto &ll = path[i];
    const double ax = ll.start_point_x, ay = ll.start_point_y;
    const double bx = ll.end_point_x,   by = ll.end_point_y;
    const double L  = seg_len(ax, ay, bx, by);
    if (L < 1e-9) { ++i; continue; }

    // sens sur ce segment
    const bool toB = choose_forward_to_B_on_segment(path, i, goal_x, goal_y);
    // vecteur unitaire selon le sens
    double ux = toB ? (bx - ax)/L : (ax - bx)/L;
    double uy = toB ? (by - ay)/L : (ay - by)/L;

    if (i == proj.seg_idx) {
      // Distance disponible sur ce segment à partir de la projection
      const double rem_on_seg = toB ? ((1.0 - proj.t) * L) : (proj.t * L);

      if (rem <= rem_on_seg) {
        // cible au sein du segment courant
        tx = cur_x + ux * rem;
        ty = cur_y + uy * rem;

        // Si on est très proche de la borne terminale globale -> marquer at_end
        const auto &last = path.back();
        const double ex = last.end_point_x, ey = last.end_point_y;
        if (dist(tx,ty, ex,ey) <= kEndClampEps) {
          note = "(at_end)";
        } else {
          note.clear();
        }
        return true;
      }

      // Sinon, on consomme tout ce segment et on passe au suivant
      rem -= rem_on_seg;
      // Avancer jusqu’à l’extrémité atteinte
      cur_x = toB ? bx : ax;
      cur_y = toB ? by : ay;

      ++i; // prochain segment
      continue;
    }

    // Segments suivants
    // On part de l’extrémité de 'i-1' atteinte (cur_x,cur_y).
    // Pour robustesse, on choisit le "start" de ce segment comme l’extrémité la plus proche de (cur_x,cur_y)
    double sx = ax, sy = ay, ex = bx, ey = by; // repères locaux
    // Si l’extrémité B est plus proche, on swap “start”<->“end”
    if (dist2(cur_x,cur_y, bx,by) < dist2(cur_x,cur_y, ax,ay)) {
      // swap
      sx = bx; sy = by; ex = ax; ey = ay;
    }

    const double Ls = seg_len(sx, sy, ex, ey);
    if (Ls < 1e-9) { ++i; continue; }

    // Orienter dans le sens qui mène à l’extrémité prévue (cohérent avec choose_forward_to_B_on_segment(j))
    bool toEnd = true; // on veut aller vers (ex,ey) depuis (sx,sy)
    double ux2 = (ex - sx) / Ls;
    double uy2 = (ey - sy) / Ls;

    if (rem <= Ls) {
      tx = sx + ux2 * rem;
      ty = sy + uy2 * rem;

      // Fin proche ?
      const auto &last = path.back();
      const double gx = last.end_point_x, gy = last.end_point_y;
      if (dist(tx,ty, gx,gy) <= kEndClampEps) {
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

  // Si on sort de la boucle : clamp à la fin “canonique”
  if (!path.empty()) {
    const auto &last = path.back();

    // Déterminer si la “fin canonique” est end(last) ou start(last)
    bool forward_on_last = choose_forward_to_B_on_segment(path, path.size()-1, goal_x, goal_y);
    if (forward_on_last) {
      tx = last.end_point_x; ty = last.end_point_y;
      note = "(at_end)";
    } else {
      // Rare : on a estimé que START est la fin canonique -> on préfère tout de même renvoyer end(last)
      // pour garder une convention unique et éviter de “glisser à l’envers” en bas de route.
      tx = last.end_point_x; ty = last.end_point_y;
      note = "(at_end)(reversed_last)";
    }
    return true;
  }

  note = "(unexpected empty path)";
  return false;
}

} // namespace hive_nav_utils
