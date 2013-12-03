#pragma once

typedef struct {
	int left;
	int right;
	int bucketLift;
	bool isEnabled;
} LiftConfig;

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
	LiftConfig lift;
	WheelConfig wheels;
	FlagConfig flag;
} MotorConfig;

const int NO_MOTOR = 0;

MotorConfig MOTOR_CONFIG;
