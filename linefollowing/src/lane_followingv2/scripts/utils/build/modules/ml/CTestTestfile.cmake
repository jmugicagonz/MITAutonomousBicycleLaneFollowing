# CMake generated Testfile for 
# Source directory: /home/jmugicagonz/LaneDetectionV2/opencv-master/modules/ml
# Build directory: /home/jmugicagonz/LaneDetectionV2/build/modules/ml
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test(opencv_test_ml "/home/jmugicagonz/LaneDetectionV2/build/bin/opencv_test_ml" "--gtest_output=xml:opencv_test_ml.xml")
set_tests_properties(opencv_test_ml PROPERTIES  LABELS "Main;opencv_ml;Accuracy" WORKING_DIRECTORY "/home/jmugicagonz/LaneDetectionV2/build/test-reports/accuracy")
