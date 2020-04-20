/***********************************************************************
 * Program:     run a light test on start up
 *
 * Author:      Philip Walsh
 *              2018-04-12
 *
 * Description:
 *  this sketch lights up the leds for 2 seconds, red then green finalluy blue
 *  at start up only
 ************************************************************************/

#include <MeMCore.h>

/******************* Global Declarations *******************************/

// Onboard LED port/slot definitions
const int PORT = 7;
const int SLOT = 2;

// LED Control settings
const int BOTH_LEDS = 0;
const int RIGHT_LED = 1;
const int LEFT_LED  = 2;

// Declare the MeRGLed object
MeRGBLed onboardLEDs(PORT, SLOT);

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

/***********************************************************************
 * Method:       setup
 *
 * Arguments:    None
 *
 * Returns:      N/A
 *
 * Description:
 *    This method handles all of the initialization for the program.
 ************************************************************************/
void setup() {
  // init the vars
  int red = 0;
  int green = 0;
  int blue = 0;
  int wait_duration = 2000;  // duration in milliseconds


  // *********
  // ** RED **
  // *********
  
  // set to green, light it up, and pause, then off
  red = 150;
  updateLED(BOTH_LEDS, red, green, blue);
  delay(wait_duration);
  red = green = blue = 0;
  updateLED(BOTH_LEDS, red, green, blue);
  delay(wait_duration);

  // ***********
  // ** GREEN **
  // ***********
  
  // set to green, light it up, and pause, then off
  green = 150;
  updateLED(BOTH_LEDS, red, green, blue);
  delay(wait_duration);
  red = green = blue = 0;
  updateLED(BOTH_LEDS, red, green, blue);
  delay(wait_duration);

  // **********
  // ** BLUE **
  // **********
  
  // set to green, light it up, and pause, then off
  blue = 150;
  updateLED(BOTH_LEDS, red, green, blue);
  delay(wait_duration);
  red = green = blue = 0;
  updateLED(BOTH_LEDS, red, green, blue);
  delay(wait_duration);
  
}

/***********************************************************************
 * Method:      loop
 *
 * Arguments:   None
 *
 * Returns:     N/A
 *
 * Description:
 *    This method executes continuously after the setup method
 *    completes its tasks.
 ***********************************************************************/
void loop() {
}
