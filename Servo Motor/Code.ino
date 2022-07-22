
#include <Servo.h>
Servo servo;
int potpin = A0;
int val;

void setup() {
servo.attach(8);

}

void loop() {
  val = analogRead(potpin);           
  val = map(val, 0, 1023, 90, 180);
  servo.write( val); 

}
