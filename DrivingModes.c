#pragma once
#include "DrivingModes.h"

#include "JoystickDriver.h"
#include "JoystickUtil.h"
#include "MotorUtil.h"

void updateWithArcadeDriving()
{
	if (!MOTOR_CONFIG.wheels.isEnabled) return;
	writeDebugStreamLine("Updating driving");

	int y = joystick.joy1_y1;
	int x = joystick.joy1_x2;

	int power = joystickToPower(y) * POWER_LIMIT_FACTOR;
	HorizontalDirection direction = getHorizontalDirection(x);

	if (isInDeadzone(x) && isInDeadzone(y)) {
		stopWheels();
		return;
	}

	drive(direction, power);
}

void updateWithTankDriving()
{
	if (!MOTOR_CONFIG.wheels.isEnabled) return;

	int leftPower = joystickToPower(joystick.joy1_y1);
	int rightPower = joystickToPower(joystick.joy1_y2);

	motor[MOTOR_CONFIG.wheels.frontLeft] = leftPower;
	motor[MOTOR_CONFIG.wheels.backLeft] = leftPower;
	motor[MOTOR_CONFIG.wheels.frontRight] = rightPower;
	motor[MOTOR_CONFIG.wheels.backRight] = rightPower;
}
