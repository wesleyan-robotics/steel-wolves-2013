#pragma once
#include "Joystick.h";

#include "Math.c";

int joystickExp(int x)
{
	if(abs(x) > DEAD_ZONE)
	{
		return (((pow(x, 2) / pow(127, 2)) * 80 * signOf(x)) + 20 * signOf(x));
	}
	else return 0;
}
