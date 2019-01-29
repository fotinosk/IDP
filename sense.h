#ifndef SENSE_H
#define SENSE_H

#include "Arduino.h"
//#include <StandardCplusplus.h>
//#include <vector>
#include "move.h"

// using standard cpp libraries
using namespace std;

//Variable Declarations
//extern vector<bool> encoder_status; 
//extern vector<int> encoder_count;
//rextern vector<int> encoder_count_ABS;

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
bool switchFrontBoth();
bool switchBackBoth();
void countEncoder();
void encoderCountReset();


#endif
