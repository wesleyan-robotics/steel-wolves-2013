#pragma once
#include "Joystick.h";

#include "JoystickDriver.h"
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

	if (MOTOR_CONFIG.wheels.isEnabled) {
		updateDriving();
	}
	if (MOTOR_CONFIG.flag.isEnabled) {
		updateFlag();
	}
	if (MOTOR_CONFIG.lift.isEnabled) {
		updateLift();
	}
}

void updateDriving()
{
	updateWithArcadeDriving();
}

void updateLift()
{
	if (!MOTOR_CONFIG.lift.isEnabled) return;

	if (joystick.joy1_TopHat == (short)DPAD_UP) {
		motor[MOTOR_CONFIG.lift.left] = LIFT_POWER;
		motor[MOTOR_CONFIG.lift.right] = LIFT_POWER;
	} else if (joystick.joy1_TopHat == (short)DPAD_DOWN) {
		motor[MOTOR_CONFIG.lift.left] = -LIFT_POWER;
		motor[MOTOR_CONFIG.lift.right] = -LIFT_POWER;
	}

	if (joy1Btn(BUTTON_A)) {
		servo[MOTOR_CONFIG.lift.bucketLift] = 100;
	} else {
		servo[MOTOR_CONFIG.lift.bucketLift] = 0;
	}
}

void updateFlag()
{
	if (!MOTOR_CONFIG.flag.isEnabled) return;

	if (joy1Btn(BUTTON_A) == 1) {
		motor[MOTOR_CONFIG.flag.id] = FLAG_POWER;
	} else {
		motor[MOTOR_CONFIG.flag.id] = 0;
	}
}
