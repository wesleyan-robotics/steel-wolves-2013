#pragma once
#include "config/MotorConfigImpl.h"

void SL_InitMotorConfig()
{
	SL_CONFIG_MOTOR(wheelGroup[FRONT_LEFT], motorWheelFrontLeft, SL_TYPE_MOTOR, true)
	SL_CONFIG_MOTOR(wheelGroup[FRONT_RIGHT], motorWheelFrontRight, SL_TYPE_MOTOR, true)
	SL_CONFIG_MOTOR(wheelGroup[BACK_LEFT], motorWheelBackLeft, SL_TYPE_MOTOR, true)
	SL_CONFIG_MOTOR(wheelGroup[BACK_RIGHT], motorWheelBackRight, SL_TYPE_MOTOR, true)

	SL_CONFIG_MOTOR(flag, motorFlag, SL_TYPE_MOTOR, true)
	SL_CONFIG_MOTOR(lift, motorLift, SL_TYPE_MOTOR, true)
}
