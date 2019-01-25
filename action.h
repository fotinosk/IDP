#ifndef ACTION_H
#define ACTION_H

//Includes + any other includes you need
#include "Arduino.h"
#include "Servo.h"

//Variable Declarations
extern Servo gateServo;
extern Servo sortServo;
extern uint8_t gateUpPos;
extern uint8_t gateDownPos;
extern uint8_t sortKeepPos;
extern uint8_t sortDiscardPos;
extern uint8_t redLEDPin;

//Function Definitions
void initAction();
//Gates and servos
void sortKeep();
void sortDiscard();
void gateDown();
void gateUp();
//Block carrying light
void redLEDOn();
void redLEDOff();

#endif /* ACTION_H */
