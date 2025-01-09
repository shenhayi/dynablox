#include <gflags/gflags.h>
#include <ros/ros.h>

#include "dynablox_ros/motion_detector.h"

int main(int argc, char** argv) {
  ros::init(argc, argv, "motion_detector");

  // Always add these arguments for proper logging.
  config_utilities::RequiredArguments ra(
      &argc, &argv, {"GLOG_logtostderr=1", "GLOG_colorlogtostderr=1"});

  // Setup logging.
  google::InitGoogleLogging(argv[0]);
  google::InstallFailureSignalHandler();
  google::ParseCommandLineFlags(&argc, &argv, false);

  // Setup node.
  ros::NodeHandle nh;
  ros::NodeHandle nh_private("~");
  dynablox::MotionDetector motion_detector(nh, nh_private);

  ros::spin();
  return 0;
}
