#include <HCSR04.h>
#include <Servo.h>
HCSR04 hc(2, 3); //initialisation class HCSR04 (trig pin , echo pin)


//We initialize the servo motors

Servo servo1 ;
Servo servo2 ;


long randNum;

void setup()
{
  Serial.begin(9600);
  //We declare the leds as a output

  pinMode(13, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode (11, OUTPUT);
  pinMode (10, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode (8, OUTPUT);

  servo1.attach (5);
  servo2.attach (6);
  servo1.write (0);
  servo2.write (0);

  randomSeed (analogRead(0));
}

void loop()
{
  float distance = hc.dist();
  distance = constrain (distance, 0, 60);

  if (distance <= 25) {

    for (int leds = 8; leds <= 13; leds ++ ) {
      digitalWrite(leds, HIGH);
    }
    randNum = random (-45, 45);

    servo1.write (randNum);
    delay (50);
    servo2.write (randNum);
    delay (50);
    servo2.write (randNum);
    delay (50);
    servo2.write (randNum);
    delay (50);
    servo1.write (randNum);



  } else {
    for (int leds = 8; leds <= 13; leds ++ ) {
      digitalWrite(leds, LOW);
    }

    servo1.write (0);
    servo2.write (0);

  }
 
  Serial.println( distance );  //return curent distance in serial
}
