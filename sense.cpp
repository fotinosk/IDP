//Include
#include "sense.h"

//Variable Definitions
//int color;
uint8_t switchFrontLeftPin = 1;
uint8_t switchFrontRightPin = 2;
uint8_t switchBackLeftPin = 3;
uint8_t switchBackRightPin = 4;

//Function Definitions
void initSense() {
  pinMode(switchFrontLeftPin, INPUT);
  pinMode(switchFrontRightPin, INPUT);
  pinMode(switchBackLeftPin, INPUT);
  pinMode(switchFrontRightPin, INPUT);
  return;
}

bool switchFrontLeft() {
  return digitalRead(switchFrontLeftPin);
}
bool switchFrontRight() {
  return digitalRead(switchFrontRightPin); 
}
bool switchBackLeft() {
  return digitalRead(switchBackLeftPin);
}
bool switchBackRight() {
  return digitalRead(switchBackRightPin);
}

/*
 * Box Blue 75-85
 * Track Black 9-10
 * Track Red 100-110
 * Track White 200-215
 * TRack Green 115-120
 */
/*
int LineSensor() {
  int rd = analogRead(A1); 
  delay(100);
  if (rd < 15 && rd > 5) {
    //black
    return 1; 
  }
  if (rd < 110 && rd > 100) {
    //red
    return 2; 
  }
  if (rd < 215 && rd > 200) {
    //white
    return 3; 
  }
  if (rd < 120 && rd > 115) {
    //green
    return 4; 
  }
}
*/
