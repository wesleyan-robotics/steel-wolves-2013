#pragma once
#include "Includes.h"

void initButtonConfig()
{
    CONFIG_BUTTON(liftUp, JOYSTICK_1, DPAD, DPAD_UP)
    CONFIG_BUTTON(liftDown, JOYSTICK_1, DPAD, DPAD_DOWN)
    CONFIG_BUTTON(flagUp, JOYSTICK_1, BUTTON, BUTTON_Y)
    CONFIG_BUTTON(flagDown, JOYSTICK_1, BUTTON, BUTTON_A)
}
