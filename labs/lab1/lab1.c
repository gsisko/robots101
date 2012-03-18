#include "BuiltIns.h"

//excersise 1
//sets port 3 motor to full
void motorFull(void)
{
	SetPWM(3, 255);
}

//excersise 2
//sets port 3 motor to full and port 2 motor to full for three seconds then stops
void goStop(void)
{
	SetPWM(3, 255);
	SetPWM(2, 0);
	Wait(3000);
	SetPWM(3, 127);
	SetPWM(2, 127);
}

//bumper test
//prints whether bumper is pressed or not
void bumperTest(void)
{
	bool bumper=0;
	for(;;)
	{
		bumper = GetDigitalInput(6);
		printf("Bumper Switch = %d\n", (int)bumper);
	}
}

//excersise 3
//goes forward only when bumber is pressed
void pressGo(void)
{
	bool bumper=0;
	for(;;)
	{
		bumper = GetDigitalnput(6);
		if(bumper)
		{
			SetPWM(3, 255);
			SetPWM(2, 0);
		}
		else
		{
			SetPWM(2, 127);
			SetPWM(3, 127);
		}
	}
}

//excersise 4
//goes forward untill it hits a wall, then backs up and turns and then goes forward again
void reverseTurn(void)
{
	bool bumper=0;
	for(;;)
	{
		bumper = GetDigitalnput(6);
		if(bumper)
		{
			SetPWM(3, 255);
			SetPWM(2, 0);
		}
		else
		{
			SetPWM(2,255);
			SetPWM(3, 0);
			Wait(1000);
			SetPWM(2,255);
			SetPWM(3, 255);
			Wait(500);
		}
	}
}	

//excersise 5
//puts the robot in tank drive mode
void tankDrive(void)
{
	for(;;)
	{
		Tank2(0, 3, 2, 3, 2, 0, 0);
	}
}

//excersise 6
//puts the robot in tank drive mode untill it hits a wall, where it then backs up and turns
void smartTank(void)
{
	bool bumper=0;
	for(;;)
	{
		bumper = GetDigitalnput(6);
		if(bumper)
		{
			Tank2(0, 3, 2, 3, 2, 0, 0);
		}
		else
		{
			SetPWM(2,255);
			SetPWM(3, 0);
			Wait(1000);
			SetPWM(2,255);
			SetPWM(3, 255);
			Wait(500);
		}
	}
}
