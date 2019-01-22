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

void spinRight(int spd) {
  motorRight->setSpeed((int16_t) spd*255/100);
  motorRight->run(spd>=0 ? FORWARD : BACKWARD);
  return;
}

void spinLeft(int spd) {
  motorLeft->setSpeed((int16_t) spd*255/100);
  motorLeft->run(spd>=0 ? FORWARD : BACKWARD);
  return;
}

void spinBoth(int spd) {
  motorRight->setSpeed((int16_t) spd*255/100);
  motorLeft->setSpeed((int16_t) spd*255/100);
  motorRight->run(spd>=0 ? FORWARD : BACKWARD);
  motorLeft->run(spd>=0 ? FORWARD : BACKWARD);
}

void wallRight(int spd) {
  motorRight->setSpeed((int16_t) spd*255/100*0.95);
  motorLeft->setSpeed((int16_t) spd*255/100);
  motorRight->run(spd>=0 ? FORWARD : BACKWARD);
  motorLeft->run(spd>=0 ? FORWARD : BACKWARD);
}

void wallLeft(int spd) {
  motorRight->setSpeed((int16_t) spd*255/100);
  motorLeft->setSpeed((int16_t) spd*255/100*0.95);
  motorRight->run(spd>=0 ? FORWARD : BACKWARD);
  motorLeft->run(spd>=0 ? FORWARD : BACKWARD);
}
