#pragma once
#include "../include/DrivingModes.h"

#include "../include/Joystick.h"
#include "../include/JoystickDriver.h"
#include "../include/JoystickUtil.h"
#include "../include/MotorUtil.h"
#include "../include/MotorConfig.h"

void updateWithArcadeDriving()
{
	if (!isGroupEnabled(MOTOR_CONFIG.wheelGroup)) return;

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
