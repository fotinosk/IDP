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

//Function Declarations
void initMove();
void spinRight(int spd);
void spinLeft(int spd);
void spinBoth(int spd);
void wallRight(int spd);
void wallLeft(int spd);


//spin right
//spin left
//travel wall
//spin both
//turn centre, right and left using previous functions
//travel wall right left


#endif /* MOVE_H */
