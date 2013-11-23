#pragma once
#include "Joystick.h";

#include "JoystickDriver.c"
#include "Math.h";

int joystickToPower(int x)
{
	if (abs(x) > DEAD_ZONE) {
		float offset = 20.0;
		float intialOffset = offset * signOf(x);

		float fraction = pow(x, 2) / (float)pow(JOYSTICK_MAX, 2);
		float exponential = fraction * (POWER_MAX - offset) * signOf(x);
		float power = exponential + intialOffset;

		return floor(power);
	}

	return 0;
}

void joystickDebugDisplay()
{
	eraseDisplay();
    nxtDisplayTextLine(0, "L X: %i, Y: %i", joystick.joy1_x1, joystick.joy1_y1);
    nxtDisplayTextLine(1, "R X: %i, Y: %i", joystick.joy1_x2, joystick.joy1_y2);
    nxtDisplayTextLine(3, "%i L | R %i", motor[motorFrontLeft], motor[motorFrontRight]);
    nxtDisplayTextLine(4, "%i L | R %i", motor[motorBackLeft], motor[motorBackRight]);
}

void setMotorsWithTurning(int leftStick, int rightStick)
{
#if TANK_DRIVING_MODE == 1
		int leftPower = joystickToPower(leftStick);
		int rightPower = joystickToPower(rightStick);
		motor[motorFrontLeft] = leftPower;
		motor[motorBackLeft] = leftPower;
		motor[motorFrontRight] = rightPower;
		motor[motorBackRight] = rightPower;
#else
		int adjustedTurnStick = joystickToPower(rightStick + 100);
		int adjustedPower = joystickToPower(leftStick) * POWER_LIMIT_FACTOR;
		motor[motorFrontLeft] = (adjustedPower - adjustedTurnStick);
		motor[motorBackLeft] = (adjustedPower - adjustedTurnStick);
		motor[motorFrontRight] = (adjustedPower + adjustedTurnStick);
		motor[motorFrontLeft] = (adjustedPower + adjustedTurnStick);
#endif
}

void doJoystickUpdate()
{
		joystickDebugDisplay();
		setMotorsWithTurning(joystick.joy1_y1, joystick.joy1_x2);
		if(joy1Btn(BUTTON_A) == 1)
			motor[motorFlag] = 75;
		else
			motor[motorFlag] = 0;

		if(joystick.joy1_TopHat == DPAD_UP)
		{
				motor[motorLiftLeft] = 10;
				motor[motorLiftRight] = 10;
		}
		else if(joystick.joy1_TopHat == DPAD_DOWN)
		{
				motor[motorLiftLeft] = -10;
				motor[motorLiftRight] = -10;
		}
}

task joystickListener()
{
	while(true) {
		wait1Msec(LOOP_DELAY_TIME);
		getJoystickSettings(joystick);
		doJoystickUpdate();
	}
}
