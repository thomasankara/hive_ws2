// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from hive_interface2:msg/FreeZoneArray.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "hive_interface2/msg/free_zone_array.hpp"


#ifndef HIVE_INTERFACE2__MSG__DETAIL__FREE_ZONE_ARRAY__STRUCT_HPP_
#define HIVE_INTERFACE2__MSG__DETAIL__FREE_ZONE_ARRAY__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


// Include directives for member types
// Member 'items'
#include "hive_interface2/msg/detail/free_zone__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__hive_interface2__msg__FreeZoneArray __attribute__((deprecated))
#else
# define DEPRECATED__hive_interface2__msg__FreeZoneArray __declspec(deprecated)
#endif

namespace hive_interface2
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct FreeZoneArray_
{
  using Type = FreeZoneArray_<ContainerAllocator>;

  explicit FreeZoneArray_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_init;
  }

  explicit FreeZoneArray_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_init;
    (void)_alloc;
  }

  // field types and members
  using _items_type =
    std::vector<hive_interface2::msg::FreeZone_<ContainerAllocator>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<hive_interface2::msg::FreeZone_<ContainerAllocator>>>;
  _items_type items;

  // setters for named parameter idiom
  Type & set__items(
    const std::vector<hive_interface2::msg::FreeZone_<ContainerAllocator>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<hive_interface2::msg::FreeZone_<ContainerAllocator>>> & _arg)
  {
    this->items = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    hive_interface2::msg::FreeZoneArray_<ContainerAllocator> *;
  using ConstRawPtr =
    const hive_interface2::msg::FreeZoneArray_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<hive_interface2::msg::FreeZoneArray_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<hive_interface2::msg::FreeZoneArray_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      hive_interface2::msg::FreeZoneArray_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<hive_interface2::msg::FreeZoneArray_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      hive_interface2::msg::FreeZoneArray_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<hive_interface2::msg::FreeZoneArray_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<hive_interface2::msg::FreeZoneArray_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<hive_interface2::msg::FreeZoneArray_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__hive_interface2__msg__FreeZoneArray
    std::shared_ptr<hive_interface2::msg::FreeZoneArray_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__hive_interface2__msg__FreeZoneArray
    std::shared_ptr<hive_interface2::msg::FreeZoneArray_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const FreeZoneArray_ & other) const
  {
    if (this->items != other.items) {
      return false;
    }
    return true;
  }
  bool operator!=(const FreeZoneArray_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct FreeZoneArray_

// alias to use template instance with default allocator
using FreeZoneArray =
  hive_interface2::msg::FreeZoneArray_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace hive_interface2

#endif  // HIVE_INTERFACE2__MSG__DETAIL__FREE_ZONE_ARRAY__STRUCT_HPP_
