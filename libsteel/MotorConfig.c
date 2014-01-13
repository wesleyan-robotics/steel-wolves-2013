#pragma once
#include "include/MotorConfig.h"

void SL_SetPower(SL_MotorConfigDef *def, int power)
{
	if (!def->isEnabled) return;

	if (def->type == SL_TYPE_MOTOR)
	{
		motor[def->id] = power;
		return;
	}

	if (def->type == SL_TYPE_SERVO)
	{
		servo[def->id] = power;
		return;
	}
}

int SL_GetPower(SL_MotorConfigDef *def)
{
	if (!def->isEnabled) return 0;

	if (def->type == SL_TYPE_MOTOR)
	{
		return motor[def->id];
	}

	if (def->type == SL_TYPE_SERVO)
	{
		return servo[def->id];
	}

    return 0;
}

void SL_SetGroupPower(SL_MotorConfigDef *group, int power)
{
    SL_FOREACH_MOTOR_IN_GROUP(group)
    {
        SL_SetPower(&group[INDEX], power);
    }
}

void SL_EnableGroup(SL_MotorConfigDef *group)
{
    SL_FOREACH_MOTOR_IN_GROUP(group)
    {
        group[INDEX].isEnabled = true;
    }
}

void SL_DisableGroup(SL_MotorConfigDef *group)
{
    SL_FOREACH_MOTOR_IN_GROUP(group)
    {
        group[INDEX].isEnabled = false;
    }
}

bool SL_IsGroupEnabled(SL_MotorConfigDef *group)
{
    bool isEnabled = true;

    SL_FOREACH_MOTOR_IN_GROUP(group)
    {
        isEnabled = isEnabled && group[INDEX].isEnabled;
    }

    return isEnabled;
}
