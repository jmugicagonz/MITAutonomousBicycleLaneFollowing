#include "ros/ros.h"
#include "sensor_msgs/Joy.h"
#include "std_msgs/Float64.h"

/**
 * This tutorial demonstrates simple sending of messages over the ROS system.
 */
ros::Publisher pub;
ros::Publisher pub2;

void JoyCallback(const sensor_msgs::Joy joy)
{
  // std::cout << joy.axes[0] << std::endl;
  std_msgs::Float64 steering_angle;
  steering_angle.data = -1*joy.axes[0] * 0.785;
  pub.publish(steering_angle);


  std_msgs::Float64 speed;
  speed.data = joy.axes[4]*7000;
  pub2.publish(speed);

}

int main(int argc, char **argv)
{
  ros::init(argc, argv, "joytest");
  ros::NodeHandle nh;
  pub =nh.advertise<std_msgs::Float64>("steering_motor", 1);
  pub2 =nh.advertise<std_msgs::Float64>("drive_motor", 1);
  ros::Subscriber sub = nh.subscribe("joy", 1, JoyCallback);
  ros::spin();
  return 0;
}
