#include <sMotor.h>

  sMotor motorA(4,5,3,99,99,0,0);
  sMotor motorB(7,8,6,99,99,120,.2);
  sMotor motorC(10,11,9,99,99,-120,0);

void setup()
{
 
  

}

void loop()
{
  int vel = 64;
  drive(vel,0);
  delay(1000);
  drive(vel,90);
  delay(1000);
  drive(vel,180);
  delay(1000);
  drive(vel,-90);
  delay(1000);
}

void drive(double velocity, double angle)
{
   angle*=0.01745;
   motorA.setVelocity(velocity*sin(angle-motorA.thetaMotor));
   motorB.setVelocity(velocity*sin(angle-motorB.thetaMotor));
   motorC.setVelocity(velocity*sin(angle-motorC.thetaMotor));
}
