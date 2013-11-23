#pragma once
#include "Joystick.h";

#include "JoystickDriver.c"

#include "JoystickUtil.h"
#include "Math.h";

task joystickListener()
{
	while(true) {
		wait1Msec(LOOP_DELAY_TIME);
		getJoystickSettings(joystick);
		doJoystickUpdate();
	}
}

void doJoystickUpdate()
{
	joystickDebugDisplay();

	updateDrivingMotors();

	if (joy1Btn(BUTTON_A) == 1) {
		motor[motorFlag] = FLAG_POWER;
	} else {
		motor[motorFlag] = 0;
	}

	if (joystick.joy1_TopHat == DPAD_UP) {
		motor[motorLiftLeft] = LIFT_POWER;
		motor[motorLiftRight] = LIFT_POWER;
	} else if (joystick.joy1_TopHat == DPAD_DOWN) {
		motor[motorLiftLeft] = -LIFT_POWER;
		motor[motorLiftRight] = -LIFT_POWER;
	}
}

void updateDrivingMotors()
{
#if TANK_DRIVING_MODE == 1

	int leftPower = joystickToPower(joystick.joy1_y1);
	int rightPower = joystickToPower(joystick.joy1_y2);
	motor[motorFrontLeft] = leftPower;
	motor[motorBackLeft] = leftPower;
	motor[motorFrontRight] = rightPower;
	motor[motorBackRight] = rightPower;

#else
	int y = joystick.joy1_y1;
	int x = joystick.joy2_x1;

	int power = joystickToPower(y) * POWER_LIMIT_FACTOR;
	float limit = abs(joystickToPower(x) / (float)POWER_MAX);

	if (getHorizontalDirection(x) == CENTER) {
		motor
	}

	if (getHorizontalDirection(x) == RIGHT) {
		motor[motorFrontRight] = leftPower;
		motor[motorBackLeft] = leftPower;
		motor[motorFrontRight] = rightPower;
		motor[motorFrontLeft] = rightPower;
#endif
}
