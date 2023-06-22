#include "ros/ros.h"
#include "std_msgs/Int32.h"
#include <iostream>

void number_callbak(const std_msgs::Int32::ConstPtr& msg){
    ROS_INFO("Received [%d]",msg->data);
}

int main(int argc, char **argv){
    ros::init(argc, argv,"demo_topic_subscriber");
    ros::NodeHandle node_obj;
    ros::Subscriber number_subscriber = node_obj.subscribe("/number",10, number_callbak);
    ros::spin();

    return 0;
}// ctrl + shift + p -> bongocat