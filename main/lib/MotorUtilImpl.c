#pragma once
#include "libsteel/interface/MotorUtilInterface.h"

void SL_StopWheels()
{
	SL_SetGroupPower(SL_MOTOR_CONFIG->wheelGroup, 0);
}

void SL_SetWheelPower(int power)
{
	SL_SetGroupPower(SL_MOTOR_CONFIG->wheelGroup, power);
}

void SL_SetWheelPower(int leftPower, int rightPower)
{
	SL_SetWheelPowerOnSide(SL_WHEELS_LEFT, leftPower);
	SL_SetWheelPowerOnSide(SL_WHEELS_RIGHT, rightPower);
}

void SL_SetWheelPowerOnSide(SL_WheelSide side, int power)
{
	if (side == SL_WHEELS_LEFT)
	{
		SL_SetPower(SL_MOTOR_CONFIG->wheelGroup[FRONT_LEFT], power);
		SL_SetPower(SL_MOTOR_CONFIG->wheelGroup[BACK_LEFT], power);
		return;
	}

	if (side == SL_WHEELS_RIGHT)
	{
		SL_SetPower(SL_MOTOR_CONFIG->wheelGroup[FRONT_RIGHT], power);
		SL_SetPower(SL_MOTOR_CONFIG->wheelGroup[BACK_RIGHT], power);
		return;
	}
}

void SL_TurnWheels(SL_HDirection direction, int power)
{
	if (direction == SL_HDIR_RIGHT)
	{
		SL_SetPower(SL_MOTOR_CONFIG->wheelGroup[FRONT_RIGHT], -power);
		SL_SetPower(SL_MOTOR_CONFIG->wheelGroup[BACK_RIGHT], -power);
		SL_SetPower(SL_MOTOR_CONFIG->wheelGroup[FRONT_LEFT], power);
		SL_SetPower(SL_MOTOR_CONFIG->wheelGroup[BACK_LEFT], power);
		return;
	}

	if (direction == SL_HDIR_LEFT)
	{
		SL_SetPower(SL_MOTOR_CONFIG->wheelGroup[FRONT_RIGHT], power);
		SL_SetPower(SL_MOTOR_CONFIG->wheelGroup[BACK_RIGHT], power);
		SL_SetPower(SL_MOTOR_CONFIG->wheelGroup[FRONT_LEFT], -power);
		SL_SetPower(SL_MOTOR_CONFIG->wheelGroup[BACK_LEFT], -power);
		return;
	}
}

void SL_Drive(SL_HDirection direction, int power)
{
	if (direction == SL_HDIR_CENTER)
	{
		SL_SetWheelPower(power);
		return;
	}

	if (direction == SL_HDIR_RIGHT)
	{
		SL_TurnWheels(SL_HDIR_RIGHT, power);
		return;
	}

	if (direction == SL_HDIR_LEFT)
	{
		SL_TurnWheels(SL_HDIR_LEFT, power);
		return;
	}
}
