// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from nav2_msgs:srv/ClearEntireCostmap.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "nav2_msgs/srv/clear_entire_costmap.hpp"


#ifndef NAV2_MSGS__SRV__DETAIL__CLEAR_ENTIRE_COSTMAP__STRUCT_HPP_
#define NAV2_MSGS__SRV__DETAIL__CLEAR_ENTIRE_COSTMAP__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


// Include directives for member types
// Member 'request'
#include "std_msgs/msg/detail/empty__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__nav2_msgs__srv__ClearEntireCostmap_Request __attribute__((deprecated))
#else
# define DEPRECATED__nav2_msgs__srv__ClearEntireCostmap_Request __declspec(deprecated)
#endif

namespace nav2_msgs
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct ClearEntireCostmap_Request_
{
  using Type = ClearEntireCostmap_Request_<ContainerAllocator>;

  explicit ClearEntireCostmap_Request_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : request(_init)
  {
    (void)_init;
  }

  explicit ClearEntireCostmap_Request_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : request(_alloc, _init)
  {
    (void)_init;
  }

  // field types and members
  using _request_type =
    std_msgs::msg::Empty_<ContainerAllocator>;
  _request_type request;

  // setters for named parameter idiom
  Type & set__request(
    const std_msgs::msg::Empty_<ContainerAllocator> & _arg)
  {
    this->request = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    nav2_msgs::srv::ClearEntireCostmap_Request_<ContainerAllocator> *;
  using ConstRawPtr =
    const nav2_msgs::srv::ClearEntireCostmap_Request_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<nav2_msgs::srv::ClearEntireCostmap_Request_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<nav2_msgs::srv::ClearEntireCostmap_Request_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      nav2_msgs::srv::ClearEntireCostmap_Request_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<nav2_msgs::srv::ClearEntireCostmap_Request_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      nav2_msgs::srv::ClearEntireCostmap_Request_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<nav2_msgs::srv::ClearEntireCostmap_Request_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<nav2_msgs::srv::ClearEntireCostmap_Request_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<nav2_msgs::srv::ClearEntireCostmap_Request_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__nav2_msgs__srv__ClearEntireCostmap_Request
    std::shared_ptr<nav2_msgs::srv::ClearEntireCostmap_Request_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__nav2_msgs__srv__ClearEntireCostmap_Request
    std::shared_ptr<nav2_msgs::srv::ClearEntireCostmap_Request_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const ClearEntireCostmap_Request_ & other) const
  {
    if (this->request != other.request) {
      return false;
    }
    return true;
  }
  bool operator!=(const ClearEntireCostmap_Request_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct ClearEntireCostmap_Request_

// alias to use template instance with default allocator
using ClearEntireCostmap_Request =
  nav2_msgs::srv::ClearEntireCostmap_Request_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace nav2_msgs


// Include directives for member types
// Member 'response'
// already included above
// #include "std_msgs/msg/detail/empty__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__nav2_msgs__srv__ClearEntireCostmap_Response __attribute__((deprecated))
#else
# define DEPRECATED__nav2_msgs__srv__ClearEntireCostmap_Response __declspec(deprecated)
#endif

namespace nav2_msgs
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct ClearEntireCostmap_Response_
{
  using Type = ClearEntireCostmap_Response_<ContainerAllocator>;

  explicit ClearEntireCostmap_Response_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : response(_init)
  {
    (void)_init;
  }

  explicit ClearEntireCostmap_Response_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : response(_alloc, _init)
  {
    (void)_init;
  }

  // field types and members
  using _response_type =
    std_msgs::msg::Empty_<ContainerAllocator>;
  _response_type response;

  // setters for named parameter idiom
  Type & set__response(
    const std_msgs::msg::Empty_<ContainerAllocator> & _arg)
  {
    this->response = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    nav2_msgs::srv::ClearEntireCostmap_Response_<ContainerAllocator> *;
  using ConstRawPtr =
    const nav2_msgs::srv::ClearEntireCostmap_Response_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<nav2_msgs::srv::ClearEntireCostmap_Response_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<nav2_msgs::srv::ClearEntireCostmap_Response_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      nav2_msgs::srv::ClearEntireCostmap_Response_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<nav2_msgs::srv::ClearEntireCostmap_Response_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      nav2_msgs::srv::ClearEntireCostmap_Response_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<nav2_msgs::srv::ClearEntireCostmap_Response_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<nav2_msgs::srv::ClearEntireCostmap_Response_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<nav2_msgs::srv::ClearEntireCostmap_Response_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__nav2_msgs__srv__ClearEntireCostmap_Response
    std::shared_ptr<nav2_msgs::srv::ClearEntireCostmap_Response_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__nav2_msgs__srv__ClearEntireCostmap_Response
    std::shared_ptr<nav2_msgs::srv::ClearEntireCostmap_Response_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const ClearEntireCostmap_Response_ & other) const
  {
    if (this->response != other.response) {
      return false;
    }
    return true;
  }
  bool operator!=(const ClearEntireCostmap_Response_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct ClearEntireCostmap_Response_

// alias to use template instance with default allocator
using ClearEntireCostmap_Response =
  nav2_msgs::srv::ClearEntireCostmap_Response_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace nav2_msgs


// Include directives for member types
// Member 'info'
#include "service_msgs/msg/detail/service_event_info__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__nav2_msgs__srv__ClearEntireCostmap_Event __attribute__((deprecated))
#else
# define DEPRECATED__nav2_msgs__srv__ClearEntireCostmap_Event __declspec(deprecated)
#endif

namespace nav2_msgs
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct ClearEntireCostmap_Event_
{
  using Type = ClearEntireCostmap_Event_<ContainerAllocator>;

  explicit ClearEntireCostmap_Event_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : info(_init)
  {
    (void)_init;
  }

  explicit ClearEntireCostmap_Event_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : info(_alloc, _init)
  {
    (void)_init;
  }

  // field types and members
  using _info_type =
    service_msgs::msg::ServiceEventInfo_<ContainerAllocator>;
  _info_type info;
  using _request_type =
    rosidl_runtime_cpp::BoundedVector<nav2_msgs::srv::ClearEntireCostmap_Request_<ContainerAllocator>, 1, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<nav2_msgs::srv::ClearEntireCostmap_Request_<ContainerAllocator>>>;
  _request_type request;
  using _response_type =
    rosidl_runtime_cpp::BoundedVector<nav2_msgs::srv::ClearEntireCostmap_Response_<ContainerAllocator>, 1, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<nav2_msgs::srv::ClearEntireCostmap_Response_<ContainerAllocator>>>;
  _response_type response;

  // setters for named parameter idiom
  Type & set__info(
    const service_msgs::msg::ServiceEventInfo_<ContainerAllocator> & _arg)
  {
    this->info = _arg;
    return *this;
  }
  Type & set__request(
    const rosidl_runtime_cpp::BoundedVector<nav2_msgs::srv::ClearEntireCostmap_Request_<ContainerAllocator>, 1, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<nav2_msgs::srv::ClearEntireCostmap_Request_<ContainerAllocator>>> & _arg)
  {
    this->request = _arg;
    return *this;
  }
  Type & set__response(
    const rosidl_runtime_cpp::BoundedVector<nav2_msgs::srv::ClearEntireCostmap_Response_<ContainerAllocator>, 1, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<nav2_msgs::srv::ClearEntireCostmap_Response_<ContainerAllocator>>> & _arg)
  {
    this->response = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    nav2_msgs::srv::ClearEntireCostmap_Event_<ContainerAllocator> *;
  using ConstRawPtr =
    const nav2_msgs::srv::ClearEntireCostmap_Event_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<nav2_msgs::srv::ClearEntireCostmap_Event_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<nav2_msgs::srv::ClearEntireCostmap_Event_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      nav2_msgs::srv::ClearEntireCostmap_Event_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<nav2_msgs::srv::ClearEntireCostmap_Event_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      nav2_msgs::srv::ClearEntireCostmap_Event_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<nav2_msgs::srv::ClearEntireCostmap_Event_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<nav2_msgs::srv::ClearEntireCostmap_Event_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<nav2_msgs::srv::ClearEntireCostmap_Event_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__nav2_msgs__srv__ClearEntireCostmap_Event
    std::shared_ptr<nav2_msgs::srv::ClearEntireCostmap_Event_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__nav2_msgs__srv__ClearEntireCostmap_Event
    std::shared_ptr<nav2_msgs::srv::ClearEntireCostmap_Event_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const ClearEntireCostmap_Event_ & other) const
  {
    if (this->info != other.info) {
      return false;
    }
    if (this->request != other.request) {
      return false;
    }
    if (this->response != other.response) {
      return false;
    }
    return true;
  }
  bool operator!=(const ClearEntireCostmap_Event_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct ClearEntireCostmap_Event_

// alias to use template instance with default allocator
using ClearEntireCostmap_Event =
  nav2_msgs::srv::ClearEntireCostmap_Event_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace nav2_msgs

namespace nav2_msgs
{

namespace srv
{

struct ClearEntireCostmap
{
  using Request = nav2_msgs::srv::ClearEntireCostmap_Request;
  using Response = nav2_msgs::srv::ClearEntireCostmap_Response;
  using Event = nav2_msgs::srv::ClearEntireCostmap_Event;
};

}  // namespace srv

}  // namespace nav2_msgs

#endif  // NAV2_MSGS__SRV__DETAIL__CLEAR_ENTIRE_COSTMAP__STRUCT_HPP_
