#include <Wire.h>
#include <Adafruit_MotorShield.h>
#include "utility/Adafruit_PWMServoDriver.h"

// Create the motor shield object with the default I2C address
Adafruit_MotorShield AFMS = Adafruit_MotorShield(); 
// Or, create it with a different I2C address (say for stacking)
// Adafruit_MotorShield AFMS = Adafruit_MotorShield(0x61); 

// Connect a stepper motor with 200 steps per revolution (1.8 degree)
// to motor port #2 (M3 and M4)
Adafruit_StepperMotor *myMotor = AFMS.getStepper(200, 2);
Adafruit_StepperMotor *myMotor2 = AFMS.getStepper(200, 1);
int schritteR;
int schritteL;
int schritteU;
int schritteD; 
void setup() {
  Serial.begin(9600);           // set up Serial library at 9600 bps

  AFMS.begin();  // create with the default frequency 1.6KHz
  AFMS.begin(1000);  // OR with a different frequency, say 1KHz
  
  myMotor->setSpeed(10);  // 10 rpm   
  myMotor2->setSpeed(10);
}

void loop() {

  if (Serial.available() > 0) {
    if (Serial.peek() == 'r') {
      Serial.read();
      schritteR = Serial.parseInt();
      myMotor->step(schritteR, FORWARD, INTERLEAVE);
      schritteR = 0;
      Serial.println('k');
    }
    
    if (Serial.peek() == 'l') {
      Serial.read();
      schritteL = Serial.parseInt();
      myMotor->step(schritteL, BACKWARD, INTERLEAVE);
      schritteL = 0;
      Serial.println('k');
    }
    
    if (Serial.peek() == 'u') {
      Serial.read();
      schritteU = Serial.parseInt();
      myMotor2->step(schritteU, FORWARD, INTERLEAVE);
      schritteU = 0;
      Serial.println('k');
    }
    
    if (Serial.peek() == 'd') {
      Serial.read();
      schritteD = Serial.parseInt();
      myMotor2->step(schritteD, BACKWARD, INTERLEAVE);
      schritteD = 0;
      Serial.println('k');
    }
    
    while(Serial.available() > 0) {
      Serial.read(); 
  }
}
}
