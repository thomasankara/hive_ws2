// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from hive_interface2:msg/Poi.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "hive_interface2/msg/poi.hpp"


#ifndef HIVE_INTERFACE2__MSG__DETAIL__POI__BUILDER_HPP_
#define HIVE_INTERFACE2__MSG__DETAIL__POI__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "hive_interface2/msg/detail/poi__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace hive_interface2
{

namespace msg
{

namespace builder
{

class Init_Poi_is_long_wait_zone
{
public:
  explicit Init_Poi_is_long_wait_zone(::hive_interface2::msg::Poi & msg)
  : msg_(msg)
  {}
  ::hive_interface2::msg::Poi is_long_wait_zone(::hive_interface2::msg::Poi::_is_long_wait_zone_type arg)
  {
    msg_.is_long_wait_zone = std::move(arg);
    return std::move(msg_);
  }

private:
  ::hive_interface2::msg::Poi msg_;
};

class Init_Poi_charging_mode
{
public:
  explicit Init_Poi_charging_mode(::hive_interface2::msg::Poi & msg)
  : msg_(msg)
  {}
  Init_Poi_is_long_wait_zone charging_mode(::hive_interface2::msg::Poi::_charging_mode_type arg)
  {
    msg_.charging_mode = std::move(arg);
    return Init_Poi_is_long_wait_zone(msg_);
  }

private:
  ::hive_interface2::msg::Poi msg_;
};

class Init_Poi_is_available
{
public:
  explicit Init_Poi_is_available(::hive_interface2::msg::Poi & msg)
  : msg_(msg)
  {}
  Init_Poi_charging_mode is_available(::hive_interface2::msg::Poi::_is_available_type arg)
  {
    msg_.is_available = std::move(arg);
    return Init_Poi_charging_mode(msg_);
  }

private:
  ::hive_interface2::msg::Poi msg_;
};

class Init_Poi_parking_mode
{
public:
  explicit Init_Poi_parking_mode(::hive_interface2::msg::Poi & msg)
  : msg_(msg)
  {}
  Init_Poi_is_available parking_mode(::hive_interface2::msg::Poi::_parking_mode_type arg)
  {
    msg_.parking_mode = std::move(arg);
    return Init_Poi_is_available(msg_);
  }

private:
  ::hive_interface2::msg::Poi msg_;
};

class Init_Poi_yaw
{
public:
  explicit Init_Poi_yaw(::hive_interface2::msg::Poi & msg)
  : msg_(msg)
  {}
  Init_Poi_parking_mode yaw(::hive_interface2::msg::Poi::_yaw_type arg)
  {
    msg_.yaw = std::move(arg);
    return Init_Poi_parking_mode(msg_);
  }

private:
  ::hive_interface2::msg::Poi msg_;
};

class Init_Poi_z
{
public:
  explicit Init_Poi_z(::hive_interface2::msg::Poi & msg)
  : msg_(msg)
  {}
  Init_Poi_yaw z(::hive_interface2::msg::Poi::_z_type arg)
  {
    msg_.z = std::move(arg);
    return Init_Poi_yaw(msg_);
  }

private:
  ::hive_interface2::msg::Poi msg_;
};

class Init_Poi_y
{
public:
  explicit Init_Poi_y(::hive_interface2::msg::Poi & msg)
  : msg_(msg)
  {}
  Init_Poi_z y(::hive_interface2::msg::Poi::_y_type arg)
  {
    msg_.y = std::move(arg);
    return Init_Poi_z(msg_);
  }

private:
  ::hive_interface2::msg::Poi msg_;
};

class Init_Poi_x
{
public:
  explicit Init_Poi_x(::hive_interface2::msg::Poi & msg)
  : msg_(msg)
  {}
  Init_Poi_y x(::hive_interface2::msg::Poi::_x_type arg)
  {
    msg_.x = std::move(arg);
    return Init_Poi_y(msg_);
  }

private:
  ::hive_interface2::msg::Poi msg_;
};

class Init_Poi_poi_id
{
public:
  explicit Init_Poi_poi_id(::hive_interface2::msg::Poi & msg)
  : msg_(msg)
  {}
  Init_Poi_x poi_id(::hive_interface2::msg::Poi::_poi_id_type arg)
  {
    msg_.poi_id = std::move(arg);
    return Init_Poi_x(msg_);
  }

private:
  ::hive_interface2::msg::Poi msg_;
};

class Init_Poi_poi_full_id_str
{
public:
  explicit Init_Poi_poi_full_id_str(::hive_interface2::msg::Poi & msg)
  : msg_(msg)
  {}
  Init_Poi_poi_id poi_full_id_str(::hive_interface2::msg::Poi::_poi_full_id_str_type arg)
  {
    msg_.poi_full_id_str = std::move(arg);
    return Init_Poi_poi_id(msg_);
  }

private:
  ::hive_interface2::msg::Poi msg_;
};

class Init_Poi_is_in_free_zone
{
public:
  explicit Init_Poi_is_in_free_zone(::hive_interface2::msg::Poi & msg)
  : msg_(msg)
  {}
  Init_Poi_poi_full_id_str is_in_free_zone(::hive_interface2::msg::Poi::_is_in_free_zone_type arg)
  {
    msg_.is_in_free_zone = std::move(arg);
    return Init_Poi_poi_full_id_str(msg_);
  }

private:
  ::hive_interface2::msg::Poi msg_;
};

class Init_Poi_free_zone_full_id_str
{
public:
  explicit Init_Poi_free_zone_full_id_str(::hive_interface2::msg::Poi & msg)
  : msg_(msg)
  {}
  Init_Poi_is_in_free_zone free_zone_full_id_str(::hive_interface2::msg::Poi::_free_zone_full_id_str_type arg)
  {
    msg_.free_zone_full_id_str = std::move(arg);
    return Init_Poi_is_in_free_zone(msg_);
  }

private:
  ::hive_interface2::msg::Poi msg_;
};

class Init_Poi_slam_session_full_id_str
{
public:
  explicit Init_Poi_slam_session_full_id_str(::hive_interface2::msg::Poi & msg)
  : msg_(msg)
  {}
  Init_Poi_free_zone_full_id_str slam_session_full_id_str(::hive_interface2::msg::Poi::_slam_session_full_id_str_type arg)
  {
    msg_.slam_session_full_id_str = std::move(arg);
    return Init_Poi_free_zone_full_id_str(msg_);
  }

private:
  ::hive_interface2::msg::Poi msg_;
};

class Init_Poi_deployment_full_id_str
{
public:
  explicit Init_Poi_deployment_full_id_str(::hive_interface2::msg::Poi & msg)
  : msg_(msg)
  {}
  Init_Poi_slam_session_full_id_str deployment_full_id_str(::hive_interface2::msg::Poi::_deployment_full_id_str_type arg)
  {
    msg_.deployment_full_id_str = std::move(arg);
    return Init_Poi_slam_session_full_id_str(msg_);
  }

private:
  ::hive_interface2::msg::Poi msg_;
};

class Init_Poi_enterprise_full_id_str
{
public:
  Init_Poi_enterprise_full_id_str()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Poi_deployment_full_id_str enterprise_full_id_str(::hive_interface2::msg::Poi::_enterprise_full_id_str_type arg)
  {
    msg_.enterprise_full_id_str = std::move(arg);
    return Init_Poi_deployment_full_id_str(msg_);
  }

private:
  ::hive_interface2::msg::Poi msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::hive_interface2::msg::Poi>()
{
  return hive_interface2::msg::builder::Init_Poi_enterprise_full_id_str();
}

}  // namespace hive_interface2

#endif  // HIVE_INTERFACE2__MSG__DETAIL__POI__BUILDER_HPP_
