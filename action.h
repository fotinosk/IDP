#ifndef ACTION_H
#define ACTION_H

//Includes + any other includes you need
#include "Arduino.h"
#include "Servo.h"


//Variable Declarations
<<<<<<< HEAD
extern Servo frontServo;
extern Servo backServo;
extern uint8_t gateLeftPos;
extern uint8_t gateMidPos;
extern uint8_t gateRightPos;
extern uint8_t flapLeftPos;
extern uint8_t flapMidPos;
extern uint8_t flapRightPos;
=======
extern Servo sortServo;
extern Servo flapServo;
extern uint8_t flapRightPos;
extern uint8_t flapLeftPos;
extern uint8_t sortKeepPos;
extern uint8_t sortDiscardPos;
>>>>>>> 8398b369f24a8048ab93ec1fb98b4f9a6535127a
extern uint8_t redLEDPin;

//Function Definitions
void initAction();
<<<<<<< HEAD
//Gates and servos
void flapSet(uint8_t pos);
void gateSet(uint8_t pos);
void openHatch();

=======
//Flaps and servos
void flapRight();
void flapLeft();
void sortKeep();
void sortDiscard();
>>>>>>> 8398b369f24a8048ab93ec1fb98b4f9a6535127a
//Block carrying light
void redLEDOn();
void redLEDOff();

#endif /* ACTION_H */
