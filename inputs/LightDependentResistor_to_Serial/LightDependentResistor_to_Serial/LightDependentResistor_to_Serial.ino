/*
* Curators: Eszter Kovács, Filippo De Togni
* Date: 08/02/2025
* Affiliation: IOIO Lab, Malmö University
*
* Sketch Name: LightDependentResistor_to_Serial
* Behaviour: A light dependent resistor outputs a voltage value based on ambient light
* Components required: LDR, 10kΩ Resistor
* 
* Extra info here: See image 'LightDependentResistor_to_Serial' for wiring diagram
*/

// This signal pin is the one that you use to monitor the changing resistance
#define SIGNAL_PIN A0 

void setup() {
  Serial.begin(9600);
  pinMode(SIGNAL_PIN, INPUT);
}

void loop() {
  int measuredValue = analogRead(SIGNAL_PIN);
  Serial.println(measuredValue);
  delay(50);
}
