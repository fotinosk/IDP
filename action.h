#ifndef ACTION_H
#define ACTION_H

//Includes + any other includes you need
#include "Arduino.h"
#include "Servo.h"


//Variable Declarations
extern Servo frontServo;
extern Servo backServo;
extern uint8_t gateLeftPos;
extern uint8_t gateMidPos;
extern uint8_t gateRightPos;
extern uint8_t flapLeftPos;
extern uint8_t flapMidPos;
extern uint8_t flapRightPos;
extern uint8_t redLEDPin;

//Function Definitions
void initAction();
//Gates and servos
void flapSet(uint8_t pos);
void gateSet(uint8_t pos);
void openHatch();

//Block carrying light
void redLEDOn();
void redLEDOff();

#endif /* ACTION_H */
