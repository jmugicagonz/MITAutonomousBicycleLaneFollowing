#include <iostream>
#include <fstream>
#include <string>

#include <sensor_msgs/Image.h>
#include <opencv2/opencv.hpp>
#include "lane_followingv2/common.h"
#include "lane_followingv2/Helper.h"
#include "lane_followingv2/HelperXML.h"
#include "lane_followingv2/PreProcessing.h"
#include "lane_followingv2/PublisherSubscriber.h"
#include <cv_bridge/cv_bridge.h>
#include "ros/ros.h"
#include "std_msgs/String.h"
#include <sstream>


//Use image transport for publishing and suscribing to images in ROS allows to suscribe to compressed image streams. image_transport MUST be included also in package.xml
#include <image_transport/image_transport.h>
//Includes the header for CvBridge as well as some useful constants and functions related to image encodings. cv_bridge MUST be included also in package.xml
#include <cv_bridge/cv_bridge.h>
#include <sensor_msgs/image_encodings.h>
//Includes the headers for OpenCV's image procesing and GUI modules. opencv2 MUST be included also in package.xml
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>


#define NUM_PARTICLES 400
#define HOUGH_ONLY false
#define USAR_ALTURA true
#define IMG_QUALITY 1

using namespace std;
using namespace cv;

ConfigXML *config;


template<>
void PublisherSubscriber<sensor_msgs::Image, sensor_msgs::Image>::subscriberCallback(const sensor_msgs::Image::ConstPtr& msg)
{
	cv_bridge::CvImagePtr cv_ptr;
	try
	{
	//It first copies the ROS message into OpenCv format. CHECK ENCODINGS, NOT DEVELOPED.	
	cv_ptr = cv_bridge::toCvCopy(msg, sensor_msgs::image_encodings::BGR8);
	}
	//toCvCopy should always be wrapped to catch conversion errors as it will not check by itself for validity of the data.    
	catch (cv_bridge::Exception& e)
	    {
	      ROS_ERROR("cv_bridge exception: %s", e.what());
	      return;
	    }
	
	cv_ptr->image = Helper::colorToGray(cv_ptr->image);


	// Realize o Pre-Processamento (color -> [gray + roi + ipm])
	/*Mat1b grayFrameRoi; // guarda a ROI em escala de cinza
	Mat1b grayFrameRoiIPM = preProcessamento.executar(colorFrame, grayFrameRoi);
	Mat3b colorFrameRoiIPM = preProcessamento.executar(colorFrame);
	Mat1b mascaraIPM = preProcessamento.getMascaraIPM(-8);*/
	//One node handle necessary for the publisher and another one for the suscriber	
	//cout << "Arrived Here";
	cv::imshow("gray_scale", cv_ptr->image);
	cv::waitKey(3);
	publisherObject.publish(cv_ptr->toImageMsg());

}
int main(int argc, char **argv)
	{

	ros::init(argc, argv, "configurator");


	
	//Set configuration path. See loadConfig.cpp
	config = new ConfigXML();
	config->numParticles = NUM_PARTICLES;
	string path_xml_configurations = "./src/my_roscpp_library/src/config.xml";
	cout << path_xml_configurations << endl;

	// load dataset specific config file
	if (!loadDatasetConfig(path_xml_configurations, *config)) cout << "Error configuring";

	// inicializa o XML de sa�da. NOT YET DEVELOPED.
	Size frameSize = Size(config->camera.FrameSize.width, config->camera.FrameSize.height);
	OutputXML xml = createOutputXML(frameSize);
	vector<int> saida_y = {
		config->roi.y,
		config->roi.y + (int)ceil((float)config->roi.height / 4.0),
		config->roi.y + (int)ceil((float)config->roi.height / 2.0),
		config->roi.y + config->roi.height - 1
		};


	// Make Instance For Pre-Processing. The false correspond to DISPLAY. CHECK!!
	PreProcessing PreProcessing(config->roi, config->verbose, false);
	PublisherSubscriber<sensor_msgs::Image, sensor_msgs::Image> transformer("preproc_gray","/camera/image_raw",1);	
	ros::spin();


}





