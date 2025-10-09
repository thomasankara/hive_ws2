#----------------------------------------------------------------
# Generated CMake target import file for configuration "Release".
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "nav2_rotation_shim_controller::nav2_rotation_shim_controller" for configuration "Release"
set_property(TARGET nav2_rotation_shim_controller::nav2_rotation_shim_controller APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(nav2_rotation_shim_controller::nav2_rotation_shim_controller PROPERTIES
  IMPORTED_LINK_DEPENDENT_LIBRARIES_RELEASE "nav2_util::nav2_util_core;tf2::tf2"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/lib/libnav2_rotation_shim_controller.so"
  IMPORTED_SONAME_RELEASE "libnav2_rotation_shim_controller.so"
  )

list(APPEND _cmake_import_check_targets nav2_rotation_shim_controller::nav2_rotation_shim_controller )
list(APPEND _cmake_import_check_files_for_nav2_rotation_shim_controller::nav2_rotation_shim_controller "${_IMPORT_PREFIX}/lib/libnav2_rotation_shim_controller.so" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
