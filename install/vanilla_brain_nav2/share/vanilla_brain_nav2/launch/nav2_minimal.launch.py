import os
from launch import LaunchDescription
from launch.actions import DeclareLaunchArgument, GroupAction, SetEnvironmentVariable
from launch_ros.actions import Node, PushROSNamespace, SetParameter
from launch_ros.descriptions import ParameterFile
from launch.substitutions import LaunchConfiguration
from nav2_common.launch import RewrittenYaml

def generate_launch_description():
    # === Définition des arguments ===
    namespace   = LaunchConfiguration('namespace')
    use_sim     = LaunchConfiguration('use_sim_time')
    params_path = LaunchConfiguration('params_file')
    autostart   = LaunchConfiguration('autostart')

    default_params = '/home/thomas24/hive_ws2/src/vanilla_brain_nav2/config/nav2_minimal.yaml'

    declare_namespace = DeclareLaunchArgument(
        'namespace', default_value='robot1',
        description='Namespace du robot (ex: robot1, robot2, ...)'
    )

    declare_use_sim = DeclareLaunchArgument(
        'use_sim_time', default_value='true',
        description='Utiliser le temps de simulation'
    )

    declare_params = DeclareLaunchArgument(
        'params_file', default_value=default_params,
        description='Chemin complet du fichier YAML des paramètres Nav2'
    )

    declare_autostart = DeclareLaunchArgument(
        'autostart', default_value='true',
        description='Démarrage automatique du lifecycle manager'
    )

    # === Rewritten YAML (pour namespace + typage auto) ===
    configured_params = ParameterFile(
        RewrittenYaml(
            source_file=params_path,
            root_key=namespace,
            param_rewrites={},
            convert_types=True
        ),
        allow_substs=True
    )

    # === Remappings (🔥 forcer TF / Clock globales) ===
    remaps = [
        ('/tf', '/tf'),
        ('/tf_static', '/tf_static'),
        ('/clock', '/clock')
    ]

    # === Groupe de nodes Nav2 ===
    nav2_nodes = GroupAction([
        SetParameter('use_sim_time', use_sim),
        PushROSNamespace(namespace),

        # Contrôleur (MPPI)
        Node(
            package='nav2_controller',
            executable='controller_server',
            name='controller_server',
            output='screen',
            parameters=[configured_params],
            remappings=remaps,
        ),

        # Planificateur global (Smac)
        Node(
            package='nav2_planner',
            executable='planner_server',
            name='planner_server',
            output='screen',
            parameters=[configured_params],
            remappings=remaps,
        ),

        # Lifecycle manager
        Node(
            package='nav2_lifecycle_manager',
            executable='lifecycle_manager',
            name='lifecycle_manager_navigation',
            output='screen',
            parameters=[{
                'autostart': autostart,
                'node_names': [
                    'controller_server',
                    'planner_server'
                ]
            }],
            remappings=remaps,
        ),
    ])

    # === Assemblage du LaunchDescription ===
    ld = LaunchDescription()
    ld.add_action(SetEnvironmentVariable('RCUTILS_LOGGING_BUFFERED_STREAM', '1'))
    ld.add_action(declare_namespace)
    ld.add_action(declare_use_sim)
    ld.add_action(declare_params)
    ld.add_action(declare_autostart)
    ld.add_action(nav2_nodes)

    return ld
