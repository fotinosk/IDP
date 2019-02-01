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

//might need a middle level movement fucniton in here which spins wheels but can also loop and detect block etc

//high level movement fucntions
/*general high-level function for movement. follow is whether its tracking a wall/line. until is the point at which it breaks out of this function*/
void moveForwards(uint8_t follow = NONE, uint32_t until = WALL) { 
  uint16_t flapDelay = 800; //in ms
  moveTimer(SET, until);
  for (;;) {
    long tm = millis();
    flapSet(tm%(2*flapDelay)>flapDelay ? LEFTPOS : RIGHTPOS); //Flap back and forth at flapDelay
   
    if (0 /* OR detect blockw tih microswitch*/) {
      analyseBlock();
    }
    if (until == WALL && switchFrontBoth()) {
      break;
    }
    if (until == LINE/* && Line != black() */) {
      break;
    }
    if (until > 10 && !moveTimer(READ, 0)) {
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
  delay(1100); //700
  spinWheels(100, 100); //so blocks are pushed back again.
  delay(100); //500
//  sortSet(RIGHTPOS);
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

void analyseBlock() {
  bool magnetic = false;
  spinWheels(0,0);
  sortSet(MIDPOS);
  flapSet(MIDPOS);
//  magnetTimer(2000, SET);
  spinWheels(5,5);
  while (1/*magnetTimer(0, READ)*/) { //while magnet timer is set
    //if detect a wall do a safety thing here
    if (hallSensor())
      magnetic = true;
      break;
  }
  sortSet(magnetic ? RIGHTPOS : LEFTPOS); //will need to remember the position so it can return to it after a corner.
  return;
}

 
