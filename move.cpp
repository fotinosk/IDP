//Only include move.h
#include "move.h"

//Variable Definitions
Adafruit_MotorShield motorShield = Adafruit_MotorShield();//
Adafruit_DCMotor *motorRight;
Adafruit_DCMotor *motorLeft;
float rTune = 1;
float lTune = 0.975;
bool spinDirection [2] = {1,1};

//Function Definitions
void initMove() {
  motorRight = motorShield.getMotor(1);
  motorLeft = motorShield.getMotor(2);
  motorShield.begin();
  return;
}

//low level movement function literally for spinning the wheels.
void spinWheels(int16_t lspd, int16_t rspd) {
  motorRight->setSpeed((int16_t) abs(rspd)*255/100*rTune);
  motorLeft->setSpeed((int16_t) abs(lspd)*255/100*lTune);
  motorRight->run(rspd>=0 ? FORWARD : BACKWARD);
  motorLeft->run(lspd>=0 ? FORWARD : BACKWARD);
  spinDirection[0] = lspd >= 0;
  spinDirection[1] = rspd >= 0;
}

//might need a middle level movement fucniton in here which spins wheels individually but can also loop and detect block etc
bool moveWheels(int16_t lspd, int16_t rspd, uint8_t until, uint32_t duration, uint16_t flapDelay) {
  if (until == TIMER)
    moveTimer(SET, duration);
  else if (until == DISTANCE)
    encoderRun(RESET);
  while(true) {
    flapDelay ? flapSet(millis()%(2*flapDelay)>flapDelay ? LEFTPOS : RIGHTPOS) : flapSet(MIDPOS); //Flap back and forth at flapDelay unless its 0 so it goes middle
    //different checks and analyses i.e. a block or end condition met
    if (0 /*detect blocks here*/){
      //do block detection routing or call a function for it
    }
    //determine if conditions for stopping are met
    if (switchFrontBoth() || switchBackBoth())
      return until == WALL; //if we hit a wall unintentionaly we need to deal with it => return an error flag - might make this an int later to detect other possible sources of going wrong ie crossing the red line when we don't want to
    if (until == DISTANCE) { 
      encoderRun(RUN);
      if ((encoderCount[0] + encoderCount[1])/2*mmPerEncoder >= duration)//encoder counts are averaged to give central distance
        break;
    }
    if (until == TIMER && !moveTimer(READ, 0))
      break;
    if (until == LINE && lineSensor())
      break;
    //perform movement
    spinWheels(lspd, rspd);
  }
  return true;
}
//high level movement fucntions

void turnCorner(bool dir) { //might need to use timer to flap paddle really fast if blocks not held in
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

void turn90(bool dir) {
 return; 
}

void turnAround (bool dir) {
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

 
