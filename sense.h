#ifndef SENSE_H
#define SENSE_H

#include "Arduino.h"

//Variable Declarations
//extern int color;
//extern uint8_t switchFrontLeftPin;
//extern uint8_t switchFrontLeftPin;
//extern uint8_t switchFrontLeftPin;
//extern uint8_t switchFrontLeftPin;


//Function Definitions + other functions that are required
void initSense();
bool switchFrontLeft();
bool switchFrontRight();
bool switchBackLeft();
bool switchBackRight();

#endif
