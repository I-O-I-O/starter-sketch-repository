/*
* Curators: Eszter Kovács, Filippo De Togni
* Date: 15/02/2025
* Affiliation: IOIO Lab, Malmö University
*
* Sketch Name: CapacitiveSensor_to_Buzzer
* Behaviour:
   Try: Hold the capacitive just in the air, against wood, or plastic!
   Now, touch it to skin, graphite or other highly conductive materials!

   The buzzer beeps at a rate aligned with how capacitive the touched
   surface is, meaning that it beeps faster if it meets highly capacitive
   maerials and slows down, taking longer pauses if the surface is not
   capacitive.

* Components required: 
*  MPR121 (Adafruit) capacitive sensor; 
*  Piezo Buzzer; 
*  100Ohm resistor
*  Arduino Nano BLE 33
* 
* See image 'WIRING_CapacitiveSensor_to_Buzzer' for wiring diagram
* CAPACITIVE SENSOR | ARDUINO NANO | BUZZER
               GND -->    GND   <---- GND
               SDA -->     A5
               SCL -->     A4
             3.3V  -->    3.3V
                           D9 <-100Ohm--POWER
* SOURCE
Capacitve Sensor part based on the code written by 
Limor Fried/Ladyada for Adafruit Industries (https://www.adafruit.com/products/)

Buzzer part based on the code written by Michalis Vasilakis (www.ardumotive.com)
 https://www.instructables.com/How-to-use-a-Buzzer-Arduino-Tutorial/
*/
// Initialization for the capacitive sensor
#include <Wire.h>
#include "Adafruit_MPR121.h"

#ifndef _BV
#define _BV(bit) (1 << (bit)) 
#endif

Adafruit_MPR121 cap = Adafruit_MPR121();

// Initialization for the buzzer
const int buzzer = 9; // Buzzer connected to pin 9


void setup() {
  Serial.begin(9600);

  // Set up buzzer 
  pinMode(buzzer, OUTPUT); // Set Pin 9 as OUTPUT

  // Set up the capacitive sensor
  Serial.println("Adafruit MPR121 Capacitive Touch sensor test"); 
  
  if (!cap.begin(0x5A)) {
    Serial.println("MPR121 not found, check wiring?");
    while (1);
  }
  Serial.println("MPR121 found!");
}

void loop() {
  //INPUT
  // Get capacitive value
  uint16_t capValue = cap.filteredData(0);  // Get the capacitance value for each pin
  
  // TRANSFORMATION
  // Map capacitance value (capValue) to delay value (delVal)
  int delValue = map(capValue, 80, 280, 10, 1000);
  delValue = constrain(delValue, 10, 1000); // Ensure values stay within the range
  
  // OUTPUT
  // Update delay new delValue
  analogWrite(buzzer, 128); // Set PWM (50% duty cycle)
  delay(100); // Wait 1 second
  analogWrite(buzzer, 0);
  delay(delValue); // Adjust pause according the measured capacitive value
}


