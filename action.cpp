/* Controlling servos and other 'action' functionality on the robot
 *  
 *  The servos turn at 180* in 600ms. Just something to bear in mind
*/

//Include - only the one here. others are in the header file.
#include "action.h"

//Variable Definitions
Servo sortServo;
Servo flapServo;
uint8_t flapRightPos = 50;
uint8_t flapLeftPos = 130;
uint8_t sortKeepPos = 160;
uint8_t sortDiscardPos = 50;
uint8_t redLEDPin;


//Function Definitions + all other function definitions
void initAction() {


  //## EDIT LED PIN ## \\
  redLEDPin = 0;
  
 
  sortServo.attach(10); //the number is the pin. could be 9,10,11,12 tbd
  flapServo.attach(9);  //the number is the pin. could be 9,10,11,12 tbd
  pinMode(redLEDPin,OUTPUT);
  return;
}

void sortKeep() {
  sortServo.write(sortKeepPos);
}
void sortDiscard() {
  sortServo.write(sortDiscardPos);
}
void flapRight() {
  flapServo.write(flapRightPos);
}
void flapLeft() {
  flapServo.write(flapLeftPos);
}
void redLEDOn() {
  digitalWrite(redLEDPin, HIGH);
}
void redLEDOff() {
  digitalWrite(redLEDPin, LOW);
}
