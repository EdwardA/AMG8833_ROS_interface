/***************************************************************************
  This is a library for the AMG88xx GridEYE 8x8 IR camera

  This sketch tries to read the pixels from the sensor

  Designed specifically to work with the Adafruit AMG88 breakout
  ----> http://www.adafruit.com/products/3538

  These sensors use I2C to communicate. The device's I2C address is 0x69

  Adafruit invests time and resources providing this open source code,
  please support Adafruit andopen-source hardware by purchasing products
  from Adafruit!

  Written by Dean Miller for Adafruit Industries.
  BSD license, all text above must be included in any redistribution
 ***************************************************************************/

#include <Wire.h>
#include <Adafruit_AMG88xx.h>

Adafruit_AMG88xx amg;

int x;
int firstDigit;
int secondDigit;
float pixels[AMG88xx_PIXEL_ARRAY_SIZE];
int lookUpArray[64] = 
{11, 21, 31, 41, 51, 61, 71, 81,
12, 22, 32, 42, 52, 62, 72, 82,
13, 23, 33, 43, 53, 63, 73, 83,
14, 24, 34, 44, 54, 64, 74, 84,
15, 25, 35, 45, 55, 65, 75, 85,
16, 26, 36, 46, 56, 66, 76, 86,
17, 27, 37, 47, 57, 67, 77, 87,
18, 28, 38, 48, 58, 68, 78, 88};


void setup() {
    Serial.begin(115200);
    Serial.println(F("AMG88xx pixels"));

    bool status;
    
    // default settings
    status = amg.begin();
    if (!status) {
        Serial.println("Could not find a valid AMG88xx sensor, check wiring!");
        while (1);
    }
    
    Serial.println("-- Pixels Test --");

    Serial.println();

    delay(100); // let sensor boot up
}


void loop() { 
    //read all the pixels
    amg.readPixels(pixels);

    Serial.print("[");
    for(int i=1; i<=AMG88xx_PIXEL_ARRAY_SIZE; i++){
      Serial.print(pixels[i-1]);
      Serial.print(", ");
      if( i%8 == 0 ) Serial.println();
    }
    const byte maxMeasurements = 64;
    byte maxIndex = 0;
    float maxValue = pixels[maxIndex];

    for(byte i = 1; i < maxMeasurements; i++)
    {
        if(pixels[i] > maxValue) {
            maxValue = pixels[i];
            maxIndex = i;
            x = lookUpArray[maxIndex -1];
            secondDigit = x %10;
            firstDigit = (x/10)%10;
            
        }
    }
    Serial.println("]");
    Serial.print("Max value is: "); Serial.println(maxValue);
    Serial.print("At index: "); Serial.println(maxIndex);
    Serial.print("Convert to co-ordinate: "); Serial.println(x);
    Serial.print("X coordinate: "); Serial.println(firstDigit);
    Serial.print("Y coordinate: "); Serial.println(secondDigit);
    Serial.println();
    Serial.println("================================================");
    Serial.println();

    //delay a second
    delay(100);
}
