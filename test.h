/* The file for testing all fucntionality to ensure proper function.  */
#ifndef TEST_H
#define TEST_H

#include "Arduino.h"
#include "action.h"
#include "sense.h"
#include "move.h"


//Function Definitions
void initTest();

void testSwitches();
void testMotors();
void testFlap();
void testSort();
void testSlider();
void testUnjam();

#endif /* TEST_H */
