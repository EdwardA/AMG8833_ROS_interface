#!/usr/bin/env python
#This is my test script to read the Hello world example from Rosserial arduino library

import rospy
from std_msgs.msg import String

def callback(data):
    rospy.loginfo(rospy.get_caller_id() + ' I heard %s', data.data)

def ard_listener():
    rospy.init_node('ard_listen', anonymous=False)
    rospy.Subscriber('ard_chatter', String, callback)
    rospy.spin()

if __name__ == '__main__':
    ard_listener()