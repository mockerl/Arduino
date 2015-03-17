
int pin = 13;
bool an = true;
void setup()
{
	Serial.begin(9600);
	pinMode(pin, OUTPUT);
}

void loop()
{
	digitalWrite(pin, status());
	delay(1000);
}

bool status()
{
	if (an == true)
	{
		an = false;
		Serial.println("aus");
	}
	else
	{
		an = true;
		Serial.println("an");
	}
		return an;
}
