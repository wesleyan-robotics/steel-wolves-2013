#pragma once

#define POWER(power)  power * POWER_LIMIT_FACTOR

const int MIN_POWER = 0;
const int MAX_POWER = 100;

const float POWER_LIMIT_FACTOR = 1.0;

const int FLAG_POWER = POWER(70);
const int LIFT_POWER = POWER(100);
const int TURNING_POWER = POWER(100);

const int LOOP_DELAY_TIME = 51;

void initJoystick();
task joystickListener();
void doJoystickUpdate();
void updateDriving();
void updateLift();
void updateFlag();
