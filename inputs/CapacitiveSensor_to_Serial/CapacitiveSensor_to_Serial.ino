/*
* Curators: Eszter Kovács, Filippo De Togni
* Date: 08/02/2024
* Affiliation: IOIO Lab, Malmö University
*
* Sketch Name: CapacitiveSensor_to_Serial
* Behaviour:
   It prints the capacitive value measure in Pin 0.
   Touch the wire coming from Pin 0 to the surface you need 
   the capacitive value of to see it printed on the Serial.

* Components required: 
*  MPR121 (Adafruit) capacitive sensor; 
*  Arduino Nano BLE 33
* 
* See image 'WIRING_CapacitiveSensor_to_Serial' for wiring diagram
* CAPACITIVE SENSOR | ARDUINO NANO
               GND --> GND
               SDA --> A5
               SCL --> A4
             3.3V --> 3.3V
/* SOURCE
Based on the code Written by 
Limor Fried/Ladyada for Adafruit Industries.
This is a library for the MPR121 12-channel Capacitive touch sensor

Designed specifically to work with the MPR121 Breakout in the Adafruit shop 
  ----> https://www.adafruit.com/products/

These sensors use I2C communicate, at least 2 pins are required 
to interface

Adafruit invests time and resources providing this open source code, 
please support Adafruit and open-source hardware by purchasing 
products from Adafruit!

Written by Limor Fried/Ladyada for Adafruit Industries.  
BSD license, all text above must be included in any redistribution
*/

#include <Wire.h>
#include "Adafruit_MPR121.h"

#ifndef _BV
#define _BV(bit) (1 << (bit)) 
#endif

Adafruit_MPR121 cap = Adafruit_MPR121();

void setup() {
  Serial.begin(9600);
  
  Serial.println("Adafruit MPR121 Capacitive Touch sensor test"); 
  
  if (!cap.begin(0x5A)) {
    Serial.println("MPR121 not found, check wiring?");
    while (1);
  }
  Serial.println("MPR121 found!");
}

void loop() {
  uint16_t value = cap.filteredData(0);  // Get the capacitance value for each pin
  Serial.print("Capacitance value (Pin 0): ");
  Serial.println(value);
  
  delay(200);  // Small delay for readability
}


