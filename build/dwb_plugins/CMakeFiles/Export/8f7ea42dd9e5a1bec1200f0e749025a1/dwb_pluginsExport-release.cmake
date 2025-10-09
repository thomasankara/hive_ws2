#----------------------------------------------------------------
# Generated CMake target import file for configuration "Release".
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "dwb_plugins::standard_traj_generator" for configuration "Release"
set_property(TARGET dwb_plugins::standard_traj_generator APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(dwb_plugins::standard_traj_generator PROPERTIES
  IMPORTED_LINK_DEPENDENT_LIBRARIES_RELEASE "nav_2d_utils::conversions"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/lib/libstandard_traj_generator.so"
  IMPORTED_SONAME_RELEASE "libstandard_traj_generator.so"
  )

list(APPEND _cmake_import_check_targets dwb_plugins::standard_traj_generator )
list(APPEND _cmake_import_check_files_for_dwb_plugins::standard_traj_generator "${_IMPORT_PREFIX}/lib/libstandard_traj_generator.so" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
