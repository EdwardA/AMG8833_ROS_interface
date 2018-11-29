#!/usr/bin/env python2
#This script reads the depth from the RGBD scanner, extracts the centre distance and combines it with the temperature reading

import rospy, roslib
from std_msgs.msg import Float64, Float32, Header, Time
from sensor_msgs.msg import Temperature, LaserScan
import tf
dist_mid = 0
	
def ScanCallback(data):
    #rospy.init_node('Sensor_Position')
    br = tf.TransformBroadcaster()
    rate = rospy.Rate(10.0)
    distanceZ = (data.ranges[319] - 0.1)
    #while not rospy.is_shutdown():
    br.sendTransform((distanceZ, 0.0 , 0.18364),
                     (0.0, 0.0, 0.0, 1.0),
                     rospy.Time.now(),
                     "Heat_point",
                     "base_link")
    rospy.loginfo(br)
    
def distance_listen():
	rospy.init_node('Sensor_Position')
	rospy.Subscriber('scan', LaserScan, ScanCallback)
	rospy.spin()
    
    
if __name__ == '__main__':
	distance_listen()
