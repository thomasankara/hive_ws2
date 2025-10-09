#----------------------------------------------------------------
# Generated CMake target import file for configuration "Release".
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "opennav_docking::opennav_docking_core" for configuration "Release"
set_property(TARGET opennav_docking::opennav_docking_core APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(opennav_docking::opennav_docking_core PROPERTIES
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/lib/libopennav_docking_core.so"
  IMPORTED_SONAME_RELEASE "libopennav_docking_core.so"
  )

list(APPEND _cmake_import_check_targets opennav_docking::opennav_docking_core )
list(APPEND _cmake_import_check_files_for_opennav_docking::opennav_docking_core "${_IMPORT_PREFIX}/lib/libopennav_docking_core.so" )

# Import target "opennav_docking::controller" for configuration "Release"
set_property(TARGET opennav_docking::controller APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(opennav_docking::controller PROPERTIES
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/lib/libcontroller.so"
  IMPORTED_SONAME_RELEASE "libcontroller.so"
  )

list(APPEND _cmake_import_check_targets opennav_docking::controller )
list(APPEND _cmake_import_check_files_for_opennav_docking::controller "${_IMPORT_PREFIX}/lib/libcontroller.so" )

# Import target "opennav_docking::pose_filter" for configuration "Release"
set_property(TARGET opennav_docking::pose_filter APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(opennav_docking::pose_filter PROPERTIES
  IMPORTED_LINK_DEPENDENT_LIBRARIES_RELEASE "rclcpp::rclcpp"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/lib/libpose_filter.so"
  IMPORTED_SONAME_RELEASE "libpose_filter.so"
  )

list(APPEND _cmake_import_check_targets opennav_docking::pose_filter )
list(APPEND _cmake_import_check_files_for_opennav_docking::pose_filter "${_IMPORT_PREFIX}/lib/libpose_filter.so" )

# Import target "opennav_docking::simple_charging_dock" for configuration "Release"
set_property(TARGET opennav_docking::simple_charging_dock APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(opennav_docking::simple_charging_dock PROPERTIES
  IMPORTED_LINK_DEPENDENT_LIBRARIES_RELEASE "nav2_util::nav2_util_core;tf2::tf2"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/lib/libsimple_charging_dock.so"
  IMPORTED_SONAME_RELEASE "libsimple_charging_dock.so"
  )

list(APPEND _cmake_import_check_targets opennav_docking::simple_charging_dock )
list(APPEND _cmake_import_check_files_for_opennav_docking::simple_charging_dock "${_IMPORT_PREFIX}/lib/libsimple_charging_dock.so" )

# Import target "opennav_docking::simple_non_charging_dock" for configuration "Release"
set_property(TARGET opennav_docking::simple_non_charging_dock APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(opennav_docking::simple_non_charging_dock PROPERTIES
  IMPORTED_LINK_DEPENDENT_LIBRARIES_RELEASE "nav2_util::nav2_util_core;tf2::tf2"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/lib/libsimple_non_charging_dock.so"
  IMPORTED_SONAME_RELEASE "libsimple_non_charging_dock.so"
  )

list(APPEND _cmake_import_check_targets opennav_docking::simple_non_charging_dock )
list(APPEND _cmake_import_check_files_for_opennav_docking::simple_non_charging_dock "${_IMPORT_PREFIX}/lib/libsimple_non_charging_dock.so" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
