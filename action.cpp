/* Controlling servos and other 'action' functionality on the robot
 *  
 *  The servos turn at 180* in 600ms. Just something to bear in mind
*/

//Include - only the one here. others are in the header file.
#include "action.h"

//Variable Definitions
Servo frontServo;
Servo backServo;
uint8_t gateUpPos;
uint8_t gateDownPos;
uint8_t sortKeepPos;
uint8_t sortDiscardPos;
uint8_t redLEDPin;


//Function Definitions + all other function definitions
void initAction() {

  //## EDIT GATE POSITIONS in degrees ## \\
  gateUpPos = 0;
  gateDownPos = 180;
  sortKeepPos = 0;
  sortDiscardPos = 180;
  //## EDIT LED PIN ## \\
  redLEDPin = 0;
  
 
  frontServo.attach(10); //the number is the pin. could be 9,10,11,12 tbd
  backServo.attach(9);  //the number is the pin. could be 9,10,11,12 tbd
  pinMode(redLEDPin,OUTPUT);
  return;
}

void sortKeep() {
  frontServo.write(sortKeepPos);
}
void sortDiscard() {
  frontServo.write(sortDiscardPos);
}
void gateDown() {
  backServo.write(gateDownPos);
}
void gateUp() {
  backServo.write(gateUpPos);
}
void redLEDOn() {
  digitalWrite(redLEDPin, HIGH);
}
void redLEDOff() {
  digitalWrite(redLEDPin, LOW);
}
