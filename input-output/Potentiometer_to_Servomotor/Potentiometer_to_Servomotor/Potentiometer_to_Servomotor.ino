/*
* Curators: Agnes Elfvingsson, Filippo De Togni
* Date: 10/10/2024
* Affiliation: IOIO Lab, Malmö University
*
* Sketch Name: Potentiometer_to_Servomotor
* Behaviour: The motor is adjusted by a potentiometer
* Components required: Potentiometer, Micro Servo, Polar Capacitor (100µF)
* Based on: https://docs.arduino.cc/learn/electronics/servo-motors/
* 
* Extra info here: See image 'Potentiometer_to_Servomotor' for wiring diagram
* and a preview of expexted behaviour
*/

#include <Servo.h> // The 'Servo' library is needed to control the servomotor
#define MAX_DEGREES 180 // Change this based on the motor you're using (e.g. a 360 degree motor)

Servo myServo; // Create a variable of type 'Servo'
int potPin = A0; // Potentiometer is attached to pin A0
int potVal = 0; // A variable to hold the potentiometer value
int motPin = 12; // The motor's signal input

void setup() {
  Serial.begin(9600);
  pinMode(potPin, INPUT);
  myServo.attach(motPin);
}

void loop() {
  potVal = analogRead(potPin);
  potVal = map(potVal, 0, 1023, 0, MAX_DEGREES);
  myServo.write(potVal);
  delay(100); // Adjust this value to make it more or less responsive
}
