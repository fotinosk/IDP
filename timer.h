#ifndef TIMER_H
#define TIMER_H

#include "Arduino.h"

//Timer commands
#define READ 0
#define SET 1
#define PAUSE 2
#define RESUME 3

bool moveTimer(bool action, uint32_t dur) ;
bool magnetTimer(bool action, uint32_t dur);
bool magnetMoveTimer(bool action, uint32_t dur);

#endif /* TIMER_H */
