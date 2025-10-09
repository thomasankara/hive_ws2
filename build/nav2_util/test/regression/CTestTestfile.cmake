# CMake generated Testfile for 
# Source directory: /home/thomas24/hive_ws2/src/navigation2/nav2_util/test/regression
# Build directory: /home/thomas24/hive_ws2/build/nav2_util/test/regression
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test(map_bresenham_2d "/usr/bin/python3" "-u" "/opt/ros/jazzy/share/ament_cmake_test/cmake/run_test.py" "/home/thomas24/hive_ws2/build/nav2_util/test_results/nav2_util/map_bresenham_2d.gtest.xml" "--package-name" "nav2_util" "--output-file" "/home/thomas24/hive_ws2/build/nav2_util/ament_cmake_gtest/map_bresenham_2d.txt" "--command" "/home/thomas24/hive_ws2/build/nav2_util/test/regression/map_bresenham_2d" "--gtest_output=xml:/home/thomas24/hive_ws2/build/nav2_util/test_results/nav2_util/map_bresenham_2d.gtest.xml")
set_tests_properties(map_bresenham_2d PROPERTIES  LABELS "gtest" REQUIRED_FILES "/home/thomas24/hive_ws2/build/nav2_util/test/regression/map_bresenham_2d" TIMEOUT "60" WORKING_DIRECTORY "/home/thomas24/hive_ws2/build/nav2_util/test/regression" _BACKTRACE_TRIPLES "/opt/ros/jazzy/share/ament_cmake_test/cmake/ament_add_test.cmake;125;add_test;/opt/ros/jazzy/share/ament_cmake_gtest/cmake/ament_add_gtest_test.cmake;95;ament_add_test;/opt/ros/jazzy/share/ament_cmake_gtest/cmake/ament_add_gtest.cmake;93;ament_add_gtest_test;/home/thomas24/hive_ws2/src/navigation2/nav2_util/test/regression/CMakeLists.txt;2;ament_add_gtest;/home/thomas24/hive_ws2/src/navigation2/nav2_util/test/regression/CMakeLists.txt;0;")
subdirs("../../gtest")
