# AMG8833_ROS_interface
This repo interfaces an AMG8833 IR camera with ROS.

The AMG8833 uses I2C to comunicate and so the data is read and interprreted using an Arduino MEGA and assigning the centra line of the dat to the intensity feild of a LaserScan message.

This LaserScan message is then given depth data from ROS thanks to the /SCAN topic within the Turtlebot2.

This program requires an arduino mega as the uno does not have sufficent memory and no other boards ahve been tested.

Arduino code:
	[package]>src>Arduino_rosserial_temp

the package can be launched used the camera_sim.launch file. This uses the turtlebot2 stage simulator.



Limitations / future work:
Currently, this package uses the sensor_msgs LaserScan message type, which is not apropriate message type for the ROS system. Instead, either a custom message type or pointcloud2 would be more appropriate. However, as a proof of concept this implentation allows the data to be visualised well within RVIZ.
