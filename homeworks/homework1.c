#include "BuiltIns.h"
#define FULL_SPEED 128
//this is the time it took the robot to turn 90 degrees in lab
#define RIGHT_ANGLE 580

//helper functions
void waitFor(bpin)
{
	while(!GetDigitalInput(bpin));
	while(GetDigitalInput(bpin));
}

void setWheels(signed char rightWheel, signed char leftWheel)
{
	//this setup is used so that each wheel has a full range from -127 to 128
	SetPWM(2, 127 + rightWheel);
	SetPWM(3, 128 - leftWheel);	
}

inline void setWheels(signed char speed)
{
	setWheels(speed, speed);
}

inline void stop(void)
{
	setWheels(0,1);
}
void rotateRight(degrees)
{
	setWheels(128, -127)
	Wait(degrees);
}

//excercise 2
void forwardRoute(void)
{
	setWheels(0);		    //start at rest
	setWheels(FULL_SPEED/4);    //go forward at 1/4 speed for 4 seconds
	Wait(4000);
	setWheels(FULL_SPEED/2);    //go forward at 1/2 speed for 3 seconds
	Wait(3000);
	setWheels(FULL_SPEED*(3/4));//go forward 3/4 speed for 2 seconds
	Wait(2000);
	setWheels(FULL_SPEED);	    //go forward at full speed for 1 second
	Wait(1000);
	setWheels(FULL_SPEED*(3/4));//go foreward 3/4 speed for 2 seconds
	Wait(2000);
	setWheels(FULL_SPEED/2);    //go forward at 1/4 speed for 4 second
	Wait(3000);
	setWheels(FULL_SPEED/4);    //go forward at 1/4 speed for 4 seconds
	Wait(4000);
	stop();			    //stop
}

//excercise 3
//for this function to work there must be a bump sensor in digital port 6
void forwardMarch(void)
{
	setWheels(0);		    //start at rest
	setWheels(FULL_SPEED/4);    //go forward at 1/4 speed for 4 seconds
	waitFor(6);
	setWheels(FULL_SPEED/2);    //go forward at 1/2 speed for 3 seconds
	waitFor(6);
	setWheels(FULL_SPEED*(3/4));//go foreward 3/4 speed for 2 seconds
	waitFor(6);
	setWheels(FULL_SPEED);      //go forward at full speed for 1 second
	waitFor(6);
	setWheels(FULL_SPEED*(3/4));//go forward 3/4 speed for 2 seconds
	waitFor(6);
	setWheels(FULL_SPEED/2);    //go forward at 1/4 speed for 4 second
	waitFor(6);
	setWheels(FULL_SPEED/4);    //go forward at 1/4 speed for 4 seconds
	waitFor(6);
	stop();			    //stop
}

//excersise 4
void drawSpiral(void)
{    
	//the purpose of this function is to increase the length the robot goes each time it makes another line in the square spiral
	int i;
	for(i = 1; i < 13; i++)
	{
		setWheels(FULL_SPEED);
		Wait(500*i);
		rotateRight(RIGHT_ANGLE);
	}
}

//this is just a main function so that this program will compile
//instead of writing separate main functins for each excersise, I just made them into a function
//they are called in main so that the compiler doesn't ignore them when it realizes they aren't used
void main(void)
{
	drawSpiral();
	forwardMarch();
	forwardRoute();
}
