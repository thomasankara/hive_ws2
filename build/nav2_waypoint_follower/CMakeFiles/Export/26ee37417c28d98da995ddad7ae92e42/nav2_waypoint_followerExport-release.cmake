#----------------------------------------------------------------
# Generated CMake target import file for configuration "Release".
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "nav2_waypoint_follower::waypoint_follower_core" for configuration "Release"
set_property(TARGET nav2_waypoint_follower::waypoint_follower_core APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(nav2_waypoint_follower::waypoint_follower_core PROPERTIES
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/lib/libwaypoint_follower_core.so"
  IMPORTED_SONAME_RELEASE "libwaypoint_follower_core.so"
  )

list(APPEND _cmake_import_check_targets nav2_waypoint_follower::waypoint_follower_core )
list(APPEND _cmake_import_check_files_for_nav2_waypoint_follower::waypoint_follower_core "${_IMPORT_PREFIX}/lib/libwaypoint_follower_core.so" )

# Import target "nav2_waypoint_follower::wait_at_waypoint" for configuration "Release"
set_property(TARGET nav2_waypoint_follower::wait_at_waypoint APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(nav2_waypoint_follower::wait_at_waypoint PROPERTIES
  IMPORTED_LINK_DEPENDENT_LIBRARIES_RELEASE "nav2_util::nav2_util_core"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/lib/libwait_at_waypoint.so"
  IMPORTED_SONAME_RELEASE "libwait_at_waypoint.so"
  )

list(APPEND _cmake_import_check_targets nav2_waypoint_follower::wait_at_waypoint )
list(APPEND _cmake_import_check_files_for_nav2_waypoint_follower::wait_at_waypoint "${_IMPORT_PREFIX}/lib/libwait_at_waypoint.so" )

# Import target "nav2_waypoint_follower::photo_at_waypoint" for configuration "Release"
set_property(TARGET nav2_waypoint_follower::photo_at_waypoint APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(nav2_waypoint_follower::photo_at_waypoint PROPERTIES
  IMPORTED_LINK_DEPENDENT_LIBRARIES_RELEASE "nav2_util::nav2_util_core"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/lib/libphoto_at_waypoint.so"
  IMPORTED_SONAME_RELEASE "libphoto_at_waypoint.so"
  )

list(APPEND _cmake_import_check_targets nav2_waypoint_follower::photo_at_waypoint )
list(APPEND _cmake_import_check_files_for_nav2_waypoint_follower::photo_at_waypoint "${_IMPORT_PREFIX}/lib/libphoto_at_waypoint.so" )

# Import target "nav2_waypoint_follower::input_at_waypoint" for configuration "Release"
set_property(TARGET nav2_waypoint_follower::input_at_waypoint APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(nav2_waypoint_follower::input_at_waypoint PROPERTIES
  IMPORTED_LINK_DEPENDENT_LIBRARIES_RELEASE "nav2_util::nav2_util_core"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/lib/libinput_at_waypoint.so"
  IMPORTED_SONAME_RELEASE "libinput_at_waypoint.so"
  )

list(APPEND _cmake_import_check_targets nav2_waypoint_follower::input_at_waypoint )
list(APPEND _cmake_import_check_files_for_nav2_waypoint_follower::input_at_waypoint "${_IMPORT_PREFIX}/lib/libinput_at_waypoint.so" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
