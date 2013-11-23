#pragma once
#include "JoystickUtil.h"

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
    nxtDisplayTextLine(3, "%i L | R %i", motor[motorFrontLeft], motor[motorFrontRight]);
    nxtDisplayTextLine(4, "%i L | R %i", motor[motorBackLeft], motor[motorBackRight]);
}

HorizontalDirection getHorizontalDirection(int x)
{
	if (x == 0) return CENTER;
	else if (x > 0) return RIGHT;
	else return LEFT;
}

VerticalDirection getVerticalDirection(int y)
{
	if (y == 0) return CENTER;
	else if (y > 0) return UP;
	else return DOWN;
}
