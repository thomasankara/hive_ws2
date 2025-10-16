#pragma once
#include <vector>
#include <string>
#include <tuple>
#include <limits>
#include <cmath>

#include "hive_interface2/msg/lanelet_mini2.hpp"

namespace hive_route_planner {

enum class CostMode : int { DISTANCE = 0, TIME = 1 };

struct GraphNode {
  int id{};
  double x{0.0}, y{0.0};
};

struct GraphEdge {
  int from{-1};
  int to{-1};
  int lanelet_idx{-1};
  double length_m{0.0};
  double speed_mps{0.0};
  int nodeA{-1}; // extrémité start_point_* du lanelet
  int nodeB{-1}; // extrémité end_point_*   du lanelet
  bool forward_start_to_end{true}; // true = A->B
};

struct Graph {
  std::vector<GraphNode> nodes;
  std::vector<GraphEdge> edges;
  std::vector<std::vector<int>> adj;
  std::vector<std::pair<int,int>> lanelet_nodes; // [lanelet_idx] -> (nodeA,nodeB)
  double max_speed_mps_global{1.0};
};

struct Projection {
  int lanelet_idx{-1};
  double t{0.0};
  double px{0.0}, py{0.0};
  bool at_start{false};
  bool at_end{false};
};

enum class EndSide : int { A = 0, B = 1 };

struct CandidateEnd {
  int node{-1};
  double extra_dist_m{0.0};
  double extra_time_s{0.0};
  int lanelet_idx{-1};
  EndSide side{EndSide::A};   // <-- côté choisi (A ou B)
  bool valid{false};
};

struct Segment {
  int lanelet_idx{-1};
  bool forward{true}; // true = start->end, false = end->start
};

// infos pour les "demi-segments" (projection <-> extrémité)
struct PartialInfo {
  bool valid{false};
  int lanelet_idx{-1};
  EndSide side{EndSide::A}; // côté extrémité jointe
  double px{0.0}, py{0.0};  // point projeté
};

struct PathResult {
  bool success{false};
  std::vector<int> lanelet_indices; // compat service
  std::vector<Segment> segments;    // viz orientée
  double total_dist_m{0.0};
  double total_time_s{0.0};
  std::string message;

  // NOUVEAU: demi-segments à ajouter manuellement au début/à la fin
  PartialInfo start_partial;
  PartialInfo goal_partial;
};

class AStarPlanner {
public:
  struct Params {
    double epsilon_merge_m{0.001};           // garder très petit !
    double epsilon_endpoint_frac{1e-3};
    double fallback_speed_mps{1.0};
    double direct_link_threshold_m{10.0};
    double direct_link_nominal_speed_mps{1.5};
  };

  explicit AStarPlanner(const std::vector<hive_interface2::msg::LaneletMini2>& lanelets,
                        const Params& params);

  PathResult compute(const std::pair<double,double>& start_xy,
                     const std::pair<double,double>& goal_xy,
                     CostMode mode,
                     bool return_with_projection_lanelets);

  const Projection& start_projection() const { return start_proj_; }
  const Projection& goal_projection()  const { return goal_proj_;  }
  const std::vector<PathResult>& candidate_results() const { return candidate_results_; }
  const Graph& graph() const { return graph_; }

private:
  const std::vector<hive_interface2::msg::LaneletMini2>& L_;
  Params P_;
  Graph graph_;
  Projection start_proj_, goal_proj_;
  std::vector<PathResult> candidate_results_;

  static inline double kmh_to_mps(int kmh) { return std::max(0.0, (double)kmh) / 3.6; }

  void buildGraph();
  static Projection projectOnLanelets(const std::vector<hive_interface2::msg::LaneletMini2>& L,
                                      double px, double py,
                                      double eps_frac);

  static std::vector<CandidateEnd> makeStartCandidates(const Projection& prj,
                                                       const Graph& G,
                                                       const std::vector<hive_interface2::msg::LaneletMini2>& L,
                                                       const Params& P,
                                                       CostMode mode);

  static std::vector<CandidateEnd> makeGoalCandidates(const Projection& prj,
                                                      const Graph& G,
                                                      const std::vector<hive_interface2::msg::LaneletMini2>& L,
                                                      const Params& P,
                                                      CostMode mode);

  PathResult runAStarCombo(const CandidateEnd& start_c,
                           const CandidateEnd& goal_c,
                           CostMode mode) const;

  PathResult solveSameLaneletDirect(CostMode mode) const;

  static void appendLaneletIfMissing(std::vector<int>& ordered_lanelets, int lanelet_idx);
  static void prependLaneletIfMissing(std::vector<int>& ordered_lanelets, int lanelet_idx);

  static double edgeWeight(const GraphEdge& e, CostMode mode, double fallback_speed);
  static double heuristic(const GraphNode& n, const GraphNode& goal,
                          CostMode mode, double max_speed_mps_global);
};

} // namespace hive_route_planner
