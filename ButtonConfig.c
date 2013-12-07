#pragma once
#include "ButtonConfig.h"
#include "JoystickDriver.h"

bool isButtonDown(ButtonConfigDef def)
{
	if (def.refType == INVALID) return false;

	if (def.refType == DPAD)
	{
		if (def.joystickIndex == INVALID) return false;

		if (def.joystickIndex == JOYSTICK_1)
		{
			writeDebugStreamLine("DPAD");
			return joystick.joy1_TopHat == def.button;
		}

		if (def.joystickIndex == JOYSTICK_2)
		{
			writeDebugStreamLine("DPAD");
			return joystick.joy2_TopHat == def.button;
		}

		return false;
	}

	if (def.refType == BUTTONS)
	{
		if (def.joystickIndex == INVALID) return false;

		if (def.joystickIndex == JOYSTICK_1)
		{
			writeDebugStreamLine("BUTTONS");
			return joy1Btn(def.button) == BUTTON_DOWN;
		}

		if (def.joystickIndex == JOYSTICK_2)
		{
			writeDebugStreamLine("BUTTONS");
			return joy2Btn(def.button) == BUTTON_DOWN;
		}
		
		return false;
	}

	return false;
}
