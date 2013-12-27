#pragma once
#include "MotorConfigImpl.h"

#include "MotorConfig.h"

void initMotorConfig()
{
	//CONFIG_MOTOR(liftGroup[MOTOR_LEFT], motorLiftLeft, TYPE_MOTOR, false)
	//CONFIG_MOTOR(liftGroup[MOTOR_RIGHT], motorLiftRight, TYPE_MOTOR, false)

	//CONFIG_MOTOR(auxiliaryLift, servoAuxLift, TYPE_SERVO, false)

    CONFIG_MOTOR(wheelGroup[FRONT_LEFT], motorWheelFrontLeft, TYPE_MOTOR, true)
	CONFIG_MOTOR(wheelGroup[FRONT_RIGHT], motorWheelFrontRight, TYPE_MOTOR, true)
	CONFIG_MOTOR(wheelGroup[BACK_LEFT], motorWheelBackLeft, TYPE_MOTOR, true)
	CONFIG_MOTOR(wheelGroup[BACK_RIGHT], motorWheelBackRight, TYPE_MOTOR, true)

    //CONFIG_MOTOR(flag, servoFlag, TYPE_SERVO, true)

    //CONFIG_MOTOR(bucketGroup[MOTOR_LEFT], NO_MOTOR_ID, TYPE_INVALID, false)
    //CONFIG_MOTOR(bucketGroup[MOTOR_RIGHT], servoBucketRight, TYPE_SERVO, false)
}
