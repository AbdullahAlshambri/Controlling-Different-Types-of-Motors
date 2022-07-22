# Controlling Different Types of Motors with an Arduino

These are simple Arduino codes and diagrams to control a stepper motor, a servo motor, and a Brushless DC Motor.

1-[Controlling a Stepper Motor](https://github.com/AbdullahAlshambri/Controlling-Different-Types-of-Motors#1--controlling-stepper-motor
) 
  - [A4988 Driver](https://github.com/AbdullahAlshambri/Controlling-Different-Types-of-Motors#a4988-driver)

  - [Stepper Circuit Diagram](https://github.com/AbdullahAlshambri/Controlling-Different-Types-of-Motors#stepper-circuit-diagram
)

  - [Stepper Code Explanation](https://github.com/AbdullahAlshambri/Controlling-Different-Types-of-Motors#stepper-code-explanation
)

2- [Controlling a Servo Motor](https://github.com/AbdullahAlshambri/Controlling-Different-Types-of-Motors#2--controlling-servo-motor
) 

  - [Servo Circuit Diagram](https://github.com/AbdullahAlshambri/Controlling-Different-Types-of-Motors#bldc-circuit-diagram
)

  - [Servo Code Explanation](https://github.com/AbdullahAlshambri/Controlling-Different-Types-of-Motors#bldc-motor-code-explanation)


3- [Controlling a Brushless DC Motor](https://github.com/AbdullahAlshambri/Controlling-Different-Types-of-Motors#3--controlling-brushless-dc-motor
) 

  - [BLDC Motor Circuit Diagram](https://github.com/AbdullahAlshambri/Controlling-Different-Types-of-Motors#bldc-circuit-diagram
)

  - [BLDC Motor Code Explanation](https://github.com/AbdullahAlshambri/Controlling-Different-Types-of-Motors#bldc-motor-code-explanation)
  

## 1- Controlling Stepper Motor
To control a stepper motor, a driver is needed. A4988 driver is one of the most common drivers to be used.

### A4988 Driver

Following is the pin diagram of the driver. MS1,Ms2 and MS3 are left unconnected if a complete revloution is intended.

![DriverPins](https://a.pololu-files.com/picture/0J10073.600.jpg?75d9ca5bb2e095e5c5f64350019e1b81
)



    
### Stepper Circuit Diagram

![Diagram](https://github.com/AbdullahAlshambri/StepperMotorControl/blob/main/diagram.png?raw=true)




### Stepper Code Explanation  

1-Pins Numbers and steps are determined.
```
const int Direction = 12;
const int steps = 13;
const int stepsNumber = 200;
```
2- Declaring pins as outputs.
```
	pinMode(steps, OUTPUT);
	pinMode(Direction, OUTPUT);
```
3- Motor direction is set then the frequency and speed of the steps are determined according to the delayes between the pulses.

```
digitalWrite(Direction, 1);

for(int x = 0; x < stepsNumber; x++)
{
	digitalWrite(steps, 1);
	delay(1);
	digitalWrite(steps, 0);
	delay(1);
}
delay(1000); 
```
4- The direction of the motor is inverted, then a quick spin takes place.
```
digitalWrite(Direction, 0);

for(int x = 0; x < stepsNumber; x++)
{
	digitalWrite(steps, 1);
	delay(1);
	digitalWrite(steps, 0);
	delay(1);
}
delay(1000); 
```



## 2- Controlling Servo Motor


### Servo Circuit Diagram

![Diagram](https://github.com/AbdullahAlshambri/ServoMOTORControl/blob/main/Diagram.png?raw=true)



### Servo Code Explanation  

1-the library Servo.h is imported.
```
#include <Servo.h>
```
2- The servo is defined along with two varable pins to take read from the potentiometer and map it into an appropriate value.
```
Servo servo;
int potpin = A0;
int val;
```
3- The servo is attached to the arduino.

```
void setup() {
servo.attach(8);

}
```


## 3- Controlling Brushless DC Motor
There are many controllers used to control the BLDC Motors. In this example, one direction ESC is used.


### BLDC Circuit Diagram

![Diagram](https://user-images.githubusercontent.com/83937586/180501804-bb5e93a0-b8a5-4a72-b1cb-922952bf923f.png)



### BLDC Motor Code Explanation  

1-the library Servo.h is imported.
```
#include <Servo.h>
#define SpeedPin A0
#define MotorPin 5
```
2- DC Motor is defined along with two variables to control the speed of the motor with a potentiometer.
```
Servo Motor;
int Speed = 0;
int PotVal = 0;
```
3- The Motor is attached.

```
void setup() {
  Motor.attach(MotorPin); 
  
}
```
4- The value is taken from the potentiometer, then mapped into a proper value before sending the signal to the driver.
```
void loop() {
  PotVal = analogRead(SpeedPin);
  Speed = map(PotVal, 0, 1023, 0, 180);
  Motor.write(Speed);

}
```
