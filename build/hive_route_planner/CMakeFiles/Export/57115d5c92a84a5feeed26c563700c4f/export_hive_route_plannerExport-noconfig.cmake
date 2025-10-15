#----------------------------------------------------------------
# Generated CMake target import file.
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "hive_route_planner::hive_route_planner_node" for configuration ""
set_property(TARGET hive_route_planner::hive_route_planner_node APPEND PROPERTY IMPORTED_CONFIGURATIONS NOCONFIG)
set_target_properties(hive_route_planner::hive_route_planner_node PROPERTIES
  IMPORTED_LOCATION_NOCONFIG "${_IMPORT_PREFIX}/lib/hive_route_planner/hive_route_planner_node"
  )

list(APPEND _cmake_import_check_targets hive_route_planner::hive_route_planner_node )
list(APPEND _cmake_import_check_files_for_hive_route_planner::hive_route_planner_node "${_IMPORT_PREFIX}/lib/hive_route_planner/hive_route_planner_node" )

# Import target "hive_route_planner::route_utils" for configuration ""
set_property(TARGET hive_route_planner::route_utils APPEND PROPERTY IMPORTED_CONFIGURATIONS NOCONFIG)
set_target_properties(hive_route_planner::route_utils PROPERTIES
  IMPORTED_LINK_INTERFACE_LANGUAGES_NOCONFIG "CXX"
  IMPORTED_LOCATION_NOCONFIG "${_IMPORT_PREFIX}/lib/libroute_utils.a"
  )

list(APPEND _cmake_import_check_targets hive_route_planner::route_utils )
list(APPEND _cmake_import_check_files_for_hive_route_planner::route_utils "${_IMPORT_PREFIX}/lib/libroute_utils.a" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
