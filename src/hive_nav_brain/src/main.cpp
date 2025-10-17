#include "hive_nav_brain/hive_nav_brain_node.hpp"
#include <rclcpp/rclcpp.hpp>

int main(int argc, char** argv)
{
  rclcpp::init(argc, argv);
  auto node = std::make_shared<HiveNavBrainNode>();
  node->blocking_startup();   // bloque jusqu’à service + datas, puis démarre le timer 10 Hz
  rclcpp::spin(node);         // boucle d’évènements ROS 2
  rclcpp::shutdown();
  return 0;
}
