# IDP
Clone this IDP repository into your /user/Arduino/ directory/

Libraries you need to install are as follows:
* Adafruit_Motor_Shield_V2_Library (Via the Tools->Manage Libraries...  in the arduino IDE)
* ArduinoSTL library https://github.com/mike-matera/ArduinoSTL/ for cpp stl functions.
  - To install: `$cd ~/Arduino/libraries && git clone https://github.com/mike-matera/ArduinoSTL.git`

TODO:
* We will need some form of documentation so all team members can start using abstraced functions.

* Incorpotate line sensor
* Use millis to replace delay
* Carrying LED - will go to pin 0
* Encoders
* Could change current #defines to enums

NOTES:
Each count in the encoder - 0.869cm of distance covered +- 2%

For the slider 4200 ms to open the slide. slider(1) -> open
