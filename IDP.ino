/*The Main file of the IDP project.
   This will contain only the setup() and loop() functions. All else should be #included.
   Any include will take up valuable space on the arduino so should be
   modular and application specific.
   I.E not including test-suite header files in final running build etc.
   Arduino convention tab = 2 spaces
   Each #include will also require it's initName(); function to be run in setup.
*/
//Add needed includes
#include "Arduino.h"
#include "move.h"
#include "sense.h"
#include "action.h"
//#include "test.h"

//Declare global variables

void setup() {
  initMove();
  initSense();
  initAction();
  initTest();


while(!switchFrontRight()){}
delay(500);

slider(1);
delay(4200);
slider(0);
delay(4400);
breakSlider();

delay(99999999);

int distance = 100;
}

void loop() {
  //make into a respond function for testing the switches in the test.cpp
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

//Serial.print(encoder_count);
breakWheels();
delay(9999999);



}
