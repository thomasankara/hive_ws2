#----------------------------------------------------------------
# Generated CMake target import file for configuration "Release".
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "dwb_critics::dwb_critics" for configuration "Release"
set_property(TARGET dwb_critics::dwb_critics APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(dwb_critics::dwb_critics PROPERTIES
  IMPORTED_LINK_DEPENDENT_LIBRARIES_RELEASE "nav2_util::nav2_util_core;nav_2d_utils::path_ops"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/lib/libdwb_critics.so"
  IMPORTED_SONAME_RELEASE "libdwb_critics.so"
  )

list(APPEND _cmake_import_check_targets dwb_critics::dwb_critics )
list(APPEND _cmake_import_check_files_for_dwb_critics::dwb_critics "${_IMPORT_PREFIX}/lib/libdwb_critics.so" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
