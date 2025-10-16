// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from hive_interface2:msg/FreeZone.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "hive_interface2/msg/free_zone.hpp"


#ifndef HIVE_INTERFACE2__MSG__DETAIL__FREE_ZONE__TRAITS_HPP_
#define HIVE_INTERFACE2__MSG__DETAIL__FREE_ZONE__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "hive_interface2/msg/detail/free_zone__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace hive_interface2
{

namespace msg
{

inline void to_flow_style_yaml(
  const FreeZone & msg,
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

  // member: free_zone_full_id_str
  {
    out << "free_zone_full_id_str: ";
    rosidl_generator_traits::value_to_yaml(msg.free_zone_full_id_str, out);
    out << ", ";
  }

  // member: free_zone_id
  {
    out << "free_zone_id: ";
    rosidl_generator_traits::value_to_yaml(msg.free_zone_id, out);
    out << ", ";
  }

  // member: is_parking_available
  {
    out << "is_parking_available: ";
    rosidl_generator_traits::value_to_yaml(msg.is_parking_available, out);
    out << ", ";
  }

  // member: is_offpoi_parking_allowed
  {
    out << "is_offpoi_parking_allowed: ";
    rosidl_generator_traits::value_to_yaml(msg.is_offpoi_parking_allowed, out);
    out << ", ";
  }

  // member: is_long_wait_zone
  {
    out << "is_long_wait_zone: ";
    rosidl_generator_traits::value_to_yaml(msg.is_long_wait_zone, out);
    out << ", ";
  }

  // member: zone_polygon_points_json
  {
    out << "zone_polygon_points_json: ";
    rosidl_generator_traits::value_to_yaml(msg.zone_polygon_points_json, out);
    out << ", ";
  }

  // member: max_speed
  {
    out << "max_speed: ";
    rosidl_generator_traits::value_to_yaml(msg.max_speed, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const FreeZone & msg,
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

  // member: free_zone_full_id_str
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "free_zone_full_id_str: ";
    rosidl_generator_traits::value_to_yaml(msg.free_zone_full_id_str, out);
    out << "\n";
  }

  // member: free_zone_id
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "free_zone_id: ";
    rosidl_generator_traits::value_to_yaml(msg.free_zone_id, out);
    out << "\n";
  }

  // member: is_parking_available
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "is_parking_available: ";
    rosidl_generator_traits::value_to_yaml(msg.is_parking_available, out);
    out << "\n";
  }

  // member: is_offpoi_parking_allowed
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "is_offpoi_parking_allowed: ";
    rosidl_generator_traits::value_to_yaml(msg.is_offpoi_parking_allowed, out);
    out << "\n";
  }

  // member: is_long_wait_zone
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "is_long_wait_zone: ";
    rosidl_generator_traits::value_to_yaml(msg.is_long_wait_zone, out);
    out << "\n";
  }

  // member: zone_polygon_points_json
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "zone_polygon_points_json: ";
    rosidl_generator_traits::value_to_yaml(msg.zone_polygon_points_json, out);
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
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const FreeZone & msg, bool use_flow_style = false)
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
  const hive_interface2::msg::FreeZone & msg,
  std::ostream & out, size_t indentation = 0)
{
  hive_interface2::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use hive_interface2::msg::to_yaml() instead")]]
inline std::string to_yaml(const hive_interface2::msg::FreeZone & msg)
{
  return hive_interface2::msg::to_yaml(msg);
}

template<>
inline const char * data_type<hive_interface2::msg::FreeZone>()
{
  return "hive_interface2::msg::FreeZone";
}

template<>
inline const char * name<hive_interface2::msg::FreeZone>()
{
  return "hive_interface2/msg/FreeZone";
}

template<>
struct has_fixed_size<hive_interface2::msg::FreeZone>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<hive_interface2::msg::FreeZone>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<hive_interface2::msg::FreeZone>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // HIVE_INTERFACE2__MSG__DETAIL__FREE_ZONE__TRAITS_HPP_
