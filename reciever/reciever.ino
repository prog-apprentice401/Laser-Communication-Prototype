#define LED_PIN		3
#define INPUT_PIN	A0

uint8_t recievedData = 0;
uint8_t readBit;
byte numOfBitsRecieved = 0;

void setup ()
{
	Serial.begin (9600);
	pinMode (LED_PIN, OUTPUT);
	pinMode (INPUT_PIN, INPUT);
	digitalWrite (LED_PIN, LOW);
}

void loop ()
{
	readBit = 0;
	for (int i = 0; i < 8; i++) {
		while ((analogRead (INPUT_PIN) > 500 ? 1 : 0) == readBit)
			;
		delay (50);
		readBit	 = analogRead (INPUT_PIN) > 500 ? 1 : 0;
		recievedData |= readBit << i;
		Serial.println (i);
	}
	delay (100);
	Serial.println (recievedData);
}
