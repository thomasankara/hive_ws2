#----------------------------------------------------------------
# Generated CMake target import file for configuration "Release".
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "nav2_smoother::smoother_server_core" for configuration "Release"
set_property(TARGET nav2_smoother::smoother_server_core APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(nav2_smoother::smoother_server_core PROPERTIES
  IMPORTED_LINK_DEPENDENT_LIBRARIES_RELEASE "tf2::tf2"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/lib/libsmoother_server_core.so"
  IMPORTED_SONAME_RELEASE "libsmoother_server_core.so"
  )

list(APPEND _cmake_import_check_targets nav2_smoother::smoother_server_core )
list(APPEND _cmake_import_check_files_for_nav2_smoother::smoother_server_core "${_IMPORT_PREFIX}/lib/libsmoother_server_core.so" )

# Import target "nav2_smoother::simple_smoother" for configuration "Release"
set_property(TARGET nav2_smoother::simple_smoother APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(nav2_smoother::simple_smoother PROPERTIES
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/lib/libsimple_smoother.so"
  IMPORTED_SONAME_RELEASE "libsimple_smoother.so"
  )

list(APPEND _cmake_import_check_targets nav2_smoother::simple_smoother )
list(APPEND _cmake_import_check_files_for_nav2_smoother::simple_smoother "${_IMPORT_PREFIX}/lib/libsimple_smoother.so" )

# Import target "nav2_smoother::savitzky_golay_smoother" for configuration "Release"
set_property(TARGET nav2_smoother::savitzky_golay_smoother APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(nav2_smoother::savitzky_golay_smoother PROPERTIES
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/lib/libsavitzky_golay_smoother.so"
  IMPORTED_SONAME_RELEASE "libsavitzky_golay_smoother.so"
  )

list(APPEND _cmake_import_check_targets nav2_smoother::savitzky_golay_smoother )
list(APPEND _cmake_import_check_files_for_nav2_smoother::savitzky_golay_smoother "${_IMPORT_PREFIX}/lib/libsavitzky_golay_smoother.so" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
