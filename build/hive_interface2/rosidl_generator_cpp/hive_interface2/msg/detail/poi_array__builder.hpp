// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from hive_interface2:msg/PoiArray.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "hive_interface2/msg/poi_array.hpp"


#ifndef HIVE_INTERFACE2__MSG__DETAIL__POI_ARRAY__BUILDER_HPP_
#define HIVE_INTERFACE2__MSG__DETAIL__POI_ARRAY__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "hive_interface2/msg/detail/poi_array__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace hive_interface2
{

namespace msg
{

namespace builder
{

class Init_PoiArray_items
{
public:
  Init_PoiArray_items()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::hive_interface2::msg::PoiArray items(::hive_interface2::msg::PoiArray::_items_type arg)
  {
    msg_.items = std::move(arg);
    return std::move(msg_);
  }

private:
  ::hive_interface2::msg::PoiArray msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::hive_interface2::msg::PoiArray>()
{
  return hive_interface2::msg::builder::Init_PoiArray_items();
}

}  // namespace hive_interface2

#endif  // HIVE_INTERFACE2__MSG__DETAIL__POI_ARRAY__BUILDER_HPP_
