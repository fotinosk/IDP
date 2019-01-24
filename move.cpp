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
  return;
}

void spinRight(int16_t spd) {
  motorRight->setSpeed(spd >= 0 ? spd*255/100 : -spd*255/100);
  motorRight->run(spd>=0 ? FORWARD : BACKWARD);
  return;
}

void spinLeft(int16_t spd) {
  motorLeft->setSpeed(spd >= 0 ? spd*255/100*0.96 : -spd*255/100*0.96);
  motorLeft->run(spd>=0 ? FORWARD : BACKWARD);
  return;
}

void spinBoth(int16_t spd) {
  motorRight->setSpeed((int16_t) spd*255/100);
  motorLeft->setSpeed((int16_t) spd*255/100);
  motorRight->run(spd>=0 ? FORWARD : BACKWARD);
  motorLeft->run(spd>=0 ? FORWARD : BACKWARD);
}

void wallRight(int16_t spd) {
  motorRight->setSpeed((int16_t) spd*255/100*0.95);
  motorLeft->setSpeed((int16_t) spd*255/100);
  motorRight->run(spd>=0 ? FORWARD : BACKWARD);
  motorLeft->run(spd>=0 ? FORWARD : BACKWARD);
}

void wallLeft(int16_t spd) {
  motorRight->setSpeed((int16_t) spd*255/100);
  motorLeft->setSpeed((int16_t) spd*255/100*0.95);
  motorRight->run(spd>=0 ? FORWARD : BACKWARD);
  motorLeft->run(spd>=0 ? FORWARD : BACKWARD);
}
