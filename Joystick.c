#pragma once
#include "Joystick.h";

#include "MotorConfig.h"
#include "JoystickDriver.h"
#include "JoystickUtil.h"
#include "Math.h";
#include "DrivingModes.h"
#include "ButtonConfig.h"

void initJoystick()
{
    CONFIG_BUTTON(liftUp, JOYSTICK_1, DPAD, DPAD_UP)
    CONFIG_BUTTON(liftDown, JOYSTICK_1, DPAD, DPAD_DOWN)
    CONFIG_BUTTON(flagUp, JOYSTICK_1, BUTTON, BUTTON_Y)
    CONFIG_BUTTON(flagDown, JOYSTICK_1, BUTTON, BUTTON_A)
    CONFIG_BUTTON(rightBucket, JOYSTICK_1, BUTTON, BUTTON_X)
    CONFIG_BUTTON(leftBucket, JOYSTICK_1, BUTTON, BUTTON_B)
    CONFIG_BUTTON(rackMoveLeft, JOYSTICK_1, BUTTON, BUTTON_LB)
    CONFIG_BUTTON(rackMoveRight, JOYSTICK_1, BUTTON, BUTTON_RB)
}

void initServos()
{
    setPower(MOTOR_CONFIG.bucketGroup[SIDE_LEFT], 0);
    setPower(MOTOR_CONFIG.bucketGroup[SIDE_RIGHT], 0);
}

task joystickListener()
{
	initJoystick();
	initServos();

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

	if (MOTOR_CONFIG.bucketRack.isEnabled)
	{
	    updateRack();
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

void updateFlag()
{
	if (!MOTOR_CONFIG.flag.isEnabled) return;

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

void updateRack()
{
    if (!MOTOR_CONFIG.bucketRack.isEnabled) return;

	if (isButtonDown(BUTTON_CONFIG.rackMoveLeft))
	{
		setPower(MOTOR_CONFIG.bucketRack, 75); // TODO: Remove this magic number
		return;
	}

	if (isButtonDown(BUTTON_CONFIG.rackMoveRight))
	{
		setPower(MOTOR_CONFIG.bucketRack, -75); // TODO: Remove this magic number
		return;
	}

	setPower(MOTOR_CONFIG.bucketRack, 0);
}
