#include "HX711.h"
#include <LiquidCrystal.h>
#include <SPI.h>

// HX711.DOUT	- pin #A1
// HX711.PD_SCK	- pin #A0
HX711 scale(A1, A0);
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup () {
   scale.set_scale(- 11994383);                      // this value is obtained by calibrating the scale with known weights; see the README for details
   scale.tare();
   lcd.begin(16, 2);
   lcd.print("Gewicht:");
}

void loop () {
   lcd.setCursor(0, 1);
   lcd.print(scale.get_units(5), 1); 
   delay (300);
}
