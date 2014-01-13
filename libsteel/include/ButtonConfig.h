#pragma once

/*  Descrption:
        The `CONFIG_BUTTON` macro allows of having a short hand notation for
        setting up the button config section of code without having to be
        repetetive.

        Note: All `ButtonConfigDef`s that are being refrenced must be already
        defined in the `BUTTON_CONFIG` struct
    Usage:
        CONFIG_BUTTON(ButtonConfigDef def, JoystickIndex index, ButtonType type, JoystickDPad button)
    Examples:
        CONFIG_BUTTON(auxiliaryLift, JOYSTICK_1, BUTTON, BUTTON_Y)
        CONFIG_BUTTON(flag, JOYSTICK_1, BUTTON, BUTTON_A)
*/
#define CONFIG_BUTTON(name, __index, __type, __button) \
    BUTTON_CONFIG->name.button = __button; \
    BUTTON_CONFIG->name.joystickIndex = __index; \
    BUTTON_CONFIG->name.type = __type;

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

const short BUTTON_UP = 0;
const short BUTTON_DOWN = 1;

/* NOTE: This struct magic is the exactly the same as how it it done in
         MotorConfig.h
*/

struct ButtonConfigImpl;
typedef ButtonConfigImpl ButtonConfig;

ButtonConfig _BUTTON_CONFIG;
const ButtonConfig *BUTTON_CONFIG = &_BUTTON_CONFIG;

bool isButtonDown(ButtonConfigDef *def);
