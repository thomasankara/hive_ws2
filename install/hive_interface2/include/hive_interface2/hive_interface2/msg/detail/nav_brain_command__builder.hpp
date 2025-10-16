// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from hive_interface2:msg/NavBrainCommand.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "hive_interface2/msg/nav_brain_command.hpp"


#ifndef HIVE_INTERFACE2__MSG__DETAIL__NAV_BRAIN_COMMAND__BUILDER_HPP_
#define HIVE_INTERFACE2__MSG__DETAIL__NAV_BRAIN_COMMAND__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "hive_interface2/msg/detail/nav_brain_command__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace hive_interface2
{

namespace msg
{

namespace builder
{

class Init_NavBrainCommand_mission_id
{
public:
  explicit Init_NavBrainCommand_mission_id(::hive_interface2::msg::NavBrainCommand & msg)
  : msg_(msg)
  {}
  ::hive_interface2::msg::NavBrainCommand mission_id(::hive_interface2::msg::NavBrainCommand::_mission_id_type arg)
  {
    msg_.mission_id = std::move(arg);
    return std::move(msg_);
  }

private:
  ::hive_interface2::msg::NavBrainCommand msg_;
};

class Init_NavBrainCommand_object_tracking_id
{
public:
  explicit Init_NavBrainCommand_object_tracking_id(::hive_interface2::msg::NavBrainCommand & msg)
  : msg_(msg)
  {}
  Init_NavBrainCommand_mission_id object_tracking_id(::hive_interface2::msg::NavBrainCommand::_object_tracking_id_type arg)
  {
    msg_.object_tracking_id = std::move(arg);
    return Init_NavBrainCommand_mission_id(msg_);
  }

private:
  ::hive_interface2::msg::NavBrainCommand msg_;
};

class Init_NavBrainCommand_destination
{
public:
  explicit Init_NavBrainCommand_destination(::hive_interface2::msg::NavBrainCommand & msg)
  : msg_(msg)
  {}
  Init_NavBrainCommand_object_tracking_id destination(::hive_interface2::msg::NavBrainCommand::_destination_type arg)
  {
    msg_.destination = std::move(arg);
    return Init_NavBrainCommand_object_tracking_id(msg_);
  }

private:
  ::hive_interface2::msg::NavBrainCommand msg_;
};

class Init_NavBrainCommand_poi_id
{
public:
  explicit Init_NavBrainCommand_poi_id(::hive_interface2::msg::NavBrainCommand & msg)
  : msg_(msg)
  {}
  Init_NavBrainCommand_destination poi_id(::hive_interface2::msg::NavBrainCommand::_poi_id_type arg)
  {
    msg_.poi_id = std::move(arg);
    return Init_NavBrainCommand_destination(msg_);
  }

private:
  ::hive_interface2::msg::NavBrainCommand msg_;
};

class Init_NavBrainCommand_free_zone_id
{
public:
  Init_NavBrainCommand_free_zone_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_NavBrainCommand_poi_id free_zone_id(::hive_interface2::msg::NavBrainCommand::_free_zone_id_type arg)
  {
    msg_.free_zone_id = std::move(arg);
    return Init_NavBrainCommand_poi_id(msg_);
  }

private:
  ::hive_interface2::msg::NavBrainCommand msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::hive_interface2::msg::NavBrainCommand>()
{
  return hive_interface2::msg::builder::Init_NavBrainCommand_free_zone_id();
}

}  // namespace hive_interface2

#endif  // HIVE_INTERFACE2__MSG__DETAIL__NAV_BRAIN_COMMAND__BUILDER_HPP_
