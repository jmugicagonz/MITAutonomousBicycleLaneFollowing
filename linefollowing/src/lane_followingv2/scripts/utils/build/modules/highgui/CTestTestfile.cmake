# CMake generated Testfile for 
# Source directory: /home/jmugicagonz/LaneDetectionV2/opencv-master/modules/highgui
# Build directory: /home/jmugicagonz/LaneDetectionV2/build/modules/highgui
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test(opencv_test_highgui "/home/jmugicagonz/LaneDetectionV2/build/bin/opencv_test_highgui" "--gtest_output=xml:opencv_test_highgui.xml")
set_tests_properties(opencv_test_highgui PROPERTIES  LABELS "Main;opencv_highgui;Accuracy" WORKING_DIRECTORY "/home/jmugicagonz/LaneDetectionV2/build/test-reports/accuracy")
