#----------------------------------------------------------------
# Generated CMake target import file for configuration "Release".
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "nav2_amcl::amcl_core" for configuration "Release"
set_property(TARGET nav2_amcl::amcl_core APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(nav2_amcl::amcl_core PROPERTIES
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/lib/libamcl_core.so"
  IMPORTED_SONAME_RELEASE "libamcl_core.so"
  )

list(APPEND _cmake_import_check_targets nav2_amcl::amcl_core )
list(APPEND _cmake_import_check_files_for_nav2_amcl::amcl_core "${_IMPORT_PREFIX}/lib/libamcl_core.so" )

# Import target "nav2_amcl::pf_lib" for configuration "Release"
set_property(TARGET nav2_amcl::pf_lib APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(nav2_amcl::pf_lib PROPERTIES
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/lib/libpf_lib.so"
  IMPORTED_SONAME_RELEASE "libpf_lib.so"
  )

list(APPEND _cmake_import_check_targets nav2_amcl::pf_lib )
list(APPEND _cmake_import_check_files_for_nav2_amcl::pf_lib "${_IMPORT_PREFIX}/lib/libpf_lib.so" )

# Import target "nav2_amcl::map_lib" for configuration "Release"
set_property(TARGET nav2_amcl::map_lib APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(nav2_amcl::map_lib PROPERTIES
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/lib/libmap_lib.so"
  IMPORTED_SONAME_RELEASE "libmap_lib.so"
  )

list(APPEND _cmake_import_check_targets nav2_amcl::map_lib )
list(APPEND _cmake_import_check_files_for_nav2_amcl::map_lib "${_IMPORT_PREFIX}/lib/libmap_lib.so" )

# Import target "nav2_amcl::motions_lib" for configuration "Release"
set_property(TARGET nav2_amcl::motions_lib APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(nav2_amcl::motions_lib PROPERTIES
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/lib/libmotions_lib.so"
  IMPORTED_SONAME_RELEASE "libmotions_lib.so"
  )

list(APPEND _cmake_import_check_targets nav2_amcl::motions_lib )
list(APPEND _cmake_import_check_files_for_nav2_amcl::motions_lib "${_IMPORT_PREFIX}/lib/libmotions_lib.so" )

# Import target "nav2_amcl::sensors_lib" for configuration "Release"
set_property(TARGET nav2_amcl::sensors_lib APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(nav2_amcl::sensors_lib PROPERTIES
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/lib/libsensors_lib.so"
  IMPORTED_SONAME_RELEASE "libsensors_lib.so"
  )

list(APPEND _cmake_import_check_targets nav2_amcl::sensors_lib )
list(APPEND _cmake_import_check_files_for_nav2_amcl::sensors_lib "${_IMPORT_PREFIX}/lib/libsensors_lib.so" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
