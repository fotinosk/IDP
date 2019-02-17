/* Here we can put all our test and calibration functions */

#include "test.h"

//Function Definitions
void initTest() {
  Serial.begin(9600);
  initMove();
  initSense();
  initAction();
  return;
}

void testSwitches() {
/*Each wheel responds differently to each switch and should behave as if you are 'pushing' that corner and the robot will follow your suggestion*/
  while (1) {
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


void testMotors() {
/*Test motors going forwards and backwards, left and right to ensure all are wired to correct pins and polarity*/
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
/*Set the flap to right, left and centre postions to ensure these are physically correct. Useful for calibrating the exact positions to each PWM value*/
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
/*Set the sorting gate to right, left and centre postions to ensure these are physically correct. Useful for calibrating the exact positions to each PWM value*/
    sortSet(LEFTPOS);
    delay(1000);
    sortSet(MIDPOS);
    delay(1000);
    sortSet(RIGHTPOS);
    delay(1000);
}

void testUnjam() {
    sortSet(LEFTUNJAM);
    delay(1500);
    sortSet(RIGHTUNJAM);
    delay(1500);
    sortSet(MIDPOS);
    delay(1500);

}

void testSlider() {
  openSlider();
  delay(1000);
  closeSlider();
  delay(1000);
}
