#pragma once
#include "Kernel.h"

#include "MotorConfigImpl.h"
#include "JoystickDriver.h"

task run();

task main()
{
    initMotorConfig();
    waitForStart();
    StartTask(run);
}
