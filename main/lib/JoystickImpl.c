#pragma once
#include "include/JoystickImpl.h"
#include "config/MotorConfigImpl.h"

void SL_DoJoystickUpdate()
{
	joystickDebugDisplay();

	if (SL_IsGroupEnabled(SL_MOTOR_CONFIG->wheelGroup))
	{
		updateDriving();
	}

	if (SL_MOTOR_CONFIG->lift.isEnabled)
	{
		updateLift();
	}

	if (SL_MOTOR_CONFIG->flag.isEnabled)
	{
		updateFlag();
	}
}

void joystickDebugDisplay()
{
	eraseDisplay();
    nxtDisplayTextLine(0, "L X: %i, Y: %i", joystick.joy1_x1, joystick.joy1_y1);
    nxtDisplayTextLine(1, "R X: %i, Y: %i", joystick.joy1_x2, joystick.joy1_y2);

    if (SL_IsGroupEnabled(SL_MOTOR_CONFIG->wheelGroup))
    {
    	int frontLeft = SL_GetPower(SL_MOTOR_CONFIG->wheelGroup[FRONT_LEFT]);
    	int frontRight = SL_GetPower(SL_MOTOR_CONFIG->wheelGroup[FRONT_RIGHT]);
    	int backLeft = SL_GetPower(SL_MOTOR_CONFIG->wheelGroup[BACK_LEFT]);
    	int backRight = SL_GetPower(SL_MOTOR_CONFIG->wheelGroup[BACK_RIGHT]);

	    nxtDisplayTextLine(3, "%i L | R %i", frontLeft, frontRight);
	    nxtDisplayTextLine(4, "%i L | R %i", backLeft, backRight);
	}
}

void updateDriving()
{
	if (!SL_IsGroupEnabled(SL_MOTOR_CONFIG->wheelGroup)) return;

	updateWithArcadeDriving();
}

void updateLift()
{
	if (!SL_MOTOR_CONFIG->lift.isEnabled) return;

	if (SL_IsButtonDown(SL_BUTTON_CONFIG->liftUp))
	{
		SL_SetGroupPower(SL_MOTOR_CONFIG->lift, LIFT_POWER);
		return;
	}

	if (SL_IsButtonDown(SL_BUTTON_CONFIG->liftDown))
	{
		SL_SetGroupPower(SL_MOTOR_CONFIG->lift, -LIFT_POWER);
		return;
	}

	SL_SetGroupPower(SL_MOTOR_CONFIG->lift, 0);
}

void updateLift()
{
	if (!SL_MOTOR_CONFIG->lift.isEnabled) return;

	if (SL_IsButtonDown(SL_BUTTON_CONFIG->liftDown))
	{
		SL_SetPower(SL_MOTOR_CONFIG->lift, -100);
		return;
	}

	if (SL_IsButtonDown(SL_BUTTON_CONFIG->liftUp))
	{
		SL_SetPower(SL_MOTOR_CONFIG->lift, 100);
		return;
	}

	SL_SetPower(SL_MOTOR_CONFIG->lift, 0);
}

void updateFlag()
{
	if(!SL_MOTOR_CONFIG->flag.isEnabled) return;

	if (SL_IsButtonDown(SL_BUTTON_CONFIG->flagUp))
	{
		SL_SetPower(SL_MOTOR_CONFIG->flag, FLAG_POWER);
		return;
	}

	if (SL_IsButtonDown(SL_BUTTON_CONFIG->flagDown))
	{
		SL_SetPower(SL_MOTOR_CONFIG->flag, -FLAG_POWER);
		return;
	}

	SL_SetPower(SL_MOTOR_CONFIG->flag, 0);
}
