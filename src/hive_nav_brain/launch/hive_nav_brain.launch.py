from launch import LaunchDescription
from launch.actions import DeclareLaunchArgument, GroupAction, SetEnvironmentVariable
from launch_ros.actions import Node, PushROSNamespace, SetParameter
from launch_ros.descriptions import ParameterFile
from launch.substitutions import LaunchConfiguration
from nav2_common.launch import RewrittenYaml

def generate_launch_description():
    # --- Arguments ---
    robot_namespace          = LaunchConfiguration('robot_namespace')
    fetch_service_basename   = LaunchConfiguration('fetch_service_basename')
    use_sim_time             = LaunchConfiguration('use_sim_time')
    params_file              = LaunchConfiguration('params_file')
    autostart                = LaunchConfiguration('autostart')

    # ⚠️ Mets ton chemin YAML Nav2 par défaut ici si besoin
    default_params = '/home/thomas24/hive_ws2/src/vanilla_brain_nav2/config/nav2_minimal.yaml'

    declare_robot_ns = DeclareLaunchArgument(
        'robot_namespace', default_value='robot1',
        description='Namespace du robot (ex: robot1, robot2, ...)'
    )
    declare_fetch = DeclareLaunchArgument(
        'fetch_service_basename', default_value='refresh_all_data',
        description='Nom de base du service de fetch (ex: refresh_all_data)'
    )
    declare_use_sim = DeclareLaunchArgument(
        'use_sim_time', default_value='true',
        description='Utiliser /clock (simulation)'
    )
    declare_params = DeclareLaunchArgument(
        'params_file', default_value=default_params,
        description='Chemin du fichier YAML des paramètres Nav2'
    )
    declare_autostart = DeclareLaunchArgument(
        'autostart', default_value='true',
        description='Démarrage auto du lifecycle manager'
    )

    # --- Rewritten YAML pour Namespacer proprement les params Nav2 ---
    configured_params = ParameterFile(
        RewrittenYaml(
            source_file=params_file,
            root_key=robot_namespace,   # injecte le namespace en racine du YAML
            param_rewrites={},          # tu peux surcharger des clés ici si besoin
            convert_types=True
        ),
        allow_substs=True
    )

    # --- Remappings globaux (garde TF/clock globaux partagés) ---
    remaps = [
        ('/tf', '/tf'),
        ('/tf_static', '/tf_static'),
        ('/clock', '/clock'),
    ]

    # --- Groupe sous namespace ---
    group = GroupAction([
        # Sim time partagé dans le groupe
        SetParameter('use_sim_time', use_sim_time),

        # Namespace des 3 nodes
        PushROSNamespace(robot_namespace),

        # 1) Ton cerveau de nav Hive
        Node(
            package='hive_nav_brain',
            executable='hive_nav_brain_node',
            name='hive_nav_brain_node',
            output='screen',
            parameters=[
                {'robot_namespace': robot_namespace},
                {'fetch_service_basename': fetch_service_basename},
                # Si jamais tu veux que le node lise /clock :
                {'use_sim_time': use_sim_time},
            ],
            remappings=remaps,
        ),

        # 2) Nav2 Controller (ex: MPPI si configuré dans ton YAML)
        Node(
            package='nav2_controller',
            executable='controller_server',
            name='controller_server',
            output='screen',
            parameters=[configured_params],
            remappings=remaps,
        ),

        # 3) Nav2 Planner (ex: Smac si configuré dans ton YAML)
        Node(
            package='nav2_planner',
            executable='planner_server',
            name='planner_server',
            output='screen',
            parameters=[configured_params],
            remappings=remaps,
        ),

        # 4) Lifecycle Manager pour controller/planner
        Node(
            package='nav2_lifecycle_manager',
            executable='lifecycle_manager',
            name='lifecycle_manager_navigation',
            output='screen',
            parameters=[{
                'use_sim_time': use_sim_time,
                'autostart': autostart,
                'node_names': [
                    'controller_server',
                    'planner_server'
                ],
            }],
            remappings=remaps,
        ),
    ])

    # --- Assemblage LD ---
    ld = LaunchDescription()
    ld.add_action(SetEnvironmentVariable('RCUTILS_LOGGING_BUFFERED_STREAM', '1'))  # logs plus fluides
    ld.add_action(declare_robot_ns)
    ld.add_action(declare_fetch)
    ld.add_action(declare_use_sim)
    ld.add_action(declare_params)
    ld.add_action(declare_autostart)
    ld.add_action(group)
    return ld
