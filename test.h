/* The file for testing all the other things. here we nee to include all the other header files/
 */
#ifndef TEST_H
#define TEST_H

//Includes + any other includes you need
#include "Arduino.h"
#include "action.h"
#include "sense.h"
#include "move.h"

//Variable Declarations
  //extern Type globalVariable;

//Function Definitions + other functions that are required
void initTest();

void testSwitches();
void testMotors();
void testFlap();
void testSort();
void testSlider();

#endif /* TEST_H */
