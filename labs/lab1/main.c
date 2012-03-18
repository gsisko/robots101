#include "BuiltIns.h"
/*
	SetPWM(2, 0);
	SetPWM(3, 255);
	Wait(3000);
	SetPWM(2, 127);
	SetPWM(3, 127);
	*/
void driveStraight(void)
{
	SetPWM(2, 0);
	SetPWM(3, 255);
}
void stop(void)
{
	SetPWM(2, 127);
	SetPWM(3, 127);
}
void rotateRight(void)
{
	SetPWM(2, 255);
	SetPWM(3, 255);
}
void circle(void)
{
	for(;;)
	{
		SetPWM(2, 104);
		SetPWM(3, 255);		
	}
}

void square()
{
	int i = 0;
	for(i; i < 4; i++)
	{
		driveStraight();
		Wait(1400);
		rotateRight();
		Wait(560);
	}
	stop();
}

void main(void)
{
	square();
}

