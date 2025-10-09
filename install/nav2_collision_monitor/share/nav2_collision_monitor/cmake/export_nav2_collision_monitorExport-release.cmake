#----------------------------------------------------------------
# Generated CMake target import file for configuration "Release".
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "nav2_collision_monitor::collision_monitor_core" for configuration "Release"
set_property(TARGET nav2_collision_monitor::collision_monitor_core APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(nav2_collision_monitor::collision_monitor_core PROPERTIES
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/lib/libcollision_monitor_core.so"
  IMPORTED_SONAME_RELEASE "libcollision_monitor_core.so"
  )

list(APPEND _cmake_import_check_targets nav2_collision_monitor::collision_monitor_core )
list(APPEND _cmake_import_check_files_for_nav2_collision_monitor::collision_monitor_core "${_IMPORT_PREFIX}/lib/libcollision_monitor_core.so" )

# Import target "nav2_collision_monitor::collision_detector_core" for configuration "Release"
set_property(TARGET nav2_collision_monitor::collision_detector_core APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(nav2_collision_monitor::collision_detector_core PROPERTIES
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/lib/libcollision_detector_core.so"
  IMPORTED_SONAME_RELEASE "libcollision_detector_core.so"
  )

list(APPEND _cmake_import_check_targets nav2_collision_monitor::collision_detector_core )
list(APPEND _cmake_import_check_files_for_nav2_collision_monitor::collision_detector_core "${_IMPORT_PREFIX}/lib/libcollision_detector_core.so" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
