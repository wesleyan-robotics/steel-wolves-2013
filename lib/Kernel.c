#pragma once
#include "../include/Kernel.h"

#include "../include/MotorConfigImpl.h"
#include "../include/JoystickDriver.h"

task run();

task main()
{
    initMotorConfig();
    waitForStart();
    StartTask(run);
    while(true);
}
