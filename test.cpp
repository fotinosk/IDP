/* Here we can put all our test and calibration functions that won't end up in the final build. i.e Line calibration
*/

//Include - only the one here. others are in the header file.
#include "test.h"

//Variable Definitions
//Type globalVariable;


//Function Definitions + all other function definitions
void initTest() {
  Serial.begin(9600);
  initMove();
  initSense();
  initAction();
  return;
}

void testSwitches() {
  for(;;) {
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
            spinWheels(lspd, rspd);
  }
}
