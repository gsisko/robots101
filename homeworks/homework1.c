#include "BuiltIns.h"
#define FULL_SPEED 128
//this is the time it took the robot to turn 90 degrees in lab
#define 90DEG 580

//helper functions
void setWheels(signed char rightWheel, signed char leftWheel)
{
	SetPWM(2, 127 + rightWheel);
	SetPWM(3, 128 - leftWheel);	
}

inline void setWheels(signed char speed)
{
	setWheels(speed, speed);
}

void rotateRight(degrees)
{
	setWheels(128, -128)
	Wait(degrees);
}

//excercise 2
void forwardRoute()
{
	setWheels(0);
	setWheels(FULL_SPEED/4);
	Wait(4000);
	setWheels(FULL_SPEED/2);
	Wait(3000);
	setWheels(FULL_SPEED*(3/4));
	Wait(2000);
	setWheels(FULL_SPEED);
	Wait(1000);
	setWheels(FULL_SPEED*(3/4));
	Wait(2000);
	setWheels(FULL_SPEED/2);
	Wait(3000);
	setWheels(FULL_SPEED/4);
	Wait(4000);
	setWheels(0);
}

//excercise 3
//for this function to work there must be a bump sensor in digital port 6
void forwardMarch()
{
	setWheels(0);
	setWheels(FULL_SPEED/4);
	while(!getDigitalInput(6)){}
	setWheels(FULL_SPEED/2);
	while(!getDigitalInput(6)){}
	setWheels(FULL_SPEED*(3/4));
	while(!getDigitalInput(6)){}
	setWheels(FULL_SPEED);
	while(!getDigitalInput(6)){}
	setWheels(FULL_SPEED*(3/4));
	while(!getDigitalInput(6)){}
	setWheels(FULL_SPEED/2);
	while(!getDigitalInput(6)){}
	setWheels(FULL_SPEED/4);
	while(!getDigitalInput(6)){}
	setWheels(0);
}

//excersise 4
void drawSpiral()
{
	int i;
	for(i = 1; i < 13) i++)
	{
		setWheels(FULL_SPEED);
		Wait(500*i);
		rotateRight(90DEG);
	}
}
