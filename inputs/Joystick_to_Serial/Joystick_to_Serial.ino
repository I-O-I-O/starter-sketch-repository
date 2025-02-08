/*
* Curators: Eszter Kovács, Filippo De Togni
* Date: 08/02/2025
* Affiliation: IOIO Lab, Malmö University
*
* Sketch Name: Joystick_to_Serial
* Behaviour: A light dependent resistor outputs a voltage value based on ambient light
* Components required: Joystick
* 
* Extra info here:
* – This sketch assumes the 5V Pin on the Arduino Nano 33 Ble Rev2 has been enables.
* – Read more about it here:https://docs.arduino.cc/hardware/nano-33-ble/#tech-specs.
*/

#define VRX_PIN  A0 // Arduino pin connected to VRX pin
#define VRY_PIN  A1 // Arduino pin connected to VRY pin
// #define SW_PIN   D10  // Arduino pin connected to SW  pin

int xValue = 0;
int yValue = 0;

void setup() {
  Serial.begin(115200);

  pinMode(VRX_PIN, INPUT);
  pinMode(VRY_PIN, INPUT);
  // pinMode(SW_PIN, INPUT_PULLUP);
}

void loop() {
  // Use these two values to 
  xValue = analogRead(VRX_PIN);
  yValue = analogRead(VRY_PIN);

  Serial.println("===============");
  displayValues(xValue, yValue);
  Serial.println("");

  delay(100);
}

void displayValues(int x, int y) {
  int mappedX = map(x, 0, 1023, 0, 5); // Map to 0-5 for a 5x5 grid
  int mappedY = map(y, 0, 1023, 0, 5); 

  for (int i = 0; i < 5; i++) {
    for (int j = 0; j < 5; j++) {
      if (i == mappedY && j == mappedX) {
        Serial.print(" x ");
      } else {
        Serial.print("  ");
      }
    }
    Serial.println();
  }
}