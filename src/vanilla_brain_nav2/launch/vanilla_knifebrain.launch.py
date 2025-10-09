from launch import LaunchDescription
from launch.actions import DeclareLaunchArgument
from launch.substitutions import LaunchConfiguration
from launch_ros.actions import Node

def generate_launch_description():
    namespace = LaunchConfiguration('namespace')
    goal_topic = LaunchConfiguration('goal_topic')
    global_frame = LaunchConfiguration('global_frame')
    base_frame = LaunchConfiguration('base_frame')
    log_level = LaunchConfiguration('log_level')

    return LaunchDescription([
        DeclareLaunchArgument('namespace', default_value='robot1'),
        DeclareLaunchArgument('goal_topic', default_value='goal_pose'),
        DeclareLaunchArgument('global_frame', default_value='odom'),
        DeclareLaunchArgument('base_frame', default_value='base_footprint'),
        DeclareLaunchArgument('log_level', default_value='info'),

        Node(
            package='vanilla_brain_nav2',
            executable='vanilla_knifebrain',
            namespace=namespace,
            name='vanilla_knifebrain',
            output='screen',
            parameters=[{
                'goal_topic': goal_topic,
                'global_frame': global_frame,
                'base_frame': base_frame
            }],
            arguments=['--ros-args', '--log-level', log_level],
            remappings=[('/tf', 'tf'), ('/tf_static', 'tf_static')],
        )
    ])
