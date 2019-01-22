/*The Main file of the IDP project.
 * This will contain only the setup() and loop() functions. All else should be #included.
 * Any include will take up valuable space on the arduino so should be 
 * modular and application specific.
 * I.E not including test-suite header files in final running build etc.  
 * 
 * Arduino convention tab = 2 spaces
 * 
 * Each #include will also require it's initName(); function to be run in setup.
 * 
*/
//Add needed includes
#include "Arduino.h"
#include "move.h"

//Declare global variables
int j = 0;
int i = 0;

void setup() {
  initMove();
  spinBoth(0);
}

void loop() {
  spinBoth(0);
  spinRight(50);
  delay(500);
  spinRight(100);
  delay(500);
  spinBoth(0);
  spinLeft(50);
  delay(500);
  spinLeft(100);
  delay(500);
  spinBoth(0);
  spinRight(-50);
  delay(500);
  spinRight(-100);
  delay(500);
  spinBoth(0);
  spinLeft(-50);
  delay(500);
  spinLeft(-100);
  delay(500);
  spinBoth(80);
  delay(500);
  spinBoth(-80);
  delay(500);
  spinBoth(0);
  
  
  
}
