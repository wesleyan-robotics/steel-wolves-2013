#pragma once
#include "include/JoystickImpl.h"
#include "include/MotorConfigImpl.h"

void doJoystickUpdate()
{
	joystickDebugDisplay();

	if (isGroupEnabled(MOTOR_CONFIG->wheelGroup))
	{
		updateDriving();
	}

	if (MOTOR_CONFIG->lift.isEnabled)
	{
		updateLift();
	}

	if (MOTOR_CONFIG->flag.isEnabled)
	{
		updateFlag();
	}
}

void joystickDebugDisplay()
{
	eraseDisplay();
    nxtDisplayTextLine(0, "L X: %i, Y: %i", joystick.joy1_x1, joystick.joy1_y1);
    nxtDisplayTextLine(1, "R X: %i, Y: %i", joystick.joy1_x2, joystick.joy1_y2);

    if (isGroupEnabled(MOTOR_CONFIG->wheelGroup))
    {
    	int frontLeft = getPower(MOTOR_CONFIG->wheelGroup[FRONT_LEFT]);
    	int frontRight = getPower(MOTOR_CONFIG->wheelGroup[FRONT_RIGHT]);
    	int backLeft = getPower(MOTOR_CONFIG->wheelGroup[BACK_LEFT]);
    	int backRight = getPower(MOTOR_CONFIG->wheelGroup[BACK_RIGHT]);

	    nxtDisplayTextLine(3, "%i L | R %i", frontLeft, frontRight);
	    nxtDisplayTextLine(4, "%i L | R %i", backLeft, backRight);
	}
}

void updateDriving()
{
	if (!isGroupEnabled(MOTOR_CONFIG->wheelGroup)) return;

	updateWithArcadeDriving();
}

void updateLift()
{
	if (!MOTOR_CONFIG->lift.isEnabled) return;

	if (isButtonDown(BUTTON_CONFIG.liftUp))
	{
		setGroupPower(MOTOR_CONFIG->lift, LIFT_POWER);
		return;
	}

	if (isButtonDown(BUTTON_CONFIG.liftDown))
	{
		setGroupPower(MOTOR_CONFIG->lift, -LIFT_POWER);
		return;
	}

	setGroupPower(MOTOR_CONFIG->lift, 0);
}

void updateLift()
{
	if (!MOTOR_CONFIG->lift.isEnabled) return;

	if (isButtonDown(BUTTON_CONFIG.liftDown))
	{
		setPower(MOTOR_CONFIG->lift, -100);
		return;
	}

	if (isButtonDown(BUTTON_CONFIG.liftUp))
	{
		setPower(MOTOR_CONFIG->lift, 100);
		return;
	}

	setPower(MOTOR_CONFIG->lift, 0);
}

void updateFlag()
{
	if(!MOTOR_CONFIG->flag.isEnabled) return;

	if (isButtonDown(BUTTON_CONFIG.flagUp))
	{
		setPower(MOTOR_CONFIG->flag, FLAG_POWER);
		return;
	}

	if (isButtonDown(BUTTON_CONFIG.flagDown))
	{
		setPower(MOTOR_CONFIG->flag, -FLAG_POWER);
		return;
	}

	setPower(MOTOR_CONFIG->flag, 0);
}
