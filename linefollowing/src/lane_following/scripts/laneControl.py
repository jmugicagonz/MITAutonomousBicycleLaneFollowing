#!/usr/bin/env python2
import logging
import cv2
import datetime
from lineDetector import HandCodedLaneFollower
#from objects_on_road_processor import ObjectsOnRoadProcessor
import rospy
from std_msgs.msg import Float64
import math

_SHOW_IMAGE = True


class DeepPiCar(object):

    __INITIAL_SPEED = 0
    __SCREEN_WIDTH = 320
    __SCREEN_HEIGHT = 240

    def __init__(self):
        logging.info('Creating a DeepPiCar...')

        logging.debug('Set up camera')
        self.camera = cv2.VideoCapture(-1)
        self.camera.set(3, self.__SCREEN_WIDTH)
        self.camera.set(4, self.__SCREEN_HEIGHT)


        self.lane_follower = HandCodedLaneFollower(self)
        if rospy.has_param('~max_angle_deviation_two_lanes'):
            self.lane_follower.max_angle_deviation_two_lanes = rospy.get_param('~max_angle_deviation_two_lanes')
        else:
            rospy.logwarn("Max angle deviation two lanes not provided; using %.1f" % self.lane_follower.max_angle_deviation_two_lanes)
        if rospy.has_param('~max_angle_deviation_one_lane'):
            self.lane_follower.max_angle_deviation_one_lane = rospy.get_param('~max_angle_deviation_one_lane')
        else:
            rospy.logwarn(
                "Max angle deviation one lane not provided; using %.1f" % self.lane_follower.max_angle_deviation_one_lane)
        if rospy.has_param('~sensitivity'):
            self.lane_follower.sensitivity = rospy.get_param('~sensitivity')
        else:
            rospy.logwarn(
                "Sensitivity not provided; using %.1f" % self.lane_follower.sensitivity)

        self.fourcc = cv2.VideoWriter_fourcc(*'XVID')
        datestr = datetime.datetime.now().strftime("%y%m%d_%H%M%S")
        '''self.video_orig = self.create_video_recorder('../data/tmp/car_video%s.avi' % datestr)
        self.video_lane = self.create_video_recorder('../data/tmp/car_video_lane%s.avi' % datestr)'''


        logging.info('Created a DeepPiCar')

    def create_video_recorder(self, path):
        return cv2.VideoWriter(path, self.fourcc, 20.0, (self.__SCREEN_WIDTH, self.__SCREEN_HEIGHT))

    def __enter__(self):
        return self

    def __exit__(self, _type, value, traceback):
        if traceback is not None:
            # Exception occurred:
            logging.error('Exiting with statement with exception %s' % traceback)

        self.cleanup()

    def cleanup(self):
        logging.info('Stopping the car, resetting hardware.')
        self.camera.release()
        self.video_orig.release()
        self.video_lane.release()
        cv2.destroyAllWindows()

    def drive(self, speed=__INITIAL_SPEED):

        logging.info('Starting to drive at speed %s...' % speed)

        i = 0
        while self.camera.isOpened():
            _, image_lane = self.camera.read()
            image_objs = image_lane.copy()
            i += 1
            self.video_orig.write(image_lane)



            image_lane = self.follow_lane(image_lane)
            self.video_lane.write(image_lane)
            show_image('Lane Lines', image_lane)

            if cv2.waitKey(1) & 0xFF == ord('q'):
                self.cleanup()
                break



    def follow_lane(self, image):
        image = self.lane_follower.follow_lane(image)
        return image


############################
# Utility Functions
############################
def show_image(title, frame, show=_SHOW_IMAGE):
    if show:
        cv2.imshow(title, frame)


'''def main():
    with DeepPiCar() as car:
        car.drive(40)'''


'''def laneControl():
    rospy.init_node('laneControl', anonymous=True)
    pub = rospy.Publisher('steeringAngle', Float64, queue_size=10)
    rate = rospy.Rate(10) # 10hz
    while not rospy.is_shutdown():
        with DeepPiCar() as car:
            car.drive(40)
            curr_steering_angle_pub = car.lane_follower.curr_steering_angle - 90.0
    msg = Float64()
    msg.data = 1.0
    //hello_str = "hello world %s" % rospy.get_time()
    rospy.loginfo(msg)
    pub.publish(msg)
    rate.sleep()'''

if __name__ == '__main__':
    try:
        rospy.init_node('laneControl', anonymous=True)
        pub = rospy.Publisher('steeringAngle', Float64, queue_size=10)
        rate = rospy.Rate(10)  # 10hz
        with DeepPiCar() as car:
		i = 0
		while (car.camera.isOpened() and not rospy.is_shutdown()):
			_, image_lane = car.camera.read()
			image_objs = image_lane.copy()
			i += 1
			'''car.video_orig.write(image_lane)'''
			image_lane = car.follow_lane(image_lane)
			'''car.video_lane.write(image_lane)'''
			show_image('Lane Lines', image_lane)
			curr_steering_angle_pub = car.lane_follower.curr_steering_angle - 90.0
			msg = Float64()
			if (curr_steering_angle_pub>=35):
				curr_steering_angle_pub = 35
			if (curr_steering_angle_pub<=-35):
				curr_steering_angle_pub = -35
			msg.data = math.radians(curr_steering_angle_pub)
			'''msg.data = curr_steering_angle_pub'''
			rospy.loginfo(msg)
			pub.publish(msg)
			rate.sleep()

			if cv2.waitKey(1) & 0xFF == ord('q'):
			    self.cleanup()
			    break
        #laneControl()
    except rospy.ROSInterruptException:
        pass


