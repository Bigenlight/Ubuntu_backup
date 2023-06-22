#!/usr/bin/env python3

import rospy
from std_msgs.msg import Int32

rospy.init_node("topic_publisher2") # 노드 만들기

pub = rospy.Publisher("topic", Int32, queue_size=10) # 토픽 정의

rate = rospy.Rate(2) # 시간

#보낼 메시지
count = 0

while not rospy.is_shutdown():

    pub.publish(count) # 메시지 보내기
    count +=1
    rate.sleep() # 1초에 2번이 되게끔 쉰다