#pragma once

typedef enum {
	INVALID,
	DPAD,
	BUTTONS
} ButtonRefType;

typedef enum {
	INVALID,
	JOYSTICK_1,
	JOYSTICK_2
} ButtonJoystick;

typedef struct {
	int button;
	ButtonJoystick joystickIndex;
	ButtonRefType refType;
} ButtonConfigDef;

typedef struct {
	ButtonConfigDef liftUp;
	ButtonConfigDef liftDown;
	ButtonConfigDef auxiliaryLift;
	ButtonConfigDef flag;
} ButtonConfig;

const short BUTTON_UP = 0;
const short BUTTON_DOWN = 1;

ButtonConfig BUTTON_CONFIG;

bool isButtonDown(ButtonConfigDef def);
