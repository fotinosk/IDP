//Include - only the one here. others are in the header file.
#include "timer.h"

//Multiple timers will have to be made (eg move_timer etc) from the same framework

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

bool magnetTimer(uint16_t dur, bool set) { //dur is duration, 1 to set, 0 to read
  static bool active = false;
  static unsigned long endtime;
  if(!active){
    if (set) {
      active = true;
      endtime = millis() + dur;
      return true;
    }
    return false;
  }
  else{//if active
    if (set) {
      active = true;
      endtime = millis() + dur;
      return true;
    }
    if (endtime <= millis()) {
      active = false;
      return false();
    }
    return true
  }
  
}
