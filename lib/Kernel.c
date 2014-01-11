#pragma once
#include "include/Kernel.h"

#include "include/JoystickDriver.h"

void config();
task run();

task main()
{
    config();
    waitForStart();
    StartTask(run);

    while(true);
}
