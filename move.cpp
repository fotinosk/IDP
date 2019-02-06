//Only include move.h
#include "move.h"

//Variable Definitions
Adafruit_MotorShield motorShield = Adafruit_MotorShield();//
Adafruit_DCMotor *motorRight;
Adafruit_DCMotor *motorLeft;
float rTune = 1;
float lTune = 0.97;
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

//might need a middle level movement fucniton in here which spins wheels individually but can also loop and detect block etc,
//make acceleration less brutal to ease it into movement
bool moveWheels(int16_t lspd, int16_t rspd, uint8_t until, uint32_t duration, uint16_t flapDelay) {
  amberLED(abs(lspd)+abs(rspd)!=0?ON:OFF);
  if (until == TIMER)
    moveTimer(SET, duration);
  else if (until == DISTANCE)
    encoderRun(RESET);

  bool blockDetected = false;
  bool magnetDetected = false;
  int currentEncoderCount;
  // the actual going forward loop
  while(true) {

    // move flap when block is not detected. We don't want to accidently push away the block when it is detected
    if(!blockDetected){
      flapDelay ? flapSet(millis()%(2*flapDelay)>flapDelay ? LEFTPOS : RIGHTPOS) : flapSet(MIDPOS); //Flap back and forth at flapDelay unless its 0 so it goes middle
    }
    //different checks and analyses i.e. a block or end condition met

    /*
     * BLOCK DETCTION SEQUENCE
     */
    if (irSensor() && !blockDetected){
      blockDetected = true;
      currentEncoderCount = encoderCount[0];
    }

    // move a bit forward after block detected 
    if(blockDetected && abs(encoderCount[0] - currentEncoderCount)/mmPerEncoder >= 30) {
      analyseBlock(magnetDetected);
      magnetDetect = false;
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
      encoderRun(RUN);
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
  sortSet(MIDPOS);
  flapSet(MIDPOS);
  spinWheels(-100, -100);
  //Serial.print("Starting backwards movement");
  delay(380);
  //Serial.-println("Delay FInished");
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

void turn90(bool dir) { //this function is for turning in open space when we don't have the wall to guide us.
 moveWheels(-80, -83, DISTANCE, 120, 0);// back slightly.
 moveWheels(70, 0, DISTANCE, 130, 0); //turn
 delay(1000);
 moveWheels(-100,-100, WALL, 0, 0); //get on the wall
 while(switchBackBoth()){
  spinWheels(80,80);
 }
 delay(100);
 return;
}

void turnAround (bool dir) {
   //sortSet(MIDPOS);
  flapSet(MIDPOS);
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

}

void analyseBlock(bool alreadyMagnetic) {
  spinWheels(0,0);
  sortSet(RIGHTPOS);
  flapSet(MIDPOS);
  delay(2000); // long delays coming ahead. just there for testing

  spinSheels(60,60);
  while(irSensor()) {
    encoderRun(RUN);  
  }
  stopMotor(2000);

  while(!switchFrontRight()) {}  // <- this is just for testing convenience. 
  delay(1000); 

  bool magnetic = false;  
  if(!alreadyMagnetic)
  {
    sortSet(MIDPOS);
    delay(500);
  }
  magnetTimer(SET, 1000);
  spinWheels(70,70);
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
  while(!switchFrontRight()) {}  // <- this is just for testing convenience. 
  delay(1000); 

  if(!alreadyMagnetic){
    sortSet(magnetic ? RIGHTPOS : LEFTPOS); //will need to remember the position so it can return to it after a corner.
    delay(1000); 
    magnetMoveTimer(SET, 1000);
    while(magnetMoveTimer(READ, 0)){
      encoderRun(RUN);
      spinWheels(80,80);
    }
  }
  spinWheels(0,0);
  return;
}


void stopMotors(int seconds) {
  spinWheels(0,0);
  delay(seconds);
}
