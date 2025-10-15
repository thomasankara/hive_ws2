// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from hive_interface2:msg/LaneletMini2.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "hive_interface2/msg/lanelet_mini2.hpp"


#ifndef HIVE_INTERFACE2__MSG__DETAIL__LANELET_MINI2__TRAITS_HPP_
#define HIVE_INTERFACE2__MSG__DETAIL__LANELET_MINI2__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "hive_interface2/msg/detail/lanelet_mini2__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace hive_interface2
{

namespace msg
{

inline void to_flow_style_yaml(
  const LaneletMini2 & msg,
  std::ostream & out)
{
  out << "{";
  // member: enterprise_full_id_str
  {
    out << "enterprise_full_id_str: ";
    rosidl_generator_traits::value_to_yaml(msg.enterprise_full_id_str, out);
    out << ", ";
  }

  // member: deployment_full_id_str
  {
    out << "deployment_full_id_str: ";
    rosidl_generator_traits::value_to_yaml(msg.deployment_full_id_str, out);
    out << ", ";
  }

  // member: slam_session_full_id_str
  {
    out << "slam_session_full_id_str: ";
    rosidl_generator_traits::value_to_yaml(msg.slam_session_full_id_str, out);
    out << ", ";
  }

  // member: lanelet_mini_id
  {
    out << "lanelet_mini_id: ";
    rosidl_generator_traits::value_to_yaml(msg.lanelet_mini_id, out);
    out << ", ";
  }

  // member: start_point_x
  {
    out << "start_point_x: ";
    rosidl_generator_traits::value_to_yaml(msg.start_point_x, out);
    out << ", ";
  }

  // member: start_point_y
  {
    out << "start_point_y: ";
    rosidl_generator_traits::value_to_yaml(msg.start_point_y, out);
    out << ", ";
  }

  // member: start_point_z
  {
    out << "start_point_z: ";
    rosidl_generator_traits::value_to_yaml(msg.start_point_z, out);
    out << ", ";
  }

  // member: end_point_x
  {
    out << "end_point_x: ";
    rosidl_generator_traits::value_to_yaml(msg.end_point_x, out);
    out << ", ";
  }

  // member: end_point_y
  {
    out << "end_point_y: ";
    rosidl_generator_traits::value_to_yaml(msg.end_point_y, out);
    out << ", ";
  }

  // member: end_point_z
  {
    out << "end_point_z: ";
    rosidl_generator_traits::value_to_yaml(msg.end_point_z, out);
    out << ", ";
  }

  // member: navigation_direction
  {
    out << "navigation_direction: ";
    rosidl_generator_traits::value_to_yaml(msg.navigation_direction, out);
    out << ", ";
  }

  // member: border_mode
  {
    out << "border_mode: ";
    rosidl_generator_traits::value_to_yaml(msg.border_mode, out);
    out << ", ";
  }

  // member: u_turn_allowed
  {
    out << "u_turn_allowed: ";
    rosidl_generator_traits::value_to_yaml(msg.u_turn_allowed, out);
    out << ", ";
  }

  // member: slope_alert
  {
    out << "slope_alert: ";
    rosidl_generator_traits::value_to_yaml(msg.slope_alert, out);
    out << ", ";
  }

  // member: vegetation_alert
  {
    out << "vegetation_alert: ";
    rosidl_generator_traits::value_to_yaml(msg.vegetation_alert, out);
    out << ", ";
  }

  // member: offroad_alert
  {
    out << "offroad_alert: ";
    rosidl_generator_traits::value_to_yaml(msg.offroad_alert, out);
    out << ", ";
  }

  // member: configuration_group_id_str
  {
    out << "configuration_group_id_str: ";
    rosidl_generator_traits::value_to_yaml(msg.configuration_group_id_str, out);
    out << ", ";
  }

  // member: road_group_id_str
  {
    out << "road_group_id_str: ";
    rosidl_generator_traits::value_to_yaml(msg.road_group_id_str, out);
    out << ", ";
  }

  // member: max_speed
  {
    out << "max_speed: ";
    rosidl_generator_traits::value_to_yaml(msg.max_speed, out);
    out << ", ";
  }

  // member: width
  {
    out << "width: ";
    rosidl_generator_traits::value_to_yaml(msg.width, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const LaneletMini2 & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: enterprise_full_id_str
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "enterprise_full_id_str: ";
    rosidl_generator_traits::value_to_yaml(msg.enterprise_full_id_str, out);
    out << "\n";
  }

  // member: deployment_full_id_str
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "deployment_full_id_str: ";
    rosidl_generator_traits::value_to_yaml(msg.deployment_full_id_str, out);
    out << "\n";
  }

  // member: slam_session_full_id_str
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "slam_session_full_id_str: ";
    rosidl_generator_traits::value_to_yaml(msg.slam_session_full_id_str, out);
    out << "\n";
  }

  // member: lanelet_mini_id
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "lanelet_mini_id: ";
    rosidl_generator_traits::value_to_yaml(msg.lanelet_mini_id, out);
    out << "\n";
  }

  // member: start_point_x
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "start_point_x: ";
    rosidl_generator_traits::value_to_yaml(msg.start_point_x, out);
    out << "\n";
  }

  // member: start_point_y
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "start_point_y: ";
    rosidl_generator_traits::value_to_yaml(msg.start_point_y, out);
    out << "\n";
  }

  // member: start_point_z
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "start_point_z: ";
    rosidl_generator_traits::value_to_yaml(msg.start_point_z, out);
    out << "\n";
  }

  // member: end_point_x
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "end_point_x: ";
    rosidl_generator_traits::value_to_yaml(msg.end_point_x, out);
    out << "\n";
  }

  // member: end_point_y
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "end_point_y: ";
    rosidl_generator_traits::value_to_yaml(msg.end_point_y, out);
    out << "\n";
  }

  // member: end_point_z
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "end_point_z: ";
    rosidl_generator_traits::value_to_yaml(msg.end_point_z, out);
    out << "\n";
  }

  // member: navigation_direction
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "navigation_direction: ";
    rosidl_generator_traits::value_to_yaml(msg.navigation_direction, out);
    out << "\n";
  }

  // member: border_mode
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "border_mode: ";
    rosidl_generator_traits::value_to_yaml(msg.border_mode, out);
    out << "\n";
  }

  // member: u_turn_allowed
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "u_turn_allowed: ";
    rosidl_generator_traits::value_to_yaml(msg.u_turn_allowed, out);
    out << "\n";
  }

  // member: slope_alert
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "slope_alert: ";
    rosidl_generator_traits::value_to_yaml(msg.slope_alert, out);
    out << "\n";
  }

  // member: vegetation_alert
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "vegetation_alert: ";
    rosidl_generator_traits::value_to_yaml(msg.vegetation_alert, out);
    out << "\n";
  }

  // member: offroad_alert
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "offroad_alert: ";
    rosidl_generator_traits::value_to_yaml(msg.offroad_alert, out);
    out << "\n";
  }

  // member: configuration_group_id_str
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "configuration_group_id_str: ";
    rosidl_generator_traits::value_to_yaml(msg.configuration_group_id_str, out);
    out << "\n";
  }

  // member: road_group_id_str
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "road_group_id_str: ";
    rosidl_generator_traits::value_to_yaml(msg.road_group_id_str, out);
    out << "\n";
  }

  // member: max_speed
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "max_speed: ";
    rosidl_generator_traits::value_to_yaml(msg.max_speed, out);
    out << "\n";
  }

  // member: width
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "width: ";
    rosidl_generator_traits::value_to_yaml(msg.width, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const LaneletMini2 & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace msg

}  // namespace hive_interface2

namespace rosidl_generator_traits
{

[[deprecated("use hive_interface2::msg::to_block_style_yaml() instead")]]
inline void to_yaml(
  const hive_interface2::msg::LaneletMini2 & msg,
  std::ostream & out, size_t indentation = 0)
{
  hive_interface2::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use hive_interface2::msg::to_yaml() instead")]]
inline std::string to_yaml(const hive_interface2::msg::LaneletMini2 & msg)
{
  return hive_interface2::msg::to_yaml(msg);
}

template<>
inline const char * data_type<hive_interface2::msg::LaneletMini2>()
{
  return "hive_interface2::msg::LaneletMini2";
}

template<>
inline const char * name<hive_interface2::msg::LaneletMini2>()
{
  return "hive_interface2/msg/LaneletMini2";
}

template<>
struct has_fixed_size<hive_interface2::msg::LaneletMini2>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<hive_interface2::msg::LaneletMini2>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<hive_interface2::msg::LaneletMini2>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // HIVE_INTERFACE2__MSG__DETAIL__LANELET_MINI2__TRAITS_HPP_
