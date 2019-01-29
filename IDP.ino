#include "Arduino.h"
#include "move.h"
#include "sense.h"
#include "timer.h"

#include <vector>
  
//Declare global variables
  
void setup() {
  initMove();
  initSense();
  initTimer();
  Serial.begin(9600);
}
  
void loop() {

while(1)
{
  for(int i= 2;  i < 6; i++){
    Serial.print(digitalRead(i));
  }
  Serial.println();
}

while(!switchFrontRight())
{
 spinWheels(-30,30); 
 countEncoder();

 
}

breakWheels();
delay(9999999);
}
  
 
