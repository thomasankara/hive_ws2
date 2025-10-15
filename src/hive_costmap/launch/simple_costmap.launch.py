from launch import LaunchDescription
from launch_ros.actions import Node

def generate_launch_description():
    return LaunchDescription([
        Node(
            package="hive_costmap",
            executable="simple_costmap_node",
            name="simple_costmap",
            namespace="robot1",
            output="screen",
            parameters=[{"use_sim_time": True}],
        )
    ])
