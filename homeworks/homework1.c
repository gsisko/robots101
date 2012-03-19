#include "BuiltIns.h"
#define FULL_SPEED 128
//this is the time it took the robot to turn 90 degrees in lab
#define RIGHT_ANGLE 580

//helper functions
void setWheels(signed char rightWheel, signed char leftWheel)
{
	SetPWM(2, 127 + rightWheel);
	SetPWM(3, 127 - leftWheel);	
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
	setWheels(0);		    //stop
}

//excercise 3
//for this function to work there must be a bump sensor in digital port 6
void forwardMarch()
{
	setWheels(0);		    //start at rest
	setWheels(FULL_SPEED/4);    //go forward at 1/4 speed for 4 seconds
	while(!getDigitalInput(6)){}                                       
	setWheels(FULL_SPEED/2);    //go forward at 1/2 speed for 3 seconds
	while(!getDigitalInput(6)){}                                       
	setWheels(FULL_SPEED*(3/4));//go foreward 3/4 speed for 2 seconds
	while(!getDigitalInput(6)){}                                       
	setWheels(FULL_SPEED);      //go forward at full speed for 1 second
	while(!getDigitalInput(6)){}                                       
	setWheels(FULL_SPEED*(3/4));//go forward 3/4 speed for 2 seconds
	while(!getDigitalInput(6)){}                                       
	setWheels(FULL_SPEED/2);    //go forward at 1/4 speed for 4 second
	while(!getDigitalInput(6)){}                                       
	setWheels(FULL_SPEED/4);    //go forward at 1/4 speed for 4 seconds
	while(!getDigitalInput(6)){}
	setWheels(0);		    //stop
}

//excersise 4
void drawSpiral()
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
