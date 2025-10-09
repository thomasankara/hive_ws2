#----------------------------------------------------------------
# Generated CMake target import file for configuration "Release".
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "costmap_queue::costmap_queue" for configuration "Release"
set_property(TARGET costmap_queue::costmap_queue APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(costmap_queue::costmap_queue PROPERTIES
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/lib/libcostmap_queue.so"
  IMPORTED_SONAME_RELEASE "libcostmap_queue.so"
  )

list(APPEND _cmake_import_check_targets costmap_queue::costmap_queue )
list(APPEND _cmake_import_check_files_for_costmap_queue::costmap_queue "${_IMPORT_PREFIX}/lib/libcostmap_queue.so" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
