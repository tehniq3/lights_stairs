/*
  original created in 2006 by David A. Mellis
  modified 30 Aug 2011   by Tom Igoe
  This example code is in the public domain.
  http://www.arduino.cc/en/Tutorial/ForLoop
  adapted for 16 leds and 2 buttons by Nicu FLORICA (niq_ro)
  https://nicuflorica.blogspot.com/
*/

#define senzor1 A4 // first sensor
#define senzor2 A5 // other sensor

int timer = 100;           // The higher the number, the slower the timing.
int intarziere = 3000;     // delay for lit on at 100%77
void setup() {
  pinMode(senzor1, INPUT);
  pinMode(senzor2, INPUT);
  digitalWrite(senzor1, HIGH);
  digitalWrite(senzor2, HIGH); 
  
  // use a for loop to initialize each pin as an output:
  for (int thisPin = 1; thisPin <= 16; thisPin++) {
    pinMode(thisPin, OUTPUT);
  }
}

void loop() {
if (digitalRead(senzor1) == LOW)
{
  inainte();
  delay(intarziere);
  inainte2();
}
if (digitalRead(senzor2) == LOW)
{
  inapoi();
  delay(intarziere);
  inapoi2();
}
byte j = 100;

 for (int thisPin = 16; thisPin >= 1; thisPin--) {
    // turn the pin on:
    digitalWrite(thisPin, HIGH);
    delayMicroseconds(1);
    // turn the pin off:
    digitalWrite(thisPin, LOW);
    delayMicroseconds(50);
  } 
  
}  // end main loop

void inainte()  // forward
{
   // loop from the lowest pin to the highest:
  for (int thisPin = 1; thisPin <= 16; thisPin++) {
    // turn the pin on:
    digitalWrite(thisPin, HIGH);
    delay(timer);
    // turn the pin off:
   // digitalWrite(thisPin, LOW);
  }
}
void inainte2()  // forward
{
   // loop from the lowest pin to the highest:
  for (int thisPin = 1; thisPin <= 16; thisPin++) {
    // turn the pin on:
    digitalWrite(thisPin, LOW);
    delay(timer);
    // turn the pin off:
   // digitalWrite(thisPin, LOW);
  }
}

void inapoi()  // backward
{
  // loop from the highest pin to the lowest:
  for (int thisPin = 16; thisPin >= 1; thisPin--) {
    // turn the pin on:
    digitalWrite(thisPin, HIGH);
    delay(timer);
    // turn the pin off:
    // digitalWrite(thisPin, LOW);
  } 
}

void inapoi2()  // backward
{
  // loop from the highest pin to the lowest:
  for (int thisPin = 16; thisPin >= 1; thisPin--) {
    // turn the pin on:
    digitalWrite(thisPin, LOW);
    delay(timer);
    // turn the pin off:
    //digitalWrite(thisPin, LOW);
  } 
}
