#define POT_PIN A0
#define OUTPUT_PIN 2
#define SIGNAL_PIN 3

uint16_t potValue;
void sendThroughLaser (const byte, uint16_t);

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
		;

	potValue = analogRead (POT_PIN);
	sendThroughLaser (OUTPUT_PIN, potValue);
}

void sendThroughLaser (const byte outputPin, uint16_t dataToSend)
{
	bool currentOutputState = LOW;

	for (int i = 0; i < 16; i++){
		digitalWrite (outputPin, !currentOutputState);
		delay (50); //signalling new bit
		digitalWrite (outputPin, HIGH);
		currentOutputState = dataToSend & (1 << i); //access LSB of data
		digitalWrite (outputPin, currentOutputState);	
		delay (150);
		Serial.println ("asdf");
	}
	digitalWrite (outputPin, !currentOutputState);
	digitalWrite (outputPin, LOW);
}
