#pragma once
#include "JoystickUtil.h"

typedef enum
{
	SL_WHEELS_LEFT,
	SL_WHEELS_RIGHT
} SL_WheelSide;

void SL_StopWheels();
void SL_SetWheelPower(int power);
void SL_SetWheelPower(int leftPower, int rightPower);
void SL_SetWheelPowerOnSide(SL_WheelSide side, int power);
void SL_Drive(SL_HDirection direction, int power);
void SL_TurnWheels(SL_HDirection direction, int power);
