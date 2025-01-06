# ogmen robotics
#  assignment

Bot Description & Bot World: A simulation and visualization setup for the two-wheeled robot in ROS 2, integrating URDF and Gazebo with visualization tools like RViz.

This repository contains a URDF (Unified Robot Description Format) model of a mobile robot with a rectangular box body, two wheels (left and right), and a caster wheel. The robot is designed for simulation in ROS 2 and Gazebo, and it's a simple example for testing basic mobility and sensor setups.

Table of Contents
Robot Description
Features
Installation
Usage
Gazebo Setup
Sensor Configurations
Contributing
License
Robot Description
This robot consists of:

Base Link: The central link of the robot.
Main Box: A rectangular box representing the main body of the robot.
Left and Right Wheels: Two wheels on the left and right side for movement.
Caster Wheel: A spherical caster wheel at the back for support.
Lidar: A sensor mounted on top of the robot for distance measurements.
Camera: A camera mounted on the robot for visual feedback.
The URDF model is designed to work with ROS 2 and Gazebo for testing various robotics applications, including sensor integration and robot motion control.

Features
Mobile Robot: Two-wheel drive with a caster wheel for stability.
Lidar Sensor: Includes a ray-based LIDAR sensor for environment scanning.
Camera Sensor: Includes a camera for visual feedback.
Gazebo Integration: Ready-to-use with Gazebo for simulation, including sensor data output.

Installation
Prerequisites
ROS 2 Humble.
Gazeb0.
A catkin workspace or colcon workspace for building ROS 2 packages.
Setup Instructions
Clone this repository into your ROS 2 workspace:


cd ~/pavan_ws/src

Build the workspace:

in src you should have these files

bot_control, bot_decription, bot_world

in bot_control/src/reading_laser.cpp

cd ~/pavan_ws
colcon build --packages-select
after this

colcon build --packages-select bot_description

next have to source it :

source install/setup.bash

Running the Robot in Gazebo:

ros2 launch bot_description spawn.launch

After this launch rviz2 :

ros2 launch bot_description rviz.launch

Control the Robot
To control the robot, you can use teleop_twist_keyboard for basic teleoperation or set up a controller for automated movement.

Teleoperation
To control the robot's movement via keyboard:

Install teleop_twist_keyboard if you haven't already:

sudo apt install ros-humble-teleop-twist-keyboard

Run the teleoperation node:
ros2 run teleop_twist_keyboard teleop_twist_keyboard

In another terminal you have to run : ros2 topic list

in that list check weather /scan node is there

then : ros2 echo /scan 

by this command read the lidar value
