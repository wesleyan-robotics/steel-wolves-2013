#pragma once
#include "MotorConfig.h"

void globalMotorConfig()
{
	MOTOR_CONFIG.lift.left			= motorLiftLeft;
	MOTOR_CONFIG.lift.right			= motorLiftRight;
	MOTOR_CONFIG.lift.auxiliaryLift	= servoAuxLift;
	MOTOR_CONFIG.lift.isEnabled		= true;

	MOTOR_CONFIG.wheels.frontLeft	= motorWheelFrontLeft;
	MOTOR_CONFIG.wheels.frontRight	= motorWheelFrontRight;
	MOTOR_CONFIG.wheels.backLeft	= motorWheelBackLeft;
	MOTOR_CONFIG.wheels.backRight	= motorWheelBackRight;
	MOTOR_CONFIG.wheels.isEnabled	= true;

	MOTOR_CONFIG.flag.id			= servoFlag;
	MOTOR_CONFIG.flag.isEnabled		= true;

	MOTOR_CONFIG.buckets.left		= NO_MOTOR;
	MOTOR_CONFIG.buckets.right		= servoBucketRight;
	MOTOR_CONFIG.buckets.isEnabled  = false;
}