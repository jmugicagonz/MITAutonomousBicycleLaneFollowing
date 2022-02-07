#!/usr/bin/env python2
import logging
import cv2
import datetime
from lineDetectorv2 import HandCodedLaneFollower
#from objects_on_road_processor import ObjectsOnRoadProcessor
import rospy
from lane_followingv2.msg import Lines

_SHOW_IMAGE = False


class DeepPiCar(object):

    __INITIAL_SPEED = 0
    __SCREEN_WIDTH = 320
    __SCREEN_HEIGHT = 240

    def __init__(self):
        """ Init camera and wheels"""
        logging.info('Creating a DeepPiCar...')

        '''picar.setup()'''

        logging.debug('Set up camera')
        self.camera = cv2.VideoCapture(-1)
        self.camera.set(3, self.__SCREEN_WIDTH)
        self.camera.set(4, self.__SCREEN_HEIGHT)

        self.lane_follower = HandCodedLaneFollower(self)

        if rospy.has_param('~sensitivity'):
            self.lane_follower.sensitivity = rospy.get_param('~sensitivity')
        else:
            rospy.logwarn(
                "Sensitivity not provided; using %.1f" % self.lane_follower.sensitivity)


    def __enter__(self):
        """ Entering a with statement """
        return self

    def __exit__(self, _type, value, traceback):
        """ Exit a with statement"""
        if traceback is not None:
            # Exception occurred:
            logging.error('Exiting with statement with exception %s' % traceback)

        self.cleanup()

    def cleanup(self):
        """ Reset the hardware"""
        logging.info('Stopping the car, resetting hardware.')
        '''self.back_wheels.speed = 0
        self.front_wheels.turn(90)'''
        self.camera.release()
        self.video_orig.release()
        self.video_lane.release()
        '''self.video_objs.release()'''
        cv2.destroyAllWindows()


    def follow_lane(self, image):
        lane_lines = self.lane_follower.follow_lane(image)
        return lane_lines


############################
# Utility Functions
############################
def show_image(title, frame, show=_SHOW_IMAGE):
    if show:
        cv2.imshow(title, frame)


if __name__ == '__main__':
    try:
        rospy.init_node('HoughDetector', anonymous=True)
        pub = rospy.Publisher('HoughLines', Lines, queue_size=1)
        rate = rospy.Rate(10)  # 10hz
        with DeepPiCar() as car:
            i = 0
            while (car.camera.isOpened() and not rospy.is_shutdown()):
                _, image_lane = car.camera.read()
                i += 1
                lane_lines = []
                lane_lines = car.follow_lane(image_lane)
                #car.video_lane.write(image_lane)
                #show_image('Lane Lines', image_lane)
                #curr_steering_angle_pub = car.lane_follower.curr_steering_angle - 90.0
                msg = Lines()
                '''if (curr_steering_angle_pub>=45):
                    curr_steering_angle_pub = 40
                if (curr_steering_angle_pub<=-45):
                    curr_steering_angle_pub = -40'''
                #rospy.loginfo(lane_lines)
                msg.x1i = lane_lines[0][0][0]
                msg.y1i = lane_lines[0][0][1]
                msg.x2i = lane_lines[0][0][2]
                msg.y2i = lane_lines[0][0][3]
                msg.x1d = lane_lines[1][0][0]
                msg.y1d = lane_lines[1][0][1]
                msg.x2d = lane_lines[1][0][2]
                msg.y2d = lane_lines[1][0][3]
                '''hello_str = "hello world %s" % rospy.get_time()'''
                rospy.loginfo(msg)
                pub.publish(msg)
                rate.sleep()

                if cv2.waitKey(1) & 0xFF == ord('q'):
                    self.cleanup()
                    break
        #laneControl()
    except rospy.ROSInterruptException:
        pass



