/*Include all functions to do with movement
 *
*/
//do not include move.h. It is already included in the main file and reincluding it here will lead to errors as multiple versions of certain variables are initiliased.
//There may be a better way fo doing this but I haven't found it yet.
#include "move.h"

//Functions
void initMove() {
  motorShield = Adafruit_MotorShield();
  motor1 = motorShield.getMotor(1);
  motor2 = motorShield.getMotor(2);
  motorShield.begin();
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
