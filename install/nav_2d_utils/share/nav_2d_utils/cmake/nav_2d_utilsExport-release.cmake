#----------------------------------------------------------------
# Generated CMake target import file for configuration "Release".
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "nav_2d_utils::conversions" for configuration "Release"
set_property(TARGET nav_2d_utils::conversions APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(nav_2d_utils::conversions PROPERTIES
  IMPORTED_LINK_DEPENDENT_LIBRARIES_RELEASE "nav2_util::nav2_util_core"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/lib/libconversions.so"
  IMPORTED_SONAME_RELEASE "libconversions.so"
  )

list(APPEND _cmake_import_check_targets nav_2d_utils::conversions )
list(APPEND _cmake_import_check_files_for_nav_2d_utils::conversions "${_IMPORT_PREFIX}/lib/libconversions.so" )

# Import target "nav_2d_utils::path_ops" for configuration "Release"
set_property(TARGET nav_2d_utils::path_ops APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(nav_2d_utils::path_ops PROPERTIES
  IMPORTED_LINK_DEPENDENT_LIBRARIES_RELEASE "geometry_msgs::geometry_msgs__rosidl_generator_c;geometry_msgs::geometry_msgs__rosidl_typesupport_fastrtps_c;geometry_msgs::geometry_msgs__rosidl_typesupport_introspection_c;geometry_msgs::geometry_msgs__rosidl_typesupport_c;geometry_msgs::geometry_msgs__rosidl_typesupport_fastrtps_cpp;geometry_msgs::geometry_msgs__rosidl_typesupport_introspection_cpp;geometry_msgs::geometry_msgs__rosidl_typesupport_cpp;geometry_msgs::geometry_msgs__rosidl_generator_py"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/lib/libpath_ops.so"
  IMPORTED_SONAME_RELEASE "libpath_ops.so"
  )

list(APPEND _cmake_import_check_targets nav_2d_utils::path_ops )
list(APPEND _cmake_import_check_files_for_nav_2d_utils::path_ops "${_IMPORT_PREFIX}/lib/libpath_ops.so" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
