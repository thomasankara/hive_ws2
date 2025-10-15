#include "hive_route_planner/route_utils.hpp"

#include <std_msgs/msg/color_rgba.hpp>
#include <visualization_msgs/msg/marker.hpp>
#include <builtin_interfaces/msg/time.hpp>
#include <builtin_interfaces/msg/duration.hpp>

namespace hive_route_planner {

void RouteDataStore::clear() {
  data_.clear();
}

void RouteDataStore::setFromMsg(const hive_interface2::msg::LaneletMini2Array &msg) {
  data_.assign(msg.lanelets.begin(), msg.lanelets.end());
}

UniqueIdsSummary RouteDataStore::summarize() const {
  UniqueIdsSummary s;
  for (const auto &ll : data_) {
    s.enterprises.insert(ll.enterprise_full_id_str);
    s.deployments.insert(ll.deployment_full_id_str);
    s.sessions.insert(ll.slam_session_full_id_str);
  }
  return s;
}

visualization_msgs::msg::MarkerArray RouteDataStore::buildMarkerArray(
    const std::string &frame_id,
    const std::string &ns,
    float line_width,
    float point_scale) const
{
  visualization_msgs::msg::MarkerArray arr;

  // stamp = {0,0} et lifetime = {0,0} => affichage “infini”
  builtin_interfaces::msg::Time zero_time;
  zero_time.sec = 0;
  zero_time.nanosec = 0;

  builtin_interfaces::msg::Duration zero_duration;
  zero_duration.sec = 0;
  zero_duration.nanosec = 0;

  // Couleurs
  std_msgs::msg::ColorRGBA col_line;
  col_line.r = 0.1f; col_line.g = 0.8f; col_line.b = 0.2f; col_line.a = 1.0f;

  std_msgs::msg::ColorRGBA col_point;
  col_point.r = 0.2f; col_point.g = 0.6f; col_point.b = 1.0f; col_point.a = 1.0f;

  // 1) Lignes
  visualization_msgs::msg::Marker lines;
  lines.header.frame_id = frame_id;
  lines.header.stamp = zero_time;
  lines.ns = ns + "_lines";
  lines.id = 0;
  lines.type = visualization_msgs::msg::Marker::LINE_LIST;
  lines.action = visualization_msgs::msg::Marker::ADD;
  lines.scale.x = line_width;
  lines.color = col_line;
  lines.lifetime = zero_duration;

  // 2) Points
  visualization_msgs::msg::Marker pts;
  pts.header.frame_id = frame_id;
  pts.header.stamp = zero_time;
  pts.ns = ns + "_points";
  pts.id = 1;
  pts.type = visualization_msgs::msg::Marker::POINTS;
  pts.action = visualization_msgs::msg::Marker::ADD;
  pts.scale.x = point_scale;
  pts.scale.y = point_scale;
  pts.color = col_point;
  pts.lifetime = zero_duration;

  auto mkPoint = [](float x, float y, float z){
    geometry_msgs::msg::Point p;
    p.x = x; p.y = y; p.z = z;
    return p;
  };

  for (const auto &ll : data_) {
    lines.points.push_back(mkPoint(ll.start_point_x, ll.start_point_y, ll.start_point_z));
    lines.points.push_back(mkPoint(ll.end_point_x,   ll.end_point_y,   ll.end_point_z));

    pts.points.push_back(mkPoint(ll.start_point_x, ll.start_point_y, ll.start_point_z));
    pts.points.push_back(mkPoint(ll.end_point_x,   ll.end_point_y,   ll.end_point_z));
  }

  arr.markers.push_back(lines);
  arr.markers.push_back(pts);
  return arr;
}

} // namespace hive_route_planner
