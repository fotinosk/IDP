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
  while(!switchFrontRight()){}
  delay(500);

  /* the stopMotors might seem redundant but it is a good way to see how the robot is actually behaving 
   *  between movements rather than just running a continous thing. 
   *  We can always get rid of them later on 
  */
  
  sortSet(RIGHTPOS); // set gate to rightposition
  moveWheels(0, 50, TIMER, 300, 0);
  stopMotors(1000); 
  moveWheels(97, 100, WALL, 0, 1000);
  stopMotors(1000);
  turnCorner(RIGHTTURN);

  delay(999999); // test until here for tomorrow's test 
  
  moveWheels(97, 100, WALL, 0, 1000);
  turnCorner(RIGHTTURN);
  moveWheels(97, 100, LINE, 0, 1000);
  turn90(RIGHTTURN);
  
  moveWheels(100, 100, WALL, 0, 1000);
  turnAround(RIGHTTURN);
  moveWheels(100, 100, WALL, 0, 1000);
  turnAround(LEFTTURN);
  moveWheels(100, 100, WALL, 0, 1000);
  turnAround(RIGHTTURN);
  moveWheels(100, 100, WALL, 0, 1000);
  turnAround(LEFTTURN);
  moveWheels(80, 80, WALL, 0, 0);
  turnCorner(LEFTTURN);
  moveWheels(100, 97, WALL, 0, 0);
  turnCorner(LEFTTURN);
  moveWheels(50, 48, DISTANCE, 1000, 0);
  spinWheels(0,0);
  delay(99999);
  
}

  /*delay(3000);
  moveForwards(LEFTWALL, WALL);
  turnCorner(RIGHTTURN);
  moveForwards(LEFTWALL, WALL);
  turnCorner(RIGHTTURN);
  moveForwards(LEFTWALL, 4500);
  turnCorner(RIGHTTURN);
  moveForwards(NONE, WALL);
  turnAround(RIGHTTURN);
  moveForwards(NONE, WALL);
  turnAround(LEFTTURN);
  moveForwards(NONE, WALL);
  turnAround(RIGHTTURN);
  moveForwards(NONE, WALL);
  turnAround(LEFTTURN);
  moveForwards(NONE, WALL);
  turnCorner(LEFTTURN);
  moveForwards(RIGHTWALL, WALL);
  turnCorner(LEFTTURN);
  moveForwards(RIGHTWALL, 5000);
  spinWheels(0,0);
  delay(99999999);*/
