/*-This file contains the 3 timing functions used within the program-*/
#include "timer.h"


/* Once SET, the timer returns true while the timer
 * is still within the given time and
 * false once the timer has expired
 */

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

bool magnetMoveTimer(bool action, uint32_t dur) {
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
