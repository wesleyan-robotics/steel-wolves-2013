#pragma once

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
    MOTOR_CONFIG->def.id = __id; \
    MOTOR_CONFIG->def.type = __type; \
    MOTOR_CONFIG->def.isEnabled = __isEnabled;

/*  Descrption:
        Loops through a motor group assuming that there is a `NULL`
        `MotorConfigDef` the end of the array.
    Usage:
        Use `FOREACH_MOTOR_IN_GROUP` as the for loop and `INDEX` to get the
        current index in the array
    Example:
        MotorConfigDef *group = MOTOR_CONFIG->wheelGroup;
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

const int NO_MOTOR_ID = -1;

// struct MotorConfigImml is implemented by the user
struct MotorConfigImpl;
typedef MotorConfigImpl MotorConfig;

/* HACK: For some strange reason, you have to reference the fancy forward
         declared struct with a pointer to it. Don't ask me why, but this works.
*/
MotorConfig _MOTOR_CONFIG;
const MotorConfig *MOTOR_CONFIG = &_MOTOR_CONFIG;

int getPower(MotorConfigDef *def);
void setPower(MotorConfigDef *def, int power);
void setGroupPower(MotorConfigDef *group, int power);
void enableGroup(MotorConfigDef *group);
void disableGroup(MotorConfigDef *group);
bool isGroupEnabled(MotorConfigDef *group);
