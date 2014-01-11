#pragma once
#include "MotorConfig.h"

/*  Descrption:
        The `CONFIG_MOTOR` macro allows of having a short hand notation for
        setting up the motor config section of code without having to be
        repetitive.

        Note: All `MotorConfigDef`s that are being referenced must be already
        defined in the `MOTOR_CONFIG` struct
    Usage:
        CONFIG_MOTOR(MotorConfigDef def, int motorIndex, MotorType type, bool isEnabled)
    Examples:
        CONFIG_MOTOR(flag, servoFlag, TYPE_SERVO, true)
        CONFIG_MOTOR(wheelGroup[FRONT_LEFT], motorWheelFrontLeft, TYPE_MOTOR, true)
*/
#define CONFIG_MOTOR(def, __id, __type, __isEnabled) \
    MOTOR_CONFIG.def.id = __id; \
    MOTOR_CONFIG.def.type = __type; \
    MOTOR_CONFIG.def.isEnabled = __isEnabled;

/*  Descrption:
        Loops through a motor group assuming that there is a `NULL`
        `MotorConfigDef` the end of the array.
    Usage:
        Use `FOREACH_MOTOR_IN_GROUP` as the for loop and `INDEX` to get the
        current index in the array
    Example:
        MotorConfigDef *group = MOTOR_CONFIG.wheelGroup;
        FOREACH_MOTOR_IN_GROUP(group)
        {
            group[INDEX].isEnabled = false;
        }
*/
#define FOREACH_MOTOR_IN_GROUP(array)  \
    for (int INDEX = 0; array[INDEX].type != TYPE_INVALID; INDEX++)

typedef enum
{
	TYPE_INVALID,
	TYPE_MOTOR,
	TYPE_SERVO
} MotorType;

typedef struct
{
	int id;
	MotorType type;
	bool isEnabled;
} MotorConfigDef;

typedef enum
{
	FRONT_LEFT  = 0,
    FRONT_RIGHT = 1,
    BACK_LEFT   = 2,
    BACK_RIGHT  = 3
} WheelGroupID;

typedef enum
{
	MOTOR_LEFT = 0,
    MOTOR_RIGHT = 1
} SideGroupID;

// Note: All the lengths are +1 since we want a NULL terminator
const int WHEEL_GROUP_LEN = 5;
const int SIDE_GROUP_LEN = 3;

typedef struct
{
    MotorConfigDef liftGroup[SIDE_GROUP_LEN];
    MotorConfigDef bucketGroup[SIDE_GROUP_LEN];
    MotorConfigDef wheelGroup[WHEEL_GROUP_LEN];
    MotorConfigDef auxiliaryLift;
    MotorConfigDef flag;
} MotorConfig;


const int NO_MOTOR_ID = -1;

MotorConfig MOTOR_CONFIG;
const MotorConfig *MC = &MOTOR_CONFIG;

int getPower(MotorConfigDef *def);
void setPower(MotorConfigDef *def, int power);
void setGroupPower(MotorConfigDef *group, int power);
void enableGroup(MotorConfigDef *group);
void disableGroup(MotorConfigDef *group);
bool isGroupEnabled(MotorConfigDef *group);
