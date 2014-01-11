#pragma once
#include "../include/Joystick.h";

#include "../include/MotorConfig.h"
#include "../include/JoystickDriver.h"
#include "../include/JoystickUtil.h"
#include "../include/Math.h";
#include "../include/DrivingModes.h"
#include "../include/ButtonConfig.h"

void initJoystick()
{
    CONFIG_BUTTON(liftUp, JOYSTICK_1, DPAD, DPAD_UP)
    CONFIG_BUTTON(liftDown, JOYSTICK_1, DPAD, DPAD_DOWN)
    CONFIG_BUTTON(flagUp, JOYSTICK_1, BUTTON, BUTTON_Y)
    CONFIG_BUTTON(flagDown, JOYSTICK_1, BUTTON, BUTTON_A)
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

	//writeDebugStreamLine("true = %d", true);
	//writeDebugStreamLine("false = %d", false);
	//writeDebugStreamLine("isGroupEnabled(MOTOR_CONFIG.wheelGroup) -> %d", isGroupEnabled(MOTOR_CONFIG.wheelGroup));

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
