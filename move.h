#ifndef MOVE_H
#define MOVE_H

//Includes
#include "Arduino.h"
#include <Wire.h>
#include <Adafruit_MotorShield.h>
#include "sense.h"
#include "action.h"
#include "timer.h"
#include "utility/Adafruit_MS_PWMServoDriver.h" //not sure what this does yet

//follow
#define NONE 0
#define LEFTWALL 1
#define RIGHTWALL 2
//until: end condition for robot movment - might add more like either this or that condition to be met for redundancy/safety reasons ie distance or line soj not carrying blocks out of danger zone.
#define WALL 0
#define LINE 1
#define TIMER 2
#define DISTANCE 3
//turning option
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
extern bool spinDirection [2];

//Function Declarations
void initMove();
void spinWheels(int16_t lspd, int16_t rspd); //literally just controlling the motors
//move w/ end condition. Duration. is ms mm depending on 'until' //returns false if we hit a wall and stopping condition was not wall
bool moveWheels(int16_t lspd, int16_t rspd, uint8_t until = WALL, uint32_t duration = 500, uint16_t flapDelay = 0); 

//Higher level function declarations
void turnCorner (bool dir);
void turn90 (bool dir);
void turn90WithoutReverse (bool dir);
void turnAround (bool dir);
void analyseBlock(bool alreadyMagnetic);
void stopMotors(int mseconds);
void resetJam();

#endif /* MOVE_H */
