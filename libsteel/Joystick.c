#pragma once
#include "include/Joystick.h";

#include "interface/ButtonConfigInterface.h"
#include "interface/JoystickInterface.h"

task joystickListener()
{
	initButtonConfig();

	while(true)
	{
		wait1Msec(LOOP_DELAY_TIME);
		getJoystickSettings(joystick);
		doJoystickUpdate();
	}
}
