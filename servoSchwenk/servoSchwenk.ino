#include <Servo.h>

Servo myservo;

int angle=0;

void setup () {
  myservo.attach(9); 
}

void loop() {
   for (angle=0;angle<180;angle+=90)  {
     myservo.write(angle);
     delay(3000); 
   }
   for (angle=0;angle>180;angle-=90)  {
     myservo.write(angle);
     delay(3000); 
   }
 
 
  /* for (angle=0;angle<180;angle++)  {
     myservo.write(angle);
     delay(20); 
   }
   for (angle=0;angle>180;angle--)  {
     myservo.write(angle);
     delay(20); 
   }
  */ 
}
