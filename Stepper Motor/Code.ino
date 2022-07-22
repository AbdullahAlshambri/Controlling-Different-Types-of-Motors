const int Direction = 12;
const int steps = 13;
const int stepsNumber = 200;

void setup()
{
	pinMode(steps, OUTPUT);
	pinMode(Direction, OUTPUT);
}
void loop()
{
	digitalWrite(Direction, 1);

	for(int x = 0; x < stepsNumber; x++)
	{
		digitalWrite(steps, 1);
		delay(1);
		digitalWrite(steps, 0);
		delay(1);
	}
	delay(1000); 
	
	digitalWrite(Direction, 0);

	for(int x = 0; x < stepsNumber; x++)
	{
		digitalWrite(steps, 1);
		delay(1);
		digitalWrite(steps, 0);
		delay(1);
	}
	delay(1000); 
}