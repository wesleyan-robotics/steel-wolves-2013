#pragma once

/*  Descrption:
        The `SL_CONFIG_BUTTON` macro allows of having a short hand notation for
        setting up the button config section of code without having to be
        repetetive.

        Note: All `SL_ButtonConfigDef`s that are being refrenced must be already
        defined in the `BUTTON_CONFIG` struct
    Usage:
        SL_CONFIG_BUTTON(SL_ButtonConfigDef def, SL_JoystickIndex index, SL_ButtonType type, SL_JoystickDPad button)
    Examples:
        CONFIG_BUTTON(auxiliaryLift, JOYSTICK_1, BUTTON, BUTTON_Y)
        SL_CONFIG_BUTTON(flag, JOYSTICK_1, BUTTON, BUTTON_A)
*/
#define SL_CONFIG_BUTTON(name, __index, __type, __button) \
    SL_BUTTON_CONFIG->name.button = __button; \
    SL_BUTTON_CONFIG->name.joystickIndex = __index; \
    SL_BUTTON_CONFIG->name.type = __type;

typedef enum {
	SL_INVALID,
	SL_DPAD,
	SL_BUTTON
} SL_ButtonType;

typedef enum {
	SL_INVALID,
	SL_JOYSTICK_1,
	SL_JOYSTICK_2
} SL_JoystickIndex;

typedef struct {
	int button;
	SL_JoystickIndex joystickIndex;
	SL_ButtonType type;
} SL_ButtonConfigDef;

// Rather not put this in an enum since the JoystickDriver wants shorts.
// The user would have to case it manually otherwise which is annoying.
const short SL_BUTTON_UP = 0;
const short SL_BUTTON_DOWN = 1;

/* NOTE: This struct magic is the exactly the same as how it it done in
         MotorConfig.h
*/

struct SL_ButtonConfigImpl;
typedef SL_ButtonConfigImpl SL_ButtonConfig;

SL_ButtonConfig __SL_BUTTON_CONFIG;
const SL_ButtonConfig *SL_BUTTON_CONFIG = &__SL_BUTTON_CONFIG;

bool SL_IsButtonDown(SL_ButtonConfigDef *def);
