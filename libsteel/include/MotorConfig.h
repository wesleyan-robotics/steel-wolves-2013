#pragma once

/*  Descrption:
        The `SL_CONFIG_MOTOR` macro allows of having a short hand notation for
        setting up the motor config section of code without having to be
        repetitive.

        Note: All `SL_MotorConfigDef`s that are being referenced must be already
        defined in the `SL_MOTOR_CONFIG` struct
    Usage:
        SL_CONFIG_MOTOR(SL_MotorConfigDef def, int motorIndex, SL_MotorType type, bool isEnabled)
    Examples:
        CONFIG_MOTOR(flag, servoFlag, TYPE_SERVO, true)
        CONFIG_MOTOR(wheelGroup[FRONT_LEFT], motorWheelFrontLeft, TYPE_MOTOR, true)
*/
#define SL_CONFIG_MOTOR(def, __id, __type, __isEnabled) \
    SL_MOTOR_CONFIG->def.id = __id; \
    SL_MOTOR_CONFIG->def.type = __type; \
    SL_MOTOR_CONFIG->def.isEnabled = __isEnabled;

/*  Descrption:
        Loops through a motor group assuming that there is a `NULL`
        `SL_MotorConfigDef` the end of the array.
    Usage:
        Use `SL_FOREACH_MOTOR_IN_GROUP` as the for loop and `INDEX` to get the
        current index in the array
    Example:
        SL_MotorConfigDef *group = SL_MOTOR_CONFIG->wheelGroup;
        SL_FOREACH_MOTOR_IN_GROUP(group)
        {
            group[INDEX].isEnabled = false;
        }
*/
#define SL_FOREACH_MOTOR_IN_GROUP(array)  \
    for (int INDEX = 0; array[INDEX].type != SL_TYPE_INVALID; INDEX++)

typedef enum
{
	SL_TYPE_INVALID,
	SL_TYPE_MOTOR,
	SL_TYPE_SERVO
} SL_MotorType;

typedef struct
{
	int id;
	SL_MotorType type;
	bool isEnabled;
} SL_MotorConfigDef;

const int NO_MOTOR_ID = -1;

// struct MotorConfigImml is implemented by the user
struct SL_MotorConfigImpl;
typedef SL_MotorConfigImpl SL_MotorConfig;

/* HACK: For some strange reason, you have to reference the fancy forward
         declared struct with a pointer to it. Don't ask me why, but this works.
*/
SL_MotorConfig __SL_MOTOR_CONFIG;
const SL_MotorConfig *SL_MOTOR_CONFIG = &__SL_MOTOR_CONFIG;

int SL_GetPower(SL_MotorConfigDef *def);
void SL_SetPower(SL_MotorConfigDef *def, int power);
void SL_SetGroupPower(SL_MotorConfigDef *group, int power);
void SL_EnableGroup(SL_MotorConfigDef *group);
void SL_DisableGroup(SL_MotorConfigDef *group);
bool SL_IsGroupEnabled(SL_MotorConfigDef *group);
