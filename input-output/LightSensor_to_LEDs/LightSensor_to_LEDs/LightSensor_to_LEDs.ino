/*
* Curators: Agnes Elfvingsson, Filippo De Togni
* Date: 24/10/2024
* Affiliation: IOIO Lab, Malmö University
*
* Sketch Name: LightSensor_to_LEDs
* Behaviour: The LEDs are affected by light input. If maximum light, all LEDs will be on in order green, blue, red. If minimum light they will be off.
* Components required: LilyPad ProtoSnap Plus (LilyPad USB Plus with LEDs and Light Sensor).
* Based on: https://learn.sparkfun.com/tutorials/lilypad-protosnap-plus-activity-guide/8-led-bar-graph
* 
* Extra info here: See video 'LightSensor_to_LEDs' for a preview of expexted behaviour
*/

int sensorPin = A2;  // Define the analog pin where the sensor is connected
int bargraphLED[3] = {A7, A8, 6};  // Define an array for 3 LED pins green, blue, red (A7, A8, and pin 6)

void setup()
{
  int x;  // Variable for loop indexing
  
  pinMode(sensorPin, INPUT);  // Set the sensor pin as an input

  // Set each LED pin in the array to output mode
  for (x = 0; x <= 2; x++) {
    pinMode(bargraphLED[x], OUTPUT);
  }

  Serial.begin(9600);  // Start the serial communication at 9600 baud rate
}

void loop()
{
  int sensorValue;  // Variable to store the sensor value

  sensorValue = analogRead(sensorPin);  // Read the value from the sensor

  // Print the sensor value to the serial monitor
  Serial.print("sensor value: ");
  Serial.println(sensorValue);

  // Call the function to control the LEDs based on the sensor value
  barGraph(sensorValue);
}

void barGraph(int value)
{
  int x;  // Variable for loop indexing

  // Loop through each LED
  for (x = 0; x <= 2; x++) {
    // If the sensor value is less than 50, turn all LEDs off
    if (value < 50) {
      digitalWrite(bargraphLED[x], LOW);
    }
    // If the sensor value is greater than x*340, turn the current LED on
    else if (value > (x * 340)) 
    {
      digitalWrite(bargraphLED[x], HIGH);
    }
    // Otherwise, turn the current LED off
    else
    {
      digitalWrite(bargraphLED[x], LOW);
    }    
  }
}

