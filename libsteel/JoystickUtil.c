#pragma once
#include "include/JoystickUtil.h"

#include "include/JoystickDriver.h"
#include "include/MotorConfig.h"
#include "include/Joystick.h"

bool SL_IsInDeadzone(int x)
{
	return abs(x) < SL_DEAD_ZONE;
}

int SL_JoystickToPower(int x)
{
	if (SL_IsInDeadzone(x))
	{
		return 0;
	}

	float offset = 20.0;
	float intialOffset = offset * SL_SignOf(x);

	float fraction = pow(x, 2) / (float) pow(SL_JOYSTICK_MAX, 2);
	float exponential = fraction * (SL_MAX_POWER - offset) * SL_SignOf(x);
	float power = exponential + intialOffset;

	return floor(power);
}

SL_HDirection SL_GetHDirection(int x)
{
	if (SL_IsInDeadzone(x)) return SL_HDIR_CENTER;
	if (x > SL_DEAD_ZONE) return SL_HDIR_RIGHT;
	return SL_HDIR_LEFT;
}

SL_VDirection SL_GetVDirection(int y)
{
	if (SL_IsInDeadzone(y)) return SL_VDIR_CENTER;
	if (y > SL_DEAD_ZONE) return SL_VDIR_UP;
	return SL_VDIR_DOWN;
}

SL_HDirection SL_InvertDirection(SL_HDirection direction)
{
    if (direction == SL_HDIR_CENTER) return SL_HDIR_CENTER;
    if (direction == SL_HDIR_LEFT) return SL_HDIR_RIGHT;
    if (direction == SL_HDIR_RIGHT) return SL_HDIR_LEFT;
    return SL_HDIR_INVALID;
}

SL_VDirection SL_InvertDirection(SL_VDirection direction)
{
    if (direction == SL_VDIR_CENTER) return SL_VDIR_CENTER;
    if (direction == SL_VDIR_DOWN) return SL_VDIR_UP;
    if (direction == SL_VDIR_UP) return SL_VDIR_DOWN;
    return SL_VDIR_INVALID;
}
