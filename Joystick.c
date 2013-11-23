#pragma once
#include "Joystick.h";

#include "JoystickDriver.c"
#include "JoystickUtil.h"
#include "Math.h";
#include "DrivingModes.h"

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

	if (joy1Btn(BUTTON_A)) {
		servo[servoAuxillaryLift] = 100;
	} else {
		servo[servoAuxillaryLift] = 0;
	}

	//updateDriving();
	//updateFlag();
	//updateLift();
}

void updateDriving()
{
	updateWithArcadeDriving();
}

void updateLift()
{
	if (joystick.joy1_TopHat == (short)DPAD_UP) {
		motor[motorLiftLeft] = LIFT_POWER;
		motor[motorLiftRight] = LIFT_POWER;
	} else if (joystick.joy1_TopHat == (short)DPAD_DOWN) {
		motor[motorLiftLeft] = -LIFT_POWER;
		motor[motorLiftRight] = -LIFT_POWER;
	}
}

void updateFlag()
{
	if (joy1Btn(BUTTON_A) == 1) {
		motor[motorFlag] = FLAG_POWER;
	} else {
		motor[motorFlag] = 0;
	}
}
