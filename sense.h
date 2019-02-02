#ifndef SENSE_H
#define SENSE_H

#include "Arduino.h"
#include "move.h"

//actions for the encoder
#define RESET 0
#define RUN 1

//colours for the line sensor
#define BLACK 1
#define RED 2
#define WHITE 3
#define GREEN 4

// using standard cpp libraries

//Variable Declarations
extern uint8_t switchFrontLeftPin;
extern uint8_t switchFrontLeftPin;
extern uint8_t switchFrontLeftPin;
extern uint8_t switchFrontLeftPin;
extern uint8_t hallSensorPin;
extern uint8_t blockDetectPin;
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
uint8_t lineSensor();
bool hallSensor();
bool blockDetect();

#endif
