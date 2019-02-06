//Include - only the one here. others are in the header file.
#include "timer.h"

//Multiple timers will have to be made (eg move_timer etc) from the same framework

//Function Definitions + all other function definitions
void initTimer() {
  return;
}

bool moveTimer(bool action, uint32_t dur) {
  static long unsigned endTime = 0;
  static unsigned long pauseTime = 0;
  if (action == SET) {
    endTime = millis() + dur;
    return true;
  }
  else if (action == PAUSE && !pauseTime && endTime) { //if want to pause and not already paused and timer is running
    pauseTime = pauseTime == 0 ? millis() : pauseTime;
  }
  else if (action == RESUME && pauseTime) { //if resume and it is currently Paused
    endTime += millis() - pauseTime; //set new endtime
    pauseTime = 0; //set timer to not paused
  }
  return (millis()<=endTime ? true : false);
}


bool magnetTimer(bool action, uint32_t dur) {
  static long unsigned endTime = 0;
  static unsigned long pauseTime = 0;
  if (action == SET) {
    endTime = millis() + dur;
    return true;
  }
  else if (action == PAUSE && !pauseTime && endTime) { //if want to pause and not already paused and timer is running
    pauseTime = pauseTime == 0 ? millis() : pauseTime;
  }
  else if (action == RESUME && pauseTime) { //if resume and it is currently Paused
    endTime += millis() - pauseTime; //set new endtime
    pauseTime = 0; //set timer to not paused
  }
  return (millis()<=endTime ? true : false);
}
