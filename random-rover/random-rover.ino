/**
 * @file    random-rover.ino
 * @author  Philip Walsh
 * @version V1.0.0
 * @date    2020-04-13
 * @brief   Description: testing the ultrasonic sensor and randomly roving till it hits an obstacle
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


MeDCMotor MotorL(M1);
MeDCMotor MotorR(M2);



MeRGBLed onboardLEDs(PORT, SLOT);
MeUltrasonicSensor ultraSensor(PORT_4); /* Ultrasonic module can ONLY be connected to port 3, 4, 6, 7, 8 of base shield. */


//MeLineFollower lineFinder(PORT_3); /* Line Finder module can only be connected to PORT_3, PORT_4, PORT_5, PORT_6 of base shield. */




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
  
  updateLED(BOTH_LEDS, 255, 0, 0);
  delay(1000);
  updateLED(BOTH_LEDS, 255, 128, 0);
  delay(1000);
  updateLED(BOTH_LEDS, 255, 255, 0);
  delay(1000);
  updateLED(BOTH_LEDS, 128, 255, 0);
  delay(1000);
  updateLED(BOTH_LEDS, 0, 255, 0);
  delay(1000);
  updateLED(BOTH_LEDS, 0, 255, 128);
  delay(1000);
  updateLED(BOTH_LEDS, 0, 255, 255);
  delay(1000);
  updateLED(BOTH_LEDS, 0, 128, 255);
  delay(1000);
  updateLED(BOTH_LEDS, 0, 0, 255);
  delay(1000);
  
  updateLED(BOTH_LEDS, 0, 0, 0);
  Forward();
}


void Forward()
{
  MotorL.run(-100);
  MotorR.run(100);
}


void Stop()
{
  MotorL.run(0);
  MotorR.run(0);
}

void TurnLeft(int turnFor)
{
  
  MotorL.run(50);
  MotorR.run(50);
  delay(turnFor);
}

void loop()
{
  int red = 0;
  int green = 0;
  int blue = 0;
  int green_on = 0;
  int green_off = 0;
  int lineSensorState = 0;
  int led_brightness=100;

  green_on = led_brightness;
  double current_range = 0.0;
  
  //range 3 centimeters  to 4 meters
  // 3 - 400  
  

  current_range = ultraSensor.distanceCm();
  //Serial.print(current_range);

  //if something gets right up in our grill, turn on the lights
  if ((current_range <= 15) && (current_range >= 3)){
    Stop();
    red=led_brightness;
    updateLED(BOTH_LEDS, red, green, blue);
    delay(1000);
    
    TurnLeft(250);
    delay(1000);
    Forward();
    
  }else{
    //nothing in the way, move foreward
    
    // clear to proceed, lets check the line sensor
    
    //lineSensorState = lineFinder.readSensors();
    //switch(lineSensorState)
    //{
    //  case S1_IN_S2_IN: 
    //    //Serial.println("Sensor 1 and 2 are inside of black line"); 
    //    // set both to green, light it up, and pause, then off
    //    updateLED(BOTH_LEDS, red, green_on, blue);
    //    break;
    //    
    //  case S1_IN_S2_OUT: 
    //    //Serial.println("Sensor 2 is outside of black line"); 
    //    // set both to green, light it up, and pause, then off
    //    updateLED(LEFT_LED, red, green_on, blue);
    //    updateLED(RIGHT_LED, red, green_off, blue);
    //    break;
    //    
    //  case S1_OUT_S2_IN: 
    //    //Serial.println("Sensor 1 is outside of black line"); 
    //    //Serial.println("Sensor 2 is outside of black line"); 
    //    // set both to green, light it up, and pause, then off
    //    updateLED(RIGHT_LED, red, green_on, blue);
    //    updateLED(LEFT_LED, red, green_off, blue);
    //    break;
    //    
    //  case S1_OUT_S2_OUT: 
    //    //Serial.println("Sensor 1 and 2 are outside of black line"); 
    //    //Serial.println("Sensor 2 is outside of black line"); 
    //    // set both to green, light it up, and pause, then off
    //    updateLED(BOTH_LEDS, red, green_off, blue);
    //    break;
    //    
    //  default: 
    //    break;
    //}

  
  }
  
  

  
  
  delay(200); /* the minimal measure interval is 100 milliseconds */
}
