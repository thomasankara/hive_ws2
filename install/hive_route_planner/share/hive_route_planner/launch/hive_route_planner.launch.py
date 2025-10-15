from launch import LaunchDescription
from launch_ros.actions import Node
from launch.substitutions import LaunchConfiguration
from launch.actions import DeclareLaunchArgument

def generate_launch_description():
    args = [
        DeclareLaunchArgument('robot_namespace', default_value='robot1'),

        # --- VIZ graph ---
        DeclareLaunchArgument('enable_graph_viz', default_value='true'),
        DeclareLaunchArgument('viz_frame_id', default_value='map'),
        DeclareLaunchArgument('viz_ns', default_value='route_graph'),
        DeclareLaunchArgument('viz_topic', default_value='route_graph_markers'),
        DeclareLaunchArgument('viz_line_width', default_value='0.10'),
        DeclareLaunchArgument('viz_point_scale', default_value='0.15'),

        # --- VIZ route plan (multi-topics) ---
        DeclareLaunchArgument('enable_route_plan_viz', default_value='true'),

        # --- A* params ---
        DeclareLaunchArgument('epsilon_merge_m', default_value='0.05'),
        DeclareLaunchArgument('epsilon_endpoint_frac', default_value='0.001'),
        DeclareLaunchArgument('fallback_speed_mps', default_value='1.0'),
        DeclareLaunchArgument('direct_link_threshold_m', default_value='10.0'),
        DeclareLaunchArgument('direct_link_nominal_speed_mps', default_value='1.5'),
    ]

    return LaunchDescription(args + [
        Node(
            package='hive_route_planner',
            executable='hive_route_planner_node',
            name='hive_route_planner',
            output='screen',
            parameters=[{
                'robot_namespace': LaunchConfiguration('robot_namespace'),

                # --- VIZ graph ---
                'enable_graph_viz': LaunchConfiguration('enable_graph_viz'),
                'viz_frame_id': LaunchConfiguration('viz_frame_id'),
                'viz_ns': LaunchConfiguration('viz_ns'),
                'viz_topic': LaunchConfiguration('viz_topic'),
                'viz_line_width': LaunchConfiguration('viz_line_width'),
                'viz_point_scale': LaunchConfiguration('viz_point_scale'),

                # --- VIZ route plan ---
                'enable_route_plan_viz': LaunchConfiguration('enable_route_plan_viz'),

                # --- A* params ---
                'epsilon_merge_m': LaunchConfiguration('epsilon_merge_m'),
                'epsilon_endpoint_frac': LaunchConfiguration('epsilon_endpoint_frac'),
                'fallback_speed_mps': LaunchConfiguration('fallback_speed_mps'),
                'direct_link_threshold_m': LaunchConfiguration('direct_link_threshold_m'),
                'direct_link_nominal_speed_mps': LaunchConfiguration('direct_link_nominal_speed_mps'),
            }]
        )
    ])
