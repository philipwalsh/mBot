/**
 * @file    me-led-matrix-test.ino
 * @author  Philip Walsh
 * @version V1.0.0
 * @date    2020-04-12
 * @brief   Description: testing the led matrix display as well as a using the ultrasonic sensor in this test
 * 
 * after uploading, the robot will just sit there and wait for you to put something right up in his grill
 * when that happens, his LEDs will turn red ansd, the matrix display will display the word stop
 *
 * Function List:
 * 1. double MeUltrasonicSensor::distanceCm(uint16_t MAXcm)
 * 2. void MeLEDMatrix::setBrightness(uint8_t Bright);
 * 3. void MeLEDMatrix::setColorIndex(bool Color_Number);
 * 4. void MeLEDMatrix::drawStr(int16_t X_position, int8_t Y_position, const char *str);
 * 5. void MeLEDMatrix::clearScreen();
 */
#include <MeMCore.h>

// Onboard LED port/slot definitions
const int PORT = 7;
const int SLOT = 2;

// LED Control settings
const int BOTH_LEDS = 0;
const int RIGHT_LED = 1;
const int LEFT_LED  = 2;


MeLEDMatrix ledMx(PORT_1);
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
  ledMx.setBrightness(Brightness_4);  // 0-8
  ledMx.setColorIndex(true);  //i dont think this function does squat

  
}


char *message = "xxx";


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
    ledMx.drawStr(0,7,message);
  }else{
    ledMx.clearScreen();
    red=0;
  }
  
  updateLED(BOTH_LEDS, red, green, blue);

  
  
  delay(100); /* the minimal measure interval is 100 milliseconds */
}
