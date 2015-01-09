//
// Created for the *Sphere-o-Tron* robotics project
// Based on code written for the *Balance-o-Matic* project
//
// Written by: Kevin McLeod
// BCIT Mechatronics and Robotics
// ROBT 4491, Winter 2015
//
// sMotor.cpp
// For communication with DC motors
//
// Written for Pololu 19:1 Metal Gearmotors (http://www.pololu.com/product/1442)
// Using VNH5019 Motor Driver Carriers (http://www.pololu.com/product/1451)
//

#include "Arduino.h"
#include "sMotor.h"

#define D2R 0.01745	//Convert from Degrees to Radians


//Motor initialization
//Define all pins and motor parameters
//
// motorAngle defined in DEGREES
// motorOffset is relative to 1.0
// Interrupts not attached
sMotor::sMotor(int IN_A, int IN_B, int PWM, int EN_A, int EN_B, double motorAngle, double motorOffset)
{
	//Direction input A
	Pin_INA = IN_A;
	pinMode(Pin_INA, OUTPUT);
	
	//Direction input B
	Pin_INB = IN_B;
	pinMode(Pin_INB, OUTPUT);
	
	//PWM input
	Pin_PWM = PWM;
	pinMode(Pin_PWM, OUTPUT);
	
	//Encoder input A
	Pin_ENA = EN_A;
	pinMode(Pin_ENA, INPUT);
	
	//Encoder input B
	Pin_ENB = EN_B;
	pinMode(Pin_ENB, INPUT);
	
	//Motor mounting angle
	thetaMotor = motorAngle*R2D;
	
	//Motor offset
	kM = 1.0 + motorOffset;		
		
	//Set encoderCount to zero
	encoderCount = 0;
	prevEncoderCount = 0;
	
	//Really wish I could attach and interrupt here
}

//Set PWM frequency
void sMotor::initializePWM()
{
	//Change PWM frequency
		//Change pin 9, 10 PWM frequency to 3.9 kHz
		//TCCR1B = TCCR1B & 0b11111000 | 0x2;
}

//Set motor direction
void Motor::setDirection(int dir)
{
	//Drive motor in the positive direction
	if(dir >0)
	{
		digitalWrite(Pin_INA,0);
		digitalWrite(Pin_INB,1);
	}
	//Drive motor in the negative direction
	else
	{
		digitalWrite(Pin_INA,1);
		digitalWrite(Pin_INB,0);
	}
}

//Set the speed of the motor
void Motor::setSpeed(int speed)
{
	//Constrain output
	speed = constrain(speed,-255,255);
	
	//Direction is already set (hopefully)
	speed = abs(speed);
	
	//Output PWM signal
	analogWrite(Pin_PWM,(int)(speed*kM));
}

//Set the speed and direction of the motor
void Motor::setVelocity(int vel)
{
	setDirection(vel);
	setSpeed(vel);
}

//Exactly what it says
int Motor::getEncoderCount()
{
	return encoderCount;
}

//Compute motor speed (rev/s)
float Motor::getSpeed(float dt)
{
	//Calculate number of counts motor has moved
	int deltaEncoderCount = encoderCount - prevEncoderCount;
	
	//Calculate motor speed
	//16 counts * 30:1 gear ratio = 480 counts/revolution
	float motorSpeed = (deltaEncoderCount/(480.0))/dt;
	
	//Save current motor speed
	prevEncoderCount = encoderCount;
	
	//Return speed
	return motorSpeed;
}

// --- ISRs moved to MainProgram because C++ is dumb ---

//ISR for reading RIGHT encoder
//Rising edge of EN_A_R (pin 2)
//Check EN_B_R (pin 0)
//Bit 0 of Port D (0x01)
//void Motor::readEncoderRight()
//{
//  if(PIND & 0x01)    encoderCount--;
//  else               encoderCount++;
//}

//ISR for reading LEFT encoder
//Rising edge of EN_A_L (pin 3)
//Check EN_B_L (pin 1)
//Bit 1 of Port D (0x02)
//void Motor::readEncoderLeft()
//{
//  if(PIND & 0x02)    encoderCount--;
//  else               encoderCount++;
//}

//1150x3597