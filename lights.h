#ifndef LIGHTS_H
#define LIGHTS_H

//Includes
#include "Arduino.h"

//Function Declaration
void initLights();
void FlashingAmberOn(); //moving
void FlashingAmberOff();
void GreenLEDOn(); //detected fuel cell
void GreenLEDOff();
void FlashingRedOn(); //carrying active material
void FlashingRedOff();

#endif

