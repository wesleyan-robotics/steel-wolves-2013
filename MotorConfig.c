#pragma once
#include "MotorConfig.h"

void setPower(MotorConfigDef def, int power) {
	if (!def.isEnabled) return;

	if (def.type == MOTOR)
	{
		motor[def.id] = power;
		return;
	}

	if (def.type == SERVO)
	{
		servo[def.id] = power;
		return;
	}
}
