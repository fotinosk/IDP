#ifndef TIMER_H
#define TIMER_H

#include "Arduino.h"

//for what the timer should do
#define READ 0
#define SET 1
#define PAUSE 2
#define RESUME 3

//Function Definitions + other functions that are required
void initTimer();

//bool magnetTimer(bool set, uint32_t dur) ;
bool moveTimer(bool action, uint32_t dur) ;
bool magnetTimer(bool aciton, uint32_t dur);

#endif /* TIMER_H */
