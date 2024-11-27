/*
* Curators: Agnes Elfvingsson, Filippo De Togni
* Date: 10/10/2024
* Affiliation: IOIO Lab, Malmö University
*
* Sketch Name: Potentiometer_to_Serial
* Behaviour: The motor is adjusted by a potentiometer
* Components required: Potentiometer, Micro Servo
* 
* Extra info here: See image 'Potentiometer_to_Serial' for wiring diagram
* and a preview of expexted behaviour
*/

#define MAX_VALUE 100 // Change this to map the potentiometer value to a different range

int potPin = A0; // Potentiometer is attached to pin A0
int potVal = 0; // A variable to hold the potentiometer value

void setup() {
  Serial.begin(9600);
  pinMode(potPin, INPUT);
}

void loop() {
  potVal = analogRead(potPin);
  potVal = map(potVal, 0, 1023, MAX_VALUE, 0); 
  Serial.println(potVal);
  delay(100); // Adjust this value to make it more or less responsive
}
