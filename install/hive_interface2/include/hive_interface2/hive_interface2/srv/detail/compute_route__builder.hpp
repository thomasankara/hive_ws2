// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from hive_interface2:srv/ComputeRoute.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "hive_interface2/srv/compute_route.hpp"


#ifndef HIVE_INTERFACE2__SRV__DETAIL__COMPUTE_ROUTE__BUILDER_HPP_
#define HIVE_INTERFACE2__SRV__DETAIL__COMPUTE_ROUTE__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "hive_interface2/srv/detail/compute_route__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace hive_interface2
{

namespace srv
{

namespace builder
{

class Init_ComputeRoute_Request_mode
{
public:
  explicit Init_ComputeRoute_Request_mode(::hive_interface2::srv::ComputeRoute_Request & msg)
  : msg_(msg)
  {}
  ::hive_interface2::srv::ComputeRoute_Request mode(::hive_interface2::srv::ComputeRoute_Request::_mode_type arg)
  {
    msg_.mode = std::move(arg);
    return std::move(msg_);
  }

private:
  ::hive_interface2::srv::ComputeRoute_Request msg_;
};

class Init_ComputeRoute_Request_goal_pose
{
public:
  explicit Init_ComputeRoute_Request_goal_pose(::hive_interface2::srv::ComputeRoute_Request & msg)
  : msg_(msg)
  {}
  Init_ComputeRoute_Request_mode goal_pose(::hive_interface2::srv::ComputeRoute_Request::_goal_pose_type arg)
  {
    msg_.goal_pose = std::move(arg);
    return Init_ComputeRoute_Request_mode(msg_);
  }

private:
  ::hive_interface2::srv::ComputeRoute_Request msg_;
};

class Init_ComputeRoute_Request_start_pose
{
public:
  Init_ComputeRoute_Request_start_pose()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_ComputeRoute_Request_goal_pose start_pose(::hive_interface2::srv::ComputeRoute_Request::_start_pose_type arg)
  {
    msg_.start_pose = std::move(arg);
    return Init_ComputeRoute_Request_goal_pose(msg_);
  }

private:
  ::hive_interface2::srv::ComputeRoute_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::hive_interface2::srv::ComputeRoute_Request>()
{
  return hive_interface2::srv::builder::Init_ComputeRoute_Request_start_pose();
}

}  // namespace hive_interface2


namespace hive_interface2
{

namespace srv
{

namespace builder
{

class Init_ComputeRoute_Response_estimated_time_s
{
public:
  explicit Init_ComputeRoute_Response_estimated_time_s(::hive_interface2::srv::ComputeRoute_Response & msg)
  : msg_(msg)
  {}
  ::hive_interface2::srv::ComputeRoute_Response estimated_time_s(::hive_interface2::srv::ComputeRoute_Response::_estimated_time_s_type arg)
  {
    msg_.estimated_time_s = std::move(arg);
    return std::move(msg_);
  }

private:
  ::hive_interface2::srv::ComputeRoute_Response msg_;
};

class Init_ComputeRoute_Response_total_distance_m
{
public:
  explicit Init_ComputeRoute_Response_total_distance_m(::hive_interface2::srv::ComputeRoute_Response & msg)
  : msg_(msg)
  {}
  Init_ComputeRoute_Response_estimated_time_s total_distance_m(::hive_interface2::srv::ComputeRoute_Response::_total_distance_m_type arg)
  {
    msg_.total_distance_m = std::move(arg);
    return Init_ComputeRoute_Response_estimated_time_s(msg_);
  }

private:
  ::hive_interface2::srv::ComputeRoute_Response msg_;
};

class Init_ComputeRoute_Response_path
{
public:
  explicit Init_ComputeRoute_Response_path(::hive_interface2::srv::ComputeRoute_Response & msg)
  : msg_(msg)
  {}
  Init_ComputeRoute_Response_total_distance_m path(::hive_interface2::srv::ComputeRoute_Response::_path_type arg)
  {
    msg_.path = std::move(arg);
    return Init_ComputeRoute_Response_total_distance_m(msg_);
  }

private:
  ::hive_interface2::srv::ComputeRoute_Response msg_;
};

class Init_ComputeRoute_Response_message
{
public:
  explicit Init_ComputeRoute_Response_message(::hive_interface2::srv::ComputeRoute_Response & msg)
  : msg_(msg)
  {}
  Init_ComputeRoute_Response_path message(::hive_interface2::srv::ComputeRoute_Response::_message_type arg)
  {
    msg_.message = std::move(arg);
    return Init_ComputeRoute_Response_path(msg_);
  }

private:
  ::hive_interface2::srv::ComputeRoute_Response msg_;
};

class Init_ComputeRoute_Response_success
{
public:
  Init_ComputeRoute_Response_success()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_ComputeRoute_Response_message success(::hive_interface2::srv::ComputeRoute_Response::_success_type arg)
  {
    msg_.success = std::move(arg);
    return Init_ComputeRoute_Response_message(msg_);
  }

private:
  ::hive_interface2::srv::ComputeRoute_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::hive_interface2::srv::ComputeRoute_Response>()
{
  return hive_interface2::srv::builder::Init_ComputeRoute_Response_success();
}

}  // namespace hive_interface2


namespace hive_interface2
{

namespace srv
{

namespace builder
{

class Init_ComputeRoute_Event_response
{
public:
  explicit Init_ComputeRoute_Event_response(::hive_interface2::srv::ComputeRoute_Event & msg)
  : msg_(msg)
  {}
  ::hive_interface2::srv::ComputeRoute_Event response(::hive_interface2::srv::ComputeRoute_Event::_response_type arg)
  {
    msg_.response = std::move(arg);
    return std::move(msg_);
  }

private:
  ::hive_interface2::srv::ComputeRoute_Event msg_;
};

class Init_ComputeRoute_Event_request
{
public:
  explicit Init_ComputeRoute_Event_request(::hive_interface2::srv::ComputeRoute_Event & msg)
  : msg_(msg)
  {}
  Init_ComputeRoute_Event_response request(::hive_interface2::srv::ComputeRoute_Event::_request_type arg)
  {
    msg_.request = std::move(arg);
    return Init_ComputeRoute_Event_response(msg_);
  }

private:
  ::hive_interface2::srv::ComputeRoute_Event msg_;
};

class Init_ComputeRoute_Event_info
{
public:
  Init_ComputeRoute_Event_info()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_ComputeRoute_Event_request info(::hive_interface2::srv::ComputeRoute_Event::_info_type arg)
  {
    msg_.info = std::move(arg);
    return Init_ComputeRoute_Event_request(msg_);
  }

private:
  ::hive_interface2::srv::ComputeRoute_Event msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::hive_interface2::srv::ComputeRoute_Event>()
{
  return hive_interface2::srv::builder::Init_ComputeRoute_Event_info();
}

}  // namespace hive_interface2

#endif  // HIVE_INTERFACE2__SRV__DETAIL__COMPUTE_ROUTE__BUILDER_HPP_
