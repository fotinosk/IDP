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

//Declare global variables

/*phase of operations
-1 will set the function state to inactive ie waiting for a real command
2 levels of movement functions */

void setup() {
  initMove();
  initSense();

}

void loop() {
  //make into a respond function for testing the switches in the test.cpp
{
    int rspd = 20;
    int lspd = 20;
    
  if (switchFrontRight()) {
      rspd = -100;
  }
  if (switchFrontLeft()) {
    lspd = -100;
  }
  if (switchBackRight()) {
      rspd = 100;
  }
  if (switchBackLeft()) {
      lspd = 100;
  }

  if ((switchFrontRight() && switchBackRight()) || (switchFrontLeft() && switchBackLeft())) {
    rspd = 0;
    lspd = 0;
  }
  spinRight(rspd);
  spinLeft(lspd);
  
  /*if (run) {
    run = !run;
    drive(100,100,1);

    mode = square
    starting turn

    if switches both on and corner_timer finished
      turn corner
    if detectblock
      emergency stop
      drive slowly
    else
      drivewall
      
      if*/
    
  }
}
