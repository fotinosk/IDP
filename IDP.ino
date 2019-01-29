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
#include "timer.h"

//Declare global variables

void setup() {
  initTimer();
  Serial.begin(9600);
}

void loop() {  
}
