#include "BuiltIns.h"
#define ITS .0641025641
#define 90DEG 580

void DriveStraight(int distance)
{
	SetPWM(2, 255);
	SetPWM(3, 0);
	Wait(distance);
}

void stop(void)
{
	SetPWM(2, 127);
	SetPWM(3, 127);
}

void waitFor(void)
{
	while(!GetDigitalInput(6));
	while(!GetDigitalInput(6));
}

void Turn90(void)
{
	SetPWM(2, 255);
	SetPWM(3, 255);
	Wait(90DEG);
	stop();
}
	

void Square(float length-of-side)
{
	int i;
	for(i=0; i < 4; i++)
	{
		DriveStraight(length-of-side*ITS);
		Turn90();
	}
}
//rather than creating a new project for spiral, I'm just inluding it in this one
//I am also not usin Two WHeel drive, because you really only need to sed one of the wheel speeds once
void Spiral(int wait-time)
//wait-time will effectively control the size of the spiral
{
	char i;
	SetPWM(2, 255);
	for(i = 255; i > 0; i--)
	{
		SetPWM(3, i);
		Wait(wait-time);
	}
}

void main(void)
{
	Squrare(24);
	waitFor();
	DriveStraight(*ITS);
	stop();
}
