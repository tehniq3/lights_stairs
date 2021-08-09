/*
  original created in 2006 by David A. Mellis
  modified 30 Aug 2011   by Tom Igoe
  This example code is in the public domain.
  http://www.arduino.cc/en/Tutorial/ForLoop
  - adapted for maximum 17 leds and 2 buttons by Nicu FLORICA (niq_ro), 03.11.2018
  - adapted for maximum 17 leds and 2 sensors by Nicu FLORICA (niq_ro), 05.12.2020
  - added LDR (fotoresistor), resumt maximum 16 leds and 2 sensors, 09.08.2021 
  https://nicuflorica.blogspot.com/
*/

#define senzor0 A3 // +5V----LDR----A3----|==10k==|----GND, details: https://learn.adafruit.com/photocells/using-a-photocell
#define senzor1 A4 // first sensor
#define senzor2 A5 // other sensor

int intuneric = 512;     // level for night
int timer = 50;           // The higher the number, the slower the timing.
int intarziere = 3000;     // delay for lit on at 100%
int n = 16;  // number of leds (max 16)
/*
 * for n = 16, output1 = D1, output2 = D2, ..., output16 = D16 (A2)
 * for n = 6, output1 = D1, output2 = D2, ..., output6 = D6
 */

void setup() {
  pinMode(senzor1, INPUT);
  pinMode(senzor2, INPUT);
//  digitalWrite(senzor1, HIGH);
//  digitalWrite(senzor2, HIGH); 
  
  // use a for loop to initialize each pin as an output:
  for (int thisPin = 1; thisPin <= n; thisPin++) {
    pinMode(thisPin, OUTPUT);
  }
}

void loop() {

if (analogRead(senzor0) < intuneric)  // night
{
if (digitalRead(senzor1) == HIGH)
{
  inainte();
  delay(intarziere);
  inainte2();
}
if (digitalRead(senzor2) == HIGH)
{
  inapoi();
  delay(intarziere);
  inapoi2();
}
byte j = 100;

 for (int thisPin = n; thisPin >= 1; thisPin--) {
    // turn the pin on:
    digitalWrite(thisPin, HIGH);
    delayMicroseconds(1);
    // turn the pin off:
    digitalWrite(thisPin, LOW);
    delayMicroseconds(50);
  } 
}
if (analogRead(senzor0) > intuneric + 25)  // daytime
{
  delay(5000);
}

}  // end main loop

void inainte()  // forward
{
   // loop from the lowest pin to the highest:
  for (int thisPin = 1; thisPin <= n; thisPin++) {
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
  for (int thisPin = 1; thisPin <= n; thisPin++) {
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
  for (int thisPin = n; thisPin >= 1; thisPin--) {
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
  for (int thisPin = n; thisPin >= 1; thisPin--) {
    // turn the pin on:
    digitalWrite(thisPin, LOW);
    delay(timer);
    // turn the pin off:
    //digitalWrite(thisPin, LOW);
  } 
}
