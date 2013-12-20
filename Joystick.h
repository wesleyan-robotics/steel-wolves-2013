#pragma once

const int FLAG_POWER = 50;
const int LIFT_POWER = 100;

const int LOOP_DELAY_TIME = 51;
const float POWER_LIMIT_FACTOR = 1.0;

void initJoystick();
task joystickListener();
void doJoystickUpdate();
void updateDriving();
void updateLift();
void updateAuxiliaryLift();
void updateFlag();
