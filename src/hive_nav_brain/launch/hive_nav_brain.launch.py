from launch import LaunchDescription
from launch_ros.actions import Node
from launch.substitutions import LaunchConfiguration
from launch.actions import DeclareLaunchArgument

def generate_launch_description():
    return LaunchDescription([
        DeclareLaunchArgument('robot_namespace', default_value='robot1'),
        DeclareLaunchArgument('fetch_service_basename', default_value='refresh_all_data'),

        Node(
            package='hive_nav_brain',
            executable='hive_nav_brain_node',
            name='hive_nav_brain_node',
            parameters=[
                {'robot_namespace': LaunchConfiguration('robot_namespace')},
                {'fetch_service_basename': LaunchConfiguration('fetch_service_basename')}
            ],
            output='screen'
        )
    ])
