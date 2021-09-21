#define POT_PIN A0
#define OUTPUT_PIN 2
#define SIGNAL_PIN 3

uint8_t potValue;
void sendThroughLaser (const byte, uint8_t);

void setup ()
{
	Serial.begin (9600);
	pinMode (POT_PIN, INPUT);
	pinMode (OUTPUT_PIN, OUTPUT);
	pinMode (SIGNAL_PIN, INPUT);
	digitalWrite (OUTPUT_PIN, LOW);
}

void loop ()
{
	while (!digitalRead (SIGNAL_PIN))
		Serial.println (1);

	//potValue = map (analogRead (POT_PIN), 0, 1023, 0, 255);
	potValue = B10110101;
	sendThroughLaser (OUTPUT_PIN, potValue);
}

void sendThroughLaser (const byte outputPin, uint8_t dataToSend)
{
	bool currentOutputState = LOW;

	for (int i = 0; i < 8; i++){
		digitalWrite (outputPin, !currentOutputState);
		delay (50); //signalling new bit
		currentOutputState = dataToSend & (1 << i); //access LSB of data
		digitalWrite (outputPin, currentOutputState);	
		delay (50);
		Serial.println (currentOutputState);
	}
	digitalWrite (outputPin, LOW);
}
