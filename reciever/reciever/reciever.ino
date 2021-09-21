#define LED_PIN		3
#define INPUT_PIN	A0

uint8_t recievedData = 0;
uint8_t readBit;

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
	recievedData = 0;
	for (int i = 0; i < 8; i++) {
		while ((analogRead (INPUT_PIN) > 500 ? 1 : 0) == readBit)
			;
		delay (100);
		readBit	 = analogRead (INPUT_PIN) > 500 ? 1 : 0;
		recievedData |= readBit << i;
		Serial.println (readBit, BIN);
	}
	Serial.println (recievedData, BIN);
	analogWrite (LED_PIN, recievedData);
	delay (100);
}
