#pragma once
#include "DrivingModes.h"

#include "Joystick.h"
#include "JoystickDriver.h"
#include "JoystickUtil.h"
#include "MotorUtil.h"

void updateWithArcadeDriving()
{
	if (!isGroupEnabled(MOTOR_CONFIG.wheelGroup)) return;
	writeDebugStreamLine("Updating driving");

	int y = joystick.joy1_y1;
	int x = joystick.joy1_x2;

	int power = joystickToPower(y);
	HorizontalDirection direction = getHorizontalDirection(x);

	if (isInDeadzone(x) && isInDeadzone(y))
	{
		stopWheels();
		return;
	}

	if (isInDeadzone(x) && !isInDeadzone(y))
	{
		drive(direction, TURNING_POWER);
		return;
	}

	drive(direction, power);
}

void updateWithTankDriving()
{
	if (!isGroupEnabled(MOTOR_CONFIG.wheelGroup)) return;

	int leftPower = joystickToPower(joystick.joy1_y1);
	int rightPower = joystickToPower(joystick.joy1_y2);

	setPower(MOTOR_CONFIG.wheelGroup[FRONT_LEFT], leftPower);
	setPower(MOTOR_CONFIG.wheelGroup[BACK_LEFT], leftPower);
	setPower(MOTOR_CONFIG.wheelGroup[FRONT_RIGHT], rightPower);
	setPower(MOTOR_CONFIG.wheelGroup[BACK_RIGHT], rightPower);
}
