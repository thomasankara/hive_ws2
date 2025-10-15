cmake_minimum_required(VERSION 3.16)
project(dev_route_provider)

find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(std_srvs REQUIRED)
find_package(hive_interface2 REQUIRED)

# Try pkg-config for mysqlclient
find_package(PkgConfig QUIET)
if(PkgConfig_FOUND)
  pkg_check_modules(MYSQLCLIENT QUIET mysqlclient)
endif()

if(MYSQLCLIENT_FOUND)
  message(STATUS "mysqlclient via pkg-config found")
  add_library(mysqlclient_imported INTERFACE)
  target_include_directories(mysqlclient_imported INTERFACE ${MYSQLCLIENT_INCLUDE_DIRS})
  target_link_libraries(mysqlclient_imported INTERFACE ${MYSQLCLIENT_LINK_LIBRARIES})
else()
  message(STATUS "pkg-config mysqlclient NOT found, falling back to find_library/include")
  find_library(MYSQLCLIENT_LIB mysqlclient)
  if(NOT MYSQLCLIENT_LIB)
    message(FATAL_ERROR "Could not find libmysqlclient. Install libmysqlclient-dev")
  endif()
  # Ubuntu 24.04 headers
  set(MYSQLCLIENT_INCLUDE_DIR "/usr/include/mysql")
  if(NOT EXISTS "${MYSQLCLIENT_INCLUDE_DIR}/mysql.h")
    message(FATAL_ERROR "mysql.h not found in ${MYSQLCLIENT_INCLUDE_DIR}. Install libmysqlclient-dev")
  endif()
  add_library(mysqlclient_imported INTERFACE)
  target_include_directories(mysqlclient_imported INTERFACE ${MYSQLCLIENT_INCLUDE_DIR})
  target_link_libraries(mysqlclient_imported INTERFACE ${MYSQLCLIENT_LIB})
endif()

add_executable(dev_route_provider_node
  src/dev_route_provider_node.cpp
  src/db_mysql.cpp
)
target_include_directories(dev_route_provider_node PRIVATE
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
)
ament_target_dependencies(dev_route_provider_node
  rclcpp
  std_srvs
  hive_interface2
)
target_link_libraries(dev_route_provider_node
  mysqlclient_imported
)

install(TARGETS dev_route_provider_node
  RUNTIME DESTINATION lib/${PROJECT_NAME}
)

install(DIRECTORY launch
  DESTINATION share/${PROJECT_NAME}
)

ament_package()
