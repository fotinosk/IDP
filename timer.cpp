//Include - only the one here. others are in the header file.
#include "timer.h"

unsigned long previousMillis = 0;

//Function Definitions + all other function definitions
void initTimer() {
  return;
}

unsigned long timer() {
  unsigned long tm = millis() - previousMillis ;
  return tm ;
}
void reset_timer() {
 unsigned long previousMillis = millis();
}