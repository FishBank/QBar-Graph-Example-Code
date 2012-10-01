/*
  QBar Graph-ArduSensor
 
  Turns on the QBar Graph based on the value of an ArduSensor. This sketch
  makes the QBar Graph a "meter".
  
  You should change int lowVal and int highVal to your ArduSensor needs.
 
 created 17 Feb 2012
 by Quin Etnyre
 */

int lowVal = 0;          // declare the low value of your ArduSensor
int highVal = 1023;      // declare the high value of your ArduSensor

// these constants won't change:
const int analogPin = A0;   // the pin that our ArduSensor is connected
const int ledCount = 10;    // the number of LEDs in the QBar Graph

int ledPins[] = { 
13, 12, 11, 10, 9, 8, 7, 6, 5, 4 };   // an array of our LED pins


void setup() {
  // loop over the pin array and set them all to output:
  for (int thisLed = 0; thisLed < ledCount; thisLed++) {
    pinMode(ledPins[thisLed], OUTPUT); 
  }
  Serial.begin(9600);    // start serial communication
}

void loop() {
  // read the ArduSensor:
  int sensorReading = analogRead(analogPin);
  // map the result to a range from 0 to the number of LEDs:
  int ledLevel = map(sensorReading, highVal, lowVal, 0, ledCount);

  // loop over the QBar Graph:
  for (int thisLed = 0; thisLed < ledCount; thisLed++) {
    // if the array element's index is less than ledLevel,
    // turn the pin for this element on:
    if (thisLed < ledLevel) {
      digitalWrite(ledPins[thisLed], HIGH);
    } 
    // turn off all pins higher than the ledLevel:
    else {
      digitalWrite(ledPins[thisLed], LOW); 
    }
  } 
  
  Serial.println(sensorReading, DEC);     // print the ArduSensor value to the
  delay(100);                             // serial monitor
}
