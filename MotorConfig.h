#pragma once

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

typedef struct
{
	MotorConfigDef frontLeft;
	MotorConfigDef frontRight;
	MotorConfigDef backLeft;
	MotorConfigDef backRight;
} WheelConfig;

typedef struct
{
	MotorConfigDef left;
	MotorConfigDef right;
	bool isEnabled;
} LiftConfig;

typedef struct
{
	MotorConfigDef id
	bool isEnabled;
} AuxiliaryLiftConfig;

typedef struct
{
	MotorConfigDef left;
	MotorConfigDef right;
	bool isEnabled;
} BucketConfig;

typedef struct
{
	WheelConfig wheels;
	LiftConfig lift;
	MotorConfigDef flag;
	AuxiliaryLiftConfig auxiliaryLift;
	BucketConfig buckets;
} MotorConfig;

const int NO_MOTOR = 0;

MotorConfig MOTOR_CONFIG;
