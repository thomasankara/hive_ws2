cmake_minimum_required(VERSION 3.8)
project(hive_costmap)

# ==============================
#  Dependencies
# ==============================
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(nav_msgs REQUIRED)
find_package(sensor_msgs REQUIRED)
find_package(geometry_msgs REQUIRED)
find_package(tf2 REQUIRED)
find_package(tf2_ros REQUIRED)
find_package(tf2_geometry_msgs REQUIRED)
find_package(nav2_costmap_2d REQUIRED)
find_package(pluginlib REQUIRED)
find_package(grid_map_core REQUIRED)
find_package(grid_map_ros REQUIRED)
find_package(nav2_msgs REQUIRED)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# ==============================
#  Include directories
# ==============================
include_directories(include)

# ==============================
#  Build the simple costmap node
# ==============================
add_executable(simple_costmap_node src/simple_costmap.cpp)

ament_target_dependencies(simple_costmap_node
  rclcpp
  nav_msgs
  sensor_msgs
  geometry_msgs
  tf2
  tf2_ros
  tf2_geometry_msgs
  grid_map_core
  grid_map_ros
)

install(TARGETS simple_costmap_node
  DESTINATION lib/${PROJECT_NAME}
)

# ==============================
#  Build the costmap plugin
# ==============================
add_library(gridmap_fusion_plugin SHARED src/gridmap_fusion_layer.cpp)

ament_target_dependencies(gridmap_fusion_plugin
  rclcpp
  nav2_costmap_2d
  pluginlib
  tf2
  tf2_ros
  tf2_geometry_msgs
  nav_msgs
  geometry_msgs
)

target_include_directories(gridmap_fusion_plugin PRIVATE include)

# ==============================
#  Export Pluginlib XML descriptor
# ==============================
pluginlib_export_plugin_description_file(
  nav2_costmap_2d
  resource/hive_costmap_plugins.xml
)

# ==============================
#  Install targets and resources
# ==============================
install(TARGETS
  gridmap_fusion_plugin
  ARCHIVE DESTINATION lib
  LIBRARY DESTINATION lib
  RUNTIME DESTINATION bin
)

install(FILES
  resource/hive_costmap_plugins.xml
  DESTINATION share/${PROJECT_NAME}
)

install(DIRECTORY launch/
  DESTINATION share/${PROJECT_NAME}/launch
)

# ==============================
#  Package declaration
# ==============================
ament_package()
