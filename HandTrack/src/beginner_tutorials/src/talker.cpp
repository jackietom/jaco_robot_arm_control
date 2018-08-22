#include "ros/ros.h"
#include "std_msgs/String.h"

#include <sstream>
#include <vector>

/**
 * This tutorial demonstrates simple sending of messages over the ROS system.
 */


int main(int argc, char **argv)
{

  ros::init(argc, argv, "talker");

  ros::NodeHandle n;

  ros::Publisher chatter_pub = n.advertise<std_msgs::String>("chatter", 1000);

  ros::Rate loop_rate(10);

//get info from kiect
  std::string cmd = "export LD_LIBRARY_PATH=/home/zy/Documents/SummerResearch/jaco_robot_arm_control/HandTrack/src/"
                                     "NiTE-Linux-x64-2.2/Samples/Bin && unbuffer /home/zy/Documents/SummerResearch/"
                                     "jaco_robot_arm_control/HandTrack/src/NiTE-Linux-x64-2.2/Samples/Bin/SimpleHandTracker";
  std::string data;
  FILE * stream;
  const int max_buffer = 1024;
  char buffer[max_buffer];
  //cmd.append(" 2>&1");

  stream = popen(cmd.c_str(), "r");
  int count = 0;
 if (stream) {
        while (!feof(stream))
            if (fgets(buffer, max_buffer, stream) != NULL) {
                //data.append(buffer);
                //get a string of numbers and comma
                for(int k = 0; k < 4; k++)
                    buffer[k] = ' ';
                buffer[strlen(buffer)-2] = ' ';
                data = buffer;
                printf("%d\n", count); 
		//publish msg
		if(ros::ok()&&count>100)
		{
			printf("2\n");
			std_msgs::String msg;
			std::stringstream ss;
			ss << data << count;
			msg.data = ss.str();

			ROS_INFO("%s", msg.data.c_str());

			chatter_pub.publish(msg);

			ros::spinOnce();

		//	loop_rate.sleep();
		}
		++count;
            }
        pclose(stream);
    }

  return 0;
}
