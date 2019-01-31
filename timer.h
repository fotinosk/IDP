#ifndef TIMER_H
#define TIMER_H

#include "Arduino.h"

#define READ 0
#define SET 1

//Function Definitions + other functions that are required
void initTimer();
unsigned long timer();
void reset_timer();

bool magnetTimer(uint16_t dur, bool set) ;

#endif /* TEST_H */
