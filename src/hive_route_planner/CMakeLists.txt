cmake_minimum_required(VERSION 3.16)
project(hive_route_planner)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_POSITION_INDEPENDENT_CODE ON)

find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(std_srvs REQUIRED)
find_package(visualization_msgs REQUIRED)
find_package(geometry_msgs REQUIRED)
find_package(std_msgs REQUIRED)
find_package(builtin_interfaces REQUIRED)
find_package(hive_interface2 REQUIRED)        # <-- contient le .srv + msgs
find_package(rosidl_default_runtime REQUIRED) # <-- runtime pour interfaces déjà générées

add_library(route_utils src/route_utils.cpp)
target_include_directories(route_utils PUBLIC include)
ament_target_dependencies(route_utils
  rclcpp std_msgs visualization_msgs geometry_msgs builtin_interfaces hive_interface2)

add_library(astar_planner src/astar_planner.cpp)
target_include_directories(astar_planner PUBLIC include)
ament_target_dependencies(astar_planner
  rclcpp std_msgs visualization_msgs geometry_msgs builtin_interfaces hive_interface2)

add_executable(hive_route_planner_node src/hive_route_planner_node.cpp)
target_include_directories(hive_route_planner_node PRIVATE include)
ament_target_dependencies(hive_route_planner_node
  rclcpp std_srvs visualization_msgs geometry_msgs std_msgs builtin_interfaces hive_interface2)

target_link_libraries(hive_route_planner_node route_utils astar_planner)

install(TARGETS hive_route_planner_node route_utils astar_planner
  ARCHIVE DESTINATION lib
  LIBRARY DESTINATION lib
  RUNTIME DESTINATION lib/${PROJECT_NAME})

install(DIRECTORY include/${PROJECT_NAME}/
  DESTINATION include/${PROJECT_NAME})

install(DIRECTORY launch
  DESTINATION share/${PROJECT_NAME})

ament_export_dependencies(rosidl_default_runtime)  # runtime only
ament_package()
