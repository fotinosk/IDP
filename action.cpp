/* Controlling servos and other 'action' functionality on the robot
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
  gateUpPos = 180;
  gateDownPos = 30;
  sortKeepPos = 45;
  sortDiscardPos = 135;
  
  
  gateServo.attach(10); //the number is the pin. could be 9,10,11,12 tbd
  sortServo.attach(11);  //the number is the pin. could be 9,10,11,12 tbd
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
