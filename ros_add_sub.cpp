#include "ros/ros.h"
#include <ros_add/two_nums_add.h>
#include <iostream>
#include <std_msgs/Float32.h>

// variables to store globally

ros_add::two_nums_add num_one;
ros_add::two_nums_add num_two;

void callback(const ros_add::two_nums_add message_holder)
{
ROS_INFO("first number is %f", message_holder.first_num);
num_one.first_num= message_holder.first_num;
}

void callback2(const ros_add::two_nums_add message_holder2)
{
ROS_INFO("second number is %f", message_holder2.second_num);
num_two.second_num= message_holder2.second_num;
}

void callback3(const ros_add::two_nums_add message_holder3)
{
ROS_INFO("sum is %f", num_one.first_num + num_two.second_num);
}


int main(int argc, char **argv)
{
ros::init(argc, argv, "ros_add_sub");
ros::NodeHandle n;
ros::Subscriber my_sub_obj = n.subscribe("two_numbers",1,callback);
ros::Subscriber my_sub_obj2 = n.subscribe("two_numbers",1,callback2);
ros::Subscriber my_sub_obj3 = n.subscribe("two_numbers",1,callback3);
ros::spin();
return 0;
}

