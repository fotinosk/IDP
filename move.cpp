#include "move.h"

//Variable Definitions
Adafruit_MotorShield motorShield = Adafruit_MotorShield();
Adafruit_DCMotor *motorRight;
Adafruit_DCMotor *motorLeft;
float rTune = 1; //tune motor powers
float lTune = 0.974;
bool spinDirection [2] = {1,1};

//Function Definitions
void initMove() {
  motorRight = motorShield.getMotor(1);
  motorLeft = motorShield.getMotor(2);
  motorShield.begin();
  return;
}

//low level movement function spins wheels and normalises power from 0-255 to -100 - 100
void spinWheels(int16_t lspd, int16_t rspd) {
  motorRight->setSpeed((int16_t) abs(rspd)*255/100*rTune);
  motorLeft->setSpeed((int16_t) abs(lspd)*255/100*lTune);
  motorRight->run(rspd>=0 ? FORWARD : BACKWARD);
  motorLeft->run(lspd>=0 ? FORWARD : BACKWARD);
  spinDirection[0] = lspd >= 0; //used for encoder tracking
  spinDirection[1] = rspd >= 0;
}

/*The main movement function to be used.
 * 'lspd' and 'rspd' control motor power,
 * 'until' defines the stopping condition for this movement
 * 'duration' is the magnitude for quantitative stopping conditions - time in ms or distance in mm depending on 'until'
 * 'flapDelay' is the period the flap should move back and forth at. 0 is no movement and in the centre position
 */
bool moveWheels(int16_t lspd, int16_t rspd, uint8_t until, uint32_t duration, uint16_t flapDelay) {
  amberLED(abs(lspd)+abs(rspd)!=0?ON:OFF); //if moving turn on amber light
  if (until == TIMER) //if using TIMER as stopping condition start timing
    moveTimer(SET, duration);
  encoderRun(RESET); //reset the value of the encoder

  bool blockDetected = false;
  bool magnetDetected = false;
  int32_t currentEncoderCount;
  //The loop which continues until stopping condtion is met.
  while(true) {
    //Let encoder check if colour has changed
    encoderRun(RUN);

    // move flap at period of flapDelay when block is not detected. We don't want to accidently push away the block when it is detected
    if(!blockDetected){
      flapDelay ? flapSet(millis()%(2*flapDelay)>flapDelay ? LEFTPOS : RIGHTPOS) : flapSet(MIDPOS);
    }
    else if(blockDetected) {
      flapSet(millis()%(2*300)>300 ? LEFTPOS : RIGHTPOS);
    }

    /* BLOCK DETECTION SEQUENCE  */
    if (irSensor() && !blockDetected){
      blockDetected = true;
      enableHallSensor();
      if (hallSensor())
        magnetDetected = true;
      currentEncoderCount = encoderCount[0];
    }

    // move a bit forward after block detected
    if(blockDetected && abs(encoderCount[0] - currentEncoderCount)>=2) {
      analyseBlock(magnetDetected);
      magnetDetected = false;
      blockDetected = false;
      disableHallSensor();
    }
    else if(blockDetected && hallSensor()) {
      magnetDetected = true;
    }

    /* STOPPING CONDITIONS */
    //determine if conditions for stopping are met
    if (until == WALL && (switchFrontBoth() || switchBackBoth()))
      return until == WALL; //if we hit a wall unintentionally return false so we can check this and implement correction
    if (until == DISTANCE) {
      if (abs((encoderCount[0] + encoderCount[1])/2)*mmPerEncoder >= duration)//encoder counts are averaged to give central distance
        break;
    }
    if (until == TIMER && !moveTimer(READ, 0))
      break;
    if (until == LINE && lineSensor())
      break;

    //perform movement
    spinWheels(lspd, rspd);
  }
  amberLED(OFF); //turn off amber light again
  return true;
}

/*High level movement funcitons - descriptions in the header file for what these do*/

void turnCorner(bool dir) {
  spinWheels(0,0);
  delay(200);
  flapSet(MIDPOS);
  spinWheels(-100, -100);
  delay(410);
  switch (dir) {
    case RIGHTTURN: spinWheels(100, -30); break; //to actually turn, this needs fine tuning
    case LEFTTURN: spinWheels(-30, 100); break;
  }
  delay(1150);
  spinWheels(100, 100); //so blocks are pushed back again.
  delay(150);
  return;
}

void turn90(bool dir) { //when we are turning the last corner after the last sweep of the field and don't want to get stuck in the top right corner
 moveWheels(dir? -80 : -83 ,dir? -83: -80, DISTANCE, 180, 0);// back slightly.  if dir== (RIGHTTURN = TRUE)
 moveWheels(dir? 70 :0, dir?0:70, DISTANCE, 130, 0); //turn   - if dir== (RIGHTTURN = TRUE)
 delay(1000);
 unsigned long waitTime = millis();
 spinWheels(-100, -100);
 while(millis() - waitTime < 9000) {
  if(switchBackBoth()) {
    break;
  }
 }
 delay(500);
 resetJam();
 return;
}

void turn90WithoutReverse(bool dir) { //this function is for turning in open space when we don't have the wall to guide us.
 moveWheels(dir? 70 :0, dir?0:70, DISTANCE, 150, 0); //turn   - if dir== (RIGHTTURN = TRUE) was 130
 delay(1000);
 unsigned long waitTime = millis();
 spinWheels(-100, -100);
 while(millis() - waitTime < 9000) {
  if(switchBackBoth()) {
    break;
  }
 }
 //moveWheels(-100,-100, TIMER, , 0); //get on the wall
 delay(500);
 resetJam();
 return;
}


void turnAround (bool dir) {
  spinWheels(-100,-100);
  delay(680); // was 700
 /* spinWheels(dir == LEFTTURN ? -100 : 0, dir == LEFTTURN ? 0 : -100);
  delay(600);*/
  spinWheels(dir == LEFTTURN ? 0 : 100, dir == LEFTTURN ? 100 : 0);
  delay(3970); //was 3970
  stopMotors(10);
  flapSet(RIGHTPOS);
  delay(100);

  unsigned long waitTime = millis();
  spinWheels(-100, -100);
  while (!switchBackBoth() && millis() - waitTime < 9000) {
    if(switchBackRight()) {
      spinWheels(-100,-20);
    }
    if(switchBackLeft()) {
      spinWheels(-20, -100);
    }

  }

  spinWheels(-100,-100);
  delay(400);
  resetJam();
  return;


void analyseBlock(bool alreadyMagnetic) {
  bool magnetic = alreadyMagnetic;
  spinWheels(0,0);
  flapSet(MIDPOS);
  delay(200);
  //move 1 cm and test for magnetism in this time
  magnetTimer(SET, 220);
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
  sortSet(magnetic ? RIGHTPOS : LEFTPOS);
  delay(200);
  magnetMoveTimer(SET, 350); //move enough to put block in storage
  while(magnetMoveTimer(READ, 0)){
    if (hallSensor() && !magnetic){ //if late magnetic detection
      magnetMoveTimer(PAUSE, 0);
      spinWheels(-80,-80);
      delay(200);
      spinWheels(0,0);
      sortSet(RIGHTPOS);
      delay(200);
      magnetMoveTimer(RESUME, 0);
      }
    encoderRun(RUN);
    spinWheels(80,80);
  }
  if (!magnetic)
    redLED(ON);
  sortSet(MIDPOS); //return flap to default
  spinWheels(0,0);
  return;
}

void stopMotors(int mseconds) {
  spinWheels(0,0);
  delay(mseconds);
}

void resetJam() {
  flapSet(MIDPOS);
  sortSet(LEFTPOS);
  while(switchBackBoth()){
  spinWheels(60,60);
  }
  delay(100);
  moveWheels(80,80, DISTANCE, 30, 0);
  sortSet(RIGHTPOS);
  moveWheels(80,80, DISTANCE, 30, 0);
  sortSet(MIDPOS);
}

