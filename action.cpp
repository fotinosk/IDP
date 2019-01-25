/* Controlling servos and other 'action' functionality on the robot
 *  
 *  The servos turn at 180* in 600ms. Just something to bear in mind
*/

//Include - only the one here. others are in the header file.
#include "action.h"

//Variable Definitions
Servo gateServo;
Servo sortServo;
uint8_t gateUpPos;
uint8_t gateDownPos;
uint8_t sortKeepPos;
uint8_t sortDiscardPos;


//Function Definitions + all other function definitions
void initAction() {

  //## EDIT GATE POSITIONS in degrees ## \\
  gateUpPos = 0;
  gateDownPos = 180;
  sortKeepPos = 0;
  sortDiscardPos = 180;
  //## EDIT LED PIN ## \\
  redLEDPin = 1;
  
 
  gateServo.attach(10); //the number is the pin. could be 9,10,11,12 tbd
  sortServo.attach(9);  //the number is the pin. could be 9,10,11,12 tbd
  pinMode(redLEDPin,OUTPUT);
  return;
}

void sortKeep() {
  sortServo.write(sortKeepPos);
}
void sortDiscard() {
  sortServo.write(sortDiscardPos);
}
void gateDown() {
  gateServo.write(gateDownPos);
}
void gateUp() {
  gateServo.write(gateUpPos);
}
void redLEDOn() {
  digitalWrite(redLEDPin, HIGH);
}
void redLEDOff() {
  digitalWrite(redLEDPin, LOW);
}
