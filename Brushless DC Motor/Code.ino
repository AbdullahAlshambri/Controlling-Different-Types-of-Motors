#include <Servo.h>
#define SpeedPin A0
#define MotorPin 5

Servo Motor;
int Speed = 0;
int PotVal = 0;

void setup() {
  Motor.attach(MotorPin); 

}

void loop() {
  PotVal = analogRead(SpeedPin);
  Speed = map(PotVal, 0, 1023, 0, 180);
  Motor.write(Speed);
}
