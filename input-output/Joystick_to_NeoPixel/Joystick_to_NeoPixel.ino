/*
* Curators: Eszter Kovács, Filippo De Togni
* Date: 08/02/2025
* Affiliation: IOIO Lab, Malmö University
*
* Sketch Name: Joystick_to_NeoPixel
* Behaviour: A joystick is used to change the brightness of a NeoPixel ring
* Components required: Joystick, NeoPixel ring, 2.7k resistor, 5.6k resistor
* 
* Extra info here:
* – This sketch assumes the 5V Pin on the Arduino Nano 33 Ble Rev2 has been enabled.
* – Read more about it here:https://docs.arduino.cc/hardware/nano-33-ble/#tech-specs.
* - The two resistors are used to convert the signal from the joystick from a 5V logic level
*  to a 3.3V logic level. If your board supports 5V logic, the resistors are not needed.
*/

#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
 #include <avr/power.h> // Required for 16 MHz Adafruit Trinket
#endif

// Joystick Pin Definitions
#define VRX_PIN  A0 // Arduino pin connected to VRX pin
#define VRY_PIN  A1 // Arduino pin connected to VRY pin
#define SW_PIN  D12  // Arduino pin connected to SW  pin

// NeoPixel Pin Definitions
#define NEOPIXELPIN 11
#define NUMPIXELS 16

Adafruit_NeoPixel ring(NUMPIXELS, NEOPIXELPIN, NEO_GRB + NEO_KHZ800);

int xValue = 0;
int yValue = 0;

int hue = 0;
int brightness = 100;

int r, g, b;

void setup() {
  Serial.begin(115200);

  pinMode(VRX_PIN, INPUT);
  pinMode(VRY_PIN, INPUT);
  pinMode(SW_PIN, INPUT_PULLUP);

  r = 255;
  g = 255;
  b = 255;

  ring.begin();
  ring.clear();
  for (int i = 0; i < NUMPIXELS; i++) {
      ring.setPixelColor(i, ring.Color(255, 0, 0));
      ring.show();
  }
  
}

void loop() {
  // Use these two values to read the X and Y movement of the joystick
  xValue = analogRead(VRX_PIN);
  yValue = analogRead(VRY_PIN);

  // Here, the X value is used to change the brightness of the whole strip
  // As explained here https://learn.adafruit.com/adafruit-neopixel-uberguide/arduino-library-use
  // this is not the optimal way to change brightness but it works in this showcase.
  ring.setBrightness(map(xValue, 0, 1023, 10, 255));
  ring.show();

  delay(100);
}
