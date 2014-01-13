#pragma once
#include "include/ButtonConfig.h"
#include "include/JoystickDriver.h"

#define SL_EMULATOR_TARGET  \
	(defined(NXT) || defined(TETRIX)) && defined(_Target_Emulator_)

bool SL_IsButtonDown(SL_ButtonConfigDef *def)
{
	if (def->type == SL_INVALID) return false;

	if (def->type == SL_DPAD)
	{
		if (def->joystickIndex == SL_INVALID) return false;

		if (def->joystickIndex == SL_JOYSTICK_1)
		{
			return joystick.joy1_TopHat == def->button;
		}

#if !SL_EMULATOR_TARGET
		if (def->joystickIndex == SL_JOYSTICK_2)
		{
			return joystick.joy2_TopHat == def->button;
		}
#endif

		return false;
	}

	if (def->type == SL_BUTTON)
	{
		if (def->joystickIndex == SL_INVALID) return false;

		if (def->joystickIndex == SL_JOYSTICK_1)
		{
			return joy1Btn(def->button) == SL_BUTTON_DOWN;
		}

#if !SL_EMULATOR_TARGET
		if (def->joystickIndex == SL_JOYSTICK_2)
		{
			return joy2Btn(def->button) == SL_BUTTON_DOWN;
		}
#endif

		return false;
	}

	return false;
}
