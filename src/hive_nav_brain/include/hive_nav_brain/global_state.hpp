#pragma once
#include <mutex>
#include <string>
#include <rclcpp/rclcpp.hpp>
#include <geometry_msgs/msg/pose_stamped.hpp>
#include "hive_interface2/msg/nav_brain_command.hpp"

namespace hive_nav {

// Statuts (strictement ceux demandés)
enum class MissionStatus {
  IDLE = 0,
  READY_TO_GET_GLOBAL_PATH,
  WAITING_TO_GET_GLOBAL_PATH,
  READY_FOR_PATH
};

inline const char* to_string(MissionStatus s) {
  switch (s) {
    case MissionStatus::IDLE:                      return "idle";
    case MissionStatus::READY_TO_GET_GLOBAL_PATH:  return "ready_to_get_global_path";
    case MissionStatus::WAITING_TO_GET_GLOBAL_PATH:return "waiting_to_get_global_path";
    case MissionStatus::READY_FOR_PATH:            return "ready_for_path";
    default: return "unknown";
  }
}

// Mode de déplacement
enum class MovementMode {
  HIVE_PLANNER = 0,
  ASTAR_PLANNER = 1
};

inline const char* to_string(MovementMode m) {
  switch (m) {
    case MovementMode::HIVE_PLANNER:  return "hive_planner";
    case MovementMode::ASTAR_PLANNER: return "astar_planner";
    default: return "unknown";
  }
}

struct RobotInfo {
  std::string namespace_name;
  geometry_msgs::msg::PoseStamped pose_map; // pose dans le frame "map"
  bool has_pose = false;
};

struct MissionInfo {
  int32_t mission_id = 0;
  int32_t poi_id = 0;
  int32_t free_zone_id = 0;
  int32_t object_tracking_id = 0;
  geometry_msgs::msg::PoseStamped destination; // attendu en "map"
  MissionStatus status = MissionStatus::IDLE;
  MovementMode movement_mode = MovementMode::ASTAR_PLANNER; // <<< ajouté ici
};

class GlobalState {
public:
  void set_robot_namespace(const std::string& ns) {
    std::scoped_lock lk(m_);
    robot_.namespace_name = ns;
  }

  void set_robot_pose_map(const geometry_msgs::msg::PoseStamped& pose) {
    std::scoped_lock lk(m_);
    robot_.pose_map = pose;
    robot_.has_pose = true;
  }

  void update_from_command(const hive_interface2::msg::NavBrainCommand& cmd,
                           const std::string& dest_frame = "map")
  {
    std::scoped_lock lk(m_);
    mission_.mission_id = cmd.mission_id;
    mission_.poi_id = cmd.poi_id;
    mission_.free_zone_id = cmd.free_zone_id;
    mission_.object_tracking_id = cmd.object_tracking_id;

    mission_.destination.header.frame_id = dest_frame;
    mission_.destination.pose = cmd.destination.pose;

    mission_.status = MissionStatus::READY_TO_GET_GLOBAL_PATH;
    // mission_.movement_mode garde sa valeur courante (ou ASTAR_PLANNER par défaut)
  }

  void set_status(MissionStatus s) {
    std::scoped_lock lk(m_);
    mission_.status = s;
  }

  MissionStatus status() const {
    std::scoped_lock lk(m_);
    return mission_.status;
  }

  // --- accès au MovementMode stocké dans MissionInfo ---
  void set_movement_mode(MovementMode m) {
    std::scoped_lock lk(m_);
    mission_.movement_mode = m;
  }

  MovementMode movement_mode() const {
    std::scoped_lock lk(m_);
    return mission_.movement_mode;
  }

  MissionInfo mission() const {
    std::scoped_lock lk(m_);
    return mission_;
  }

  RobotInfo robot() const {
    std::scoped_lock lk(m_);
    return robot_;
  }

private:
  mutable std::mutex m_;
  RobotInfo  robot_;
  MissionInfo mission_;
};

} // namespace hive_nav
