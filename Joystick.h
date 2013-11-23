#pragma once

const int FLAG_POWER = 70;
const int LIFT_POWER = 10;

const int LOOP_DELAY_TIME = 51;
const float POWER_LIMIT_FACTOR = 0.75;

task joystickListener();
void doJoystickUpdate();
void updateDriving();
void updateLift();
void updateFlag();
