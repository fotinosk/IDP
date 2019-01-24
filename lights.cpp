
//Include - only the one here. others are in the header file.
#include "lights.h"

//Variable Definitions
const int Amber = 13; //or any other DIGITAL pin
const int Green = 12;
const int Red = 11;
int timer1_counter;

/*
  timer 0 (controls pin 13, 4)
  timer 1 (controls pin 12, 11) avoid since it is used for servo
  timer 2 (controls pin 10, 9)
  timer 3 (controls pin 5, 3, 2)
  timer 4 (controls pin 8, 7, 6)
 */

unsigned long previousMillis = 0;
const long interval = 1000;  

void initLights() {
  pinMode(Amber,OUTPUT); //sets the specific pins as outputs
  pinMode(Green,OUTPUT);
  pinMode(Red,OUTPUT);
}

void GreenLEDOn() {
  digitalWrite(Green,HIGH);
}
void GreenLEDOff() {
  digitalWrite(Green,LOW);
}
void FlashingAmberOn() {
  digitalWrite(Amber,HIGH);
  /* noInterrupts();
  TCCR1A = 0; //uses timer1 might cause conflict with servo
  TCCR1B = 0;

  timer1_counter = 64911;   // preload timer 65536-16MHz/256/100Hz
  //timer1_counter = 64286;   // preload timer 65536-16MHz/256/50Hz
  //timer1_counter = 34286;   // preload timer 65536-16MHz/256/2Hz

  TCNT1 = timer1_counter;   // preload timer
  TCCR1B |= (1 << CS12);    // 256 prescaler 
  TIMSK1 |= (1 << TOIE1);   // enable timer overflow interrupt
  interrupts();             // enable all interrupts */
  delay(1000);
  digitalWrite(Amber,LOW);
  delay(1000);
}
/*
ISR(TIMER1_OVF_vect)        // interrupt service routine 
{
  TCNT1 = timer1_counter;   // preload timer
  digitalWrite(Amber, digitalRead(Amber) ^ 1);
}
*/
void FlashingAmberOff() {
  digitalWrite(Amber,LOW);
}
void FlashingRedOff() {
  digitalWrite(Red,LOW);
}
void FlashingRedOn() {
  noInterrupts();
  TCCR1A = 0; //uses timer1 might cause conflict with servo
  TCCR1B = 0;

  //timer1_counter = 64911;   // preload timer 65536-16MHz/256/100Hz
  //timer1_counter = 64286;   // preload timer 65536-16MHz/256/50Hz
  timer1_counter = 34286;   // preload timer 65536-16MHz/256/2Hz

  TCNT1 = timer1_counter;   // preload timer
  TCCR1B |= (1 << CS12);    // 256 prescaler 
  TIMSK1 |= (1 << TOIE1);   // enable timer overflow interrupt
  interrupts();             // enable all interrupts
}

lights.cpp

