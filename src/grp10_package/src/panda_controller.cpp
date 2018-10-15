
#include <ros/ros.h>
#include <geometry_msgs/Pose.h>

#include <moveit_msgs/PlanningScene.h>
#include <moveit_msgs/AttachedCollisionObject.h>
#include <moveit_msgs/GetStateValidity.h>
#include <moveit_msgs/DisplayRobotState.h>
#include <moveit_msgs/ApplyPlanningScene.h>

#include <moveit/robot_model_loader/robot_model_loader.h>
#include <moveit/robot_state/robot_state.h>
#include <moveit/robot_state/conversions.h>

#include <moveit_visual_tools/moveit_visual_tools.h>

int main(int argc, char **argv) {
	
	ros::init(argc, argv, "panda_controller");
	ros::AsyncSpinner spinner(1);

	spinner.start();

	ros::NodeHandle nh;



	robot_model_loader::RobotModelLoader rml("robot_description");
	robot_model::RobotModelPtr kinematic_model = rml.getModel();

	ROS_INFO("Model frame: %s", kinematic_model->getModelFrame().c_str());


	std::cout << "starting moveit visual tools" << std::endl;
	moveit_visual_tools::MoveItVisualTools visual_tools("panda_link0");
	visual_tools.deleteAllMarkers();

	
	

	std::cout << "terminating node" << std::endl;
		
	return 0;
}
