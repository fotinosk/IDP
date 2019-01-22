/*Template file to understand how to set up multiple files.
 *
 * This is an include guard but it doesn't work across different translation units.
 * Therefore only put function declarations and preproccesor directives here.
 * Other setup should go in the init function in the .cpp file.
 */
#ifndef NAME_H
#define NAME_H

//Includes + any other includes you need
#include "Arduino.h"

//Variable Declarations
  //extern Type globalVariable;

//Function Definitions + other functions that are required
void initName();

#endif /* NAME_H */
