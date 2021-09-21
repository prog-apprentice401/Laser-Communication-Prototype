#define LED_PIN		3
#define INPUT_PIN	A0

uint16_t recievedData = 0;
uint16_t readBit;

void setup ()
{
	Serial.begin (9600);
	pinMode (LED_PIN, OUTPUT);
	pinMode (INPUT_PIN, INPUT);
	digitalWrite (LED_PIN, LOW);
}

void loop ()
{
	while (analogRead (INPUT_PIN) < 500)
		;

	recievedData = 0;
	for (int i = 0; i < 16; i++) {
		delay (150);
		readBit = (analogRead (INPUT_PIN) > 400) ? 1 : 0;
		recievedData |= readBit << i;
		Serial.print ("Bit Recieved: ");
		Serial.print (readBit);
		Serial.print ("#");
		Serial.println (i);
		while ((analogRead (INPUT_PIN) > 400 ? 1 : 0) == readBit
				&& i < 15)
			;
	}
	Serial.print ("Recieved data: ");
	Serial.println (recievedData);
	analogWrite (LED_PIN, recievedData);
}
