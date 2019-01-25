//Include
#include "sense.h"

//Variable Definitions
int color;

/*
 * Box Blue 75-85
 * Track Black 9-10
 * Track Red 100-110
 * Track White 200-215
 * TRack Green 115-120
 */

//Function Definitions
void initSense() {
//  globalVariable = whatever;
  return;
}

int LineSensor() {
  int rd = analogRead(A1); 
  delay(100);
  if (rd < 15 && rd > 5) {
    //black
    return 1; 
  }
  if (rd < 110 && rd > 100) {
    //red
    return 2; 
  }
  if (rd < 215 && rd > 200) {
    //white
    return 3; 
  }
  if (rd < 120 && rd > 115) {
    //green
    return 4; 
  }
}
