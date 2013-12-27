#pragma once

const int FLAG_POWER = 50;
const int LIFT_POWER = 100;

const int LOOP_DELAY_TIME = 51;
const float POWER_LIMIT_FACTOR = 1.0;
const float TURNING_LIMIT_FACTOR = 0.75;
const int TURNING_POWER = (int) round(POWER_LIMIT_FACTOR * TURNING_LIMIT_FACTOR);

void initJoystick();
task joystickListener();
void doJoystickUpdate();
void updateDriving();
void updateLift();
void updateAuxiliaryLift();
void updateFlag();
