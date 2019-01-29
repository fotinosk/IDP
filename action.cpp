/* Controlling servos and other 'action' functionality on the robot
 *  
 *  The servos turn at 180* in 600ms. Just something to bear in mind
*/

//Include - only the one here. others are in the header file.
#include "action.h"

//Variable Definitions
Servo frontServo;
Servo backServo;
uint8_t gateLeftPos;
uint8_t gateMidPos;
uint8_t gateRightPos;
uint8_t flapLeftPos;
uint8_t flapMidPos;
uint8_t flapRightPos;
uint8_t redLEDPin;


//Function Definitions + all other function definitions
void initAction() {
  gateLeftPos = 80;
  gateMidPos = 90;
  gateRightPos = 100;
  flapLeftPos = 80;
  flapMidPos = 90;
  flapRightPos = 100;
  redLEDPin = 0;
  
  frontServo.attach(10); //the number is the pin. could be 9,10,11,12 tbd
  backServo.attach(9);  //the number is the pin. could be 9,10,11,12 tbd
  pinMode(redLEDPin,OUTPUT);
  return;
}

void flapSet(uint8_t pos) { // 0 - 1- 2 for positions
  switch (pos) {
    case 0: frontServo.write(flapLeftPos); break;
    case 1: frontServo.write(flapMidPos); break;
    case 2: frontServo.write(flapRightPos); break;
  }
  return;
}
void gateSet(uint8_t pos) { // 0 - 1- 2 for positions
  switch (pos) {
    case 0: backServo.write(gateLeftPos); break;
    case 1: backServo.write(gateMidPos); break;
    case 2: backServo.write(gateRightPos); break;
  }
  return;
}

void openHatch() {
  //TODO
  return;
}

void redLEDOn() {
  digitalWrite(redLEDPin, HIGH);
}
void redLEDOff() {
  digitalWrite(redLEDPin, LOW);
}
