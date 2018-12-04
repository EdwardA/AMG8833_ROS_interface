/*
 * rosserial Publisher
 * assigns AMG8833 sensor data 
 * to a laser scan intensity 
 * reading to be used further into ros
 */

#include <ros.h>
#include <ros/time.h>
#include <sensor_msgs/LaserScan.h>

#include <Wire.h>
#include <Adafruit_AMG88xx.h>

//***ROS requrments***//
ros::NodeHandle  nh;

sensor_msgs::LaserScan Temp_distance;
ros::Publisher pub_dis("AMG833", &Temp_distance);

const float angle = 60;
float minimum_angle = 0 - (((angle * 71) / 4068) / 2);
float max_angle = (((angle * 71) / 4068) / 2);
float inc = (((angle * 71) / 4068)/8);

char frameid[] = "/AMG833id";


//***AMG8833 requrments***//
Adafruit_AMG88xx amg;
float pixels[AMG88xx_PIXEL_ARRAY_SIZE];
float middle[7];


void setup()
{
  //***ROS requrments***//
  nh.initNode();
  nh.advertise(pub_dis);

  //***AMG8833 requrments***//
  delay(100); //sensor boot
}

void loop()
{
  //read all the pixels
  amg.readPixels(pixels);
  

 for (int i = 0; i <=7; i++)
 {
  int pixelval = 32-i;
  middle[i] = pixels[pixelval];
 }
  
  
  Temp_distance.angle_min = minimum_angle;
  Temp_distance.angle_max = max_angle;
  Temp_distance.intensities = middle[7];
  Temp_distance.header.frame_id = frameid;
  Temp_distance.header.stamp = nh.now();
  Temp_distance.angle_increment = inc;
  Temp_distance.scan_time = 0.1;
  
  pub_dis.publish( &Temp_distance );
  nh.spinOnce();
  delay(1000);
}
