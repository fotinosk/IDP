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
<<<<<<< HEAD
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
=======
 while(!switchFrontRight()){}
  delay(1000);
  moveWheels(0, 100, TIMER, 200, 0);          Serial.println("Initial slight turn");
  moveWheels(97,100, WALL, 0, 700);            Serial.println("Left wall");
  turnCorner(RIGHTTURN);                       Serial.println("First Corner");
  moveWheels(97,100, WALL, 0, flapDelay);      Serial.println("Back wall");
  turnCorner(RIGHTTURN);                       Serial.println("Second Corner  ");
  moveWheels(97, 100, LINE, 0, flapDelay);     Serial.println("Right wall until line");
  turn90(RIGHTTURN);                           Serial.println("Turn to first pass");
  moveWheels(100, 100, WALL, 0, flapDelay);    Serial.println("First pass (on line)");
  turnAround(RIGHTTURN);                       Serial.println("Turn to second pass");
  moveWheels(100, 100, WALL, 0, flapDelay);    Serial.println("Second pass");
  turnAround(LEFTTURN);                        Serial.println("Turn to third pass");
  moveWheels(100, 100, WALL, 0, flapDelay);    Serial.println("Third pass");
  turnAround(RIGHTTURN);                       Serial.println("Turn to fourth pass");
  moveWheels(100, 100, WALL, 0, flapDelay);    Serial.println("Fourth pass");
  turnCorner(LEFTTURN);                        Serial.println("Turn to fifth pass - but go into wall instead");
  moveWheels(100, 100, WALL, 0, 0);            Serial.println("Drive into wall - back right corner");
  turn90(LEFTTURN);                            Serial.println("Turn to fifth pass w/ turn90 function");
  moveWheels(100, 100, WALL, 0, 0);            Serial.println("Fifth pass");
  turnCorner(LEFTTURN);                        Serial.println("Turn back onto leftwall");
  moveWheels(100, 97, WALL, 0, 0);             Serial.println("drive back to start wall");
  turnCorner(LEFTTURN);                        Serial.println("turn towards safe box");
  moveWheels(80, 78, DISTANCE, 1000, 0);       Serial.println("move into safe box");
  spinWheels(0,0);                             Serial.println("stop");
  openSlider();                                Serial.println("open slider");
  redLED(OFF);                                 Serial.println("turn off red LED as no longer carrying blocks");
  moveWheels(80,80, DISTANCE, 950, 0);         Serial.println("move into end box");
  spinWheels(0,0);                             Serial.println("close slider");
>>>>>>> 90603b313f9a404dc57cae922e96921d8d55d348
  closeSlider();
  delay(99999);
  
}
