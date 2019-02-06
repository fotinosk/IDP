//Include
#include "sense.h"

//Variable Definitions
//int color;
uint8_t switchFrontLeftPin = 3;
uint8_t switchFrontRightPin = 2;
uint8_t switchBackLeftPin = 5;
uint8_t switchBackRightPin = 4;
uint8_t hallSensorPin = 6;
uint8_t irSensorPin = 11;//=
uint8_t leftEncoderPin = 14;//=
uint8_t rightEncoderPin = 15;//=
uint8_t rightLineSensorPin = 13;
float mmPerEncoder = 9.48;

int32_t encoderCount [2] = {0,0};
uint16_t encoderThreshold[2][2] = {{64,50},{62,48}};


//Function Definitions
void initSense() {
  pinMode(switchFrontLeftPin, INPUT);
  pinMode(switchFrontRightPin, INPUT);
  pinMode(switchBackLeftPin, INPUT);
  pinMode(switchFrontRightPin, INPUT);
  pinMode(hallSensorPin, INPUT);
  pinMode(irSensorPin, INPUT);
  //pinMode(leftEncoderPin, INPUT);
  //pinMode(rightEncoderPin, INPUT);
  return;
}

bool switchFrontLeft() {
  return !digitalRead(switchFrontLeftPin);
}
bool switchFrontRight() {
  return !digitalRead(switchFrontRightPin); 
}
bool switchBackLeft() {
  return !digitalRead(switchBackLeftPin);
}
bool switchBackRight() {
  return !digitalRead(switchBackRightPin);
}
bool switchFrontBoth() {
  return !(digitalRead(switchFrontLeftPin) || digitalRead(switchFrontRightPin));
}

bool switchBackBoth() {
  return !(digitalRead(switchBackLeftPin) || digitalRead(switchBackRightPin));
}

void encoderRun(uint8_t action) {
  static bool encoderStatus [2] = {0,0};

  if (action == RESET) {
    encoderCount[0] = encoderCount[1] = 0;
    encoderStatus[0] = analogRead(leftEncoderPin) > (encoderThreshold[0][0]+encoderThreshold[0][1])/2 ? 0 : 1;
    encoderStatus[1] = analogRead(rightEncoderPin) > (encoderThreshold[1][0]+encoderThreshold[1][1])/2 ? 0 : 1;
    return;
  }
  if (encoderStatus[0] && analogRead(leftEncoderPin) > encoderThreshold[0][0]) {
    encoderStatus[0] = false;
    encoderCount[0] += 2*spinDirection[0] - 1;
  }
  else if(!encoderStatus[0] && analogRead(leftEncoderPin) < encoderThreshold[0][1]){
    encoderStatus[0] = true;
    encoderCount[0] += 2*spinDirection[0] - 1;
  }
  if (encoderStatus[1] && analogRead(rightEncoderPin) > encoderThreshold[1][0]) {
    encoderStatus[1] = false;
    encoderCount[1] += 2*spinDirection[1] - 1;
  }
  else if(!encoderStatus[1] && analogRead(rightEncoderPin) < encoderThreshold[1][1]){
    encoderStatus[1] = true;
    encoderCount[1] += 2*spinDirection[1] - 1;
  }
  return;
}

bool lineSensor() {
  return analogRead(rightLineSensorPin) < 980; // then it detects a line
}

bool hallSensor() {
  return !digitalRead(hallSensorPin);
}

bool irSensor() {
  return digitalRead(irSensorPin);
}
