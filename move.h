#ifndef MOVE_H
#define MOVE_H

//Includes
#include "Arduino.h"
#include <Wire.h>
#include <Adafruit_MotorShield.h>
#include <StandardCplusplus.h>
#include <vector>
//#include "utility/Adafruit_MS_PWMServoDriver.h" //not sure what this does yet

using namespace std;

//Variable Declarations
extern Adafruit_MotorShield motorShield;
extern Adafruit_DCMotor *motorRight;
extern Adafruit_DCMotor *motorLeft;
extern float rTune;
extern float lTune;
extern vector<bool> spinDirection;

//Function Declarations
void initMove();
void spinWheels(int16_t rspd, int16_t lspd);
void breakWheels();

#endif /* MOVE_H */
