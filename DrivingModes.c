#pragma once
#include "DrivingModes.h"

#include "JoystickDriver.h"
#include "JoystickUtil.h"

void updateWithArcadeDriving()
{
	if (!MOTOR_CONFIG.wheels.isEnabled) return;

	int y = joystick.joy1_y1;
	int x = joystick.joy2_x1;

	int maxPower = joystickToPower(y) * POWER_LIMIT_FACTOR;
	float limit = abs(joystickToPower(x) / (float)POWER_MAX);
	int sidePower = floor(maxPower * limit);


	switch (getHorizontalDirection(x)) {
		case CENTER:
			motor[MOTOR_CONFIG.wheels.frontRight] = 0;
			motor[MOTOR_CONFIG.wheels.backRight] = 0;
			motor[MOTOR_CONFIG.wheels.frontLeft] = 0;
			motor[MOTOR_CONFIG.wheels.backLeft] = 0;
			break;
		case RIGHT:
			motor[MOTOR_CONFIG.wheels.frontRight] = sidePower;
			motor[MOTOR_CONFIG.wheels.backRight] = sidePower;
			motor[MOTOR_CONFIG.wheels.frontLeft] = 0;
			motor[MOTOR_CONFIG.wheels.backLeft] = 0;
			break;
		case LEFT:
			motor[MOTOR_CONFIG.wheels.frontRight] = 0;
			motor[MOTOR_CONFIG.wheels.backRight] = 0;
			motor[MOTOR_CONFIG.wheels.frontLeft] = sidePower;
			motor[MOTOR_CONFIG.wheels.backLeft] = sidePower;
			break;
	}
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
