/* Controlling servos and other 'action' functionality on the robot
 *  
 *  The servos turn at 180* in 600ms. Just something to bear in mind
*/

//Include - only the one here. others are in the header file.
#include "action.h"

//Variable Definitions
Servo flapServo;
Servo sortServo;
Adafruit_DCMotor *sliderMotor;
uint8_t sortLeftPos = 170; //tbd
uint8_t sortMidPos = 118;
uint8_t sortRightPos = 60;
uint8_t flapLeftPos = 120;
uint8_t flapMidPos = 90;
uint8_t flapRightPos = 60;
uint8_t redLEDPin = 13;
uint8_t amberLEDPin = 8;

//Function Definitions + all other function definitions
void initAction() {
  sliderMotor = motorShield.getMotor(3);
  flapServo.attach(10); //the number is the pin. could be 9,10,11,12 tbd
  sortServo.attach(9);  //the number is the pin. could be 9,10,11,12 tbd
  pinMode(redLEDPin,OUTPUT);
  pinMode(amberLEDPin, OUTPUT);
  pinMode(9, OUTPUT); // the pin nanded with the IR sensor
  digitalWrite(9, LOW);
  return;
}

void flapSet(uint8_t pos) { // 0 - 1 - 2 for positions
  switch (pos) {
    case 0: flapServo.write(flapLeftPos); break;
    case 1: flapServo.write(flapMidPos); break;
    case 2: flapServo.write(flapRightPos); break;
  }
  return;
}
void sortSet(uint8_t pos) { //postions are set with the macros LEFTPOS RIGHTPOS and MIDPOS. For sort RIGHTPOS = reject - might change this to be more verbose
  switch (pos) {
    case 0: sortServo.write(sortLeftPos); break;
    case 1: sortServo.write(sortMidPos); break;
    case 2: sortServo.write(sortRightPos); break;
  }
  return;
}
void openSlider() {
  sliderMotor->setSpeed(255);
  sliderMotor->run(BACKWARD);
  delay(4500);
  sliderMotor->setSpeed(0);
  return;
}

void closeSlider() {
  sliderMotor->setSpeed(255);
  sliderMotor->run(FORWARD);
  delay(4500);
  sliderMotor->setSpeed(0);
  return;
}

void redLED(bool state) {
  digitalWrite(redLEDPin, state == ON ? HIGH : LOW);
}

void amberLED(bool state) {
  digitalWrite(amberLEDPin, state == ON ? HIGH : LOW);
}
