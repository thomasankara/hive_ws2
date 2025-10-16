// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from hive_interface2:msg/FreeZone.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "hive_interface2/msg/free_zone.hpp"


#ifndef HIVE_INTERFACE2__MSG__DETAIL__FREE_ZONE__BUILDER_HPP_
#define HIVE_INTERFACE2__MSG__DETAIL__FREE_ZONE__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "hive_interface2/msg/detail/free_zone__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace hive_interface2
{

namespace msg
{

namespace builder
{

class Init_FreeZone_max_speed
{
public:
  explicit Init_FreeZone_max_speed(::hive_interface2::msg::FreeZone & msg)
  : msg_(msg)
  {}
  ::hive_interface2::msg::FreeZone max_speed(::hive_interface2::msg::FreeZone::_max_speed_type arg)
  {
    msg_.max_speed = std::move(arg);
    return std::move(msg_);
  }

private:
  ::hive_interface2::msg::FreeZone msg_;
};

class Init_FreeZone_zone_polygon_points_json
{
public:
  explicit Init_FreeZone_zone_polygon_points_json(::hive_interface2::msg::FreeZone & msg)
  : msg_(msg)
  {}
  Init_FreeZone_max_speed zone_polygon_points_json(::hive_interface2::msg::FreeZone::_zone_polygon_points_json_type arg)
  {
    msg_.zone_polygon_points_json = std::move(arg);
    return Init_FreeZone_max_speed(msg_);
  }

private:
  ::hive_interface2::msg::FreeZone msg_;
};

class Init_FreeZone_is_long_wait_zone
{
public:
  explicit Init_FreeZone_is_long_wait_zone(::hive_interface2::msg::FreeZone & msg)
  : msg_(msg)
  {}
  Init_FreeZone_zone_polygon_points_json is_long_wait_zone(::hive_interface2::msg::FreeZone::_is_long_wait_zone_type arg)
  {
    msg_.is_long_wait_zone = std::move(arg);
    return Init_FreeZone_zone_polygon_points_json(msg_);
  }

private:
  ::hive_interface2::msg::FreeZone msg_;
};

class Init_FreeZone_is_offpoi_parking_allowed
{
public:
  explicit Init_FreeZone_is_offpoi_parking_allowed(::hive_interface2::msg::FreeZone & msg)
  : msg_(msg)
  {}
  Init_FreeZone_is_long_wait_zone is_offpoi_parking_allowed(::hive_interface2::msg::FreeZone::_is_offpoi_parking_allowed_type arg)
  {
    msg_.is_offpoi_parking_allowed = std::move(arg);
    return Init_FreeZone_is_long_wait_zone(msg_);
  }

private:
  ::hive_interface2::msg::FreeZone msg_;
};

class Init_FreeZone_is_parking_available
{
public:
  explicit Init_FreeZone_is_parking_available(::hive_interface2::msg::FreeZone & msg)
  : msg_(msg)
  {}
  Init_FreeZone_is_offpoi_parking_allowed is_parking_available(::hive_interface2::msg::FreeZone::_is_parking_available_type arg)
  {
    msg_.is_parking_available = std::move(arg);
    return Init_FreeZone_is_offpoi_parking_allowed(msg_);
  }

private:
  ::hive_interface2::msg::FreeZone msg_;
};

class Init_FreeZone_free_zone_id
{
public:
  explicit Init_FreeZone_free_zone_id(::hive_interface2::msg::FreeZone & msg)
  : msg_(msg)
  {}
  Init_FreeZone_is_parking_available free_zone_id(::hive_interface2::msg::FreeZone::_free_zone_id_type arg)
  {
    msg_.free_zone_id = std::move(arg);
    return Init_FreeZone_is_parking_available(msg_);
  }

private:
  ::hive_interface2::msg::FreeZone msg_;
};

class Init_FreeZone_free_zone_full_id_str
{
public:
  explicit Init_FreeZone_free_zone_full_id_str(::hive_interface2::msg::FreeZone & msg)
  : msg_(msg)
  {}
  Init_FreeZone_free_zone_id free_zone_full_id_str(::hive_interface2::msg::FreeZone::_free_zone_full_id_str_type arg)
  {
    msg_.free_zone_full_id_str = std::move(arg);
    return Init_FreeZone_free_zone_id(msg_);
  }

private:
  ::hive_interface2::msg::FreeZone msg_;
};

class Init_FreeZone_slam_session_full_id_str
{
public:
  explicit Init_FreeZone_slam_session_full_id_str(::hive_interface2::msg::FreeZone & msg)
  : msg_(msg)
  {}
  Init_FreeZone_free_zone_full_id_str slam_session_full_id_str(::hive_interface2::msg::FreeZone::_slam_session_full_id_str_type arg)
  {
    msg_.slam_session_full_id_str = std::move(arg);
    return Init_FreeZone_free_zone_full_id_str(msg_);
  }

private:
  ::hive_interface2::msg::FreeZone msg_;
};

class Init_FreeZone_deployment_full_id_str
{
public:
  explicit Init_FreeZone_deployment_full_id_str(::hive_interface2::msg::FreeZone & msg)
  : msg_(msg)
  {}
  Init_FreeZone_slam_session_full_id_str deployment_full_id_str(::hive_interface2::msg::FreeZone::_deployment_full_id_str_type arg)
  {
    msg_.deployment_full_id_str = std::move(arg);
    return Init_FreeZone_slam_session_full_id_str(msg_);
  }

private:
  ::hive_interface2::msg::FreeZone msg_;
};

class Init_FreeZone_enterprise_full_id_str
{
public:
  Init_FreeZone_enterprise_full_id_str()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_FreeZone_deployment_full_id_str enterprise_full_id_str(::hive_interface2::msg::FreeZone::_enterprise_full_id_str_type arg)
  {
    msg_.enterprise_full_id_str = std::move(arg);
    return Init_FreeZone_deployment_full_id_str(msg_);
  }

private:
  ::hive_interface2::msg::FreeZone msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::hive_interface2::msg::FreeZone>()
{
  return hive_interface2::msg::builder::Init_FreeZone_enterprise_full_id_str();
}

}  // namespace hive_interface2

#endif  // HIVE_INTERFACE2__MSG__DETAIL__FREE_ZONE__BUILDER_HPP_
