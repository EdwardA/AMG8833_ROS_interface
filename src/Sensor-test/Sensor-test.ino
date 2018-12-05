#include <Wire.h>
#include <Adafruit_AMG88xx.h>

//***AMG8833 requrments***//
Adafruit_AMG88xx amg;
float pixels[AMG88xx_PIXEL_ARRAY_SIZE];
float middle[7];
  
void setup() {
  //***AMG8833 requrments***//
  delay(100); //sensor boot
  Serial.begin(57600);

}

void loop() {
  //read all the pixels
  
  

 for (int i = 0; i <=7; i++)
 {
  amg.readPixels(pixels);
  Serial.print("pixel number = ");
  int pixelval = 32-i;
  Serial.println (pixelval);
  middle[i] = pixels[pixelval];
  Serial.print("pixel val= ");
  Serial.println(pixels[pixelval]);
  if (pixelval == 25){
    Serial.println();
  }
  
  delay (1000);
 }
}
 
