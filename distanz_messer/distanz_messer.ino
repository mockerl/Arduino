/*
LiquidCrystal Library - Hello World

Demonstrates the use a 16x2 LCD display.  The LiquidCrystal
library works with all LCD displays that are compatible with the
Hitachi HD44780 driver. There are many of them out there, and you
can usually tell them by the 16-pin interface.

This sketch prints "Hello World!" to the LCD
and shows the time.

The circuit:
* LCD RS pin to digital pin 12
* LCD Enable pin to digital pin 11
* LCD D4 pin to digital pin 5
* LCD D5 pin to digital pin 4
* LCD D6 pin to digital pin 3
* LCD D7 pin to digital pin 2
* 10K resistor:
* ends to +5V and ground
* wiper to LCD VO pin (pin 3)

Library originally added 18 Apr 2008
by David A. Mellis
library modified 5 Jul 2009
by Limor Fried (http://www.ladyada.net)
example added 9 Jul 2009
by Tom Igoe
modified 25 July 2009
by David A. Mellis


http://www.arduino.cc/en/Tutorial/LiquidCrystal
*/

// include the library code:
#include "Wire.h"
#include "LiquidCrystal.h"


int trigPin = 9;
int echoPin = 8;

// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup() {
	Serial.begin(9600);
	// set up the LCD's number of rows and columns: 
	lcd.begin(16, 2);
	// Print a message to the LCD.
	lcd.print("Distanz: ");

	pinMode(trigPin, OUTPUT);
	pinMode(echoPin, INPUT);
}

void loop() {
	// set the cursor to column 0, line 1
	// (note: line 1 is the second row, since counting begins with 0):
	
	// print the number of seconds since reset:
	double d = echo();
	lcd.setCursor(0, 1);
	lcd.print(d);
	delay(100);
	lcd.setCursor(5, 1);
	lcd.print(" cm");
	delay(500);
}

double echo()
{
	double duration;
	double distance;
	digitalWrite(trigPin, LOW);  // Added this line
	delayMicroseconds(2); 
	digitalWrite(trigPin, HIGH);
	delayMicroseconds(10); // Added this line
	digitalWrite(trigPin, LOW);
	duration = pulseIn(echoPin, HIGH);
	distance = duration / 58.2;

	if (distance >= 200 || distance <= 0){
		return -0;
	}
	else {
		Serial.print(distance);
		Serial.println(" cm");
	}
	return distance;
}
