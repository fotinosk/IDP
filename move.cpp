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
vector<bool> spinDirection = {1,1};

//Function Definitions
void initMove() {
  motorShield = Adafruit_MotorShield();
  motorRight = motorShield.getMotor(1);
  motorLeft = motorShield.getMotor(2);
  motorShield.begin(); //could put in desired frequency for PWM here. Default 1.6 KHz
  return;
}

//low level movement function
void spinWheels(int16_t rspd, int16_t lspd) {
  motorRight->setSpeed((int16_t) abs(rspd)*255/100*rTune);
  motorLeft->setSpeed((int16_t) abs(lspd)*255/100*lTune);
  motorRight->run(rspd>=0 ? FORWARD : BACKWARD);
  motorLeft->run(lspd>=0 ? FORWARD : BACKWARD);
  spinDirection = {rspd < 0 ? 0 : 1, lspd < 0 ? 0 : 1};
}

//high level movement fucntions
//move forwards
    void moveForwards( uint8_t track = NONE) { //This function is for general forwards movement, all-the-while looking for blocks etc
    
  }
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

 
 
