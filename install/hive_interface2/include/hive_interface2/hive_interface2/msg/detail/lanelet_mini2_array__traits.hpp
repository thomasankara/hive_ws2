// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from hive_interface2:msg/LaneletMini2Array.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "hive_interface2/msg/lanelet_mini2_array.hpp"


#ifndef HIVE_INTERFACE2__MSG__DETAIL__LANELET_MINI2_ARRAY__TRAITS_HPP_
#define HIVE_INTERFACE2__MSG__DETAIL__LANELET_MINI2_ARRAY__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "hive_interface2/msg/detail/lanelet_mini2_array__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'lanelets'
#include "hive_interface2/msg/detail/lanelet_mini2__traits.hpp"

namespace hive_interface2
{

namespace msg
{

inline void to_flow_style_yaml(
  const LaneletMini2Array & msg,
  std::ostream & out)
{
  out << "{";
  // member: lanelets
  {
    if (msg.lanelets.size() == 0) {
      out << "lanelets: []";
    } else {
      out << "lanelets: [";
      size_t pending_items = msg.lanelets.size();
      for (auto item : msg.lanelets) {
        to_flow_style_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const LaneletMini2Array & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: lanelets
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.lanelets.size() == 0) {
      out << "lanelets: []\n";
    } else {
      out << "lanelets:\n";
      for (auto item : msg.lanelets) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "-\n";
        to_block_style_yaml(item, out, indentation + 2);
      }
    }
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const LaneletMini2Array & msg, bool use_flow_style = false)
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
  const hive_interface2::msg::LaneletMini2Array & msg,
  std::ostream & out, size_t indentation = 0)
{
  hive_interface2::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use hive_interface2::msg::to_yaml() instead")]]
inline std::string to_yaml(const hive_interface2::msg::LaneletMini2Array & msg)
{
  return hive_interface2::msg::to_yaml(msg);
}

template<>
inline const char * data_type<hive_interface2::msg::LaneletMini2Array>()
{
  return "hive_interface2::msg::LaneletMini2Array";
}

template<>
inline const char * name<hive_interface2::msg::LaneletMini2Array>()
{
  return "hive_interface2/msg/LaneletMini2Array";
}

template<>
struct has_fixed_size<hive_interface2::msg::LaneletMini2Array>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<hive_interface2::msg::LaneletMini2Array>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<hive_interface2::msg::LaneletMini2Array>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // HIVE_INTERFACE2__MSG__DETAIL__LANELET_MINI2_ARRAY__TRAITS_HPP_
