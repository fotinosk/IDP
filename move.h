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
extern Adafruit_DCMotor *sliderMotor;
extern float rTune;
extern float lTune;
extern vector<bool> spinDirection;

//Function Declarations
void initMove();
void spinWheels(int16_t rspd, int16_t lspd);
void breakWheels();
void slider(bool L_R); // move left or right
void breakSlider();

#endif /* MOVE_H */
