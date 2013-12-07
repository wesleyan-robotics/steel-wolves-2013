#pragma once
#include "JoystickUtil.h"

#include "JoystickDriver.h"

bool isInDeadzone(int x) {
	return abs(x) < DEAD_ZONE;
}

int joystickToPower(int x)
{
	if (abs(x) > DEAD_ZONE) {
		float offset = 20.0;
		float intialOffset = offset * signOf(x);

		float fraction = pow(x, 2) / (float)pow(JOYSTICK_MAX, 2);
		float exponential = fraction * (POWER_MAX - offset) * signOf(x);
		float power = exponential + intialOffset;

		return floor(power);
	}

	return 0;
}

void joystickDebugDisplay()
{
	eraseDisplay();
    nxtDisplayTextLine(0, "L X: %i, Y: %i", joystick.joy1_x1, joystick.joy1_y1);
    nxtDisplayTextLine(1, "R X: %i, Y: %i", joystick.joy1_x2, joystick.joy1_y2);

    if (MOTOR_CONFIG.wheels.isEnabled) {
	    nxtDisplayTextLine(3, "%i L | R %i", motor[MOTOR_CONFIG.wheels.frontLeft],
	    				   					 motor[MOTOR_CONFIG.wheels.frontRight]);

	    nxtDisplayTextLine(4, "%i L | R %i", motor[MOTOR_CONFIG.wheels.backLeft],
	    									 motor[MOTOR_CONFIG.wheels.backRight]);
	}
}

HorizontalDirection getHorizontalDirection(int x)
{
	string toWrite;
	sprintf(toWrite, "X: %i", x);
	writeDebugStreamLine(toWrite);

	if (isInDeadzone(x)) return CENTER;
	if (x > DEAD_ZONE) return RIGHT;
	return LEFT;
}

VerticalDirection getVerticalDirection(int y)
{
	string toWrite;
	sprintf(toWrite, "Y: %i", y);
	writeDebugStreamLine(toWrite);

	if (isInDeadzone(y)) return CENTER;
	if (y > DEAD_ZONE) return UP;
	return DOWN;
}
