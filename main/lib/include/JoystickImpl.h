#pragma once

#define POWER(power)  power * POWER_LIMIT_FACTOR

const float POWER_LIMIT_FACTOR = 1.0;

const int FLAG_POWER = POWER(50);
const int LIFT_POWER = POWER(100);
const int TURNING_POWER = POWER(100);

void joystickDebugDisplay();
void updateDriving();
void updateLift();
void updateFlag();
