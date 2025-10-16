# generated from ament/cmake/core/templates/nameConfig.cmake.in

# prevent multiple inclusion
if(_hive_nav_brain_CONFIG_INCLUDED)
  # ensure to keep the found flag the same
  if(NOT DEFINED hive_nav_brain_FOUND)
    # explicitly set it to FALSE, otherwise CMake will set it to TRUE
    set(hive_nav_brain_FOUND FALSE)
  elseif(NOT hive_nav_brain_FOUND)
    # use separate condition to avoid uninitialized variable warning
    set(hive_nav_brain_FOUND FALSE)
  endif()
  return()
endif()
set(_hive_nav_brain_CONFIG_INCLUDED TRUE)

# output package information
if(NOT hive_nav_brain_FIND_QUIETLY)
  message(STATUS "Found hive_nav_brain: 0.0.0 (${hive_nav_brain_DIR})")
endif()

# warn when using a deprecated package
if(NOT "" STREQUAL "")
  set(_msg "Package 'hive_nav_brain' is deprecated")
  # append custom deprecation text if available
  if(NOT "" STREQUAL "TRUE")
    set(_msg "${_msg} ()")
  endif()
  # optionally quiet the deprecation message
  if(NOT hive_nav_brain_DEPRECATED_QUIET)
    message(DEPRECATION "${_msg}")
  endif()
endif()

# flag package as ament-based to distinguish it after being find_package()-ed
set(hive_nav_brain_FOUND_AMENT_PACKAGE TRUE)

# include all config extra files
set(_extras "")
foreach(_extra ${_extras})
  include("${hive_nav_brain_DIR}/${_extra}")
endforeach()
