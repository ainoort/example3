#include "ros/ros.h"
#include <ros_add/two_nums_add.h>
#include <iostream>
#include <std_msgs/Float64.h>

int main(int argc, char** argv){
ros::init(argc,argv,"ros_add_pub");

ros::NodeHandle nh;
ros::Publisher my_pub_obj = nh.advertise<ros_add::two_nums_add>("two_numbers",10);

ros::Rate rate(10);

while (ros::ok())
  {
    ros_add::two_nums_add numbers;
    numbers.first_num = rand();
    numbers.second_num = rand();
    ROS_INFO("%f", numbers.first_num);
     ROS_INFO("%f", numbers.second_num);
    my_pub_obj.publish(numbers);
    rate.sleep();
  }
  return 0;
}


