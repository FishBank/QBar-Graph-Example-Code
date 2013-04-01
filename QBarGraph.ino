/*  QBarGraph

"Bounces" LEDs on QBar Graph back and forth over, and over.

made on 1 Apr 13
created by Quin (Qtechknow)
*/

// LED Bar Graph pins in an array
const int ledPins[] = { 13, 12, 11, 10, 9, 8, 7, 6, 5, 4 };

void setup() {
  for(int i=0; i<10; i++) {
    pinMode(ledPins[i], OUTPUT);  // declare them all as output
  }
}

void loop() {
  
  for(int y=0; y<10; y++) {
        digitalWrite(ledPins[y], HIGH);  // turn them on in a sequence
        delay(30);
      }
      for(int z=0; z<10; z++) {
        digitalWrite(ledPins[z], LOW);   // turn them off in a sequence
        delay(30);
      }
      for(int x=10; x>0; x--) {
        digitalWrite(ledPins[x], HIGH);  // turn them on going the other way
        delay(30);
      }
      digitalWrite(ledPins[0], HIGH);
      
      for(int w=10; w>0; w--) {
        digitalWrite(ledPins[w], LOW);   // turn them off going the other way
        delay(30);
      }   
     digitalWrite(ledPins[0], LOW);
}
