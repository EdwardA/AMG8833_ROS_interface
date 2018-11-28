#!/usr/bin/env python2
#This script reads the depth from the RGBD scanner, extracts the centre distance and combines it with the temperature reading

import rospy
from std_msgs.msg import Float64, Float32, Header, Time
from sensor_msgs.msg import Temperature, LaserScan

def ExtractPoint(data):
	#pub = rospy.Publisher('temp_dis_topic', WhoKnowWhatType, queue_size=10)
	distanceScan = data.data
	dist_mid = distanceScan.ranges[319]
	
def PublishtfFrame():
    rospy.init_node('Sensor_Position')
    br = tf.TransformBroadcaster()
    rate = rospy.Rate(10.0)
    distanceZ = Float64(dist_mid - 0.18364)
    while not rospy.is_shutdown():
        br.sendTransform((0.08633, 0.0, distanceZ),
                         (0.0, 0.0, 0.0, 1.0),
                         rospy.Time.now(),
                         "Heat_point",
                         "base_link")
        rospy.loginfo(br)
    
	

def ScanCallback(data):
	#rospy.loginfo(rospy.get_caller_id() + ' I heard Scan %s', data.data)
	ExtractPoint(data)
	PublishtfFrame()
	

def distance_listen():
	rospy.init_node('temp_dis', anonymous=False)
	rospy.Subscriber('scan', LaserScan, ScanCallback)
	rospy.spin()
    
    
if __name__ == '__main__':
	ard_listener()
