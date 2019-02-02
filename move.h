#ifndef MOVE_H
#define MOVE_H

//Includes
#include "Arduino.h"
#include <Wire.h>
#include <Adafruit_MotorShield.h>
#include "sense.h"
#include "action.h"
#include "timer.h"
#include <ArduinoSTL.h>
#include <vector>
#include "utility/Adafruit_MS_PWMServoDriver.h" //not sure what this does yet

//follow
#define NONE 0
#define LEFTWALL 1
#define RIGHTWALL 2
//until - values greater than 10 reserved for timing based movement.
#define FOREVER 0
#define WALL 1
#define LINE 2
#define TIMER 3
#define DISTANCE 4
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
void spinWheels(int16_t lspd, int16_t rspd); //literally just controlling the motors
//move w/ end condition. Dur. is ms mm depending on 'until'
void moveWheels(int16_t lspd, int16_t rspd, uint8_t until = WALL, uint32_t duration = 500, uint16_t flapSpeed = 0);

//Higher level functions
void turnCorner (bool dir);
void turn90 (bool dir);
void turnAround (bool dir);
void analyseBlock();

#endif /* MOVE_H */
