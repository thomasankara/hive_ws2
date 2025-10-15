from launch import LaunchDescription
from launch_ros.actions import Node
from launch.substitutions import LaunchConfiguration
from launch.actions import DeclareLaunchArgument

def generate_launch_description():
    args = [
        DeclareLaunchArgument('robot_namespace', default_value='robot1'),
        DeclareLaunchArgument('db_host', default_value='127.0.0.1'),
        DeclareLaunchArgument('db_port', default_value='3306'),
        DeclareLaunchArgument('db_user', default_value='hive'),
        DeclareLaunchArgument('db_password', default_value='change_me_str0ng!'),
        DeclareLaunchArgument('db_name', default_value='local_robot_db'),
        DeclareLaunchArgument('enterprise_full_id_str', default_value='enterprise_001'),
        DeclareLaunchArgument('deployment_full_id_str', default_value='0001__les_trois_forets'),
        DeclareLaunchArgument('slam_session_full_id_str', default_value='slam_2025_01'),
    ]

    return LaunchDescription(args + [
        Node(
            package='dev_route_provider',
            executable='dev_route_provider_node',
            name='dev_route_provider',
            output='screen',
            parameters=[{
                'robot_namespace': LaunchConfiguration('robot_namespace'),
                'db_host': LaunchConfiguration('db_host'),
                'db_port': LaunchConfiguration('db_port'),
                'db_user': LaunchConfiguration('db_user'),
                'db_password': LaunchConfiguration('db_password'),
                'db_name': LaunchConfiguration('db_name'),
                'enterprise_full_id_str': LaunchConfiguration('enterprise_full_id_str'),
                'deployment_full_id_str': LaunchConfiguration('deployment_full_id_str'),
                'slam_session_full_id_str': LaunchConfiguration('slam_session_full_id_str'),
            }]
        )
    ])
