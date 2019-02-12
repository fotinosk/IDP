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

uint16_t flapDelay = 900;

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
  while(switchFrontRight()){}
  delay(200);

  moveWheels(0, 100, TIMER, 200, 0);           Serial.println("Initial slight turn");
  moveWheels(95,100, WALL, 0, flapDelay);            Serial.println("Left wall");
  turnCorner(RIGHTTURN);                         Serial.println("First Corner");
  moveWheels(95,100, WALL, 0, flapDelay);        Serial.println("Back wall");
  turnCorner(RIGHTTURN);                         Serial.println("Second Corner  ");
  moveWheels(97, 100, DISTANCE, 450, flapDelay); Serial.println("Right wall until line");
  stopMotors(500); 
  flapSet(MIDPOS); // set flap to midpos so blocks don't go inside
  delay(200);
  moveWheels(97, 100, DISTANCE, 310, 0);       Serial.println("Right wall until line");
  turn90WithoutReverse(RIGHTTURN);             Serial.println("Turn to first pass");
  moveWheels(100, 100, WALL, 0, flapDelay);    Serial.println("First pass (on line)");
  turnAround(RIGHTTURN);                       Serial.println("Turn to second pass");
  moveWheels(100, 100, WALL, 0, flapDelay);    Serial.println("Second pass");
  turnAround(LEFTTURN);                        Serial.println("Turn to third pass");
  moveWheels(100, 100, WALL, 0, flapDelay);    Serial.println("Third pass");
  turnAround(RIGHTTURN);                       Serial.println("Turn to fourth pass");
  moveWheels(99, 100, WALL, 0, flapDelay);    Serial.println("Fourth pass");
  turnCorner(LEFTTURN);                        Serial.println("Turn to fifth pass - but go into wall instead");
  spinWheels(-100,0); delay(700);
  moveWheels(100, 100, WALL, 0, 0);            Serial.println("Drive into wall - back right corner");
  stopMotors(100);
  moveWheels(-100,-96,TIMER, 400, 0);
  stopMotors(100);
  turn90(LEFTTURN);                            Serial.println("Turn to fifth pass w/ turn90 function");
  moveWheels(100, 100, WALL, 0, flapDelay);    Serial.println("Fifth pass");
  turnCorner(LEFTTURN);                        Serial.println("Turn back onto leftwall");
  moveWheels(100, 97, WALL, 0, 0);             Serial.println("drive back to start wall");
  turnCorner(LEFTTURN);                        Serial.println("turn towards safe box");
  moveWheels(100, 95, DISTANCE, 1100, 0);      Serial.println("move into safe box");
  spinWheels(0,0);                             Serial.println("stop");
  openSlider();                                Serial.println("open slider");
  redLED(OFF);                                 Serial.println("turn off red LED as no longer carrying blocks");
  moveWheels(95,100, WALL, 0, 0);              Serial.println("move into end box");
  stopMotors(100);
  spinWheels(-100,-100);
  delay(750);
  spinWheels(0,0);
  closeSlider();
  delay(99999);
}
