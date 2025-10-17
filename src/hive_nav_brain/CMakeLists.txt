cmake_minimum_required(VERSION 3.8)
project(hive_nav_brain)

if(NOT CMAKE_CXX_STANDARD)
  set(CMAKE_CXX_STANDARD 17)
endif()

find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(std_srvs REQUIRED)
find_package(geometry_msgs REQUIRED)
find_package(nav_msgs REQUIRED)
find_package(hive_interface2 REQUIRED)
find_package(tf2_ros REQUIRED)
find_package(tf2 REQUIRED)
find_package(tf2_geometry_msgs REQUIRED)
find_package(visualization_msgs REQUIRED)
find_package(rclcpp_action REQUIRED)
find_package(nav2_msgs REQUIRED)

include_directories(include)

add_library(hive_nav_brain_lib
  src/hive_nav_brain_node.cpp
  src/path_utils.cpp
  src/tf_helpers.cpp
  src/hive_planner.cpp
)

ament_target_dependencies(hive_nav_brain_lib
  rclcpp std_srvs geometry_msgs nav_msgs hive_interface2 tf2_ros tf2 tf2_geometry_msgs visualization_msgs rclcpp_action nav2_msgs)

add_executable(hive_nav_brain_node src/main.cpp)
target_link_libraries(hive_nav_brain_node hive_nav_brain_lib)

install(TARGETS hive_nav_brain_lib hive_nav_brain_node
  ARCHIVE DESTINATION lib
  LIBRARY DESTINATION lib
  RUNTIME DESTINATION lib/${PROJECT_NAME})

install(DIRECTORY include/
  DESTINATION include)

install(DIRECTORY launch/
  DESTINATION share/${PROJECT_NAME}/launch)

ament_package()
