#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Version 2 — Plan + FollowPath asynchrone avec stop immédiat
"""

import math
import sys
import threading
import time
import rclpy
from rclpy.node import Node
from rclpy.action import ActionClient
from geometry_msgs.msg import PoseStamped, Quaternion
from nav_msgs.msg import Path
from nav2_msgs.action import ComputePathToPose, FollowPath
from rclpy.qos import QoSProfile, ReliabilityPolicy, HistoryPolicy

# --- couleurs terminal ---
RESET = "\033[0m"; BOLD = "\033[1m"; DIM = "\033[2m"
GREEN = "\033[32m"; YELLOW = "\033[33m"; RED = "\033[31m"
CYAN = "\033[36m"; MAGENTA = "\033[35m"


def deg2quat(yaw_deg: float) -> Quaternion:
    yaw = math.radians(yaw_deg)
    q = Quaternion()
    q.z = math.sin(yaw / 2.0)
    q.w = math.cos(yaw / 2.0)
    return q


def make_pose_stamped(node: Node, frame_id: str, x: float, y: float, yaw_deg: float) -> PoseStamped:
    pose = PoseStamped()
    pose.header.stamp = node.get_clock().now().to_msg()
    pose.header.frame_id = frame_id
    pose.pose.position.x = x
    pose.pose.position.y = y
    pose.pose.orientation = deg2quat(yaw_deg)
    return pose


class PlanFollowCli(Node):
    def __init__(self, ns: str = "robot1", global_frame: str = "map", use_sim_time: bool = True):
        super().__init__(f"{ns}_plan_follow_cli")

        self.set_parameters([rclpy.parameter.Parameter(
            "use_sim_time", rclpy.parameter.Parameter.Type.BOOL, use_sim_time
        )])

        self.ns = ns
        self.global_frame = global_frame

        # Action clients
        self.plan_client = ActionClient(self, ComputePathToPose, f"/{ns}/compute_path_to_pose")
        self.follow_client = ActionClient(self, FollowPath, f"/{ns}/follow_path")

        # Publisher for RViz
        qos = QoSProfile(history=HistoryPolicy.KEEP_LAST, depth=1,
                         reliability=ReliabilityPolicy.RELIABLE)
        self.plan_pub = self.create_publisher(Path, f"/{ns}/cli_plan", qos)

        # Synchronisation
        self._follow_goal_handle = None
        self._follow_thread = None
        self._follow_lock = threading.Lock()

        # Thread de lecture clavier
        threading.Thread(target=self._stdin_loop, daemon=True).start()

        print(f"{GREEN}✔ Client prêt{RESET} — namespace={MAGENTA}{ns}{RESET}, frame={CYAN}{global_frame}{RESET}")
        print(f"{DIM}Entrée : 'x,y,yaw_deg' (ex: 3.0,1.2,90){RESET}")
        print(f"{YELLOW}s{RESET} = stop / {YELLOW}q{RESET} = quitter\n")

    # --- Lecture clavier ---
    def _stdin_loop(self):
        for line in sys.stdin:
            cmd = line.strip().lower()
            if not cmd:
                continue

            if cmd == "q":
                print(f"{YELLOW}→ Quit demandé.{RESET}")
                self.cancel_follow()
                rclpy.shutdown()
                return

            if cmd == "s":
                print(f"{YELLOW}→ Stop immédiat du contrôleur.{RESET}")
                self.cancel_follow()
                continue

            try:
                x_str, y_str, yaw_str = [s.strip() for s in cmd.split(",")]
                x, y, yaw = float(x_str), float(y_str), float(yaw_str)
            except Exception:
                print(f"{RED}⚠ Format invalide. Exemple : 2.5, -1.0, 180{RESET}")
                continue

            if self.follow_active:
                print(f"{MAGENTA}Préemption : arrêt du précédent suivi...{RESET}")
                self.cancel_follow()
                time.sleep(0.3)

            self.plan_and_follow(x, y, yaw)

    @property
    def follow_active(self) -> bool:
        with self._follow_lock:
            return self._follow_goal_handle is not None

    def cancel_follow(self):
        with self._follow_lock:
            if self._follow_goal_handle is not None:
                try:
                    self._follow_goal_handle.cancel_goal_async()
                except Exception:
                    pass
            self._follow_goal_handle = None

    # --- Phase planification ---
    def plan_and_follow(self, x: float, y: float, yaw_deg: float):
        print(f"{DIM}Connexion aux serveurs...{RESET}")
        if not self.plan_client.wait_for_server(timeout_sec=5.0):
            print(f"{RED}✖ Planner indisponible.{RESET}")
            return
        if not self.follow_client.wait_for_server(timeout_sec=5.0):
            print(f"{RED}✖ Contrôleur indisponible.{RESET}")
            return

        goal_pose = make_pose_stamped(self, self.global_frame, x, y, yaw_deg)
        plan_goal = ComputePathToPose.Goal()
        plan_goal.goal = goal_pose
        plan_goal.use_start = False

        print(f"{BOLD}→ Planifie vers{RESET} {CYAN}({x:.2f},{y:.2f},yaw={yaw_deg:.1f}°){RESET}")

        send_future = self.plan_client.send_goal_async(plan_goal)
        rclpy.spin_until_future_complete(self, send_future)
        goal_handle = send_future.result()
        if not goal_handle or not goal_handle.accepted:
            print(f"{RED}✖ Planification refusée.{RESET}")
            return

        result_future = goal_handle.get_result_async()
        rclpy.spin_until_future_complete(self, result_future)
        result = result_future.result().result

        if result.error_code != 0:
            print(f"{RED}✖ Planification échouée : {result.error_msg}{RESET}")
            return

        plan = result.path
        plan.header.stamp = self.get_clock().now().to_msg()
        self.plan_pub.publish(plan)

        print(f"{GREEN}✔ Plan OK{RESET} ({len(plan.poses)} poses, "
              f"time={result.planning_time.sec + result.planning_time.nanosec*1e-9:.3f}s)")
        print(f"{DIM}→ Lancement du suivi du chemin...{RESET}")

        # Démarre le suivi dans un thread à part
        threading.Thread(target=self._start_follow, args=(plan,), daemon=True).start()

    # --- Lancement du follow dans un thread séparé ---
    def _start_follow(self, plan: Path):
        follow_goal = FollowPath.Goal()
        follow_goal.path = plan

        send_future = self.follow_client.send_goal_async(follow_goal)
        rclpy.spin_until_future_complete(self, send_future)
        goal_handle = send_future.result()
        if not goal_handle or not goal_handle.accepted:
            print(f"{RED}✖ FollowPath refusé.{RESET}")
            return

        with self._follow_lock:
            self._follow_goal_handle = goal_handle

        print(f"{GREEN}✔ Suivi en cours...{RESET}")

        # Attente asynchrone
        result_future = goal_handle.get_result_async()
        while rclpy.ok() and not result_future.done():
            time.sleep(0.1)

        # Nettoyage
        with self._follow_lock:
            self._follow_goal_handle = None

        if not rclpy.ok():
            return

        result = result_future.result()
        status = int(result.status)
        if status == 4:
            print(f"{RED}✖ Suivi ABORTED.{RESET}")
        elif status == 5:
            print(f"{YELLOW}• Suivi CANCELLED.{RESET}")
        else:
            print(f"{GREEN}✔ Suivi terminé (status={status}).{RESET}")


def main():
    import argparse
    parser = argparse.ArgumentParser(description="Client Nav2 sans feedback continu (stop réactif)")
    parser.add_argument("--ns", default="robot1")
    parser.add_argument("--frame", default="map")
    parser.add_argument("--use-sim-time", action="store_true")
    args = parser.parse_args()

    rclpy.init()
    node = PlanFollowCli(ns=args.ns, global_frame=args.frame, use_sim_time=args.use_sim_time)

    try:
        while rclpy.ok():
            rclpy.spin_once(node, timeout_sec=0.2)
    except KeyboardInterrupt:
        pass
    finally:
        node.cancel_follow()
        node.destroy_node()
        rclpy.shutdown()


if __name__ == "__main__":
    main()

