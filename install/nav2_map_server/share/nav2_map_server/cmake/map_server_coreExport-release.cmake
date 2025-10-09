#----------------------------------------------------------------
# Generated CMake target import file for configuration "Release".
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "nav2_map_server::map_server_core" for configuration "Release"
set_property(TARGET nav2_map_server::map_server_core APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(nav2_map_server::map_server_core PROPERTIES
  IMPORTED_LINK_DEPENDENT_LIBRARIES_RELEASE "lifecycle_msgs::lifecycle_msgs__rosidl_generator_c;lifecycle_msgs::lifecycle_msgs__rosidl_typesupport_fastrtps_c;lifecycle_msgs::lifecycle_msgs__rosidl_typesupport_introspection_c;lifecycle_msgs::lifecycle_msgs__rosidl_typesupport_c;lifecycle_msgs::lifecycle_msgs__rosidl_typesupport_fastrtps_cpp;lifecycle_msgs::lifecycle_msgs__rosidl_typesupport_introspection_cpp;lifecycle_msgs::lifecycle_msgs__rosidl_typesupport_cpp;lifecycle_msgs::lifecycle_msgs__rosidl_generator_py;yaml-cpp::yaml-cpp"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/lib/libmap_server_core.so"
  IMPORTED_SONAME_RELEASE "libmap_server_core.so"
  )

list(APPEND _cmake_import_check_targets nav2_map_server::map_server_core )
list(APPEND _cmake_import_check_files_for_nav2_map_server::map_server_core "${_IMPORT_PREFIX}/lib/libmap_server_core.so" )

# Import target "nav2_map_server::map_io" for configuration "Release"
set_property(TARGET nav2_map_server::map_io APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(nav2_map_server::map_io PROPERTIES
  IMPORTED_LINK_DEPENDENT_LIBRARIES_RELEASE "tf2::tf2;yaml-cpp::yaml-cpp"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/lib/libmap_io.so"
  IMPORTED_SONAME_RELEASE "libmap_io.so"
  )

list(APPEND _cmake_import_check_targets nav2_map_server::map_io )
list(APPEND _cmake_import_check_files_for_nav2_map_server::map_io "${_IMPORT_PREFIX}/lib/libmap_io.so" )

# Import target "nav2_map_server::vector_object_core" for configuration "Release"
set_property(TARGET nav2_map_server::vector_object_core APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(nav2_map_server::vector_object_core PROPERTIES
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/lib/libvector_object_core.so"
  IMPORTED_SONAME_RELEASE "libvector_object_core.so"
  )

list(APPEND _cmake_import_check_targets nav2_map_server::vector_object_core )
list(APPEND _cmake_import_check_files_for_nav2_map_server::vector_object_core "${_IMPORT_PREFIX}/lib/libvector_object_core.so" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
