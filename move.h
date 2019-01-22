#ifndef MOVE_H
#define MOVE_H

//Includes
#include "Arduino.h"
#include <Wire.h>
#include <Adafruit_MotorShield.h>
//#include "utility/Adafruit_MS_PWMServoDriver.h" //not sure what this does yet

//Variable Definitions
extern Adafruit_MotorShield motorShield = Adafruit_MotorShield();
extern Adafruit_DCMotor *motor1 = motorShield.getMotor(1);
extern Adafruit_DCMotor *motor2 = motorShield.getMotor(2);

//Function Declarations
void initMove();
void forward(int spd);
void backward(int spd);
void turn(int spd, int COR);

void initMove() {
  motorShield.begin();
}

void forward(int spd) {
  //Set speed to start motor at
  motor1->setSpeed(spd);
  motor2->setSpeed(spd);
  motor1->run(FORWARD);
  motor2->run(FORWARD);
  return;
}

void backward(int spd) {
  motor1->setSpeed(spd);
  motor2->setSpeed(spd);
  motor1->run(BACKWARD);
  motor2->run(BACKWARD);
  return;
}


void turn(int spd, int COR) {
  return;
}


#endif /* MOVE_H */
