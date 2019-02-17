/* Controlling servos and other 'action' functionality on the robot*/

#include "action.h"

//Variable Definitions
Servo flapServo;
Servo sortServo;
Adafruit_DCMotor *sliderMotor;
uint8_t sortLeftPos = 170;
uint8_t sortMidPos = 115;
uint8_t sortRightPos = 60;
uint8_t flapLeftPos = 120;
uint8_t flapMidPos = 90;
uint8_t flapRightPos = 60;
uint8_t sortLeftUnjam = 130;
uint8_t sortRightUnjam = 87;
uint8_t redLEDPin = 13;
uint8_t amberLEDPin = 8;
uint8_t enableHallSensorPin = 24;

//Function Definitions
void initAction() { //Initialistaion for functionality relating to the action.cpp file
  sliderMotor = motorShield.getMotor(3);
  flapServo.attach(10);
  sortServo.attach(9);
  pinMode(redLEDPin,OUTPUT);
  pinMode(amberLEDPin, OUTPUT);
  digitalWrite(redLEDPin, LOW);
  pinMode(7, OUTPUT); // the pin nanded with the IR sensor
  digitalWrite(7, HIGH);
  pinMode(enableHallSensorPin, OUTPUT);
  digitalWrite(enableHallSensorPin, HIGH);
  sortSet(MIDPOS);
  return;
}

void flapSet(uint8_t pos) { // set the position of the flapper at the front of the robot
  switch (pos) {
    case 0: flapServo.write(flapLeftPos); break;
    case 1: flapServo.write(flapMidPos); break;
    case 2: flapServo.write(flapRightPos); break;
  }
  return;
}
void sortSet(uint8_t pos) { //postions are set with the defines LEFTPOS, RIGHTPOS, MIDPOS etc.
  switch (pos) {
    case 0: sortServo.write(sortLeftPos); break;
    case 1: sortServo.write(sortMidPos); break;
    case 2: sortServo.write(sortRightPos); break;
    case 3: sortServo.write(sortLeftUnjam); break;
    case 4: sortServo.write(sortRightUnjam); break;
  }
  return;
}
void openSlider() {
  sliderMotor->setSpeed(255);
  sliderMotor->run(BACKWARD);
  delay(4600);
  sliderMotor->setSpeed(0);
  return;
}

void closeSlider() {
  sliderMotor->setSpeed(255);
  sliderMotor->run(FORWARD);
  delay(4600);
  sliderMotor->setSpeed(0);
  return;
}

void redLED(bool state) {
  digitalWrite(redLEDPin, state == ON ? HIGH : LOW);
}

void amberLED(bool state) {
  digitalWrite(amberLEDPin, state == ON ? HIGH : LOW);
}

void enableHallSensor(){
  digitalWrite(enableHallSensorPin, LOW);
}

void disableHallSensor() {
  digitalWrite(enableHallSensorPin, HIGH);
}
