#include <sMotor.h>

void setup()
{
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
  
  sMotor motorA(4,5,3,99,99,0,0);
  sMotor motorB(7,8,6,99,99,120,0);
  sMotor motorC(10,11,9,99,99,-120,0);

}

void loop()
{
  digitalWrite(4,HIGH);
  digitalWrite(5,LOW);
  
  digitalWrite(7,LOW);
  digitalWrite(8,HIGH);
  
  digitalWrite(10,HIGH);
  digitalWrite(11,LOW);
  
  analogWrite(3, 0);
  analogWrite(6, 32);
  analogWrite(9, 32);

}
