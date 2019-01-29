/*Movement.
 *
*/

//Include
#include "move.h"

//Variable Definitions
Adafruit_MotorShield motorShield;// = Adafruit_MotorShield();
Adafruit_DCMotor *motorRight;// = motorShield.getMotor(1);
Adafruit_DCMotor *motorLeft;// = motorShield.getMotor(2);


//Function Definitions
void initMove() {
  motorShield = Adafruit_MotorShield();
  motorRight = motorShield.getMotor(1);
  motorLeft = motorShield.getMotor(2);
  motorShield.begin(); //could put in desired frequency for PWM here. Default 1.6 KHz
  delay(1); //ensure millis() will not return 0
  return;
}

void spinRight(int16_t spd) {
  motorRight->setSpeed(spd >= 0 ? spd*255/100 : -spd*255/100);
  motorRight->run(spd>=0 ? FORWARD : BACKWARD);
  return;
}

void spinLeft(int16_t spd) {
  motorLeft->setSpeed(spd >= 0 ? spd*255/100*0.97 : -spd*255/100*0.97); //0.97 is to calibrate difference in motor power
  motorLeft->run(spd>=0 ? FORWARD : BACKWARD);
  return;
}

void spinBoth(int16_t spd) {
  spinRight(spd);
  spinLeft(spd);
}

void wallRight(int16_t spd) {
  motorRight->setSpeed((int16_t) spd*255/100*0.97);
  motorLeft->setSpeed((int16_t) spd*255/100);
  motorRight->run(spd>=0 ? FORWARD : BACKWARD);
  motorLeft->run(spd>=0 ? FORWARD : BACKWARD);
}

void wallLeft(int16_t spd) {
  motorRight->setSpeed((int16_t) spd*255/100);
  motorLeft->setSpeed((int16_t) spd*255/100*0.97);
  motorRight->run(spd>=0 ? FORWARD : BACKWARD);
  motorLeft->run(spd>=0 ? FORWARD : BACKWARD);
}
