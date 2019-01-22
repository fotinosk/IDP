#ifndef MOVE_H
#define MOVE_H

//Includes
#include "Arduino.h"
#include <Wire.h>
#include <Adafruit_MotorShield.h>
//#include "utility/Adafruit_MS_PWMServoDriver.h" //not sure what this does yet

//Variable Definistions
static Adafruit_MotorShield motorShield;// = Adafruit_MotorShield();
static Adafruit_DCMotor *motor1;// = motorShield.getMotor(1);
static Adafruit_DCMotor *motor2;// = motorShield.getMotor(2);

//Function Definitions
void initMove();
void forward(int spd);
void backward(int spd);
void turn(int spd, int COR);

#endif
