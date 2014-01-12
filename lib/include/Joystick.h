#pragma once

#define POWER(power)  power * POWER_LIMIT_FACTOR

const int MIN_POWER = 0;
const int MAX_POWER = 100;

const int LOOP_DELAY_TIME = 50;

task joystickListener();
