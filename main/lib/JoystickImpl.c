#pragma once
#include "Includes.h"
#include "include/JoystickImpl.h"

void doJoystickUpdate()
{
	joystickDebugDisplay();

	if (isGroupEnabled(MOTOR_CONFIG.wheelGroup))
	{
		updateDriving();
	}

	if (MOTOR_CONFIG.lift.isEnabled)
	{
		updateLift();
	}

	if (MOTOR_CONFIG.flag.isEnabled)
	{
		updateFlag();
	}
}

void updateDriving()
{
	if (!isGroupEnabled(MOTOR_CONFIG.wheelGroup)) return;

	updateWithArcadeDriving();
	//updateWithTankDriving();
}

void updateLift()
{
	if (!MOTOR_CONFIG.lift.isEnabled) return;

	if (isButtonDown(BUTTON_CONFIG.liftUp))
	{
		setGroupPower(MOTOR_CONFIG.lift, LIFT_POWER);
		return;
	}

	if (isButtonDown(BUTTON_CONFIG.liftDown))
	{
		setGroupPower(MOTOR_CONFIG.lift, -LIFT_POWER);
		return;
	}

	setGroupPower(MOTOR_CONFIG.lift, 0);
}

void updateLift()
{
	if (!MOTOR_CONFIG.lift.isEnabled) return;

	if (isButtonDown(BUTTON_CONFIG.liftDown))
	{
		setPower(MOTOR_CONFIG.lift, -100);
		return;
	}

	if (isButtonDown(BUTTON_CONFIG.liftUp))
	{
		setPower(MOTOR_CONFIG.lift, 100);
		return;
	}

	setPower(MOTOR_CONFIG.lift, 0);
}

void updateFlag()
{
	if(!MOTOR_CONFIG.flag.isEnabled) return;

	if (isButtonDown(BUTTON_CONFIG.flagUp))
	{
		setPower(MOTOR_CONFIG.flag, FLAG_POWER);
		return;
	}

	if (isButtonDown(BUTTON_CONFIG.flagDown))
	{
		setPower(MOTOR_CONFIG.flag, -FLAG_POWER);
		return;
	}

	setPower(MOTOR_CONFIG.flag, 0);
}
