#!/usr/bin/env python  
import roslib, rospy
#roslib.load_manifest('learning_tf')

import tf

if __name__ == '__main__':
    rospy.init_node('Sensor_Position')
    br = tf.TransformBroadcaster()
    rate = rospy.Rate(10.0)
    while not rospy.is_shutdown():
        br.sendTransform((0.08633, 0.0, 0.18364),
                         (0.0, 0.0, 0.0, 1.0),
                         rospy.Time.now(),
                         "AMG8833",
                         "base_link")
        rospy.loginfo(br)
        rate.sleep()
