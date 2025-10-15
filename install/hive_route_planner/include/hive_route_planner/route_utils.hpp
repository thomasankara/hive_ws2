#pragma once
#include <vector>
#include <string>
#include <unordered_set>

#include <visualization_msgs/msg/marker_array.hpp>
#include <geometry_msgs/msg/point.hpp>

#include "hive_interface2/msg/lanelet_mini2.hpp"
#include "hive_interface2/msg/lanelet_mini2_array.hpp"

namespace hive_route_planner {

struct UniqueIdsSummary {
  std::unordered_set<std::string> enterprises;
  std::unordered_set<std::string> deployments;
  std::unordered_set<std::string> sessions;
};

class RouteDataStore {
public:
  void clear();
  void setFromMsg(const hive_interface2::msg::LaneletMini2Array &msg);
  const std::vector<hive_interface2::msg::LaneletMini2>& data() const { return data_; }

  UniqueIdsSummary summarize() const;

  // Construit un MarkerArray pour RViz
  visualization_msgs::msg::MarkerArray buildMarkerArray(
      const std::string &frame_id = "map",
      const std::string &ns = "route_graph",
      float line_width = 0.10f,
      float point_scale = 0.15f) const;

private:
  std::vector<hive_interface2::msg::LaneletMini2> data_;
};

} // namespace hive_route_planner
