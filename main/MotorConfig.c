#pragma once
#include "MotorConfigImpl.h"

#include "MotorConfig.h"

void initMotorConfig()
{
    CONFIG_MOTOR(wheelGroup[FRONT_LEFT], motorWheelFrontLeft, TYPE_MOTOR, true)
	CONFIG_MOTOR(wheelGroup[FRONT_RIGHT], motorWheelFrontRight, TYPE_MOTOR, true)
	CONFIG_MOTOR(wheelGroup[BACK_LEFT], motorWheelBackLeft, TYPE_MOTOR, true)
	CONFIG_MOTOR(wheelGroup[BACK_RIGHT], motorWheelBackRight, TYPE_MOTOR, true)

	CONFIG_MOTOR(flag, motorFlag, TYPE_MOTOR, true)
	CONFIG_MOTOR(lift, motorLift, TYPE_MOTOR, true)
}
