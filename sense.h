#ifndef SENSE_H
#define SENSE_H

#include "Arduino.h"
#include "move.h"

//actions for the encoder
#define RESET 0
#define RUN 1

//Variable Declarations
extern uint8_t switchFrontLeftPin;
extern uint8_t switchFrontLeftPin;
extern uint8_t switchFrontLeftPin;
extern uint8_t switchFrontLeftPin;
extern uint8_t hallSensorPin;
extern uint8_t irSensorPin;
extern int32_t encoderCount [2];
extern float mmPerEncoder;

//Function Definitions
void initSense();
bool switchFrontLeft();
bool switchFrontRight();
bool switchBackLeft();
bool switchBackRight();
bool switchFrontBoth();
bool switchBackBoth();
void encoderRun(uint8_t action);
bool lineSensor();
bool hallSensor();
bool irSensor();

#endif
