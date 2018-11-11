/*
 * rosserial Publisher Example
 * Prints "hello world!"
 */

#include <ros.h>
#include <std_msgs/String.h>

#include <Wire.h>
#include <Adafruit_AMG88xx.h>


Adafruit_AMG88xx amg;

ros::NodeHandle  nh;

float pixels[AMG88xx_PIXEL_ARRAY_SIZE];

std_msgs::String str_msg;
ros::Publisher chatter("ard_chatter", &str_msg);

char hello[64] = "hello world!";

void setup()
{
//sensor data
    bool status;
    
    // default settings
    status = amg.begin();
    delay(100);
  
  nh.initNode();
  nh.advertise(chatter);
}

void loop()
{
  //read all the pixels
    amg.readPixels(pixels);

    //Serial.print("[");

  
  amg.readPixels(pixels);
  hello[64] = pixels;
  str_msg.data = hello;
  chatter.publish( &str_msg );
  nh.spinOnce();
  delay(1000);
}
