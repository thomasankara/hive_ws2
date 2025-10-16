// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from hive_interface2:msg/NavBrainCommand.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "hive_interface2/msg/nav_brain_command.hpp"


#ifndef HIVE_INTERFACE2__MSG__DETAIL__NAV_BRAIN_COMMAND__TRAITS_HPP_
#define HIVE_INTERFACE2__MSG__DETAIL__NAV_BRAIN_COMMAND__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "hive_interface2/msg/detail/nav_brain_command__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'destination'
#include "geometry_msgs/msg/detail/pose_stamped__traits.hpp"

namespace hive_interface2
{

namespace msg
{

inline void to_flow_style_yaml(
  const NavBrainCommand & msg,
  std::ostream & out)
{
  out << "{";
  // member: free_zone_id
  {
    out << "free_zone_id: ";
    rosidl_generator_traits::value_to_yaml(msg.free_zone_id, out);
    out << ", ";
  }

  // member: poi_id
  {
    out << "poi_id: ";
    rosidl_generator_traits::value_to_yaml(msg.poi_id, out);
    out << ", ";
  }

  // member: destination
  {
    out << "destination: ";
    to_flow_style_yaml(msg.destination, out);
    out << ", ";
  }

  // member: object_tracking_id
  {
    out << "object_tracking_id: ";
    rosidl_generator_traits::value_to_yaml(msg.object_tracking_id, out);
    out << ", ";
  }

  // member: mission_id
  {
    out << "mission_id: ";
    rosidl_generator_traits::value_to_yaml(msg.mission_id, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const NavBrainCommand & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: free_zone_id
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "free_zone_id: ";
    rosidl_generator_traits::value_to_yaml(msg.free_zone_id, out);
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

  // member: destination
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "destination:\n";
    to_block_style_yaml(msg.destination, out, indentation + 2);
  }

  // member: object_tracking_id
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "object_tracking_id: ";
    rosidl_generator_traits::value_to_yaml(msg.object_tracking_id, out);
    out << "\n";
  }

  // member: mission_id
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "mission_id: ";
    rosidl_generator_traits::value_to_yaml(msg.mission_id, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const NavBrainCommand & msg, bool use_flow_style = false)
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
  const hive_interface2::msg::NavBrainCommand & msg,
  std::ostream & out, size_t indentation = 0)
{
  hive_interface2::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use hive_interface2::msg::to_yaml() instead")]]
inline std::string to_yaml(const hive_interface2::msg::NavBrainCommand & msg)
{
  return hive_interface2::msg::to_yaml(msg);
}

template<>
inline const char * data_type<hive_interface2::msg::NavBrainCommand>()
{
  return "hive_interface2::msg::NavBrainCommand";
}

template<>
inline const char * name<hive_interface2::msg::NavBrainCommand>()
{
  return "hive_interface2/msg/NavBrainCommand";
}

template<>
struct has_fixed_size<hive_interface2::msg::NavBrainCommand>
  : std::integral_constant<bool, has_fixed_size<geometry_msgs::msg::PoseStamped>::value> {};

template<>
struct has_bounded_size<hive_interface2::msg::NavBrainCommand>
  : std::integral_constant<bool, has_bounded_size<geometry_msgs::msg::PoseStamped>::value> {};

template<>
struct is_message<hive_interface2::msg::NavBrainCommand>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // HIVE_INTERFACE2__MSG__DETAIL__NAV_BRAIN_COMMAND__TRAITS_HPP_
