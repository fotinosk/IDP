#ifndef MOVE_H
#define MOVE_H

//Includes
#include "Arduino.h"
#include <Wire.h>
#include <Adafruit_MotorShield.h>
#include "sense.h"
#include "action.h"
#include <ArduinoSTL.h>
#include <vector>
#include "utility/Adafruit_MS_PWMServoDriver.h" //not sure what this does yet

//follow
#define NONE 0
#define LEFTWALL 1
#define RIGHTWALL 2
//until
#define FOREVER 0
#define WALL 1
#define LINE 2
//corner option
#define LEFTTURN 0
#define RIGHTTURN 1

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

//Higher level functions
void moveForwards (uint8_t follow, uint8_t until);
void turnCorner (uint8_t dir);
void turnAround (uint8_t dir);
#endif /* MOVE_H */
