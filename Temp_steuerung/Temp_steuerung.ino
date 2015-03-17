#include <OneWire.h>
#include <DallasTemperature.h>

// Data wire is plugged into port 5 on the Arduino
#define ONE_WIRE_BUS 5

// Setup a oneWire instance to communicate with any OneWire devices (not just Maxim/Dallas temperature ICs)
OneWire oneWire(ONE_WIRE_BUS);

// Pass our oneWire reference to Dallas Temperature. 
DallasTemperature sensors(&oneWire);

void setup(void)
{
  // start serial port
  Serial.begin(9600);
  pinMode(2, OUTPUT);
  // Start up the library
  sensors.begin();
}

void loop(void)
{ 
  sensors.requestTemperatures();
  double outside=sensors.getTempCByIndex(1);
  double inside=sensors.getTempCByIndex(0);
  Serial.print("device 1 (outside) is: ");
  Serial.println(outside); 
  Serial.print("device 2 (inside) is: "); 
  Serial.println(inside);  
  if (outside +3 < inside) 
  {
     digitalWrite(2, LOW); //schaltet das relay an
  }else 
  {
   digitalWrite(2, HIGH); //schaltet das relay aus
  }
  delay(300000);
}


