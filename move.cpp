//Only include move.h
#include "move.h"

//Variable Definitions
Adafruit_MotorShield motorShield;//
Adafruit_DCMotor *motorRight;
Adafruit_DCMotor *motorLeft;
float rTune = 1;
float lTune = 0.97;
//vector<bool> spinDirection = {1,1};

//Function Definitions
void initMove() {
  motorShield = Adafruit_MotorShield();
  motorRight = motorShield.getMotor(1);
  motorLeft = motorShield.getMotor(2);
  motorShield.begin();
  return;
}

//low level movement function
void spinWheels(int16_t rspd, int16_t lspd) {
  motorRight->setSpeed((int16_t) abs(rspd)*255/100*rTune);
  motorLeft->setSpeed((int16_t) abs(lspd)*255/100*lTune);
  motorRight->run(rspd>=0 ? FORWARD : BACKWARD);
  motorLeft->run(lspd>=0 ? FORWARD : BACKWARD);
 // spinDirection = {rspd < 0 ? 0 : 1, lspd < 0 ? 0 : 1};
}

//high level movement fucntions
/*general high-level function for movement. follow is whether its tracking a wall/line. until is the point at which it breaks out of this function*/
void moveForwards(uint8_t follow = NONE, uint8_t until = WALL) { 
  
  uint16_t flapDelay = 1000; //in ms
  
  for (;;) {
    long tm = millis();
    flapSet(tm%(2*flapDelay)>flapDelay ? 0 : 2); //Flap back and forth at flapDelay
   
    if (0 /* OR detect block*/) {
      //perform block sorting routing here
    }
    if (until == WALL && switchFrontBoth()) {
      break;
    }
    if (until == LINE/* && Line != black() */) {
      break;
    }
    
    //perform appropriate wheel actions
    switch (follow) {
      case NONE: spinWheels(100, 100); break;
      case RIGHTWALL: spinWheels(100,97); break;
      case LEFTWALL: spinWheels(97, 100); break;
      
    }
  }
  return;
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

 
 
