#pragma once

/*  Descrption:
        The `CONFIG_BUTTON` macro allows of having a short hand notation for
        setting up the button config section of code without having to be
        repetetive.
    Usage:
        CONFIG_BUTTON(JoystickDPad button, JoystickIndex index, ButtonType type)
    Examples:
        CONFIG_MOTOR(flag, servoFlag, SERVO, true)
        CONFIG_MOTOR(wheelGroup[FRONT_LEFT], motorWheelFrontLeft, MOTOR, true)
*/
#define CONFIG_BUTTON(name, __index, __type, __button) \
    BUTTON_CONFIG.name.button = __button; \
    BUTTON_CONFIG.name.joystickIndex = __index; \
    BUTTON_CONFIG.name.type = __type;

typedef enum {
	INVALID,
	DPAD,
	BUTTON
} ButtonType;

typedef enum {
	INVALID,
	JOYSTICK_1,
	JOYSTICK_2
} JoystickIndex;

typedef struct {
	int button;
	JoystickIndex joystickIndex;
	ButtonType type;
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
