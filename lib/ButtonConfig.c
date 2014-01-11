#pragma once
#include "../include/ButtonConfig.h"
#include "../include/JoystickDriver.h"

#define EMULATOR_TARGET  (defined(NXT) || defined(TETRIX)) && defined(_Target_Emulator_)

bool isButtonDown(ButtonConfigDef def)
{
	if (def.type == INVALID) return false;

	if (def.type == DPAD)
	{
		if (def.joystickIndex == INVALID) return false;

		if (def.joystickIndex == JOYSTICK_1)
		{
			writeDebugStreamLine("DPAD");
			return joystick.joy1_TopHat == def.button;
		}

#if !EMULATOR_TARGET
		if (def.joystickIndex == JOYSTICK_2)
		{
			writeDebugStreamLine("DPAD");
			return joystick.joy2_TopHat == def.button;
		}
#endif

		return false;
	}

	if (def.type == BUTTON)
	{
		if (def.joystickIndex == INVALID) return false;

		if (def.joystickIndex == JOYSTICK_1)
		{
			writeDebugStreamLine("BUTTONS");
			return joy1Btn(def.button) == BUTTON_DOWN;
		}

#if !EMULATOR_TARGET
		if (def.joystickIndex == JOYSTICK_2)
		{
			writeDebugStreamLine("BUTTONS");
			return joy2Btn(def.button) == BUTTON_DOWN;
		}
#endif

		return false;
	}

	return false;
}
