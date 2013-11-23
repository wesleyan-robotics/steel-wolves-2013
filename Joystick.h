#pragma once

typedef enum {
	DPAD_UP = 0,
	DPAD_UP_RIGHT,
	DPAD_RIGHT,
	DPAD_DOWN_RIGHT,
	DPAD_DOWN,
	DPAD_DOWN_LEFT,
	DPAD_LEFT
} JoystickDPad;

typedef enum {
	BUTTON_X = 0,
	BUTTON_A = 1,
	BUTTON_B = 2,
	BUTTON_Y = 3,
	BUTTON_LT = 4,
	BUTTON_RB = 5,
	BUTTON_LB = 6,
	BUTTON_RT = 7,
	BUTTON_BACK = 8,
	BUTTON_START = 9
} JoystickButtons;

typedef enum {
	CENTER,
	LEFT,
	RIGHT
} HorizontalDirection;

typedef enum {
	CENTER,
	UP,
	DOWN
} VerticalDirection;


const int POWER_MIN = 0;
const int POWER_MAX = 100;
const int JOYSTICK_MIN = -127;
const int JOYSTICK_MAX = 127;

const int FLAG_POWER = 70;
const int LIFT_POWER = 10;

const int DEAD_ZONE = 8;
const int LOOP_DELAY_TIME = 51;
const float POWER_LIMIT_FACTOR = 0.75;

int joystickToPower(int x);
void joystickDebugDisplay();
void doJoystickUpdate();
task joystickListener();
