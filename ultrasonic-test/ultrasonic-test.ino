/**
 * @file    ultrasonic-test.ino
 * @author  Philip Walsh
 * @version V1.0.0
 * @date    2020-04-12
 * @brief   Description: testing the ultrasonic sensor
 *
 * Function List:
 *  double MeUltrasonicSensor::distanceCm(uint16_t MAXcm)
 *
 */
#include <MeMCore.h>

// Onboard LED port/slot definitions
const int PORT = 7;
const int SLOT = 2;

// LED Control settings
const int BOTH_LEDS = 0;
const int RIGHT_LED = 1;
const int LEFT_LED  = 2;



MeRGBLed onboardLEDs(PORT, SLOT);
MeUltrasonicSensor ultraSensor(PORT_4); /* Ultrasonic module can ONLY be connected to port 3, 4, 6, 7, 8 of base shield. */



/***********************************************************************
 * Method:  updateLED(int led, int red, int green, int blue)
 *
 * Arguments:
 *           Variable        Values
 *          --------------------------
 *          led             0 - 2  (0 - Both LEDs; 1 - Right LED; 2 - Left LED)
 *          red             0 - 255
 *          green           0 - 255
 *          Blue            0 - 255
 *
 * Returns: N/A
 *
 * Description:
 *  The updateLED method manages the current color of the onboard
 *  LEDs.
 ************************************************************************/
void updateLED(int led, int red, int green, int blue) {
  onboardLEDs.setColor(led, red, green, blue);
  onboardLEDs.show();
}


void setup()
{
  Serial.begin(9600);
  updateLED(BOTH_LEDS, 0, 0, 0);
}

void loop()
{
  int red = 0;
  int green = 0;
  int blue = 0;

  int led_brightness=25;
  
  double current_range = 0.0;
  
  //range 3 centimeters  to 4 meters
  // 3 - 400  
  

  current_range = ultraSensor.distanceCm();
  //Serial.print(current_range);

  //if something gets right up in our grill, turn on the lights
  if ((current_range <= 10) && (current_range >= 3)){
    red=led_brightness;
  }else{
    red=0;
  }
  
  updateLED(BOTH_LEDS, red, green, blue);

  
  
  delay(100); /* the minimal measure interval is 100 milliseconds */
}
