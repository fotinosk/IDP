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
#include "test.h"
#include "NewPing.h"

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
  /*
Serial.println("startin code");
 while(!switchFrontRight()){}
 while(switchFrontRight()){}
 Serial.println("setting motors to spin");
 delay(1000);
 spinWheels(100,100);
*/
 
 
 while(!switchFrontRight()){}
 while(switchFrontRight()){}
 delay(1000);
  moveWheels(0, 100, TIMER, 200, 0);          //Initial slight turn
  moveWheels(97,100, WALL, 0, 700);           //Left wall
  turnCorner(RIGHTTURN);                      //First Corner
  moveWheels(97,100, WALL, 0, flapDelay);     //Back wall
  turnCorner(RIGHTTURN);                      //Second Corner  
  moveWheels(97, 100, LINE, 0, flapDelay);    //Right wall until line
  turn90(RIGHTTURN);                           //Turn to first pass
  moveWheels(100, 100, WALL, 0, flapDelay);   //First pass (on line)
  turnAround(RIGHTTURN);                      //Turn to second pass
  moveWheels(100, 100, WALL, 0, flapDelay);   //Second pass
  turnAround(LEFTTURN);                       //Turn to third pass
  moveWheels(100, 100, WALL, 0, flapDelay);   //Third pass
  turnAround(RIGHTTURN);                      //Turn to fourth pass
  moveWheels(100, 100, WALL, 0, flapDelay);   //Fourth pass
  turnCorner(LEFTTURN);                       //Turn to fifth pass - but go into wall instead
  moveWheels(100, 100, WALL, 0, 0);           //Drive into wall - back right corner
  turn90(LEFTTURN);                           //Turn to fifth pass w/ turn90 function
  moveWheels(100, 100, WALL, 0, 0);           //Fifth pass
  turnCorner(LEFTTURN);                       //Turn back onto leftwall
  moveWheels(100, 97, WALL, 0, 0);            //drive back to start wall
  turnCorner(LEFTTURN);                       //turn towards safe box
  moveWheels(80, 78, DISTANCE, 1000, 0);      //move into safe box
  spinWheels(0,0);                            //stop
  openSlider();                               //open slider
  redLED(OFF);                                //turn off red LED as no longer carrying blocks
  moveWheels(80,80, DISTANCE, 980, 0);        //move into end box
  spinWheels(0,0);                            //close slider
  closeSlider();
  delay(99999);
  
}
