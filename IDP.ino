#include "Arduino.h"
#include "move.h"
#include "sense.h"
#include "timer.h"
#include "action.h"

#include <vector>
  
//Declare global variables
  
void setup() {
  initMove();
  initSense();
  initTimer();
  initAction();
  Serial.begin(9600);
}
  
void loop() {

while(!switchFrontRight()){}
delay(500);

Serial.println("now moving servo");
Serial.println(flapRightPos);

flapRight();
delay(1000);
flapLeft();
//sortDiscard();

breakWheels();
delay(9999999);
}
  
 
