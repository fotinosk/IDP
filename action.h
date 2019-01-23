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

//Function Definitions + other functions that are required
void initAction();
void sortKeep();
void sortDiscard();
void gateDown();
void gateUp();

#endif /* ACTION_H */
