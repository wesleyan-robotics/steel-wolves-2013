#pragma once
#include "libsteel/interface/MotorUtilInterface.h"

void stopWheels()
{
	setGroupPower(MOTOR_CONFIG->wheelGroup, 0);
}

void setWheelPower(int power)
{
	setGroupPower(MOTOR_CONFIG->wheelGroup, power);
}

void setWheelPower(int leftPower, int rightPower)
{
	setWheelPowerOnSide(WHEELS_LEFT, leftPower);
	setWheelPowerOnSide(WHEELS_RIGHT, rightPower);
}

void setWheelPowerOnSide(WheelSide side, int power)
{
	if (side == WHEELS_LEFT)
	{
		setPower(MOTOR_CONFIG->wheelGroup[FRONT_LEFT], power);
		setPower(MOTOR_CONFIG->wheelGroup[BACK_LEFT], power);
		return;
	}

	if (side == WHEELS_RIGHT)
	{
		setPower(MOTOR_CONFIG->wheelGroup[FRONT_RIGHT], power);
		setPower(MOTOR_CONFIG->wheelGroup[BACK_RIGHT], power);
		return;
	}
}

void turnWheels(HorizontalDirection direction, int power)
{
	if (direction == HDIR_RIGHT)
	{
		setPower(MOTOR_CONFIG->wheelGroup[FRONT_RIGHT], -power);
		setPower(MOTOR_CONFIG->wheelGroup[BACK_RIGHT], -power);
		setPower(MOTOR_CONFIG->wheelGroup[FRONT_LEFT], power);
		setPower(MOTOR_CONFIG->wheelGroup[BACK_LEFT], power);
		return;
	}

	if (direction == HDIR_LEFT)
	{
		setPower(MOTOR_CONFIG->wheelGroup[FRONT_RIGHT], power);
		setPower(MOTOR_CONFIG->wheelGroup[BACK_RIGHT], power);
		setPower(MOTOR_CONFIG->wheelGroup[FRONT_LEFT], -power);
		setPower(MOTOR_CONFIG->wheelGroup[BACK_LEFT], -power);
		return;
	}
}

void drive(HorizontalDirection direction, int power)
{
	if (direction == HDIR_CENTER)
	{
		setWheelPower(power);
		return;
	}

	if (direction == HDIR_RIGHT)
	{
		turnWheels(HDIR_RIGHT, power);
		return;
	}

	if (direction == HDIR_LEFT)
	{
		turnWheels(HDIR_LEFT, power);
		return;
	}
}
