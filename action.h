#ifndef ACTION_H
#define ACTION_H

#include "Arduino.h"
#include "Servo.h"
#include <Wire.h>
#include <Adafruit_MotorShield.h>

//Flap and gate positions and LED state defines
#define LEFTPOS 0
#define MIDPOS 1
#define RIGHTPOS 2
#define LEFTUNJAM 3
#define RIGHTUNJAM 4
#define ON 1
#define OFF 0

//Variable Declarations
extern Servo flapServo;
extern Servo sortServo;
extern Adafruit_MotorShield motorShield;
extern Adafruit_DCMotor *sliderMotor;
extern uint8_t sortLeftPos;
extern uint8_t sortMidPos;
extern uint8_t sortRightPos;
extern uint8_t flapLeftPos;
extern uint8_t flapMidPos;
extern uint8_t flapRightPos;
extern uint8_t sortLeftUnjam;
extern uint8_t sortRightUnjam;
extern uint8_t redLEDPin;
extern uint8_t amberLEDPin;
extern uint8_t enableHallSensorPin;

//Function Definitions
void initAction();
//Servos and Slider
void flapSet(uint8_t pos);
void sortSet(uint8_t pos);
void openSlider();
void closeSlider();
void enableHallSensor();
void disableHallSensor();

//Controllable lights
void redLED(bool state);
void amberLED(bool state);

#endif /* ACTION_H */
