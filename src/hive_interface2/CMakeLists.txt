cmake_minimum_required(VERSION 3.8)
project(hive_interface2)

# -----------------------------------------------------------------------------
# 1. Trouver les dépendances nécessaires
# -----------------------------------------------------------------------------
find_package(ament_cmake REQUIRED)
find_package(rosidl_default_generators REQUIRED)
find_package(std_msgs REQUIRED)
find_package(geometry_msgs REQUIRED)
find_package(nav_msgs REQUIRED)

# -----------------------------------------------------------------------------
# 2. Génération des interfaces
# -----------------------------------------------------------------------------
rosidl_generate_interfaces(${PROJECT_NAME}
  "msg/LaneletMini2.msg"
  "msg/LaneletMini2Array.msg"
  "srv/ComputeRoute.srv"
  DEPENDENCIES std_msgs geometry_msgs nav_msgs
)


# -----------------------------------------------------------------------------
# 3. Export des dépendances
# -----------------------------------------------------------------------------
ament_export_dependencies(rosidl_default_runtime)
ament_package()
