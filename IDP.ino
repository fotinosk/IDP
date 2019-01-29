#include "Arduino.h"
#include "move.h"
#include "sense.h"
#include "timer.h"
  
  //Declare global variables
  
  void setup() {
    initMove();
    initSense();
    initTimer();
    Serial.begin(9600);
  }
  
  void loop() {
      
    }
  
 
