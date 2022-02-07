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
#include "lane_followingv2/KalmanHoughs.h"
#include "lane_followingv2/AnaliseDasHoughs.h"
#include "lane_followingv2/Kalman.h"

#include <cv_bridge/cv_bridge.h>
#include "ros/ros.h"
#include "std_msgs/String.h"
#include <sstream>
//Include custom message Lines.msg
#include "lane_followingv2/Lines.h"



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

void PublisherSubscriber<lane_followingv2::Lines, lane_followingv2::Lines>::subscriberCallback(const lane_followingv2::Lines::ConstPtr& msg)
{

    //Asign Read Houghs to HoughX. 0 width will be set
    Point2d _p1, _p2; //Initial points
    Point2d p1, p2; //Final Points
    /*houghs_X[0]._p1.x = msg.x1i;
    houghs_X[0]._p2.x = msg.x1i;
    houghs_X[0]._p1.y = msg.y1i;
    houghs_X[0]._p2.y = msg.y1i;
    houghs_X[0].p1.x = msg.x2i;
    houghs_X[0].p2.x = msg.x2i;
    houghs_X[0].p1.y = msg.y2i;
    houghs_X[0].p2.y = msg.y2i;
    houghs_X[1]._p1.x = msg.x1d;
    houghs_X[1]._p2.x = msg.x1d;
    houghs_X[1]._p1.y = msg.y1d;
    houghs_X[1]._p2.y = msg.y1d;
    houghs_X[1].p1.x = msg.x2d;
    houghs_X[1].p2.x = msg.x2d;
    houghs_X[1].p1.y = msg.y2d;
    houghs_X[1].p2.y = msg.y2d;*/


            //Poner en publisher el mensaje que se va a publicar
            publisherObject.publish(msg);

        


}

int main(int argc, char **argv)
	{

	//Initializing necessary object for execution
	//We need to charge the configuration here too
    KalmanHoughs kalmanHoughs = KalmanHoughs(config, config->verbose, config->display);
	//Creation of buffers for mesured Houghs
	deque<HoughLine> esqBuffer, dirBuffer, esqBufferRejeitados, dirBufferRejeitados;
    //deque<HoughDoMeio> bufferHoughs; Try to construct without the middle line
    vector<int> esqAdjBuffer, dirAdjBuffer;
    int esqAdjAnterior = -1, dirAdjAnterior = -1;

    //Kalman Filter Initialisation
    //KalmanFilter is an OpenCv class. (Dimensionality of the state, Dimensionality of the measurement, Dimensionality of the control vector, Type of the created matrices that should be CV_32F or CV_64F).
    KalmanFilter KF = KalmanFilter(6, 3, 0, CV_64F);
    //KalmanState is an struct in Kalman.h
    KalmanState estadoKalman;
    //Method of the Kalman namespace in Kalman.h. Resets Kalman filter and State.
    Kalman::inicializa(&KF, &estadoKalman, 6, 3);
    //Hough Analysis
    vector<HoughLine> houghs_X = { HoughLine::empty(), HoughLine::empty() };

	ros::init(argc, argv, "kalman");
	PublisherSubscriber<lane_followingv2::Lines, lane_followingv2::Lines> transformer("KalmanLines","HoughLines",1);
	ros::spin();


}

