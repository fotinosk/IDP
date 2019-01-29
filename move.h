#ifndef MOVE_H
#define MOVE_H

//Includes
#include "Arduino.h"
#include <Wire.h>
#include <Adafruit_MotorShield.h>
//#include "utility/Adafruit_MS_PWMServoDriver.h" //not sure what this does yet

//Variable Declarations
extern Adafruit_MotorShield motorShield;
extern Adafruit_DCMotor *motorRight;
extern Adafruit_DCMotor *motorLeft;
extern float rTune;
extern float lTune;

//Function Declarations
void initMove();
void spinWheels(int16_t lspd, int16_t rspd);

#endif /* MOVE_H */
