#include "hive_nav_brain/hive_nav_brain_node.hpp"
#include <rclcpp/rclcpp.hpp>

int main(int argc, char** argv)
{
  rclcpp::init(argc, argv);
  auto node = std::make_shared<HiveNavBrainNode>();
  node->blocking_startup();
  rclcpp::spin(node);
  rclcpp::shutdown();
  return 0;
}
