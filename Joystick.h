#pragma once

const int DEAD_ZONE = 8;
const int POWER_MIN = 0;
const int POWER_MAX = 100;
const int JOYSTICK_MIN = -127;
const int JOYSTICK_MAX = 127;

int joystickToPower(int x);
void joystickDebugDisplay();
void doJoystickUpdate();
task joystickListener();
