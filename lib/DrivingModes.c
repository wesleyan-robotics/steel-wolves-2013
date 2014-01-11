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

	int power = joystickToPower(y) * POWER_LIMIT_FACTOR;
	HorizontalDirection direction = getHorizontalDirection(x);

	// Allow for turning if the x value is moving while the y value is not
	// The joysticks look like this:
	//    [x]   [y]
	//    <->    *
	if (!isInDeadzone(x) && isInDeadzone(y))
	{
		drive(direction, TURNING_POWER);
		return;
	}

	// Ignore values if both the joysticks are in the deadzones
	if (isInDeadzone(x) && isInDeadzone(y))
	{
		stopWheels();
		return;
	}

	drive(direction, power);
}

void updateWithTankDriving()
{
	if (!isGroupEnabled(MOTOR_CONFIG.wheelGroup)) return;

	int left = joystick.joy1_y1;
	int right = joystick.joy1_y2;

	int leftPower = joystickToPower(left);
	int rightPower = joystickToPower(right);

	setWheelPower(leftPower, rightPower);
}
