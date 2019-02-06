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
//int period = 1000;
//unsigned long tm = timer();

void setup() {
  initMove();
  initSense();
  initAction();
  initTimer();
  //initTest();
  Serial.begin(9600);
}

void loop() {
  //spinWheels(100,100);
  //delay(1000);
  //spinWheels(0,0);
  
 while(!switchFrontRight()){}
  delay(1000);
 //sortSet(LEFTPOS);
  moveWheels(0, 100, TIMER, 200, 0);
  moveWheels(97,100, WALL, 0, 700);
  turnCorner(RIGHTTURN);
 // sortSet(LEFTPOS);
  moveWheels(97,100, WALL, 0, 1000);
  turnCorner(RIGHTTURN);
  //sortSet(LEFTPOS);
  moveWheels(97, 100, LINE, 0, 1000);
  turn90(RIGHTTURN);
  //sortSet(LEFTPOS);
  moveWheels(100, 100, WALL, 0, 1000); 
  turnAround(RIGHTTURN);
  sortSet(LEFTPOS);
  moveWheels(100, 100, WALL, 0, 1000);
  turnAround(LEFTTURN);
  sortSet(LEFTPOS);
  moveWheels(100, 100, WALL, 0, 1000);
  turnAround(RIGHTTURN);
  sortSet(LEFTPOS);
  moveWheels(100, 100, WALL, 0, 1000);
  turnAround(LEFTTURN);
  sortSet(LEFTPOS);
  moveWheels(100, 100, WALL, 0, 0);
  turnCorner(LEFTTURN);
  moveWheels(100, 97, WALL, 0, 0);
  turnCorner(LEFTTURN);
  sortSet(LEFTPOS);
  moveWheels(50, 48, DISTANCE, 1000, 0);
  spinWheels(0,0);
  openSlider();
  moveWheels(80,80, DISTANCE, 900, 0);
  delay(99999);
  
}
