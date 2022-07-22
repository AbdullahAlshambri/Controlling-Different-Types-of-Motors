# Controlling a Stepper Motor via A4988 Driver

These are two simple Arduino codes to control a stepper motor with a driver of the model A4988 and a servo motor. 
1-[Controlling a Stepper Motor](https://github.com/AbdullahAlshambri/Controlling-Stepper-and-Servo-Motors/edit/main/README.md#1--controlling-stepper-motor
) 
  - [A4988 Driver](https://github.com/AbdullahAlshambri/Controlling-Stepper-and-servo-motors/edit/main/README.md#a4988-driver)

  - [Stepper Circuit Diagram](https://github.com/AbdullahAlshambri/Controlling-Stepper-and-servo-motors/edit/main/README.md#stepper-circuit-diagram
)

  - [Stepper Code Explanation](https://github.com/AbdullahAlshambri/Controlling-Stepper-and-servo-motors/edit/main/README.md#stepper-code-explanation
)

2- [Controlling a Servo Motor](https://github.com/AbdullahAlshambri/Controlling-Stepper-and-Servo-Motors/edit/main/README.md#1--controlling-servo-motor
) 

  - [Servo Circuit Diagram](https://github.com/AbdullahAlshambri/Controlling-Stepper-and-servo-motors/edit/main/README.md#servo-circuit-diagram
)

  - [Servo Code Explanation](https://github.com/AbdullahAlshambri/Controlling-Stepper-and-servo-motors/edit/main/README.md#servo-code-explanation)


3- [Controlling a Brushless DC Motor](https://github.com/AbdullahAlshambri/Controlling-Stepper-and-Servo-Motors/edit/main/README.md#1--controlling-brushless-dc-motor
) 

  - [BLCD Motor Circuit Diagram](https://github.com/AbdullahAlshambri/Controlling-Stepper-and-servo-motors/edit/main/README.md#servo-circuit-diagram
)

  - [BLCD Motor Code Explanation](https://github.com/AbdullahAlshambri/Controlling-Stepper-and-servo-motors/edit/main/README.md#servo-code-explanation)

## 1- Controlling Stepper Motor

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
4- The analog value is taken from the poteiometer, then it is mapped into values between 90 and 180. the mapped values determine the angle between the servo starting point and the point reached.
```
void loop() {
  val = analogRead(potpin);           
  val = map(val, 0, 1023, 90, 180);
  servo.write( val); 

}
```
