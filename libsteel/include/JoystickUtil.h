#pragma once

typedef enum {
	SL_DPAD_UP = 0,
	SL_DPAD_UP_RIGHT,
	SL_DPAD_RIGHT,
	SL_DPAD_DOWN_RIGHT,
	SL_DPAD_DOWN,
	SL_DPAD_DOWN_LEFT,
	SL_DPAD_LEFT
} SL_JoystickDPad;

typedef enum {
	SL_BUTTON_X = 0,
	SL_BUTTON_A = 1,
	SL_BUTTON_B = 2,
	SL_BUTTON_Y = 3,
	SL_BUTTON_LT = 4,
	SL_BUTTON_RB = 5,
	SL_BUTTON_LB = 6,
	SL_BUTTON_RT = 7,
	SL_BUTTON_BACK = 8,
	SL_BUTTON_START = 9
} SL_JoystickButton;

typedef enum {
	SL_HDIR_CENTER,
	SL_HDIR_LEFT,
	SL_HDIR_RIGHT
} SL_HDirection;

typedef enum {
	SL_VDIR_CENTER,
	SL_VDIR_UP,
	SL_VDIR_DOWN
} SL_VDirection;

const int SL_JOYSTICK_MIN = -127;
const int SL_JOYSTICK_MAX = 127;

const int SL_DEAD_ZONE = 8;

bool SL_IsInDeadzone(int x);
int SL_JoystickToPower(int x);
SL_HDirection SL_GetHDirection(int x);
SL_VDirection SL_GetVDirection(int y);
