/*
* Curators: Agnes Elfvingsson, Filippo De Togni
* Date: 10/10/2024
* Affiliation: IOIO Lab, Malmö University
*
* Sketch Name: Code_to_Servomotor
* Behaviour: The motor oscillates between two predefined values
* Components required: Micro Servo, Polar Capacitor (100µF)
* Based on: https://docs.arduino.cc/learn/electronics/servo-motors/
* 
* Extra info here: See image and video 'Code_to_Servomotor' for wiring diagram
* and a preview of expexted behaviour
*/

#include <Servo.h> // The 'Servo' library is needed to control the servomotor

Servo myServo; // Create a variable of type 'Servo'

// Change these two values to make the motor move to different positions
// Keep the two values between 0 – 180
int positionOne = 50;
int positionTwo = 120;

int motPin = 12; // The motor's signal input

void setup() {
  myServo.attach(12);
}

void loop() {
  myServo.write(positionOne);
  delay(2000);
  myServo.write(positionTwo);
  delay(2000);
}
