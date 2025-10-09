import rclpy
from rclpy.node import Node
from rclpy.action import ActionClient
from geometry_msgs.msg import PoseStamped
from nav2_msgs.srv import ComputePathToPose
from nav2_msgs.action import FollowPath
from nav_msgs.msg import Path
import tf2_ros
from tf2_geometry_msgs import do_transform_pose
from builtin_interfaces.msg import Time

class VanillaKnifeBrain(Node):
    def __init__(self):
        super().__init__('vanilla_knifebrain')

        self.declare_parameter('goal_topic', 'goal_pose')
        self.declare_parameter('global_frame', 'odom')
        self.declare_parameter('base_frame', 'base_footprint')

        self.goal_topic = self.get_parameter('goal_topic').get_parameter_value().string_value
        self.global_frame = self.get_parameter('global_frame').get_parameter_value().string_value
        self.base_frame = self.get_parameter('base_frame').get_parameter_value().string_value

        # TF
        self.tf_buffer = tf2_ros.Buffer()
        self.tf_listener = tf2_ros.TransformListener(self.tf_buffer, self)

        # Clients
        self.planner_cli = self.create_client(ComputePathToPose, 'compute_path_to_pose')
        self.controller_action = ActionClient(self, FollowPath, 'follow_path')

        self.get_logger().info(f"Waiting for planner service...")
        self.planner_cli.wait_for_service()
        self.get_logger().info(f"Waiting for controller action server...")
        self.controller_action.wait_for_server()
        self.get_logger().info("Ready. Publish a goal PoseStamped to "
                               f"'{self.get_namespace()}/{self.goal_topic}'")

        # Subscriber to goals
        self.goal_sub = self.create_subscription(
            PoseStamped, self.goal_topic, self.on_goal, 10
        )

    def on_goal(self, goal_msg: PoseStamped):
        try:
            # Ensure goal is in global_frame
            if goal_msg.header.frame_id != self.global_frame:
                # Transform goal to global_frame if TF available
                transform = self.tf_buffer.lookup_transform(
                    self.global_frame,
                    goal_msg.header.frame_id,
                    rclpy.time.Time())
                goal_msg = do_transform_pose(goal_msg, transform)
                goal_msg.header.frame_id = self.global_frame

            # Get current pose from TF: base -> global_frame
            tf = self.tf_buffer.lookup_transform(
                self.global_frame, self.base_frame, rclpy.time.Time())
            start_pose = PoseStamped()
            start_pose.header.frame_id = self.global_frame
            start_pose.header.stamp = self.get_clock().now().to_msg()
            start_pose.pose.position.x = tf.transform.translation.x
            start_pose.pose.position.y = tf.transform.translation.y
            start_pose.pose.position.z = tf.transform.translation.z
            start_pose.pose.orientation = tf.transform.rotation

        except Exception as e:
            self.get_logger().error(f"TF lookup failed: {e}")
            return

        # Call planner
        req = ComputePathToPose.Request()
        req.start = start_pose
        req.goal = goal_msg
        req.tolerance = 0.2

        self.get_logger().info("Calling /compute_path_to_pose ...")
        future = self.planner_cli.call_async(req)
        future.add_done_callback(self._handle_plan_response)

    def _handle_plan_response(self, future):
        try:
            resp = future.result()
        except Exception as e:
            self.get_logger().error(f"Planner service failed: {e}")
            return

        if resp is None or resp.path is None or len(resp.path.poses) == 0:
            self.get_logger().warn("Empty path returned by planner.")
            return

        path: Path = resp.path
        self.get_logger().info(f"Planner returned path with {len(path.poses)} poses. Sending to controller...")

        # Send path to controller action
        goal = FollowPath.Goal()
        goal.path = path
        send_future = self.controller_action.send_goal_async(goal)
        send_future.add_done_callback(self._controller_goal_response)

    def _controller_goal_response(self, future):
        goal_handle = future.result()
        if not goal_handle.accepted:
            self.get_logger().warn("FollowPath goal rejected by controller.")
            return
        self.get_logger().info("FollowPath goal accepted. Waiting for result...")
        result_future = goal_handle.get_result_async()
        result_future.add_done_callback(self._controller_result)

    def _controller_result(self, future):
        result = future.result().result
        self.get_logger().info(f"FollowPath finished with result: {result}")

def main():
    rclpy.init()
    node = VanillaKnifeBrain()
    rclpy.spin(node)
    node.destroy_node()
    rclpy.shutdown()
