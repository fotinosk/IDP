//Only include move.h
#include "move.h"

//Variable Definitions
Adafruit_MotorShield motorShield = Adafruit_MotorShield();//
Adafruit_DCMotor *motorRight;
Adafruit_DCMotor *motorLeft;
float rTune = 1;
float lTune = 0.974; //this was almost perfectly straighta fter caster adjustment on thursday
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

//higher level movement function with its own loop
bool moveWheels(int16_t lspd, int16_t rspd, uint8_t until, uint32_t duration, uint16_t flapDelay) {
  amberLED(abs(lspd)+abs(rspd)!=0?ON:OFF);
  if (until == TIMER)
    moveTimer(SET, duration);
  encoderRun(RESET);

  bool blockDetected = false;
  bool magnetDetected = false;
  int32_t currentEncoderCount;
  // the actual going forward loop
  while(true) {
    //count the encoder
    encoderRun(RUN);
    // move flap when block is not detected. We don't want to accidently push away the block when it is detected
    if(!blockDetected){
      flapDelay ? flapSet(millis()%(2*flapDelay)>flapDelay ? LEFTPOS : RIGHTPOS) : flapSet(MIDPOS); //Flap back and forth at flapDelay unless its 0 so it goes middle
    } //don't we want to set the flap to middle to ensure not more than one block gets in
    //different checks and analyses i.e. a block or end condition met

    /*
     * BLOCK DETCTION SEQUENCE
     */
    if (irSensor() && !blockDetected){
      blockDetected = true;
      enableHallSensor(); 
      if (hallSensor())
        magnetDetected = true;
      currentEncoderCount = encoderCount[0];
    }
    
    // move a bit forward after block detected 
    if(blockDetected && abs(encoderCount[0] - currentEncoderCount)>=2) { // was 30
      analyseBlock(magnetDetected);
      magnetDetected = false;
      blockDetected = false;
      disableHallSensor();
    }
    else if(blockDetected && hallSensor()) {
      magnetDetected = true;
    }
    /*
     * STOPPING CONDITIONS
     */
    //determine if conditions for stopping are met
    if (switchFrontBoth() || switchBackBoth())
      return until == WALL; //if we hit a wall unintentionaly we need to deal with it => return an error flag - might make this an int later to detect other possible sources of going wrong ie crossing the red line when we don't want to
    if (until == DISTANCE) { 
      if (abs((encoderCount[0] + encoderCount[1])/2*mmPerEncoder) >= duration)//encoder counts are averaged to give central distance
        break;
    }
    if (until == TIMER && !moveTimer(READ, 0))
      break;
    if (until == LINE && lineSensor())
      break;

      
    //perform movement
    spinWheels(lspd, rspd);
  }
  amberLED(OFF);
  return true;
}
//high level movement fucntions

void turnCorner(bool dir) { //might need to use timer to flap paddle really fast if blocks not held in
  //set flap & gate to blocking
  spinWheels(0,0);
  delay(200);
  flapSet(MIDPOS);
  spinWheels(-100, -100);
  delay(380);
  switch (dir) {
    case RIGHTTURN: spinWheels(100, -30); break; //to actually turn, this needs fine tuning
    case LEFTTURN: spinWheels(-30, 100); break;
  }
  delay(1100); //700
  spinWheels(100, 100); //so blocks are pushed back again.
  delay(100); //500
  return;
}

void turn90(bool dir) { //this function is for turning in open space when we don't have the wall to guide us.
 moveWheels(RIGHTTURN?-80:-83,RIGHTPOS?-83:-80, DISTANCE, 120, 0);// back slightly.
 moveWheels(RIGHTTURN?70:0, RIGHTTURN?0:70, DISTANCE, 130, 0); //turn
 delay(1000);
 moveWheels(-100,-100, WALL, 0, 0); //get on the wall
 while(switchBackBoth()){
  spinWheels(80,80);
 }
 delay(100);
 return;
}

void turnAround (bool dir) {
  spinWheels(-100,-100);
  delay(700);
 /* spinWheels(dir == LEFTTURN ? -100 : 0, dir == LEFTTURN ? 0 : -100);
  delay(600);*/
  spinWheels(dir == LEFTTURN ? 0 : 100, dir == LEFTTURN ? 100 : 0);
  delay(3970);
  
  spinWheels(-100, -100);
  while (!switchBackBoth()) {}
  spinWheels(0,0);
  delay(100);
  while(switchBackBoth()) {
    spinWheels(40,40);
  }
  delay(100);
  return;

}//add little backward movment for if magnetic

void analyseBlock(bool alreadyMagnetic) {
  bool magnetic = alreadyMagnetic;
  spinWheels(0,0);
  flapSet(MIDPOS);
  delay(1000); // long delays coming ahead. just there for testing

  //move 1 cm and test for magnetism in this time
//
  
  magnetTimer(SET, 200);
  spinWheels(30,30);
  while (magnetTimer(READ, 0)) { //while magnet timer is set
    if (switchFrontBoth()) {
      moveWheels(-10, -10, TIMER, 600, 0);
    }
    encoderRun(RUN);
    if (hallSensor())
      magnetic = true;
      break;
  }
  spinWheels(0,0);

  //move the flap and move to process block
  sortSet(magnetic ? RIGHTPOS : LEFTPOS); //will need to remember the position so it can return to it after a corner.
  delay(1000); 
  magnetMoveTimer(SET, 450); //move enough to put block in storage
  while(magnetMoveTimer(READ, 0)){
    if (hallSensor() && !magnetic){ //if late magnetic detection
      magnetMoveTimer(PAUSE, 0);
      spinWheels(-80,80);
      delay(200);
      spinWheels(0,0);
      sortSet(RIGHTPOS);
      delay(200);
      magnetMoveTimer(RESUME, 0);
      }
    encoderRun(RUN);
    spinWheels(80,80);
  }

  sortSet(MIDPOS); //return flap to default
  spinWheels(0,0);
  return;
}


void stopMotors(int mseconds) {
  spinWheels(0,0);
  delay(mseconds);
}
