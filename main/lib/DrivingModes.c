#pragma once
#include "../../libsteel/include/MotorConfig.h"
#include "../../libsteel/interface/MotorUtilInterface.h"

#include "config/MotorConfigImpl.h"

#include "include/JoystickImpl.h"
#include "include/DrivingModes.h"

void updateWithArcadeDriving()
{
	if (!SL_IsGroupEnabled(SL_MOTOR_CONFIG->wheelGroup)) return;

	int y = joystick.joy1_y1;
	int x = joystick.joy1_x2;

	int power = SL_JoystickToPower(y) * POWER_LIMIT_FACTOR;
	SL_HDirection direction = SL_GetHDirection(x);

	// Allow for turning if the x value is moving while the y value is not
	// The joysticks look like this:
	//    [x]   [y]
	//    <->    *
	if (!SL_IsInDeadzone(x) && SL_IsInDeadzone(y))
	{
		SL_Drive(direction, TURNING_POWER);
		return;
	}

	// Ignore values if both the joysticks are in the deadzones
	if (SL_IsInDeadzone(x) && SL_IsInDeadzone(y))
	{
		SL_StopWheels();
		return;
	}

	SL_Drive(direction, power);
}

void updateWithTankDriving()
{
	if (!SL_IsGroupEnabled(SL_MOTOR_CONFIG->wheelGroup)) return;

	int left = joystick.joy1_y1;
	int right = joystick.joy1_y2;

	int leftPower = SL_JoystickToPower(left);
	int rightPower = SL_JoystickToPower(right);

	SL_SetWheelPower(leftPower, rightPower);
}
