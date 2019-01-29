#ifndef MOVE_H
#define MOVE_H

#define NONE 0
#define LEFTWALL 1
#define RIGHTWALL 2


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
void spinWheels(int16_t lspd, uint16_t rspd);

//Higher level functions
void moveForwards (uint8_t track);

#endif /* MOVE_H */
