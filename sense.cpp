//Include
#include "sense.h"

//Variable Definitions
//int color;
uint8_t switchFrontLeftPin = 2;
uint8_t switchFrontRightPin = 3;
uint8_t switchBackLeftPin = 4;
uint8_t switchBackRightPin = 5;
vector<bool> encoder_status = {0,0};
vector<int> encoder_count = {0,0};
vector<int> encoder_count_ABS = {0,0};


// encoder thresholds
vector<vector<int>> encoder_threshold = {{64,50},{58,40}};

//Function Definitions
void initSense() {
  pinMode(switchFrontLeftPin, INPUT);
  pinMode(switchFrontRightPin, INPUT);
  pinMode(switchBackLeftPin, INPUT);
  pinMode(switchFrontRightPin, INPUT);
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
/*
 * Call this program in a loop and it will count the encoder positions, both relative (to motor rotation direction) and the absolute number of ticks
 */

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

int LineSensor() {
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
