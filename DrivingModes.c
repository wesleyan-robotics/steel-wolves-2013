#pragma once
#include "DrivingModes.h"

#include "JoystickDriver.c"
#include "JoystickUtil.h"

void updateWithArcadeDriving()
{
	int y = joystick.joy1_y1;
	int x = joystick.joy2_x1;

	int maxPower = joystickToPower(y) * POWER_LIMIT_FACTOR;
	float limit = abs(joystickToPower(x) / (float)POWER_MAX);
	int sidePower = floor(maxPower * limit);


	switch (getHorizontalDirection(x)) {
		case CENTER:
			motor[motorFrontRight] = 0;
			motor[motorBackRight] = 0;
			motor[motorFrontLeft] = 0;
			motor[motorBackLeft] = 0;
			break;
		case RIGHT:
			motor[motorFrontRight] = sidePower;
			motor[motorBackRight] = sidePower;
			motor[motorFrontLeft] = 0;
			motor[motorBackLeft] = 0;
			break;
		case LEFT:
			motor[motorFrontRight] = 0;
			motor[motorBackRight] = 0;
			motor[motorFrontLeft] = sidePower;
			motor[motorBackLeft] = sidePower;
			break;
	}
}

void updateWithTankDriving()
{
	int leftPower = joystickToPower(joystick.joy1_y1);
	int rightPower = joystickToPower(joystick.joy1_y2);

	motor[motorFrontLeft] = leftPower;
	motor[motorBackLeft] = leftPower;
	motor[motorFrontRight] = rightPower;
	motor[motorBackRight] = rightPower;
}
