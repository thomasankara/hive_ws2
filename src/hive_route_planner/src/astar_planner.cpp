#include "hive_route_planner/astar_planner.hpp"

#include <queue>
#include <limits>
#include <algorithm>
#include <unordered_map>
#include <cmath>

namespace hive_route_planner {

AStarPlanner::AStarPlanner(const std::vector<hive_interface2::msg::LaneletMini2>& lanelets,
                           const Params& params)
: L_(lanelets), P_(params)
{
  buildGraph();
}

// --- Quantisation stricte des noeuds pour éviter de créer des connexions fantômes ---
struct Key2D {
  long long ix{0}, iy{0};
  bool operator==(const Key2D& o) const { return ix==o.ix && iy==o.iy; }
};
struct Key2DHash {
  std::size_t operator()(const Key2D& k) const noexcept {
    std::size_t h = std::hash<long long>{}(k.ix);
    // mix
    h ^= std::hash<long long>{}(k.iy) + 0x9e3779b97f4a7c15ULL + (h<<6) + (h>>2);
    return h;
  }
};

void AStarPlanner::buildGraph()
{
  graph_.nodes.clear();
  graph_.edges.clear();
  graph_.adj.clear();
  graph_.lanelet_nodes.clear();
  graph_.lanelet_nodes.resize(L_.size());
  graph_.max_speed_mps_global = std::max(0.1, P_.fallback_speed_mps);

  const double tol = std::max(P_.epsilon_merge_m, 1e-9);
  const double inv = 1.0 / tol;

  std::unordered_map<Key2D,int,Key2DHash> map_node;

  auto getOrMake = [&](double x, double y) -> int {
    Key2D k{ (long long)std::llround(x * inv), (long long)std::llround(y * inv) };
    auto it = map_node.find(k);
    if (it != map_node.end()) return it->second;
    const int id = (int)graph_.nodes.size();
    graph_.nodes.push_back(GraphNode{ id, x, y });
    map_node.emplace(k, id);
    return id;
  };

  // 1) Créer les noeuds aux extrémités, en quantisant par tolérance
  for (int i = 0; i < (int)L_.size(); ++i) {
    const auto& ll = L_[i];
    const int a = getOrMake(ll.start_point_x, ll.start_point_y);
    const int b = getOrMake(ll.end_point_x,   ll.end_point_y);
    graph_.lanelet_nodes[i] = {a, b};
  }

  graph_.adj.resize(graph_.nodes.size());

  // 2) Créer les arcs dirigés selon navigation_direction
  for (int i = 0; i < (int)L_.size(); ++i) {
    const auto& ll = L_[i];
    const auto [a, b] = graph_.lanelet_nodes[i];

    const double Lm = std::hypot(ll.end_point_x - ll.start_point_x,
                                 ll.end_point_y - ll.start_point_y);
    if (Lm <= 1e-9) continue;
    const double v  = std::max(P_.fallback_speed_mps, kmh_to_mps(ll.max_speed));

    auto add_edge = [&](int u, int vto, bool fwd) {
      GraphEdge e;
      e.from = u; e.to = vto;
      e.lanelet_idx = i;
      e.length_m = Lm;
      e.speed_mps = v;
      e.nodeA = a; e.nodeB = b;
      e.forward_start_to_end = fwd;
      const int ei = (int)graph_.edges.size();
      graph_.edges.push_back(e);
      graph_.adj[u].push_back(ei);
      graph_.max_speed_mps_global = std::max(graph_.max_speed_mps_global, e.speed_mps);
    };

    switch (ll.navigation_direction) {
      case 1: add_edge(a, b, true);  break;  // A->B
      case 2: add_edge(b, a, false); break;  // B->A
      case 3: add_edge(a, b, true); add_edge(b, a, false); break; // bi
      default: break; // fermé
    }
  }
}

// --- Projection géométrique ---
Projection
AStarPlanner::projectOnLanelets(const std::vector<hive_interface2::msg::LaneletMini2>& L,
                                double px, double py, double eps_frac)
{
  Projection best;
  best.lanelet_idx = -1; best.px = px; best.py = py;
  double best_d2 = std::numeric_limits<double>::infinity();

  for (int i=0;i<(int)L.size();++i) {
    const auto& ll = L[i];
    const double ax = ll.start_point_x, ay = ll.start_point_y;
    const double bx = ll.end_point_x,   by = ll.end_point_y;
    const double vx = bx-ax, vy = by-ay;
    const double v2 = vx*vx + vy*vy;
    if (v2 <= 1e-12) continue;
    const double wx = px-ax, wy = py-ay;
    double t = (wx*vx + wy*vy)/v2;
    t = std::clamp(t, 0.0, 1.0);
    const double qx = ax + t*vx, qy = ay + t*vy;
    const double d2 = (px-qx)*(px-qx) + (py-qy)*(py-qy);
    if (d2 < best_d2) {
      best_d2 = d2;
      best.lanelet_idx = i;
      best.t = t;
      best.px = qx; best.py = qy;
      best.at_start = (t <= eps_frac);
      best.at_end   = (t >= 1.0 - eps_frac);
    }
  }
  return best;
}

// --- Start candidates : utiliser EXACTEMENT les noeuds du lanelet projeté ---
std::vector<CandidateEnd>
AStarPlanner::makeStartCandidates(const Projection& prj,
                                  const Graph& G,
                                  const std::vector<hive_interface2::msg::LaneletMini2>& L,
                                  const Params& P,
                                  CostMode /*mode*/)
{
  std::vector<CandidateEnd> out;
  if (prj.lanelet_idx < 0) return out;

  const auto& ll = L[prj.lanelet_idx];
  const double ax = ll.start_point_x, ay = ll.start_point_y;
  const double bx = ll.end_point_x,   by = ll.end_point_y;
  const double segL = std::hypot(bx-ax, by-ay);
  const double v = std::max(P.fallback_speed_mps, kmh_to_mps(ll.max_speed));

  auto nodeOf = [&](double x, double y){
    for (const auto& n : G.nodes) if (std::hypot(n.x-x, n.y-y) <= P.epsilon_merge_m) return n.id;
    return -1;
  };
  const int nodeA = nodeOf(ax,ay);
  const int nodeB = nodeOf(bx,by);

  auto addCand = [&](int node_to_reach, double dist_m){
    CandidateEnd c;
    c.node = node_to_reach;
    c.extra_dist_m = dist_m;
    c.extra_time_s = dist_m / v;   // <-- toujours calculé
    c.lanelet_idx = prj.lanelet_idx;
    c.valid = (node_to_reach >= 0);
    if (c.valid) out.push_back(c);
  };

  if (ll.navigation_direction == 1 || ll.navigation_direction == 3) {
    const double d = (prj.at_end ? 0.0 : (1.0 - prj.t) * segL); // proj -> B
    addCand(nodeB, d);
  }
  if (ll.navigation_direction == 2 || ll.navigation_direction == 3) {
    const double d = (prj.at_start ? 0.0 : prj.t * segL); // proj -> A
    addCand(nodeA, d);
  }
  return out;
}


// --- Goal candidates : utiliser EXACTEMENT les noeuds du lanelet projeté ---
std::vector<CandidateEnd>
AStarPlanner::makeGoalCandidates(const Projection& prj,
                                 const Graph& G,
                                 const std::vector<hive_interface2::msg::LaneletMini2>& L,
                                 const Params& P,
                                 CostMode /*mode*/)
{
  std::vector<CandidateEnd> out;
  if (prj.lanelet_idx < 0) return out;

  const auto& ll = L[prj.lanelet_idx];
  const double ax = ll.start_point_x, ay = ll.start_point_y;
  const double bx = ll.end_point_x,   by = ll.end_point_y;
  const double segL = std::hypot(bx-ax, by-ay);
  const double v = std::max(P.fallback_speed_mps, kmh_to_mps(ll.max_speed));

  auto nodeOf = [&](double x, double y){
    for (const auto& n : G.nodes) if (std::hypot(n.x-x, n.y-y) <= P.epsilon_merge_m) return n.id;
    return -1;
  };
  const int nodeA = nodeOf(ax,ay);
  const int nodeB = nodeOf(bx,by);

  auto addCand = [&](int node_from_which, double dist_m){
    CandidateEnd c;
    c.node = node_from_which;
    c.extra_dist_m = dist_m;
    c.extra_time_s = dist_m / v;   // <-- toujours calculé
    c.lanelet_idx = prj.lanelet_idx;
    c.valid = (node_from_which >= 0);
    if (c.valid) out.push_back(c);
  };

  if (ll.navigation_direction == 1 || ll.navigation_direction == 3) {
    const double d = (prj.at_start ? 0.0 : prj.t * segL); // A -> proj
    addCand(nodeA, d);
  }
  if (ll.navigation_direction == 2 || ll.navigation_direction == 3) {
    const double d = (prj.at_end ? 0.0 : (1.0 - prj.t) * segL); // B -> proj
    addCand(nodeB, d);
  }
  return out;
}

double AStarPlanner::edgeWeight(const GraphEdge& e, CostMode mode, double fb)
{
  if (mode == CostMode::DISTANCE) return e.length_m;
  return e.length_m / std::max(fb, e.speed_mps);
}

double AStarPlanner::heuristic(const GraphNode& n, const GraphNode& goal,
                               CostMode mode, double vmax)
{
  const double d = std::hypot(n.x - goal.x, n.y - goal.y);
  return (mode == CostMode::DISTANCE) ? d : (d / std::max(0.1, vmax));
}

PathResult
AStarPlanner::runAStarCombo(const CandidateEnd& start_c,
                            const CandidateEnd& goal_c,
                            CostMode mode) const
{
  PathResult R; R.success = false;

  if (start_c.node < 0 || goal_c.node < 0) { R.message = "invalid nodes"; return R; }
  if (start_c.node == goal_c.node) {
    R.success = true;
    R.total_dist_m = start_c.extra_dist_m + goal_c.extra_dist_m;
    R.total_time_s = start_c.extra_time_s + goal_c.extra_time_s; // <-- toujours du temps
    R.message = "same-node (partial only)";
    return R;
  }

  const int N = (int)graph_.nodes.size();
  const int start = start_c.node, goal = goal_c.node;

  std::vector<double> g(N, std::numeric_limits<double>::infinity());
  std::vector<double> f(N, std::numeric_limits<double>::infinity());
  std::vector<int> came_edge(N, -1);
  std::vector<bool> closed(N, false);

  struct QItem { int node; double f; };
  struct Cmp { bool operator()(const QItem& a, const QItem& b) const { return a.f > b.f; } };
  std::priority_queue<QItem, std::vector<QItem>, Cmp> open;

  g[start] = 0.0;
  f[start] = heuristic(graph_.nodes[start], graph_.nodes[goal], mode, graph_.max_speed_mps_global);
  open.push(QItem{start, f[start]});

  bool found = false;
  while (!open.empty()) {
    auto cur = open.top(); open.pop();
    const int u = cur.node;
    if (closed[u]) continue;
    closed[u] = true;
    if (u == goal) { found = true; break; }

    for (int ei : graph_.adj[u]) {
      const auto& e = graph_.edges[ei];
      const int v = e.to;
      if (closed[v]) continue;
      const double w = edgeWeight(e, mode, P_.fallback_speed_mps);
      const double tentative = g[u] + w;
      if (tentative < g[v]) {
        g[v] = tentative;
        came_edge[v] = ei;
        f[v] = tentative + heuristic(graph_.nodes[v], graph_.nodes[goal], mode, graph_.max_speed_mps_global);
        open.push(QItem{v, f[v]});
      }
    }
  }

  if (!found) { R.success = false; R.message = "A* failed"; return R; }

  std::vector<int> edges_rev;
  for (int v = goal; v != start; ) {
    int ei = came_edge[v]; if (ei < 0) break;
    edges_rev.push_back(ei);
    v = graph_.edges[ei].from;
  }
  std::vector<int> edges(edges_rev.rbegin(), edges_rev.rend());

  double dist_sum = start_c.extra_dist_m + goal_c.extra_dist_m;
  double time_sum = start_c.extra_time_s + goal_c.extra_time_s; // <-- accumule base

  std::vector<int> lanelets_order;
  lanelets_order.reserve(edges.size()+2);
  std::vector<Segment> segments;
  segments.reserve(edges.size());

  for (int ei : edges) {
    const auto& e = graph_.edges[ei];
    dist_sum += e.length_m;
    time_sum += e.length_m / std::max(P_.fallback_speed_mps, e.speed_mps); // <-- toujours du temps
    appendLaneletIfMissing(lanelets_order, e.lanelet_idx);
    segments.push_back(Segment{ e.lanelet_idx, e.forward_start_to_end });
  }

  R.success = true;
  R.total_dist_m = dist_sum;
  R.total_time_s = time_sum;  // <-- toujours non nul
  R.lanelet_indices = std::move(lanelets_order);
  R.segments = std::move(segments);
  R.message = "OK";
  return R;
}


PathResult 
AStarPlanner::solveSameLaneletDirect(CostMode /*mode*/) const
{
  PathResult R; R.success = false;
  if (start_proj_.lanelet_idx < 0 || goal_proj_.lanelet_idx < 0) return R;
  if (start_proj_.lanelet_idx != goal_proj_.lanelet_idx) return R;

  const auto& ll = L_[start_proj_.lanelet_idx];
  const double segL = std::hypot(ll.end_point_x - ll.start_point_x, ll.end_point_y - ll.start_point_y);
  const double v = std::max(P_.fallback_speed_mps, kmh_to_mps(ll.max_speed));
  const double dt = goal_proj_.t - start_proj_.t;

  auto dir_ok = [&](int navdir){
    if (dt >= 0) return (navdir == 1 || navdir == 3); // A->B
    else         return (navdir == 2 || navdir == 3); // B->A
  };
  if (!dir_ok(ll.navigation_direction)) {
    R.message = "same-lanelet not allowed by navigation_direction";
    return R;
  }

  const double d = std::abs(dt) * segL;
  R.success = true;
  R.total_dist_m = d;
  R.total_time_s = d / v;  // <-- toujours du temps
  R.lanelet_indices = { start_proj_.lanelet_idx };
  R.segments = { Segment{ start_proj_.lanelet_idx, dt >= 0.0 } }; // orienté
  R.message = "same-lanelet OK";
  return R;
}


void AStarPlanner::appendLaneletIfMissing(std::vector<int>& ordered_lanelets, int lanelet_idx)
{
  if (ordered_lanelets.empty() || ordered_lanelets.back() != lanelet_idx)
    ordered_lanelets.push_back(lanelet_idx);
}

void AStarPlanner::prependLaneletIfMissing(std::vector<int>& ordered_lanelets, int lanelet_idx)
{
  if (ordered_lanelets.empty() || ordered_lanelets.front() != lanelet_idx)
    ordered_lanelets.insert(ordered_lanelets.begin(), lanelet_idx);
}

PathResult
AStarPlanner::compute(const std::pair<double,double>& start_xy,
                      const std::pair<double,double>& goal_xy,
                      CostMode mode,
                      bool return_with_projection_lanelets)
{
  candidate_results_.clear();

  // Règle "ligne droite"
  // Règle "ligne droite"
    const double dsg = std::hypot(start_xy.first - goal_xy.first,
                                start_xy.second - goal_xy.second);
    if (dsg <= P_.direct_link_threshold_m) {
    PathResult R;
    R.success = true;
    R.total_dist_m = dsg;
    R.total_time_s = dsg / std::max(0.1, P_.direct_link_nominal_speed_mps); // <-- toujours du temps
    R.message = "direct_link";
    return R;
    }


  start_proj_ = projectOnLanelets(L_, start_xy.first, start_xy.second, P_.epsilon_endpoint_frac);
  goal_proj_  = projectOnLanelets(L_, goal_xy.first,  goal_xy.second,  P_.epsilon_endpoint_frac);

  // Cas même lanelet
  if (start_proj_.lanelet_idx >= 0 && goal_proj_.lanelet_idx >= 0) {
    auto same = solveSameLaneletDirect(mode);
    if (same.success) return same;
  }

  auto S = makeStartCandidates(start_proj_, graph_, L_, P_, mode);
  auto G = makeGoalCandidates(goal_proj_,  graph_, L_, P_, mode);

  if (S.empty() || G.empty()) {
    PathResult R; R.success = false; R.message = "no start/goal candidates"; return R;
  }

  PathResult best; best.success = false;

  for (const auto& sc : S) {
    for (const auto& gc : G) {
      auto R = runAStarCombo(sc, gc, mode);

      if (R.success) {
        // Ne PAS rajouter artificiellement les lanelets de projection si tu veux un tracé strict
        if (return_with_projection_lanelets) {
          if (sc.extra_dist_m > 0.0) prependLaneletIfMissing(R.lanelet_indices, sc.lanelet_idx);
          if (gc.extra_dist_m > 0.0) appendLaneletIfMissing(R.lanelet_indices, gc.lanelet_idx);
        }
      }
      candidate_results_.push_back(R);

      if (R.success) {
        const double a = (mode==CostMode::DISTANCE) ? R.total_dist_m : R.total_time_s;
        if (!best.success) best = R;
        else {
          const double b = (mode==CostMode::DISTANCE) ? best.total_dist_m : best.total_time_s;
          if (a < b) best = R;
        }
      }
    }
  }

  if (!best.success) best.message = "no valid A* path";
  return best;
}

} // namespace hive_route_planner
