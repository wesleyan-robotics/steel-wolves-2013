#pragma once
#include "MotorUtil.h"

void stopWheels()
{
	motor[MOTOR_CONFIG.wheels.frontRight]	= 0;
	motor[MOTOR_CONFIG.wheels.backRight]	= 0;
	motor[MOTOR_CONFIG.wheels.frontLeft]	= 0;
	motor[MOTOR_CONFIG.wheels.backLeft]		= 0;
}

void setWheelPower(int power)
{
	motor[MOTOR_CONFIG.wheels.frontRight]	= power;
	motor[MOTOR_CONFIG.wheels.backRight]	= power;
	motor[MOTOR_CONFIG.wheels.frontLeft]	= power;
	motor[MOTOR_CONFIG.wheels.backLeft]		= power;
}

void turnWheelsRight(int power)
{
	motor[MOTOR_CONFIG.wheels.frontRight] = -power;
	motor[MOTOR_CONFIG.wheels.backRight]  = -power;
	motor[MOTOR_CONFIG.wheels.frontLeft]  = power;
	motor[MOTOR_CONFIG.wheels.backLeft]   = power;
}

void turnWheelsLeft(int power)
{
	motor[MOTOR_CONFIG.wheels.frontRight] = power;
	motor[MOTOR_CONFIG.wheels.backRight]  = power;
	motor[MOTOR_CONFIG.wheels.frontLeft]  = -power;
	motor[MOTOR_CONFIG.wheels.backLeft]   = -power;
}

void drive(HorizontalDirection direction, int power)
{
	if (direction == CENTER) {
		writeDebugStreamLine("Center Direction");
		setWheelPower(power);
		return;
	}
	if (direction == RIGHT) {
		writeDebugStreamLine("Right Direction");
		turnWheelsRight(power);
		return;
	}
	if (direction == LEFT) {
		writeDebugStreamLine("Left Direction");
		turnWheelsLeft(power);
		return;
	}
}

void turnWheels(HorizontalDirection direction, int power)
{
	if (direction == RIGHT) {
		writeDebugStreamLine("Right Direction");
		turnWheelsRight(power);
		return;
	}
	if (direction == LEFT) {
		writeDebugStreamLine("Left Direction");
		turnWheelsLeft(power);
		return;
	}
}
