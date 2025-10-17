#include "hive_nav_brain/hive_planner.hpp"
#include <cmath>
#include <algorithm>
#include <rclcpp/rclcpp.hpp>

namespace hive_planner {

static inline double seg_len(double ax, double ay, double bx, double by) {
  const double dx = bx - ax, dy = by - ay; return std::sqrt(dx*dx + dy*dy);
}
static inline void yaw_to_quat(double yaw, geometry_msgs::msg::Quaternion &q) {
  q.x = 0.0; q.y = 0.0; q.z = std::sin(yaw*0.5); q.w = std::cos(yaw*0.5);
}

nav_msgs::msg::Path build_nav2_path(
  const std::vector<hive_interface2::msg::LaneletMini2>& lanelets,
  const std::string& frame_id,
  double step_m,
  int window_half,
  PathBuildStats& out_stats)
{
  out_stats = {};
  out_stats.lanelet_count = lanelets.size();
  out_stats.step_m = step_m;
  out_stats.window_half = window_half;

  nav_msgs::msg::Path path;
  path.header.frame_id = frame_id;
//   path.header.stamp = rclcpp::Time(0);

  if (lanelets.empty() || step_m <= 0.0) return path;

  // 1) ÉCHANTILLONNAGE fin entre start->end de chaque lanelet
  std::vector<std::pair<double,double>> pts;
  pts.reserve(1000);
  for (const auto &ll : lanelets) {
    const double ax = ll.start_point_x, ay = ll.start_point_y;
    const double bx = ll.end_point_x,   by = ll.end_point_y;
    const double L = seg_len(ax, ay, bx, by);
    if (L <= 1e-12) continue;

    const int n = std::max(1, static_cast<int>(std::floor(L / step_m)));
    for (int i = 0; i < n; ++i) {
      const double t = static_cast<double>(i) / static_cast<double>(n);
      const double x = ax + t*(bx - ax);
      const double y = ay + t*(by - ay);
      // éviter doublons exacts consécutifs
      if (!pts.empty()) {
        auto [px,py] = pts.back();
        if (std::hypot(x - px, y - py) < 1e-9) continue;
      }
      pts.emplace_back(x,y);
    }
  }
  // Ajouter dernier point de la dernière arête pour fermeture
  if (!lanelets.empty()) {
    const auto &last = lanelets.back();
    pts.emplace_back(last.end_point_x, last.end_point_y);
  }
  out_stats.raw_points = pts.size();

  if (pts.size() < 2) return path;

  // 2) LISSAGE moyenne glissante ±window_half
  const int N = static_cast<int>(pts.size());
  std::vector<std::pair<double,double>> smoothed(N);
  for (int i = 0; i < N; ++i) {
    const int a = std::max(0, i - window_half);
    const int b = std::min(N - 1, i + window_half);
    double sx = 0.0, sy = 0.0; int cnt = 0;
    for (int k = a; k <= b; ++k) { sx += pts[k].first; sy += pts[k].second; ++cnt; }
    smoothed[i].first = sx / cnt; smoothed[i].second = sy / cnt;
  }
  out_stats.smoothed_points = smoothed.size();

  // 3) ORIENTATION via direction vers i+window_half (ou vers fin)
  path.poses.resize(N);
  for (int i = 0; i < N; ++i) {
    const auto [x,y] = smoothed[i];
    int j = std::min(N - 1, i + window_half);
    if (j == i) j = std::min(N - 1, i + 1); // fallback
    const double dx = smoothed[j].first  - x;
    const double dy = smoothed[j].second - y;
    const double yaw = std::atan2(dy, dx);

    auto &ps = path.poses[i];
    ps.header.frame_id = frame_id;
    ps.pose.position.x = x; ps.pose.position.y = y; ps.pose.position.z = 0.0;
    yaw_to_quat(yaw, ps.pose.orientation);
  }

  return path;
}

} // namespace hive_planner
