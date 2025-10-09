#!/usr/bin/env python3
import rclpy
from rclpy.action import ActionClient
from nav2_msgs.action import FollowPath
from nav_msgs.msg import Path
import yaml

def main():
    rclpy.init()
    node = rclpy.create_node('follow_path_client')
    client = ActionClient(node, FollowPath, '/robot1/follow_path')

    # Charger le Path du fichier YAML
    with open('/tmp/plan.yaml', 'r') as f:
        plan_yaml = yaml.safe_load(f)

    # Reconstituer un message Path minimal
    path_msg = Path()
    path_msg.header.frame_id = plan_yaml['header']['frame_id']
    for pose in plan_yaml['poses']:
        from geometry_msgs.msg import PoseStamped
        ps = PoseStamped()
        ps.header.frame_id = pose['header']['frame_id']
        ps.pose.position.x = pose['pose']['position']['x']
        ps.pose.position.y = pose['pose']['position']['y']
        ps.pose.position.z = pose['pose']['position']['z']
        ps.pose.orientation = type(ps.pose.orientation)(
            **pose['pose']['orientation'])
        path_msg.poses.append(ps)

    goal_msg = FollowPath.Goal()
    goal_msg.path = path_msg

    node.get_logger().info('Waiting for follow_path server...')
    client.wait_for_server()

    future = client.send_goal_async(goal_msg)
    rclpy.spin_until_future_complete(node, future)
    goal_handle = future.result()

    if not goal_handle.accepted:
        node.get_logger().error('Goal rejected by controller')
        node.destroy_node()
        rclpy.shutdown()
        return

    node.get_logger().info('Goal accepted, waiting for result...')
    result_future = goal_handle.get_result_async()
    rclpy.spin_until_future_complete(node, result_future)

    node.get_logger().info(f'FollowPath finished with status: {result_future.result().status}')
    node.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()

