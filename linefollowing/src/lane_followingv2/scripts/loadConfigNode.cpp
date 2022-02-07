#include <iostream>
#include <fstream>
#include <string>


#include <opencv2/opencv.hpp>
#include "lane_followingv2/common.h"
#include "lane_followingv2/Helper.h"
#include "lane_followingv2/HelperXML.h"
#include "ros/ros.h"
#include "std_msgs/String.h"
#include <sstream>

#define NUM_PARTICLES 400
#define HOUGH_ONLY false
#define USAR_ALTURA true
#define IMG_QUALITY 1

using namespace std;
using namespace cv;


//First the global variable which will contain the configuration is defined
ConfigXML *config;



int main(int argc, char **argv)

	{
	//The node reading the configuration is defined
	ros::init(argc, argv, "configurator");
	/**
	* NodeHandle is the main access point to communications with the ROS system.
	* The first NodeHandle constructed will fully initialize this node, and the last
	* NodeHandle destructed will close down the node.
	*/
	ros::NodeHandle n;

	//The publisher which will publish the number of times the configuration has been properly read is defined.
	ros::Publisher chatter_pub = n.advertise<std_msgs::String>("chatter", 1);

	//Telling the rate to publish the messages
	ros::Rate loop_rate(10);

	//Counter to track the humber of times the configuration has been properly read.
	int count = 0;
	while (ros::ok())
	{

		//The string which iwll contain the message is defined.
		std_msgs::String msg;

		std::stringstream ss;


		//Here the configuration path is defined, printing it on the screen. CHECK NUM_PARTICLES AND THOSE VARIABLES DEFINED IN THIS FILE, IN THE BEGINNING.
		config = new ConfigXML();
		config->numParticles = NUM_PARTICLES;
		string path_xml_configurations = "./src/my_roscpp_library/src/config.xml";
		cout << path_xml_configurations << endl;

		//Load camera specific config file, xml format
		if (!loadDatasetConfig(path_xml_configurations, *config)) ss << "Error configuring";
		

		//The name of the camera will be printed to check the correct configuration load
		else ss << config->camera.name;



		//CHECK THIS PART, NOT USED FOR THE MOMENT
		Size frameSize = Size(config->camera.FrameSize.width, config->camera.FrameSize.height);
		OutputXML xml = createOutputXML(frameSize);
		vector<int> saida_y = {
			config->roi.y,
			config->roi.y + (int)ceil((float)config->roi.height / 4.0),
			config->roi.y + (int)ceil((float)config->roi.height / 2.0),
			config->roi.y + config->roi.height - 1
			};

		msg.data = ss.str();

		ROS_INFO("%s", msg.data.c_str());

		//Publish the message
		chatter_pub.publish(msg);

		ros::spinOnce();

		loop_rate.sleep();
		++count;
	}


  return 0;
}




