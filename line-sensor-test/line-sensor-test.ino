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





void setup()
{
  Serial.begin(9600);
}

void loop()
{
  int sensorState = lineFinder.readSensors();
  switch(sensorState)
  {
    case S1_IN_S2_IN: 
      //Serial.println("Sensor 1 and 2 are inside of black line"); 
      break;
    case S1_IN_S2_OUT: 
      Serial.println("Sensor 2 is outside of black line"); 
      break;
    case S1_OUT_S2_IN: 
      Serial.println("Sensor 1 is outside of black line"); 
      break;
    case S1_OUT_S2_OUT: 
      Serial.println("Sensor 1 and 2 are outside of black line"); 
      break;
    default: 
      break;
  }
  delay(200);
}
