//Only include move.h
#include "move.h"

//Variable Definitions
Adafruit_MotorShield motorShield = Adafruit_MotorShield();//
Adafruit_DCMotor *motorRight;
Adafruit_DCMotor *motorLeft;
float rTune = 1;
float lTune = 0.975;
vector<bool> spinDirection = {1,1};

//Function Definitions
void initMove() {
  motorRight = motorShield.getMotor(1);
  motorLeft = motorShield.getMotor(2);
  motorShield.begin();
  return;
}

//low level movement function
void spinWheels(int16_t lspd, int16_t rspd) {
  motorRight->setSpeed((int16_t) abs(rspd)*255/100*rTune);
  motorLeft->setSpeed((int16_t) abs(lspd)*255/100*lTune);
  motorRight->run(rspd>=0 ? FORWARD : BACKWARD);
  motorLeft->run(lspd>=0 ? FORWARD : BACKWARD);
  spinDirection = {rspd < 0 ? 0 : 1, lspd < 0 ? 0 : 1};
}

//high level movement fucntions
/*general high-level function for movement. follow is whether its tracking a wall/line. until is the point at which it breaks out of this function*/
void moveForwards(uint8_t follow = NONE, uint8_t until = WALL) { 
  
  uint16_t flapDelay = 5000; //in ms
  
  for (;;) {
    long tm = millis();
    flapSet(tm%(2*flapDelay)>flapDelay ? LEFTPOS : RIGHTPOS); //Flap back and forth at flapDelay
   
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

void turnCorner(uint8_t dir) { //might need to use timer to flap paddle really fast if blocks not held in
  //set flap & gate to blocking
  //sortSet(MIDPOS);
  flapSet(MIDPOS);
  spinWheels(-100,-100);
  delay(380);
  switch (dir) {
    case RIGHTTURN: spinWheels(100, -30); break; //to actually turn, this needs fine tuning
    case LEFTTURN: spinWheels(-30, 100); break;
  }
  delay(700); //1100
  spinWheels(100, 100); //so blocks are pushed back again.
  delay(500); //100
//  sortSet(RIGHTPOS);

  spinWheels(100, 100); //start driving again
  delay(500);
  
  return;
}

void turnAround (uint8_t dir) {
   //sortSet(MIDPOS);
  flapSet(MIDPOS);
  spinWheels(-100,-100);
  delay(300);
  spinWheels(dir == LEFTTURN ? -100 : 0, dir == LEFTTURN ? 0 : -100);
  delay(600);
  spinWheels(dir == LEFTTURN ? 0 : 100, dir == LEFTTURN ? 100 : 0);
  delay(3200);
  spinWheels(-100, -100);
  while (!switchBackBoth()) {}
  return;

}

//turn 180 w shift left or right for snaking
//detect block
 //use a timer to see if magnetic at anypoint
 //set flaps to middle

 
