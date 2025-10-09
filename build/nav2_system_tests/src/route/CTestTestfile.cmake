# CMake generated Testfile for 
# Source directory: /home/thomas24/hive_ws2/src/navigation2/nav2_system_tests/src/route
# Build directory: /home/thomas24/hive_ws2/build/nav2_system_tests/src/route
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test(test_route "/usr/bin/python3" "-u" "/opt/ros/jazzy/share/ament_cmake_test/cmake/run_test.py" "/home/thomas24/hive_ws2/build/nav2_system_tests/test_results/nav2_system_tests/test_route.xml" "--package-name" "nav2_system_tests" "--generate-result-on-success" "--env" "TEST_DIR=/home/thomas24/hive_ws2/src/navigation2/nav2_system_tests/src/route" "BT_NAVIGATOR_XML=navigate_to_pose_w_replanning_and_recovery.xml" "TESTER=tester_node.py" "ASTAR=True" "CONTROLLER=nav2_regulated_pure_pursuit_controller::RegulatedPurePursuitController" "PLANNER=nav2_navfn_planner::NavfnPlanner" "--command" "/home/thomas24/hive_ws2/src/navigation2/nav2_system_tests/src/route/test_route_launch.py")
set_tests_properties(test_route PROPERTIES  TIMEOUT "180" WORKING_DIRECTORY "/home/thomas24/hive_ws2/build/nav2_system_tests/src/route" _BACKTRACE_TRIPLES "/opt/ros/jazzy/share/ament_cmake_test/cmake/ament_add_test.cmake;125;add_test;/home/thomas24/hive_ws2/src/navigation2/nav2_system_tests/src/route/CMakeLists.txt;1;ament_add_test;/home/thomas24/hive_ws2/src/navigation2/nav2_system_tests/src/route/CMakeLists.txt;0;")
