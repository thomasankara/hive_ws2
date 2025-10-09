# CMake generated Testfile for 
# Source directory: /home/thomas24/hive_ws2/src/navigation2/nav2_system_tests/src/gps_navigation
# Build directory: /home/thomas24/hive_ws2/build/nav2_system_tests/src/gps_navigation
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test(test_gps_waypoint_follower "/usr/bin/python3" "-u" "/opt/ros/jazzy/share/ament_cmake_test/cmake/run_test.py" "/home/thomas24/hive_ws2/build/nav2_system_tests/test_results/nav2_system_tests/test_gps_waypoint_follower.xml" "--package-name" "nav2_system_tests" "--generate-result-on-success" "--env" "TEST_DIR=/home/thomas24/hive_ws2/src/navigation2/nav2_system_tests/src/gps_navigation" "--command" "/home/thomas24/hive_ws2/src/navigation2/nav2_system_tests/src/gps_navigation/test_case_py.launch.py")
set_tests_properties(test_gps_waypoint_follower PROPERTIES  TIMEOUT "180" WORKING_DIRECTORY "/home/thomas24/hive_ws2/build/nav2_system_tests/src/gps_navigation" _BACKTRACE_TRIPLES "/opt/ros/jazzy/share/ament_cmake_test/cmake/ament_add_test.cmake;125;add_test;/home/thomas24/hive_ws2/src/navigation2/nav2_system_tests/src/gps_navigation/CMakeLists.txt;1;ament_add_test;/home/thomas24/hive_ws2/src/navigation2/nav2_system_tests/src/gps_navigation/CMakeLists.txt;0;")
