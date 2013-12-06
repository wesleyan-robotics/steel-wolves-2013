#pragma once

typedef struct {
	int frontLeft;
	int frontRight;
	int backLeft;
	int backRight;
	bool isEnabled;
} WheelConfig;

typedef struct {
	int id;
	bool isEnabled;
} FlagConfig;

typedef struct {
	int left;
	int right;
	int auxiliaryLift;
	bool isEnabled;
} LiftConfig;

typedef struct {
	int left;
	int right;
	bool isEnabled;
} BucketConfig;

typedef struct {
	WheelConfig wheels;
	LiftConfig lift;
	FlagConfig flag;
	BucketConfig buckets;
} MotorConfig;

const int NO_MOTOR = 0;

MotorConfig MOTOR_CONFIG;
