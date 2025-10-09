#----------------------------------------------------------------
# Generated CMake target import file for configuration "Release".
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "nav2_navfn_planner::nav2_navfn_planner" for configuration "Release"
set_property(TARGET nav2_navfn_planner::nav2_navfn_planner APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(nav2_navfn_planner::nav2_navfn_planner PROPERTIES
  IMPORTED_LINK_DEPENDENT_LIBRARIES_RELEASE "builtin_interfaces::builtin_interfaces__rosidl_generator_c;builtin_interfaces::builtin_interfaces__rosidl_typesupport_fastrtps_c;builtin_interfaces::builtin_interfaces__rosidl_typesupport_introspection_c;builtin_interfaces::builtin_interfaces__rosidl_typesupport_c;builtin_interfaces::builtin_interfaces__rosidl_typesupport_fastrtps_cpp;builtin_interfaces::builtin_interfaces__rosidl_typesupport_introspection_cpp;builtin_interfaces::builtin_interfaces__rosidl_typesupport_cpp;builtin_interfaces::builtin_interfaces__rosidl_generator_py"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/lib/libnav2_navfn_planner.so"
  IMPORTED_SONAME_RELEASE "libnav2_navfn_planner.so"
  )

list(APPEND _cmake_import_check_targets nav2_navfn_planner::nav2_navfn_planner )
list(APPEND _cmake_import_check_files_for_nav2_navfn_planner::nav2_navfn_planner "${_IMPORT_PREFIX}/lib/libnav2_navfn_planner.so" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
