#pragma once
#include "Joystick.h";

#include "JoystickDriver.h"
#include "JoystickUtil.h"
#include "Math.h";
#include "DrivingModes.h"
#include "ButtonConfig.h"

void initJoystick()
{
	BUTTON_CONFIG.liftUp.button			= DPAD_UP;
	BUTTON_CONFIG.liftUp.joystickIndex	= JOYSTICK_1;
	BUTTON_CONFIG.liftUp.refType		= DPAD;

	BUTTON_CONFIG.liftDown.button			= DPAD_DOWN;
	BUTTON_CONFIG.liftDown.joystickIndex	= JOYSTICK_1;
	BUTTON_CONFIG.liftDown.refType			= DPAD;

	BUTTON_CONFIG.auxiliaryLift.button			= BUTTON_Y;
	BUTTON_CONFIG.auxiliaryLift.joystickIndex	= JOYSTICK_1;
	BUTTON_CONFIG.auxiliaryLift.refType			= BUTTONS;

	BUTTON_CONFIG.flag.button			= BUTTON_A;
	BUTTON_CONFIG.flag.joystickIndex	= JOYSTICK_1;
	BUTTON_CONFIG.flag.refType			= BUTTONS;
}

task joystickListener()
{
	initJoystick();

	while(true) {
		wait1Msec(LOOP_DELAY_TIME);
		getJoystickSettings(joystick);
		doJoystickUpdate();
	}
}

void doJoystickUpdate()
{
	writeDebugStreamLine("Joystick Update Fired");
	joystickDebugDisplay();
	if(!isButtonDown(BUTTON_CONFIG.flag))
		servo[servoFlag] = 0;

	if (MOTOR_CONFIG.wheels.isEnabled)
		updateDriving();

	if (MOTOR_CONFIG.lift.isEnabled)
		updateLift();

	if(MOTOR_CONFIG.flag.isEnabled)
		updateFlag();

}

void updateDriving()
{
	if (!MOTOR_CONFIG.wheels.isEnabled) return;

	updateWithArcadeDriving();
}

void updateLift()
{
	if (!MOTOR_CONFIG.lift.isEnabled) return;

	if (isButtonDown(BUTTON_CONFIG.liftUp)) {
		motor[MOTOR_CONFIG.lift.left] = LIFT_POWER;
		motor[MOTOR_CONFIG.lift.right] = LIFT_POWER;
		return;
	}
	if (isButtonDown(BUTTON_CONFIG.liftDown)) {
		motor[MOTOR_CONFIG.lift.left] = -LIFT_POWER;
		motor[MOTOR_CONFIG.lift.right] = -LIFT_POWER;
		return;
	}

	motor[MOTOR_CONFIG.lift.left] = 0;
	motor[MOTOR_CONFIG.lift.right] = 0;
	if (isButtonDown(BUTTON_CONFIG.auxiliaryLift)) {
		servo[MOTOR_CONFIG.lift.auxiliaryLift] = 100;
		return;
	} else {
		servo[MOTOR_CONFIG.lift.auxiliaryLift] = 0;

		return;
	}
}

void updateFlag()
{
	if(!MOTOR_CONFIG.flag.isEnabled) return;

	if(isButtonDown(BUTTON_CONFIG.flag))
		servo[servoFlag] = FLAG_POWER;

	else servo[servoFlag] = 0;
}
