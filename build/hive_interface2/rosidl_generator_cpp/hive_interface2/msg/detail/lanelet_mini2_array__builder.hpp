// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from hive_interface2:msg/LaneletMini2Array.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "hive_interface2/msg/lanelet_mini2_array.hpp"


#ifndef HIVE_INTERFACE2__MSG__DETAIL__LANELET_MINI2_ARRAY__BUILDER_HPP_
#define HIVE_INTERFACE2__MSG__DETAIL__LANELET_MINI2_ARRAY__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "hive_interface2/msg/detail/lanelet_mini2_array__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace hive_interface2
{

namespace msg
{

namespace builder
{

class Init_LaneletMini2Array_lanelets
{
public:
  Init_LaneletMini2Array_lanelets()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::hive_interface2::msg::LaneletMini2Array lanelets(::hive_interface2::msg::LaneletMini2Array::_lanelets_type arg)
  {
    msg_.lanelets = std::move(arg);
    return std::move(msg_);
  }

private:
  ::hive_interface2::msg::LaneletMini2Array msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::hive_interface2::msg::LaneletMini2Array>()
{
  return hive_interface2::msg::builder::Init_LaneletMini2Array_lanelets();
}

}  // namespace hive_interface2

#endif  // HIVE_INTERFACE2__MSG__DETAIL__LANELET_MINI2_ARRAY__BUILDER_HPP_
