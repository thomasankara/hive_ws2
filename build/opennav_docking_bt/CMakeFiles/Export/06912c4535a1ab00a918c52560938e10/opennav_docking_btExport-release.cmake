#----------------------------------------------------------------
# Generated CMake target import file for configuration "Release".
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "opennav_docking_bt::opennav_dock_action_bt_node" for configuration "Release"
set_property(TARGET opennav_docking_bt::opennav_dock_action_bt_node APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(opennav_docking_bt::opennav_dock_action_bt_node PROPERTIES
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/lib/libopennav_dock_action_bt_node.so"
  IMPORTED_SONAME_RELEASE "libopennav_dock_action_bt_node.so"
  )

list(APPEND _cmake_import_check_targets opennav_docking_bt::opennav_dock_action_bt_node )
list(APPEND _cmake_import_check_files_for_opennav_docking_bt::opennav_dock_action_bt_node "${_IMPORT_PREFIX}/lib/libopennav_dock_action_bt_node.so" )

# Import target "opennav_docking_bt::opennav_undock_action_bt_node" for configuration "Release"
set_property(TARGET opennav_docking_bt::opennav_undock_action_bt_node APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(opennav_docking_bt::opennav_undock_action_bt_node PROPERTIES
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/lib/libopennav_undock_action_bt_node.so"
  IMPORTED_SONAME_RELEASE "libopennav_undock_action_bt_node.so"
  )

list(APPEND _cmake_import_check_targets opennav_docking_bt::opennav_undock_action_bt_node )
list(APPEND _cmake_import_check_files_for_opennav_docking_bt::opennav_undock_action_bt_node "${_IMPORT_PREFIX}/lib/libopennav_undock_action_bt_node.so" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
