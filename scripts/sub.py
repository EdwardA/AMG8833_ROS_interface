#!/usr/bin/env python2
#This script reads data from an Arduino based temperature sensor and publishes it as a LaserScan message using the data from /scan in the turtlebot

import rospy
from std_msgs.msg import Float64, Float32, Header, Time
from sensor_msgs.msg import Temperature, LaserScan

temp_Scan_data = LaserScan()
Laser_Scan_data = LaserScan()

def AMG8833_temp():
    global temp_Scan_data
    global Laser_Scan_data
    pub = rospy.Publisher('temp_scanner', LaserScan, queue_size=10)
    my_msg = temp_Scan_data
    Scan_count = len(Laser_Scan_data.ranges) 
    Scan_div = Scan_count / 8
    #rospy.loginfo(rospy.get_caller_id() + ' Laser_scan = %s', Laser_Scan_data)
    #extract = range(0,int(Scan_count+1),int(Scan_div))
    slicing = slice(0, int(Scan_count+1), int(Scan_div))
    sliced_data = Laser_Scan_data.ranges[slicing]
    my_msg.ranges = sliced_data
    my_msg.intensities = temp_Scan_data.intensities
    my_msg.header.frame_id = "camera_depth_frame"
    pub.publish(my_msg)
    rospy.loginfo(rospy.get_caller_id() + ' my_msg = %s', my_msg)
	
    
	

def callback(data):
	#rospy.loginfo(rospy.get_caller_id() + ' I heard %s', data.data)
	AMG8833_temp(data)
    
def temp_callback(data):
    global temp_Scan_data
    temp_Scan_data = data
    
def scan_callback(data):
    global Laser_Scan_data
    #rospy.loginfo(rospy.get_caller_id() + ' /scan = %s', data)
    Laser_Scan_data = data
    AMG8833_temp()

def ard_listener():
    rospy.init_node('ard_listen', anonymous=False)
    rospy.Subscriber('AMG8833', LaserScan, temp_callback)
    rospy.Subscriber('/scan', LaserScan, scan_callback)
    rospy.spin()
    
    
if __name__ == '__main__':
    ard_listener()
