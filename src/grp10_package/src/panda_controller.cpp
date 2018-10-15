
#include <ros/ros.h>
#include <geometry_msgs/Pose.h>

#include "moveit_msgs/PlanningScene.h"
#include "moveit_msgs/AttachedCollisionObject.h"
#include "moveit_msgs/GetStateValidity.h"
#include "moveit_msgs/DisplayRobotState.h"
#include "moveit_msgs/ApplyPlanningScene.h"

#include <moveit/robot_model_loader/robot_model_loader.h>
#include <moveit/robot_state/robot_state.h>
#include <moveit/robot_state/conversions.h>
#include <moveit/move_group_interface/move_group_interface.h>
#include <moveit_visual_tools/moveit_visual_tools.h>


#include <moveit/planning_interface/planning_interface.h>
#include <moveit/planning_scene/planning_scene.h>
#include <moveit/kinematic_constraints/utils.h>
#include <moveit_msgs/DisplayTrajectory.h>
#include <moveit_msgs/PlanningScene.h>

int main(int argc, char **argv) {
	
	ros::init(argc, argv, "panda_controller");
	ros::AsyncSpinner spinner(1);

	spinner.start();

	ros::NodeHandle nh;



	robot_model_loader::RobotModelLoader rml("robot_description");
	robot_model::RobotModelPtr kinematic_model = rml.getModel();

	planning_scene::PlanningScenePtr planning_scene(new planning_scene::PlanningScene(kinematic_model));

	ROS_INFO("Model frame: %s", kinematic_model->getModelFrame().c_str());


	
	moveit_visual_tools::MoveItVisualTools visual_tools("panda_link0");
	visual_tools.deleteAllMarkers();
	visual_tools.loadRemoteControl();
	visual_tools.trigger();
	ros::Duration(10).sleep();

	visual_tools.prompt("Press 'next' in the RvizVisualToolsGui window when the game starts");
	
	// Pose Goal
	planning_interface::MotionPlanRequest req;
	planning_interface::MotionPlanResponse res;
	geometry_msgs::PoseStamped pose;
	pose.header.frame_id = "panda_link0";

	//Random position and orientation
	pose.pose.position.x = 0.3;
	pose.pose.position.y = 0.0;
	pose.pose.position.z = 0.75;
	pose.pose.orientation.w = 1.0;

	std::vector<double> tolerance_pose(3, 0.01);
	std::vector<double> tolerance_angle(3, 0.01);

	std::cout << "terminating node" << std::endl;
		
	return 0;
}
