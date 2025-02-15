/*
* Curators: Eszter Kovács, Filippo De Togni
* Date: 15/02/2024
* Affiliation: IOIO Lab, Malmö University
*
* Sketch Name: Code_to_Buzzer
* Behaviour:
   Buzzes on 1KHz for one second and then stops, then repeats.

* Components required: 
*  Piezo Buzzer; 
*  100Ohm resistor
*  Arduino Nano BLE 33
* 
* See image 'WIRING_Code_to_Buzzer' for wiring diagram
*            BUZZER | ARDUINO NANO
               GND --> GND
   POWER -> 100Ohm --> D9
 SOURCE
 Written by Michalis Vasilakis (www.ardumotive.com)
 https://www.instructables.com/How-to-use-a-Buzzer-Arduino-Tutorial/

*/
const int buzzer = 9; // Buzzer connected to pin 9

void setup() {
  pinMode(buzzer, OUTPUT); // Set buzzer pin as an output
}

void loop() {
  analogWrite(buzzer, 128); // Set PWM (50% duty cycle)
  delay(1000); // Wait 1 second
  analogWrite(buzzer, 0); // Turn off PWM
  delay(1000); // Wait 1 second
}



