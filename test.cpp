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
            int rspd = 0;
            int lspd = 0;
              
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

/*
void turnAround (uint8_t dir) {
  sortSet(MIDPOS);
  flapSet(MIDPOS);
  spinWheels(-100,-100);
  delay(200);
  switch (dir) {
    case RIGHTTURN: spinWheels(-100, 100); break;
    case LEFTTURN: spinWheels(100, -100); break;
  }
  delay(2000); //need callibration
  spinWheels(100,100);
  delay(200);
}
*/

void testMotors() {
  spinWheels(100,0);
  delay(1000);
  spinWheels(0, 100);
  delay(1000);
  spinWheels(0, -100);
  delay(1000);
  spinWheels(-100, 0);
  delay(1000);
}

void testFlap() {
  for (;;) {
    flapSet(LEFTPOS);
    delay(1000);
    flapSet(MIDPOS);
    delay(1000);
    flapSet(RIGHTPOS);
    delay(1000);
  }
}
void testSort() {
    sortSet(LEFTPOS);
    delay(1000);
    sortSet(MIDPOS);
    delay(1000);
    sortSet(RIGHTPOS);
    delay(1000);
}

void testSlider() {
  openSlider();
  delay(1000);
  closeSlider();
  delay(1000);
}
