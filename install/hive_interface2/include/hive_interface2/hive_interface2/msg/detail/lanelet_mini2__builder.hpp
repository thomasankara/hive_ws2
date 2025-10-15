// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from hive_interface2:msg/LaneletMini2.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "hive_interface2/msg/lanelet_mini2.hpp"


#ifndef HIVE_INTERFACE2__MSG__DETAIL__LANELET_MINI2__BUILDER_HPP_
#define HIVE_INTERFACE2__MSG__DETAIL__LANELET_MINI2__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "hive_interface2/msg/detail/lanelet_mini2__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace hive_interface2
{

namespace msg
{

namespace builder
{

class Init_LaneletMini2_width
{
public:
  explicit Init_LaneletMini2_width(::hive_interface2::msg::LaneletMini2 & msg)
  : msg_(msg)
  {}
  ::hive_interface2::msg::LaneletMini2 width(::hive_interface2::msg::LaneletMini2::_width_type arg)
  {
    msg_.width = std::move(arg);
    return std::move(msg_);
  }

private:
  ::hive_interface2::msg::LaneletMini2 msg_;
};

class Init_LaneletMini2_max_speed
{
public:
  explicit Init_LaneletMini2_max_speed(::hive_interface2::msg::LaneletMini2 & msg)
  : msg_(msg)
  {}
  Init_LaneletMini2_width max_speed(::hive_interface2::msg::LaneletMini2::_max_speed_type arg)
  {
    msg_.max_speed = std::move(arg);
    return Init_LaneletMini2_width(msg_);
  }

private:
  ::hive_interface2::msg::LaneletMini2 msg_;
};

class Init_LaneletMini2_road_group_id_str
{
public:
  explicit Init_LaneletMini2_road_group_id_str(::hive_interface2::msg::LaneletMini2 & msg)
  : msg_(msg)
  {}
  Init_LaneletMini2_max_speed road_group_id_str(::hive_interface2::msg::LaneletMini2::_road_group_id_str_type arg)
  {
    msg_.road_group_id_str = std::move(arg);
    return Init_LaneletMini2_max_speed(msg_);
  }

private:
  ::hive_interface2::msg::LaneletMini2 msg_;
};

class Init_LaneletMini2_configuration_group_id_str
{
public:
  explicit Init_LaneletMini2_configuration_group_id_str(::hive_interface2::msg::LaneletMini2 & msg)
  : msg_(msg)
  {}
  Init_LaneletMini2_road_group_id_str configuration_group_id_str(::hive_interface2::msg::LaneletMini2::_configuration_group_id_str_type arg)
  {
    msg_.configuration_group_id_str = std::move(arg);
    return Init_LaneletMini2_road_group_id_str(msg_);
  }

private:
  ::hive_interface2::msg::LaneletMini2 msg_;
};

class Init_LaneletMini2_offroad_alert
{
public:
  explicit Init_LaneletMini2_offroad_alert(::hive_interface2::msg::LaneletMini2 & msg)
  : msg_(msg)
  {}
  Init_LaneletMini2_configuration_group_id_str offroad_alert(::hive_interface2::msg::LaneletMini2::_offroad_alert_type arg)
  {
    msg_.offroad_alert = std::move(arg);
    return Init_LaneletMini2_configuration_group_id_str(msg_);
  }

private:
  ::hive_interface2::msg::LaneletMini2 msg_;
};

class Init_LaneletMini2_vegetation_alert
{
public:
  explicit Init_LaneletMini2_vegetation_alert(::hive_interface2::msg::LaneletMini2 & msg)
  : msg_(msg)
  {}
  Init_LaneletMini2_offroad_alert vegetation_alert(::hive_interface2::msg::LaneletMini2::_vegetation_alert_type arg)
  {
    msg_.vegetation_alert = std::move(arg);
    return Init_LaneletMini2_offroad_alert(msg_);
  }

private:
  ::hive_interface2::msg::LaneletMini2 msg_;
};

class Init_LaneletMini2_slope_alert
{
public:
  explicit Init_LaneletMini2_slope_alert(::hive_interface2::msg::LaneletMini2 & msg)
  : msg_(msg)
  {}
  Init_LaneletMini2_vegetation_alert slope_alert(::hive_interface2::msg::LaneletMini2::_slope_alert_type arg)
  {
    msg_.slope_alert = std::move(arg);
    return Init_LaneletMini2_vegetation_alert(msg_);
  }

private:
  ::hive_interface2::msg::LaneletMini2 msg_;
};

class Init_LaneletMini2_u_turn_allowed
{
public:
  explicit Init_LaneletMini2_u_turn_allowed(::hive_interface2::msg::LaneletMini2 & msg)
  : msg_(msg)
  {}
  Init_LaneletMini2_slope_alert u_turn_allowed(::hive_interface2::msg::LaneletMini2::_u_turn_allowed_type arg)
  {
    msg_.u_turn_allowed = std::move(arg);
    return Init_LaneletMini2_slope_alert(msg_);
  }

private:
  ::hive_interface2::msg::LaneletMini2 msg_;
};

class Init_LaneletMini2_border_mode
{
public:
  explicit Init_LaneletMini2_border_mode(::hive_interface2::msg::LaneletMini2 & msg)
  : msg_(msg)
  {}
  Init_LaneletMini2_u_turn_allowed border_mode(::hive_interface2::msg::LaneletMini2::_border_mode_type arg)
  {
    msg_.border_mode = std::move(arg);
    return Init_LaneletMini2_u_turn_allowed(msg_);
  }

private:
  ::hive_interface2::msg::LaneletMini2 msg_;
};

class Init_LaneletMini2_navigation_direction
{
public:
  explicit Init_LaneletMini2_navigation_direction(::hive_interface2::msg::LaneletMini2 & msg)
  : msg_(msg)
  {}
  Init_LaneletMini2_border_mode navigation_direction(::hive_interface2::msg::LaneletMini2::_navigation_direction_type arg)
  {
    msg_.navigation_direction = std::move(arg);
    return Init_LaneletMini2_border_mode(msg_);
  }

private:
  ::hive_interface2::msg::LaneletMini2 msg_;
};

class Init_LaneletMini2_end_point_z
{
public:
  explicit Init_LaneletMini2_end_point_z(::hive_interface2::msg::LaneletMini2 & msg)
  : msg_(msg)
  {}
  Init_LaneletMini2_navigation_direction end_point_z(::hive_interface2::msg::LaneletMini2::_end_point_z_type arg)
  {
    msg_.end_point_z = std::move(arg);
    return Init_LaneletMini2_navigation_direction(msg_);
  }

private:
  ::hive_interface2::msg::LaneletMini2 msg_;
};

class Init_LaneletMini2_end_point_y
{
public:
  explicit Init_LaneletMini2_end_point_y(::hive_interface2::msg::LaneletMini2 & msg)
  : msg_(msg)
  {}
  Init_LaneletMini2_end_point_z end_point_y(::hive_interface2::msg::LaneletMini2::_end_point_y_type arg)
  {
    msg_.end_point_y = std::move(arg);
    return Init_LaneletMini2_end_point_z(msg_);
  }

private:
  ::hive_interface2::msg::LaneletMini2 msg_;
};

class Init_LaneletMini2_end_point_x
{
public:
  explicit Init_LaneletMini2_end_point_x(::hive_interface2::msg::LaneletMini2 & msg)
  : msg_(msg)
  {}
  Init_LaneletMini2_end_point_y end_point_x(::hive_interface2::msg::LaneletMini2::_end_point_x_type arg)
  {
    msg_.end_point_x = std::move(arg);
    return Init_LaneletMini2_end_point_y(msg_);
  }

private:
  ::hive_interface2::msg::LaneletMini2 msg_;
};

class Init_LaneletMini2_start_point_z
{
public:
  explicit Init_LaneletMini2_start_point_z(::hive_interface2::msg::LaneletMini2 & msg)
  : msg_(msg)
  {}
  Init_LaneletMini2_end_point_x start_point_z(::hive_interface2::msg::LaneletMini2::_start_point_z_type arg)
  {
    msg_.start_point_z = std::move(arg);
    return Init_LaneletMini2_end_point_x(msg_);
  }

private:
  ::hive_interface2::msg::LaneletMini2 msg_;
};

class Init_LaneletMini2_start_point_y
{
public:
  explicit Init_LaneletMini2_start_point_y(::hive_interface2::msg::LaneletMini2 & msg)
  : msg_(msg)
  {}
  Init_LaneletMini2_start_point_z start_point_y(::hive_interface2::msg::LaneletMini2::_start_point_y_type arg)
  {
    msg_.start_point_y = std::move(arg);
    return Init_LaneletMini2_start_point_z(msg_);
  }

private:
  ::hive_interface2::msg::LaneletMini2 msg_;
};

class Init_LaneletMini2_start_point_x
{
public:
  explicit Init_LaneletMini2_start_point_x(::hive_interface2::msg::LaneletMini2 & msg)
  : msg_(msg)
  {}
  Init_LaneletMini2_start_point_y start_point_x(::hive_interface2::msg::LaneletMini2::_start_point_x_type arg)
  {
    msg_.start_point_x = std::move(arg);
    return Init_LaneletMini2_start_point_y(msg_);
  }

private:
  ::hive_interface2::msg::LaneletMini2 msg_;
};

class Init_LaneletMini2_lanelet_mini_id
{
public:
  explicit Init_LaneletMini2_lanelet_mini_id(::hive_interface2::msg::LaneletMini2 & msg)
  : msg_(msg)
  {}
  Init_LaneletMini2_start_point_x lanelet_mini_id(::hive_interface2::msg::LaneletMini2::_lanelet_mini_id_type arg)
  {
    msg_.lanelet_mini_id = std::move(arg);
    return Init_LaneletMini2_start_point_x(msg_);
  }

private:
  ::hive_interface2::msg::LaneletMini2 msg_;
};

class Init_LaneletMini2_slam_session_full_id_str
{
public:
  explicit Init_LaneletMini2_slam_session_full_id_str(::hive_interface2::msg::LaneletMini2 & msg)
  : msg_(msg)
  {}
  Init_LaneletMini2_lanelet_mini_id slam_session_full_id_str(::hive_interface2::msg::LaneletMini2::_slam_session_full_id_str_type arg)
  {
    msg_.slam_session_full_id_str = std::move(arg);
    return Init_LaneletMini2_lanelet_mini_id(msg_);
  }

private:
  ::hive_interface2::msg::LaneletMini2 msg_;
};

class Init_LaneletMini2_deployment_full_id_str
{
public:
  explicit Init_LaneletMini2_deployment_full_id_str(::hive_interface2::msg::LaneletMini2 & msg)
  : msg_(msg)
  {}
  Init_LaneletMini2_slam_session_full_id_str deployment_full_id_str(::hive_interface2::msg::LaneletMini2::_deployment_full_id_str_type arg)
  {
    msg_.deployment_full_id_str = std::move(arg);
    return Init_LaneletMini2_slam_session_full_id_str(msg_);
  }

private:
  ::hive_interface2::msg::LaneletMini2 msg_;
};

class Init_LaneletMini2_enterprise_full_id_str
{
public:
  Init_LaneletMini2_enterprise_full_id_str()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_LaneletMini2_deployment_full_id_str enterprise_full_id_str(::hive_interface2::msg::LaneletMini2::_enterprise_full_id_str_type arg)
  {
    msg_.enterprise_full_id_str = std::move(arg);
    return Init_LaneletMini2_deployment_full_id_str(msg_);
  }

private:
  ::hive_interface2::msg::LaneletMini2 msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::hive_interface2::msg::LaneletMini2>()
{
  return hive_interface2::msg::builder::Init_LaneletMini2_enterprise_full_id_str();
}

}  // namespace hive_interface2

#endif  // HIVE_INTERFACE2__MSG__DETAIL__LANELET_MINI2__BUILDER_HPP_
