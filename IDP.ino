  /*The Main file of the IDP project.
   This will contain only the setup() and loop() functions. All else should be #included.
   Any include will take up valuable space on the arduino so should be
   modular and application specific.
   I.E not including test-suite header files in final running build etc.
   Arduino convention tab = 2 spaces
   Each #include will also require it's initName(); function to be run in setup.
*/
//Add needed includes
#include "Arduino.h"
#include "move.h"
#include "sense.h"
#include "action.h"
#include "timer.h"
#include "test.h"

//Declare global variables
int period = 1000;
unsigned long tm = timer();

void setup() {
  initMove();
  initSense();
  initAction();
  initTimer();
  //initTest();
  //closeSlider();
  flapSet(0);
}

void loop() {
  //spinWheels(50,50);
  //delay(1000);
  turnAround(LEFTTURN);
  delay(2000);
  moveForwards(RIGHTWALL, WALL);
  turnCorner(LEFTTURN);
}
