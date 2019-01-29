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

while(!switchFrontRight()){}
delay(500);

slider(1);
delay(4200);
slider(0);
delay(4400);
breakSlider();

delay(99999999);

int distance = 100;

while(!switchFrontRight())
{
 spinWheels(100,99.3); 
 countEncoder();

  Serial.println(encoder_count[0]);
  Serial.println(analogRead(0));
 if(encoder_count[0] > 100/0.87)
 {
  break;
 }
}

//Serial.print(encoder_count
breakWheels();
delay(9999999);
}
  
 
