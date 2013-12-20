#pragma once
#include "MotorUtil.h"
#include "MotorConfig.h"

void stopWheels()
{
	setGroupPower(MOTOR_CONFIG.wheelGroup, 0);
}

void setWheelPower(int power)
{
	setGroupPower(MOTOR_CONFIG.wheelGroup, power);
}

void turnWheelsRight(int power)
{
	setPower(MOTOR_CONFIG.wheelGroup[FRONT_RIGHT], -power);
	setPower(MOTOR_CONFIG.wheelGroup[BACK_RIGHT], -power);
	setPower(MOTOR_CONFIG.wheelGroup[FRONT_LEFT], power);
	setPower(MOTOR_CONFIG.wheelGroup[BACK_LEFT], power);
}

void turnWheelsLeft(int power)
{
	setPower(MOTOR_CONFIG.wheelGroup[FRONT_RIGHT], power);
	setPower(MOTOR_CONFIG.wheelGroup[BACK_RIGHT], power);
	setPower(MOTOR_CONFIG.wheelGroup[FRONT_LEFT], -power);
	setPower(MOTOR_CONFIG.wheelGroup[BACK_LEFT], -power);
}

void drive(HorizontalDirection direction, int power)
{
	if (direction == HDIR_CENTER)
	{
		writeDebugStreamLine("Center Direction");
		setWheelPower(power);
		return;
	}

	if (direction == HDIR_RIGHT)
	{
		writeDebugStreamLine("Right Direction");
		turnWheelsRight(power);
		return;
	}

	if (direction == HDIR_LEFT)
	{
		writeDebugStreamLine("Left Direction");
		turnWheelsLeft(power);
		return;
	}
}

void turnWheels(HorizontalDirection direction, int power)
{
	if (direction == HDIR_RIGHT)
	{
		writeDebugStreamLine("Right Direction");
		turnWheelsRight(power);
		return;
	}

	if (direction == HDIR_LEFT)
	{
		writeDebugStreamLine("Left Direction");
		turnWheelsLeft(power);
		return;
	}
}
