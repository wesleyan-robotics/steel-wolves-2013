#pragma once
#include "JoystickUtil.h"

typedef enum
{
	WHEELS_LEFT,
	WHEELS_RIGHT
} WheelSide;

void stopWheels();
void setWheelPower(int power);
void setWheelPower(int leftPower, int rightPower);
void setWheelPowerOnSide(WheelSide side, int power);
void drive(HorizontalDirection direction, int power);
void turnWheels(HorizontalDirection direction, int power);
