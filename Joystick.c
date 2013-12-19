#pragma once
#include "Joystick.h";

#include "JoystickDriver.h"
#include "JoystickUtil.h"
#include "Math.h";
#include "DrivingModes.h"
#include "ButtonConfig.h"

void initJoystick()
{
	BUTTON_CONFIG.liftUp.button			= DPAD_UP;
	BUTTON_CONFIG.liftUp.joystickIndex	= JOYSTICK_1;
	BUTTON_CONFIG.liftUp.refType		= DPAD;

	BUTTON_CONFIG.liftDown.button			= DPAD_DOWN;
	BUTTON_CONFIG.liftDown.joystickIndex	= JOYSTICK_1;
	BUTTON_CONFIG.liftDown.refType			= DPAD;

	BUTTON_CONFIG.auxiliaryLift.button			= BUTTON_Y;
	BUTTON_CONFIG.auxiliaryLift.joystickIndex	= JOYSTICK_1;
	BUTTON_CONFIG.auxiliaryLift.refType			= BUTTONS;

	BUTTON_CONFIG.flag.button			= BUTTON_A;
	BUTTON_CONFIG.flag.joystickIndex	= JOYSTICK_1;
	BUTTON_CONFIG.flag.refType			= BUTTONS;
}

task joystickListener()
{
	initJoystick();

	while(true)
	{
		wait1Msec(LOOP_DELAY_TIME);
		getJoystickSettings(joystick);
		doJoystickUpdate();
	}
}

void doJoystickUpdate()
{
	writeDebugStreamLine("Joystick Update Fired");
	joystickDebugDisplay();

	if (isGroupEnabled(MOTOR_CONFIG.wheelGroup))
	{
		updateDriving();
	}

	if (isGroupEnabled(MOTOR_CONFIG.liftGroup))
	{
		updateLift();
	}

	if (MOTOR_CONFIG.auxiliaryLift.isEnabled)
	{
		updateAuxiliaryLift();
	}
}

void updateDriving()
{
	if (!isGroupEnabled(MOTOR_CONFIG.wheelGroup)) return;

	updateWithArcadeDriving();
}

void updateLift()
{
	if (!isGroupEnabled(MOTOR_CONFIG.liftGroup)) return;

	if (isButtonDown(BUTTON_CONFIG.liftUp))
	{
		setGroupPower(MOTOR_CONFIG.liftGroup, LIFT_POWER);
		return;
	}

	if (isButtonDown(BUTTON_CONFIG.liftDown))
	{
		setGroupPower(MOTOR_CONFIG.liftGroup, -LIFT_POWER);
		return;
	}

	setGroupPower(MOTOR_CONFIG.liftGroup, 0);
}

void updateAuxiliaryLift()
{
	if (!MOTOR_CONFIG.auxiliaryLift.isEnabled) return;

	if (isButtonDown(BUTTON_CONFIG.auxiliaryLift))
	{
		setPower(MOTOR_CONFIG.auxiliaryLift, 100);
		return;
	}

	setPower(MOTOR_CONFIG.auxiliaryLift, 0);
}

void updateFlag()
{
	if (!MOTOR_CONFIG.flag.isEnabled) return;

	if (isButtonDown(BUTTON_CONFIG.flag))
	{
		setPower(MOTOR_CONFIG.flag, FLAG_POWER);
	}
}
