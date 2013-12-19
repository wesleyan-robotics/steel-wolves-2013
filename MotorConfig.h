#pragma once

/*  Descrption:
        The `CONFIG_MOTOR` macro allows of having a short hand notation for
        setting up the motor config section of code without having to be
        repetetive.
    Usage:
        CONFIG_MOTOR(MotorConfigDef def, int motorIndex, MotorType type, bool isEnabled)
    Examples:
        CONFIG_MOTOR(flag, servoFlag, SERVO, true)
        CONFIG_MOTOR(wheelGroup[FRONT_LEFT], motorWheelFrontLeft, MOTOR, true)
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
    for (int INDEX = 0; array[INDEX].id != NO_MOTOR_ID; INDEX++)

typedef enum
{
	INVALID,
	MOTOR,
	SERVO
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

// Note: All the lengths are +1 since we want a NULL terminator
const int WHEEL_GROUP_LEN = 5;

typedef enum
{
	LEFT = 0,
    RIGHT = 1
} SideGroupID;

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

int getPower(MotorConfigDef *def);
void setPower(MotorConfigDef *def, int power);
void setGroupPower(MotorConfigDef *group, int power);
void enableGroup(MotorConfigDef *group);
void disableGroup(MotorConfigDef *group);
bool isGroupEnabled(MotorConfigDef *group);
