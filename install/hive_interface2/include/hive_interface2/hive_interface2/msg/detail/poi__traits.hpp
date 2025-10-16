// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from hive_interface2:msg/Poi.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "hive_interface2/msg/poi.hpp"


#ifndef HIVE_INTERFACE2__MSG__DETAIL__POI__TRAITS_HPP_
#define HIVE_INTERFACE2__MSG__DETAIL__POI__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "hive_interface2/msg/detail/poi__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace hive_interface2
{

namespace msg
{

inline void to_flow_style_yaml(
  const Poi & msg,
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

  // member: is_in_free_zone
  {
    out << "is_in_free_zone: ";
    rosidl_generator_traits::value_to_yaml(msg.is_in_free_zone, out);
    out << ", ";
  }

  // member: poi_full_id_str
  {
    out << "poi_full_id_str: ";
    rosidl_generator_traits::value_to_yaml(msg.poi_full_id_str, out);
    out << ", ";
  }

  // member: poi_id
  {
    out << "poi_id: ";
    rosidl_generator_traits::value_to_yaml(msg.poi_id, out);
    out << ", ";
  }

  // member: x
  {
    out << "x: ";
    rosidl_generator_traits::value_to_yaml(msg.x, out);
    out << ", ";
  }

  // member: y
  {
    out << "y: ";
    rosidl_generator_traits::value_to_yaml(msg.y, out);
    out << ", ";
  }

  // member: z
  {
    out << "z: ";
    rosidl_generator_traits::value_to_yaml(msg.z, out);
    out << ", ";
  }

  // member: yaw
  {
    out << "yaw: ";
    rosidl_generator_traits::value_to_yaml(msg.yaw, out);
    out << ", ";
  }

  // member: parking_mode
  {
    out << "parking_mode: ";
    rosidl_generator_traits::value_to_yaml(msg.parking_mode, out);
    out << ", ";
  }

  // member: is_available
  {
    out << "is_available: ";
    rosidl_generator_traits::value_to_yaml(msg.is_available, out);
    out << ", ";
  }

  // member: charging_mode
  {
    out << "charging_mode: ";
    rosidl_generator_traits::value_to_yaml(msg.charging_mode, out);
    out << ", ";
  }

  // member: is_long_wait_zone
  {
    out << "is_long_wait_zone: ";
    rosidl_generator_traits::value_to_yaml(msg.is_long_wait_zone, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const Poi & msg,
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

  // member: is_in_free_zone
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "is_in_free_zone: ";
    rosidl_generator_traits::value_to_yaml(msg.is_in_free_zone, out);
    out << "\n";
  }

  // member: poi_full_id_str
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "poi_full_id_str: ";
    rosidl_generator_traits::value_to_yaml(msg.poi_full_id_str, out);
    out << "\n";
  }

  // member: poi_id
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "poi_id: ";
    rosidl_generator_traits::value_to_yaml(msg.poi_id, out);
    out << "\n";
  }

  // member: x
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "x: ";
    rosidl_generator_traits::value_to_yaml(msg.x, out);
    out << "\n";
  }

  // member: y
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "y: ";
    rosidl_generator_traits::value_to_yaml(msg.y, out);
    out << "\n";
  }

  // member: z
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "z: ";
    rosidl_generator_traits::value_to_yaml(msg.z, out);
    out << "\n";
  }

  // member: yaw
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "yaw: ";
    rosidl_generator_traits::value_to_yaml(msg.yaw, out);
    out << "\n";
  }

  // member: parking_mode
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "parking_mode: ";
    rosidl_generator_traits::value_to_yaml(msg.parking_mode, out);
    out << "\n";
  }

  // member: is_available
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "is_available: ";
    rosidl_generator_traits::value_to_yaml(msg.is_available, out);
    out << "\n";
  }

  // member: charging_mode
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "charging_mode: ";
    rosidl_generator_traits::value_to_yaml(msg.charging_mode, out);
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
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const Poi & msg, bool use_flow_style = false)
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
  const hive_interface2::msg::Poi & msg,
  std::ostream & out, size_t indentation = 0)
{
  hive_interface2::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use hive_interface2::msg::to_yaml() instead")]]
inline std::string to_yaml(const hive_interface2::msg::Poi & msg)
{
  return hive_interface2::msg::to_yaml(msg);
}

template<>
inline const char * data_type<hive_interface2::msg::Poi>()
{
  return "hive_interface2::msg::Poi";
}

template<>
inline const char * name<hive_interface2::msg::Poi>()
{
  return "hive_interface2/msg/Poi";
}

template<>
struct has_fixed_size<hive_interface2::msg::Poi>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<hive_interface2::msg::Poi>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<hive_interface2::msg::Poi>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // HIVE_INTERFACE2__MSG__DETAIL__POI__TRAITS_HPP_
