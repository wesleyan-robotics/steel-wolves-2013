#pragma once
#include "../include/MotorConfig.h"

void setPower(MotorConfigDef *def, int power)
{
	if (!def->isEnabled) return;

	if (def->type == TYPE_MOTOR)
	{
		motor[def->id] = power;
		return;
	}

	if (def->type == TYPE_SERVO)
	{
		servo[def->id] = power;
		return;
	}
}

int getPower(MotorConfigDef *def)
{
	if (!def->isEnabled) return 0;

	if (def->type == TYPE_MOTOR)
	{
		return motor[def->id];
	}

	if (def->type == TYPE_SERVO)
	{
		return servo[def->id];
	}

    return 0;
}

void setGroupPower(MotorConfigDef *group, int power)
{
    FOREACH_MOTOR_IN_GROUP(group)
    {
        setPower(&group[INDEX], power);
    }
}

void enableGroup(MotorConfigDef *group)
{
    FOREACH_MOTOR_IN_GROUP(group)
    {
        group[INDEX].isEnabled = true;
    }
}

void disableGroup(MotorConfigDef *group)
{
    FOREACH_MOTOR_IN_GROUP(group)
    {
        group[INDEX].isEnabled = false;
    }
}

bool isGroupEnabled(MotorConfigDef *group)
{
    bool isEnabled = true;

    FOREACH_MOTOR_IN_GROUP(group)
    {
        isEnabled = isEnabled && group[INDEX].isEnabled;
    }

    return isEnabled;
}
