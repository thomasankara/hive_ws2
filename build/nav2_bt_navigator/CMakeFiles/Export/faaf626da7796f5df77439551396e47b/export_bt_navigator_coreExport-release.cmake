#----------------------------------------------------------------
# Generated CMake target import file for configuration "Release".
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "nav2_bt_navigator::bt_navigator_core" for configuration "Release"
set_property(TARGET nav2_bt_navigator::bt_navigator_core APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(nav2_bt_navigator::bt_navigator_core PROPERTIES
  IMPORTED_LINK_DEPENDENT_LIBRARIES_RELEASE "nav2_behavior_tree::nav2_behavior_tree;rclcpp_lifecycle::rclcpp_lifecycle"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/lib/libbt_navigator_core.so"
  IMPORTED_SONAME_RELEASE "libbt_navigator_core.so"
  )

list(APPEND _cmake_import_check_targets nav2_bt_navigator::bt_navigator_core )
list(APPEND _cmake_import_check_files_for_nav2_bt_navigator::bt_navigator_core "${_IMPORT_PREFIX}/lib/libbt_navigator_core.so" )

# Import target "nav2_bt_navigator::nav2_navigate_to_pose_navigator" for configuration "Release"
set_property(TARGET nav2_bt_navigator::nav2_navigate_to_pose_navigator APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(nav2_bt_navigator::nav2_navigate_to_pose_navigator PROPERTIES
  IMPORTED_LINK_DEPENDENT_LIBRARIES_RELEASE "ament_index_cpp::ament_index_cpp;nav2_behavior_tree::nav2_behavior_tree;rclcpp_lifecycle::rclcpp_lifecycle"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/lib/libnav2_navigate_to_pose_navigator.so"
  IMPORTED_SONAME_RELEASE "libnav2_navigate_to_pose_navigator.so"
  )

list(APPEND _cmake_import_check_targets nav2_bt_navigator::nav2_navigate_to_pose_navigator )
list(APPEND _cmake_import_check_files_for_nav2_bt_navigator::nav2_navigate_to_pose_navigator "${_IMPORT_PREFIX}/lib/libnav2_navigate_to_pose_navigator.so" )

# Import target "nav2_bt_navigator::nav2_navigate_through_poses" for configuration "Release"
set_property(TARGET nav2_bt_navigator::nav2_navigate_through_poses APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(nav2_bt_navigator::nav2_navigate_through_poses PROPERTIES
  IMPORTED_LINK_DEPENDENT_LIBRARIES_RELEASE "ament_index_cpp::ament_index_cpp;rclcpp_lifecycle::rclcpp_lifecycle"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/lib/libnav2_navigate_through_poses.so"
  IMPORTED_SONAME_RELEASE "libnav2_navigate_through_poses.so"
  )

list(APPEND _cmake_import_check_targets nav2_bt_navigator::nav2_navigate_through_poses )
list(APPEND _cmake_import_check_files_for_nav2_bt_navigator::nav2_navigate_through_poses "${_IMPORT_PREFIX}/lib/libnav2_navigate_through_poses.so" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
