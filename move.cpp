/*Movement.
 *
*/

//Include
#include "move.h"

//Variable Definitions
Adafruit_MotorShield motorShield;// = Adafruit_MotorShield();
Adafruit_DCMotor *motor1;// = motorShield.getMotor(1);
Adafruit_DCMotor *motor2;// = motorShield.getMotor(2);


//Function Definitions
void initMove() {
  motorShield = Adafruit_MotorShield();
  motor1 = motorShield.getMotor(1);
  motor2 = motorShield.getMotor(2);
  motorShield.begin();
  return;
}

void forward(int spd) {
  //Set speed to start motor at
  motor1->setSpeed(spd);
  motor2->setSpeed(spd);
  motor1->run(FORWARD);
  motor2->run(FORWARD);
  return;
}

void backward(int spd) {
  motor1->setSpeed(spd);
  motor2->setSpeed(spd);
  motor1->run(BACKWARD);
  motor2->run(BACKWARD);
  return;
}


void turn(int spd, int COR) {
  return;
}
