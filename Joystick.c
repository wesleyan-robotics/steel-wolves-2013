#pragma once
#include "Joystick.h";

#include "JoystickDriver.h"
#include "JoystickUtil.h"
#include "Math.h";
#include "DrivingModes.h"
#include "ButtonConfig.h"

void initJoystick()
{
    CONFIG_BUTTON(liftUp, JOYSTICK_1, DPAD, DPAD_UP)
    CONFIG_BUTTON(liftDown, JOYSTICK_1, DPAD, DPAD_DOWN)
    CONFIG_BUTTON(auxiliaryLift, JOYSTICK_1, BUTTON, BUTTON_Y)
    CONFIG_BUTTON(flag, JOYSTICK_1, BUTTON, BUTTON_A)
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

	if (MOTOR_CONFIG.flag.isEnabled)
	{
		updateFlag();
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
	if(!MOTOR_CONFIG.flag.isEnabled) return;

	if (isButtonDown(BUTTON_CONFIG.flag))
	{
		setPower(MOTOR_CONFIG.flag, FLAG_POWER);
		return;
	}
	
	setPower(MOTOR_CONFIG.flag, 0);
}
