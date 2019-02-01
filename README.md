# IDP
Clone this IDP repository into your /user/Arduino/ directory/

Libraries you need to install are as follows:
* Adafruit_Motor_Shield_V2_Library (Via the Tools->Manage Libraries...  in the arduino IDE)
* ArduinoSTL library https://github.com/mike-matera/ArduinoSTL/ for cpp stl functions.
  - To install: `$cd ~/Arduino/libraries && git clone https://github.com/mike-matera/ArduinoSTL.git`

TODO:
* We will need some form of documentation so all team members can start using abstraced functions.

* Incorpotate line sensor
* Carrying LED - will go to pin 0
* Encoders
* Could change current #defines to enums
 
 
* Reorder timer function and make easier to use and add pausing
* make new file for block analysis
* make a mid-tier moevement fucntion to be able to move differently than just forwards and detect blocks at the same time
* Make a function to turn 90 degress without a wall to guide it
* learn how encoders are implemented and add option in moveForwards to move a specific distance
* make a robot state to keep track of gate positions and maybe y coordinate
* figure out how robot reads in over serial to listen to Fotinos' computer
* work on edge cases and try to remove all the delays in the program and replace with nice new timers

TODO for mechanical:
* The sort rack and pinion slips
* the switches on the back don't trigger
* Slider doesn't close all the way and over time tends to come off the pinion.
* front left and right wheels still not big enough.


NOTES:
Each count in the encoder - 0.869cm of distance covered +- 2%

For the slider 4200 ms to open the slide. slider(1) -> open

might need to add a timer in the turn function to spam flap instead of setting it

T
