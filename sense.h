

#ifndef SENSE_H
#define SENSE_H

#include "Arduino.h"
#include <ArduinoSTL.h>
#include <vector>
#include "move.h"

//colours for the line sensor
#define BLACK 1
#define RED 2
#define WHITE 3
#define GREEN 4

// using standard cpp libraries
using namespace std;

//Variable Declarations
extern vector<bool> encoder_status; 
extern vector<int> encoder_count;
extern vector<int> encoder_count_ABS;

extern uint8_t switchFrontLeftPin;
extern uint8_t switchFrontLeftPin;
extern uint8_t switchFrontLeftPin;
extern uint8_t switchFrontLeftPin;
extern uint8_t hallSensorPin;

//Function Definitions + other functions that are required
void initSense();
bool switchFrontLeft();
bool switchFrontRight();
bool switchBackLeft();
bool switchBackRight();
bool switchFrontBoth();
bool switchBackBoth();
void countEncoder();
void encoderCountReset();
uint8_t lineSensor();
bool hallSensor();

#endif
