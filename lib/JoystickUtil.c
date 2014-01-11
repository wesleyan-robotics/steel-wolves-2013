#pragma once
#include "include/JoystickUtil.h"

#include "include/JoystickDriver.h"
#include "include/MotorConfig.h"
#include "include/Joystick.h"

bool isInDeadzone(int x)
{
	return abs(x) < DEAD_ZONE;
}

int joystickToPower(int x)
{
	if (isInDeadzone(x))
	{
		return 0;
	}

	float offset = 20.0;
	float intialOffset = offset * signOf(x);

	float fraction = pow(x, 2) / (float) pow(JOYSTICK_MAX, 2);
	float exponential = fraction * (MAX_POWER - offset) * signOf(x);
	float power = exponential + intialOffset;

	return floor(power);
}

void joystickDebugDisplay()
{
	eraseDisplay();
    nxtDisplayTextLine(0, "L X: %i, Y: %i", joystick.joy1_x1, joystick.joy1_y1);
    nxtDisplayTextLine(1, "R X: %i, Y: %i", joystick.joy1_x2, joystick.joy1_y2);

    if (isGroupEnabled(MOTOR_CONFIG.wheelGroup))
    {
	    nxtDisplayTextLine(3, "%i L | R %i", getPower(MOTOR_CONFIG.wheelGroup[FRONT_LEFT]),
	    				   					 getPower(MOTOR_CONFIG.wheelGroup[FRONT_RIGHT]));

	    nxtDisplayTextLine(4, "%i L | R %i", getPower(MOTOR_CONFIG.wheelGroup[BACK_LEFT]),
	    									 getPower(MOTOR_CONFIG.wheelGroup[BACK_RIGHT]));
	}
}

HorizontalDirection getHorizontalDirection(int x)
{
	if (isInDeadzone(x)) return HDIR_CENTER;
	if (x > DEAD_ZONE) return HDIR_RIGHT;
	return HDIR_LEFT;
}

VerticalDirection getVerticalDirection(int y)
{
	if (isInDeadzone(y)) return VDIR_CENTER;
	if (y > DEAD_ZONE) return VDIR_UP;
	return VDIR_DOWN;
}
