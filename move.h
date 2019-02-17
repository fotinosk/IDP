#ifndef MOVE_H
#define MOVE_H

#include "Arduino.h"
#include <Wire.h>
#include <Adafruit_MotorShield.h>
#include "sense.h"
#include "action.h"
#include "timer.h"
#include "utility/Adafruit_MS_PWMServoDriver.h"

//loop break conditions for moveWheels function
#define WALL 0
#define LINE 1
#define TIMER 2
#define DISTANCE 3
//turning option
#define LEFTTURN 0
#define RIGHTTURN 1

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
void spinWheels(int16_t lspd, int16_t rspd); //Controlling the motors - power normalised from 0-255 to -100 - 100;

/*move w/ end condition. Duration. is ms mm depending on 'until'*/
bool moveWheels(int16_t lspd, int16_t rspd, uint8_t until = WALL, uint32_t duration = 500, uint16_t flapDelay = 0);

//Higher level function declarations
void turnCorner (bool dir); //Turning a corner rolling against the wall
void turn90 (bool dir); //turning 90 degreess with a reverse maneouver to ensure we don't get stuck on a wall
void turn90WithoutReverse (bool dir); //turn 90 degress without reverse when there is no wall to get stuck on
void turnAround (bool dir); // turn around 180 degrees for when we are sweeping the field back and forth
void analyseBlock(bool alreadyMagnetic); //analyse whether a block is magnetic or not and sort it accordingly
void stopMotors(int mseconds); //stop motors for a specified time in ms
void resetJam(); //reset if a block is jammed in the gate

#endif /* MOVE_H */
