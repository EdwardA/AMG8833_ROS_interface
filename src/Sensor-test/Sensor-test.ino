#include <Wire.h>
#include <Adafruit_AMG88xx.h>

//***AMG8833 requrments***//
Adafruit_AMG88xx amg;
float pixels[AMG88xx_PIXEL_ARRAY_SIZE];
float middle[8];


void setup() {
  //***AMG8833 requrments***//
  delay(100); //sensor boot
  Serial.begin(57600);

}

void loop() {
  //read all the pixels
  amg.readPixels(pixels);
  float first = pixels[32];
  float second = pixels[31];
  float third = pixels[30];
  float fourth = pixels[29];
  float fith = pixels[28];
  float sixth = pixels[27];
  float seventh = pixels[26];
  float eighth = pixels[25];
  Serial.println(first);
  Serial.println(second);
  Serial.println(third);
  Serial.println(fourth);
  Serial.println(fith);
  Serial.println(sixth);
  Serial.println(seventh);
  Serial.println(eighth);
  Serial.println();
  delay (2000);
}
