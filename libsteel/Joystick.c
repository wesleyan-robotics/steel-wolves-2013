#pragma once
#include "include/Joystick.h";

#include "interface/ButtonConfigInterface.h"
#include "interface/JoystickInterface.h"

task SL_JoystickListener()
{
	SL_InitButtonConfig();

	while(true)
	{
		wait1Msec(SL_LOOP_DELAY_TIME);
		getJoystickSettings(joystick);
		SL_DoJoystickUpdate();
	}
}
