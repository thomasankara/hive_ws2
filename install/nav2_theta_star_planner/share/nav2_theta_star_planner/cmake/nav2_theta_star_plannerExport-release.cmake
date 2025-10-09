#----------------------------------------------------------------
# Generated CMake target import file for configuration "Release".
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "nav2_theta_star_planner::nav2_theta_star_planner" for configuration "Release"
set_property(TARGET nav2_theta_star_planner::nav2_theta_star_planner APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(nav2_theta_star_planner::nav2_theta_star_planner PROPERTIES
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/lib/libnav2_theta_star_planner.so"
  IMPORTED_SONAME_RELEASE "libnav2_theta_star_planner.so"
  )

list(APPEND _cmake_import_check_targets nav2_theta_star_planner::nav2_theta_star_planner )
list(APPEND _cmake_import_check_files_for_nav2_theta_star_planner::nav2_theta_star_planner "${_IMPORT_PREFIX}/lib/libnav2_theta_star_planner.so" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
