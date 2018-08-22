#include <moveit/move_group_interface/move_group.h>
#include <moveit_msgs/PlanningScene.h>
#include <moveit/planning_scene_interface/planning_scene_interface.h>
#include <moveit/planning_scene/planning_scene.h>

#include <moveit_msgs/DisplayRobotState.h>
#include <moveit_msgs/DisplayTrajectory.h>

#include <moveit_msgs/AttachedCollisionObject.h>
#include <moveit_msgs/CollisionObject.h>

#include <kinova_driver/kinova_ros_types.h>
#include "ros/ros.h"
#include "std_msgs/String.h"
#include "std_msgs/ColorRGBA.h"
#include <vector>
#include <string>
#include <iostream>

std::vector<double> vect = {0.5,0.5,0.5};
std::vector<double> init = {0.5,0.5,0.5};
std::vector<double> base = {0,0.6,0};
int cnt = -1;
std::vector<double> getNumber(std::string str)
{
    std::vector<double> vect;

    std::stringstream ss(str);

    double i;

    while (ss >> i)
    {
        vect.push_back(i);

        if (ss.peek() == ',')
            ss.ignore();
    }

    std::cout << str<<std::endl;
    if(cnt == -1){
	init = vect;
	cnt = 1;
    }
    for(int i = 0; i<3; i++){
    	vect[i] = (vect[i] - init[i])/500+base[i];
    }
    return vect;
}


void chatterCallback(const std_msgs::String::ConstPtr& msg)
{
	std::string str =  msg->data.c_str();
	vect = getNumber(str);
	for(int i = 0; i<3; i++)
		std::cout<<vect[i]<<std::endl;
}
 
int main(int argc, char **argv)
{
  ros::init(argc, argv, "motion_plan2");
  ros::NodeHandle node_handle;  
  ros::AsyncSpinner spinner(1);
  spinner.start();

  ros::Subscriber sub = node_handle.subscribe("chatter", 1000, chatterCallback);
  /* This sleep is ONLY to allow Rviz to come up */
  sleep(10.0);
  
  // BEGIN_TUTORIAL
  // 
  // Setup
  // ^^^^^
  // 
  // The :move_group_interface:`MoveGroup` class can be easily 
  // setup using just the name
  // of the group you would like to control and plan for.
  moveit::planning_interface::MoveGroup group("arm");

  // We will use the :planning_scene_interface:`PlanningSceneInterface`
  // class to deal directly with the world.
  moveit::planning_interface::PlanningSceneInterface planning_scene_interface;  

  // (Optional) Create a publisher for visualizing plans in Rviz.
  //ros::Publisher display_publisher = node_handle.advertise<moveit_msgs::DisplayTrajectory>("/move_group/display_planned_path", 1, true);
  moveit_msgs::DisplayTrajectory display_trajectory;

  // We can print the name of the reference frame for this robot.
  ROS_INFO("Reference frame: %s", group.getPlanningFrame().c_str());
  
  // We can also print the name of the end-effector link for this group.
  ROS_INFO("Reference frame: %s", group.getEndEffectorLink().c_str());

  // Home position for jaco:
//  currentCartesianCommand = [feedback.X, feedback.Y, feedback.Z, feedback.ThetaX, feedback.ThetaY, feedback.Z]
//  currentCartesianCommand = [0.212322831154, -0.257197618484, 0.509646713734, 1.63771402836, 1.11316478252, 0.134094119072]
  tf::Pose Home;
  Home.setOrigin(tf::Vector3(0.212322831154, -0.257197618484, 0.509646713734));
  Home.setRotation(kinova::EulerXYZ2Quaternion(1.63771402836,1.11316478252, 0.134094119072));
//  Home.setRotation(tf::Quaternion(0.68463, -0.22436, 0.68808, 0.086576));

  tf::Pose random_pose;
  random_pose.setOrigin(tf::Vector3(0.54882, -0.30854,  0.65841));
  random_pose.setRotation(tf::Quaternion(0.68463, -0.22436, 0.68808, 0.086576));

  // Planning to a Pose goal
  // ^^^^^^^^^^^^^^^^^^^^^^^
  // We can plan a motion for this group to a desired pose for the 
  // end-effector.
  geometry_msgs::Pose target_pose1;
  tf::poseTFToMsg(random_pose, target_pose1);
  group.setPoseTarget(target_pose1);


  // Now, we call the planner to compute the plan
  // and visualize it.
  // Note that we are just planning, not asking move_group 
  // to actually move the robot.
  moveit::planning_interface::MoveGroup::Plan my_plan;
  moveit::planning_interface::MoveItErrorCode success = group.plan(my_plan);

  ROS_INFO("Visualizing plan 1 (pose goal) %s",success?"":"FAILED");    
  /* Sleep to give Rviz time to visualize the plan. */
  sleep(5.0);

  // Visualizing plans
  // ^^^^^^^^^^^^^^^^^
  // Now that we have a plan we can visualize it in Rviz.  This is not
  // necessary because the group.plan() call we made above did this
  // automatically.  But explicitly publishing plans is useful in cases that we
  // want to visualize a previously created plan.
  
  // Adding/Removing Objects and Attaching/Detaching Objects
  // ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
  // First, we will define the collision object message.
  moveit_msgs::CollisionObject collision_object1;
  moveit_msgs::CollisionObject collision_object2;
  collision_object1.header.frame_id = group.getPlanningFrame();
  collision_object2.header.frame_id = group.getPlanningFrame();


  /* The id of the object is used to identify it. */
  collision_object1.id = "box1";
  collision_object2.id = "box2";
  /*The color object*/
  std_msgs::ColorRGBA color;

  color.r = 255;
  color.g = 0;
  color.b = 0;
  color.a = 1;

  /* Define a box to add to the world. */
  shape_msgs::SolidPrimitive primitive;
  primitive.type = primitive.BOX;
  primitive.dimensions.resize(3);
  // dimention less than the distance between start point and goal point
  primitive.dimensions[0] = 0.1;
  primitive.dimensions[1] = 0.02;
  primitive.dimensions[2] = 0.05;

  /* A pose for the box (specified relative to frame_id) */
  geometry_msgs::Pose box_pose;
  box_pose.orientation.w = 1.0;
  // place between start point and goal point.
  box_pose.position.x =  0.37;
  box_pose.position.y = -0.27;
  box_pose.position.z =  0.5;

  collision_object1.primitives.push_back(primitive);
  collision_object1.primitive_poses.push_back(box_pose);
  collision_object1.operation = collision_object1.ADD;

  box_pose.position.x = -0.37;
  box_pose.position.y = -0.27;
  box_pose.position.z = 0.5;
  collision_object2.primitives.push_back(primitive);
  collision_object2.primitive_poses.push_back(box_pose);
  collision_object2.operation = collision_object2.ADD;

  std::vector<moveit_msgs::CollisionObject> collision_objects;  
  collision_objects.push_back(collision_object1);
  collision_objects.push_back(collision_object2);  
  
  //Set color of objects

  // Now, let's add the collision object into the world
  ROS_INFO("Add an object into the world");  
  planning_scene_interface.addCollisionObjects(collision_objects);
  
  /* Sleep so we have time to see the object in RViz */
  sleep(2.0);
  while(ros::ok()){
  // Getting Basic Information
  // ^^^^^^^^^^^^^^^^^^^^^^^^^
  //
  // We can print the name of the reference frame for this robot.
  ROS_INFO("Reference frame: %s", group.getPlanningFrame().c_str());
  
  // We can also print the name of the end-effector link for this group.
  ROS_INFO("Reference frame: %s", group.getEndEffectorLink().c_str());

  // Home position for jaco:
//  currentCartesianCommand = [feedback.X, feedback.Y, feedback.Z, feedback.ThetaX, feedback.ThetaY, feedback.Z]
//  currentCartesianCommand = [0.212322831154, -0.257197618484, 0.509646713734, 1.63771402836, 1.11316478252, 0.134094119072]
  tf::Pose Home;
  Home.setOrigin(tf::Vector3(0.212322831154, -0.257197618484, 0.509646713734));
  Home.setRotation(kinova::EulerXYZ2Quaternion(1.63771402836,1.11316478252, 0.134094119072));
//  Home.setRotation(tf::Quaternion(0.68463, -0.22436, 0.68808, 0.086576));

  tf::Pose random_pose;
  random_pose.setOrigin(tf::Vector3(vect[0], vect[2],  vect[1]));
  random_pose.setRotation(tf::Quaternion(0.68463, -0.22436, 0.68808, 0.086576));

  // Planning to a Pose goal
  // ^^^^^^^^^^^^^^^^^^^^^^^
  // We can plan a motion for this group to a desired pose for the 
  // end-effector.
  geometry_msgs::Pose target_pose1;
  tf::poseTFToMsg(random_pose, target_pose1);
  group.setPoseTarget(target_pose1);


  // Now, we call the planner to compute the plan
  // and visualize it.
  // Note that we are just planning, not asking move_group 
  // to actually move the robot.
  moveit::planning_interface::MoveGroup::Plan my_plan;
  moveit::planning_interface::MoveItErrorCode success = group.plan(my_plan);

  group.move(); 
  }


// END_TUTORIAL

  ros::shutdown();  
  return 0;
}
