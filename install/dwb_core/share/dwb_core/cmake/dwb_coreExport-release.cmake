#----------------------------------------------------------------
# Generated CMake target import file for configuration "Release".
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "dwb_core::dwb_core" for configuration "Release"
set_property(TARGET dwb_core::dwb_core APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(dwb_core::dwb_core PROPERTIES
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/lib/libdwb_core.so"
  IMPORTED_SONAME_RELEASE "libdwb_core.so"
  )

list(APPEND _cmake_import_check_targets dwb_core::dwb_core )
list(APPEND _cmake_import_check_files_for_dwb_core::dwb_core "${_IMPORT_PREFIX}/lib/libdwb_core.so" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
