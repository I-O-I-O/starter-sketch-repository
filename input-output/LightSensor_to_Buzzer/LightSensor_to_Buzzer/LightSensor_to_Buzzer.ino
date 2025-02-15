/*
* Curators: Agnes Elfvingsson, Filippo De Togni
* Date: 24/10/2024
* Affiliation: IOIO Lab, Malmö University
*
* Sketch Name: LightSensor_to_Buzzer
* Behaviour: The Buzzer is affected by light input. Depending on light input, the buzzer will play the notes
* like Do Re Mi Fa So La. The Buzzer is activated by the Button
* Components required: LilyPad ProtoSnap Plus (LilyPad USB Plus with LEDs and Light Sensor).
* Based on: https://learn.sparkfun.com/tutorials/lilypad-protosnap-plus-activity-guide/9-theremin-project
* For some guidance on how to sew, you can check out this guide: https://learn.sparkfun.com/tutorials/getting-started-with-lilypad
* 
* Extra info here: See video 'LightSensor_to_Buzzer' for a preview of expexted behaviour
*/

// Define pin numbers for the sensor, button, and buzzer

#if defined(ARDUINO_SAMD_CIRCUITPLAYGROUND_EXPRESS)
#define LIGHT_SENSOR A8
#define BUTTON 5
#define BUZZER A0
#else
#define LIGHT_SENSOR A2
#define BUTTON A4
#define BUZZER A3
#endif



// The LED bargraph uses pins 15 to 20, which represent each LED
int bargraphLED[6] = {15, 16, 17, 18, 19, 20};

// Define the frequencies for musical notes Do, Re, Mi, Fa, So, La, Ti
int Do = 523;  // Frequency for note C5
int Re = 587;  // Frequency for note D5
int Mi = 659;  // Frequency for note E5
int Fa = 698;  // Frequency for note F5
int So = 784;  // Frequency for note G5
int La = 880;  // Frequency for note A5
int Ti = 988;  // Frequency for note B5

// Store the note frequencies in an array
int frequencies[7] = {Do, Re, Mi, Fa, So, La, Ti};

void setup() {
  int x;
  
  // Set the sensor pin as input
  pinMode(LIGHT_SENSOR, INPUT);
  // Set the buzzer pin as output
  pinMode(BUZZER, OUTPUT);
  // Set the button pin as input with an internal pull-up resistor
  pinMode(BUTTON, INPUT_PULLUP);
  
  // Loop through each LED pin in the bargraph array and set them as output
  for (x = 0; x <= 5; x++) {
    pinMode(bargraphLED[x], OUTPUT);
  }

  // Begin serial communication for debugging or output
  Serial.begin(9600);
}

void loop() {
  int sensorValue;  // Variable to store the sensor reading
  int frequency;    // Variable to store the mapped frequency

  // Read the analog value from the sensor
  sensorValue = analogRead(LIGHT_SENSOR);

  // Print the sensor value to the Serial Monitor
  Serial.print("sensor value: ");
  Serial.println(sensorValue);

  // Call the barGraph function to update the LEDs based on sensor value
  barGraph(sensorValue);

  // Map the sensor value (0-1023) to a range of 0-6 to select a note from the array
  frequency = map(sensorValue, 0, 1023, 0, 6);

  // Check if the button is pressed (LOW state)
  if (digitalRead(BUTTON) == LOW) {
    // Play the tone corresponding to the mapped frequency
    tone(BUZZER, frequencies[frequency]);
  } else {
    // Stop playing the tone when the button is not pressed
    noTone(BUZZER);
  }
}

// Function to control the bargraph LEDs based on sensor value
void barGraph(int value) {
  int x;

  // Loop through each LED in the bargraph
  for (x = 0; x <= 5; x++) {
    // Turn on the LED if the value exceeds a threshold (x * 170)
    if (value > (x * 170)) {
      digitalWrite(bargraphLED[x], HIGH);
    } else {
      // Turn off the LED if the value is below the threshold
      digitalWrite(bargraphLED[x], LOW);
    }    
  }
}
