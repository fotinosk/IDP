#ifndef MOVE_H
#define MOVE_H

//Includes
#include "Arduino.h"
#include <Wire.h>
#include <Adafruit_MotorShield.h>
//#include "utility/Adafruit_MS_PWMServoDriver.h" //not sure what this does yet

//Variable Declarations
extern Adafruit_MotorShield motorShield;
extern Adafruit_DCMotor *motor1;
extern Adafruit_DCMotor *motor2;

//Function Declarations
void initMove();
void forward(int spd);
void backward(int spd);
void turn(int spd, int COR);


#endif /* MOVE_H */
