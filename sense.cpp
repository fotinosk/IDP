//Include
#include "sense.h"

//Variable Definitions
//int color;
uint8_t switchFrontLeftPin = 2;
uint8_t switchFrontRightPin = 3;
uint8_t switchBackLeftPin = 4;
uint8_t switchBackRightPin = 5;
uint8_t hallSensorPin = 22;
uint8_t blockDetectPin;//=
uint8_t leftEncoderPin;//=
uint8_t rightEncoderPin;//=
float mmPerEncoder = 8.69;

int32_t encoderCount [2] = {0,0};
uint16_t encoderThreshold[2][2] = {{64,50},{58,40}};

//Function Definitions
void initSense() {
  pinMode(switchFrontLeftPin, INPUT);
  pinMode(switchFrontRightPin, INPUT);
  pinMode(switchBackLeftPin, INPUT);
  pinMode(switchFrontRightPin, INPUT);
  pinMode(hallSensorPin, INPUT);
  pinMode(blockDetectPin, INPUT);
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
    encoderStatus[1] = analogRead(rightEncoderPin)> (encoderThreshold[1][0]+encoderThreshold[1][1])/2 ? 0 : 1;
    return;
  }
  if (encoderStatus[0] && analogRead(leftEncoderPin > encoderThreshold[0][0])) {
    encoderStatus[0] = false;
    encoderCount[0] += 2*spinDirection[0] - 1;
  }
  else if(encoderStatus[0] && analogRead(leftEncoderPin < encoderThreshold[0][1])){
    encoderStatus[0] = true;
    encoderCount[0] += 2*spinDirection[0] - 1;
  }
  if (encoderStatus[1] && analogRead(rightEncoderPin > encoderThreshold[1][0])) {
    encoderStatus[1] = false;
    encoderCount[1] += 2*spinDirection[1] - 1;
  }
  else if(encoderStatus[1] && analogRead(rightEncoderPin < encoderThreshold[1][1])){
    encoderStatus[1] = true;
    encoderCount[1] += 2*spinDirection[1] - 1;
  }
  return;
}
/*void countEncoder() {

  for(int i = 0; i < 2; i++)
  {
    if(encoder_status[i] && analogRead(i) > encoder_threshold[i][0])
    {
      encoder_status[i] = false;
      encoder_count[i] += 2*spinDirection[i] - 1;
      encoder_count_ABS[i] += 1;
    }
    else if(!encoder_status[i] && analogRead(i) < encoder_threshold[i][1])
    {
      encoder_status[i] = true;
      encoder_count[i] += 2*spinDirection[i] - 1;
      encoder_count_ABS[i] += 1;
    }
  }
  
}

void encoderCountReset() {
  encoder_count = {0,0};
  encoder_count_ABS = {0,0};
} */


/*
 * Box Blue 75-85
 * Track Black 9-10
 * Track Red 100-110
 * Track White 200-215
 * TRack Green 115-120
 */

uint8_t lineSensor() {
  int rd = analogRead(A2); 
  delay(20);
  if (rd < 15 && rd > 5) {
    return BLACK;  

  }
  if (rd < 110 && rd > 100) {
    return RED; 
  }
  if (rd < 215 && rd > 200) {
    return WHITE; 
  }
  if (rd < 120 && rd > 115) {
    return GREEN; 
  }
}

bool hallSensor() {
  return digitalRead(hallSensorPin);
}

bool blockDetect() {
  return digitalRead(blockDetectPin);
}
