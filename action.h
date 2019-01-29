#ifndef ACTION_H
#define ACTION_H

//Includes + any other includes you need
#include "Arduino.h"
#include "Servo.h"

//Variable Declarations
extern Servo sortServo;
extern Servo flapServo;
extern uint8_t flapRightPos;
extern uint8_t flapLeftPos;
extern uint8_t sortKeepPos;
extern uint8_t sortDiscardPos;
extern uint8_t redLEDPin;


//Function Definitions
void initAction();
//Flaps and servos
void flapRight();
void flapLeft();
void sortKeep();
void sortDiscard();
//Block carrying light
void redLEDOn();
void redLEDOff();

#endif /* ACTION_H */
