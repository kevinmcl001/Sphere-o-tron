//
// Created for the *Balance-O-Matic* robotics project
// Written by Kevin McLeod and Myles Shepherd, Summer 2014
// I haven't got a clue how all that copyright shit works
//
// Motor.h
// This is just a header file. See Motor.cpp for code that actually does something.
//

#include "Arduino.h"



class sMotor
{
  public:
    sMotor(int IN_A, int IN_B, int PWM, int EN_A, int EN_B, double motorAngle, double motorOffset);
	static void initializePWM();
	void setVelocity(double vel);
	int	getEncoderCount();
	float getSpeed(float dt);
	
	volatile int encoderCount;	//Motor encoder count (public so the interrupts can see it)
	
  private:	
	void setDirection(double value);
	void setSpeed(double speed);
	
	int Pin_INA;				//Pin Direction Input A
	int Pin_INB;				//Pin Direction Input B
	int Pin_PWM;				//Pin Pulse Width Modulation signal
	int Pin_ENA;				//Pin for Encoder Channel A
	int Pin_ENB;				//Pin for Encoder Channel B
	//double thetaMotor;			//Motor mounting angle (RADIANS)
	double kM;					//Motor gain (to adjust for imbalance)
	int prevEncoderCount;		//For determining motor speed
	
	public:
		double thetaMotor;			//Motor mounting angle (RADIANS)
	
};

//1150x3597