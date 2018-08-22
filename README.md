# jaco\_robot\_arm\_control
Control Jaco Robot arm's hand position by human hand position using kinect

##### Installation

Environment: ubuntu:16.04 ROS:kinetic

Pre-install:

```sudo apt-get install expect ros-kinetic-rosconsole* ros-kinetic-moveit* ros-kinetic-trac*``` 

#Download files

```
git clone https://github.com/jackietom/jaco\_robot\_arm\_control.git
```

cd jaco\_robot\_arm\_control/

#Recompile HandTrack workspace
cd HandTrack

rm -r build && rm -r devel

catkin\_make

#Recompile control\_ws2 workspace
```
cd ../control\_ws2 
rm -r build devel
catkin\_make
```
##### Usage

You need to open 3 terminals(or use tmux) and connect your kinect V1 to PC

1. Go to jaco\_robot\_arm\_control/control\_ws2 

run

```
roslaunch j2n6s300\_moveit\_config j2n6s300\_virtual\_robot\_demo.launch
```

2. Go to ~/Documents/SummerResearch/jaco\_robot\_arm\_control/HandTrack

run

```
rosrun beginner\_tutorials talker
```

Shake your hand in front of the camera after '16' printed on the screen to calibrate.

3. Go to jaco\_robot\_arm\_control/control\_ws2

run 

```
rosrun kinova\_arm\_moveit\_demo motion\_plan2
```

Wait for about 10 ~ 30s for RViz to initialize the position of the arm.

Up to now, the arm can move slowly as human hand. There are still many things needed to be done. Any suggestions can be written in issues or sent to zhang-py@mails.tsinghua.edu.cn

