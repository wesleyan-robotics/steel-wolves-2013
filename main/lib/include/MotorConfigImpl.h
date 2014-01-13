#pragma once
#include "libsteel/include/MotorConfig.h"

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

struct {
    MotorConfigDef bucketGroup[SIDE_GROUP_LEN];
    MotorConfigDef wheelGroup[WHEEL_GROUP_LEN];
    MotorConfigDef lift;
    MotorConfigDef flag;
} MotorConfigImpl;