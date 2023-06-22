#include "ros/ros.h"
#include "std_msgs/Int32.h"
#include <iostream>

void chatter_callback(const std_msgs::Int32::ConstPtr& msg){
    ROS_INFO("Received [%d]", msg->data);
}

int main(int argc, char **argv){
    ros::init(argc,argv,"topic_subscriber2");
    ros::NodeHandle node_obj;
    ros::Subscriber text_subscriber = node_obj.subscribe("/topic",10, chatter_callback);
    ros::spin();

    return 0;
}