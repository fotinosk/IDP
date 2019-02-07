  /*The Main file of the IDP project.
   This will contain only the setup() and loop() functions. All else should be #included.
   Any include will take up valuable space on the arduino so should be
   modular and application specific.
*/
//Add needed includes
#include "Arduino.h"
#include "move.h"
#include "sense.h"
#include "action.h"
#include "timer.h"
//#include "test.h"

uint16_t flapDelay = 1000;

void setup() {
  initMove();
  initSense();
  initAction();
  initTimer();
  //initTest();
  Serial.begin(9600);
  
}

void loop() {
 
 while(!switchFrontRight()){}
  delay(1000);
 sortSet(LEFTPOS);
  moveWheels(0, 100, TIMER, 200, 0);
  moveWheels(97,100, WALL, 0, 700);

  turnCorner(RIGHTTURN);
  sortSet(LEFTPOS);
  moveWheels(97,100, WALL, 0, flapDelay);
  turnCorner(RIGHTTURN);
  sortSet(LEFTPOS);
  moveWheels(97, 100, LINE, 0, flapDelay);
  turn90(RIGHTTURN);
  sortSet(LEFTPOS);
  moveWheels(100, 100, WALL, 0, flapDelay); 
  turnAround(RIGHTTURN);
  sortSet(LEFTPOS);
  moveWheels(100, 100, WALL, 0, flapDelay);
  turnAround(LEFTTURN);
  sortSet(LEFTPOS);
  moveWheels(100, 100, WALL, 0, flapDelay);
  turnAround(RIGHTTURN);
  sortSet(LEFTPOS);
  moveWheels(100, 100, WALL, 0, flapDelay);
  turnAround(LEFTTURN);
  sortSet(LEFTPOS);
  moveWheels(100, 100, WALL, 0, 0);
  turnCorner(LEFTTURN);
  moveWheels(100, 97, WALL, 0, 0);
  turnCorner(LEFTTURN);
  sortSet(LEFTPOS);
  moveWheels(80, 78, DISTANCE, 1000, 0);
  spinWheels(0,0);
  openSlider();
  redLED(OFF);
  moveWheels(80,80, DISTANCE, 900, 0);
  spinWheels(0,0);
  closeSlider();
  delay(99999);
  
}
