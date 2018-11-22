#!/usr/bin/env python2
#This script reads data from an arduino based temperature sensor and publishes it as a temperature message

import rospy
from std_msgs.msg import Float64, Float32, Header
from sensor_msgs.msg import Temperature

def AMG8833_temp(data):
	pub = rospy.Publisher('temp_chatter', Temperature, queue_size=10)
	my_msg = Temperature()
	my_msg.Header
	my_msg.temperature = Float64(data)
	my_msg.variance = 0
	pub.publish(my_msg)
	#rospy.loginfo(rospy.get_caller_id() + ' I published', my_msg)
    
	

def callback(data):
	rospy.loginfo(rospy.get_caller_id() + ' I heard %s', data.data)
	AMG8833_temp(data)
    
    

def ard_listener():
	rospy.init_node('ard_listen', anonymous=False)
	rospy.Subscriber('ard_chatter', Float32, callback)
	rospy.spin()
    
    
if __name__ == '__main__':
	ard_listener()
