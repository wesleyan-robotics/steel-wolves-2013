#pragma once
#include "Joystick.h";

#include "Math.h";
#include "JoystickDriver.c"

int joystickToPower(int x)
{
	if(abs(x) > DEAD_ZONE)
	{
		float offset = 20.0;
		float intialOffset = offset * signOf(x);

		float fraction = pow(x, 2) / (float)pow(JOYSTICK_MAX, 2);
		float exponential = fraction * (POWER_MAX - offset) * signOf(x);
		float power = exponential + intialOffset;

		return floor(power);
	}
	else return 0;
}

void joystickDebugDisplay()
{
	eraseDisplay();
    nxtDisplayTextLine(0, "PowX1: %i", joystickToPower(joystick.joy1_x1));
    nxtDisplayTextLine(1, "PowY1: %i", joystickToPower(joystick.joy1_y1));
    nxtDisplayTextLine(3, "PowX2: %i", joystickToPower(joystick.joy1_x2));
    nxtDisplayTextLine(4, "PowY2: %i", joystickToPower(joystick.joy1_y2));

    nxtDisplayTextLine(6, "L X: %i, Y: %i", joystick.joy1_x1, joystick.joy1_y1);
    nxtDisplayTextLine(7, "R X: %i, Y: %i", joystick.joy1_x2, joystick.joy1_y2);
}

void doJoystickUpdate()
{
	joystickDebugDisplay();

    int power = joystickToPower(joystick.joy1_y1) * 0.75;
    motor[motorE] = power;
    motor[motorD] = power;
}

task joystickListener()
{
	while(true) {
		wait1Msec(51);
		getJoystickSettings(joystick);
		doJoystickUpdate();
	}
}
