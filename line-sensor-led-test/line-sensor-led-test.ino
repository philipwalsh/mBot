/**
 * 
 * @file    line-sensor-test.ino
 * @author  Philip Walsh
 * @date    2020-04-12
 * @brief   Description: testing the line sensor
 *
 * Function List:
 *  uint8_t MeLineFollower::readSensors(void)
 *
 */
#include <MeMCore.h>

// test 1 - line sensor is connetced to slot #2
// MeLineFollower lineFinder(PORT_3); /* Line Finder module can only be connected to PORT_3, PORT_4, PORT_5, PORT_6 of base shield. */

// test 2 - I moved line sensor to slot #1 and tried the same code, PORT_3, it seemed to function the same
// MeLineFollower lineFinder(PORT_3); /* Line Finder module can only be connected to PORT_3, PORT_4, PORT_5, PORT_6 of base shield. */



// Onboard LED port/slot definitions
const int PORT = 7;
const int SLOT = 2;

// LED Control settings
const int BOTH_LEDS = 0;
const int RIGHT_LED = 1;
const int LEFT_LED  = 2;

const int WAIT_DURATION=1000;

// Declare the MeRGLed object
MeRGBLed onboardLEDs(PORT, SLOT);
MeLineFollower lineFinder(PORT_3); /* Line Finder module can only be connected to PORT_3, PORT_4, PORT_5, PORT_6 of base shield. */

/**************** End of Global Declarations ***************************/

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
}

void loop()
{
  int red = 0;
  int green_off = 0;
  int green_on = 50;
  int blue = 0;
  
  int sensorState = 0
  
  
  sensorState = lineFinder.readSensors();
  switch(sensorState)
  {
    case S1_IN_S2_IN: 
      //Serial.println("Sensor 1 and 2 are inside of black line"); 
      // set both to green, light it up, and pause, then off
      updateLED(BOTH_LEDS, red, green_on, blue);
      break;
    case S1_IN_S2_OUT: 
      //Serial.println("Sensor 2 is outside of black line"); 
      // set both to green, light it up, and pause, then off
      updateLED(LEFT_LED, red, green_on, blue);
      updateLED(RIGHT_LED, red, green_off, blue);
      
      break;
    case S1_OUT_S2_IN: 
      //Serial.println("Sensor 1 is outside of black line"); 
      //Serial.println("Sensor 2 is outside of black line"); 
      // set both to green, light it up, and pause, then off
      updateLED(RIGHT_LED, red, green_on, blue);
      updateLED(LEFT_LED, red, green_off, blue);
      
      break;
    case S1_OUT_S2_OUT: 
      //Serial.println("Sensor 1 and 2 are outside of black line"); 
      //Serial.println("Sensor 2 is outside of black line"); 
      // set both to green, light it up, and pause, then off
      updateLED(BOTH_LEDS, red, green_off, blue);
      
      break;
    default: 
      break;
  }
  delay(200);
}
