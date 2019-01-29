/*Movement.
 *
*/

//Include
#include "move.h"

//Variable Definitions
Adafruit_MotorShield motorShield;// = Adafruit_MotorShield();
Adafruit_DCMotor *motorRight;// = motorShield.getMotor(1);
Adafruit_DCMotor *motorLeft;// = motorShield.getMotor(2);
float rTune = 1;
float lTune = 0.97;

//Function Definitions
void initMove() {
  motorShield = Adafruit_MotorShield();
  motorRight = motorShield.getMotor(1);
  motorLeft = motorShield.getMotor(2);
  motorShield.begin(); //could put in desired frequency for PWM here. Default 1.6 KHz
  return;
}

//low level movement function
void spinWheels(uint16_t lspd, uint16_t rspd) {
  motorRight->setSpeed((int16_t) rspd*255/100*rTune);
  motorLeft->setSpeed((int16_t) lspd*255/100*lTune);
  motorRight->run(rspd>=0 ? FORWARD : BACKWARD);
  motorLeft->run(lspd>=0 ? FORWARD : BACKWARD);
}


//high level movement fucntions
//move forwards
  
  //determine break mechanism
  //look fro blocks
  //flappy flappy

//turn corner
  //set flaps to block
  //perform turning maneuver.
  //could even use delay here if we wanted to

//detect block
 //use a timer to see if magnetic at anypoint
 //set flaps to middle
 
 
