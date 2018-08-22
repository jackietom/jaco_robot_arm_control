# jaco\_robot\_arm\_control
Control Jaco Robot arm's hand position by human hand position using kinect

##### Installation

Environment: ubuntu:16.04 ROS:kinetic

##### Usage

You need to open 3 terminals(or use tmux)

1. Go to jaco\_robot\_arm\_control/control\_ws2 

run

roslaunch j2n6s300\_moveit\_config j2n6s300\_virtual\_robot\_demo.launch

2. Go to ~/Documents/SummerResearch/jaco\_robot\_arm\_control/HandTrack

run

rosrun beginner\_tutorials talker

3. Go to jaco\_robot\_arm\_control/control\_ws2

run 

rosrun kinova\_arm\_moveit\_demo motion\_plan2
