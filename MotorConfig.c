#pragma once
#include "MotorConfig.h"

// Loops through a motor group assuming that there is a NULL MotorConfigDef at
// the end of the array.
// Use `MOTOR_INDEX` to get the current index in the array
#define FOREACH_MOTOR_IN_GROUP(array)  \
    for (int MOTOR_INDEX = 0; array[MOTOR_INDEX].id != NO_MOTOR_ID; MOTOR_INDEX++)

void setPower(MotorConfigDef *def, int power)
{
	if (!def->isEnabled) return;

	if (def->type == MOTOR)
	{
		motor[def->id] = power;
		return;
	}

	if (def->type == SERVO)
	{
		servo[def->id] = power;
		return;
	}
}

int getPower(MotorConfigDef *def)
{
	if (!def->isEnabled) return 0;

	if (def->type == MOTOR)
	{
		return motor[def->id];
	}

	if (def->type == SERVO)
	{
		return servo[def->id];
	}

    return 0;
}

void setGroupPower(MotorConfigDef *group, int power)
{
    FOREACH_MOTOR_IN_GROUP(group)
    {
        setPower(&group[MOTOR_INDEX], power);
    }
}

void enableGroup(MotorConfigDef *group)
{
    FOREACH_MOTOR_IN_GROUP(group)
    {
        group[MOTOR_INDEX].isEnabled = true;
    }
}

void disableGroup(MotorConfigDef *group)
{
    FOREACH_MOTOR_IN_GROUP(group)
    {
        group[MOTOR_INDEX].isEnabled = false;
    }
}

bool isGroupEnabled(MotorConfigDef *group)
{
    bool isEnabled = true;

    FOREACH_MOTOR_IN_GROUP(group)
    {
        isEnabled = isEnabled && group[MOTOR_INDEX].isEnabled;
    }

    return isEnabled;
}
