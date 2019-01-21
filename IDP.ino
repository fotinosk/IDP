/*The Main file of the IDP project.
 * This will contain only the setup() and loop() functions. All else should be included.
 * Any include will take up valuable space on the arduino so should be 
 * modular and application specific.
 * I.E not including test-suite header files in final running build etc.  
 * 
 * Arduino convention tab = 2 spaces
 * 
 * Building:                 
 *    #includes                 For external files declarations go in .h files, content goes
 *    IDP.ino               =>  in .cpp files which will be included automatically if h file
 *    all other .cpp files      is included. Don't have .cpp alone as they will get included
 *                              and break things.
*/

#include "Arduino.h"
#include "move.h"
//#include "sense.h"

void blink(int deltime);

void setup() {
  //setup scope
  forward(5);
  backward(5);
//  int x = readhall();
}


void loop() {
  
}
