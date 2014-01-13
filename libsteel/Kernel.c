#pragma once
#include "include/Kernel.h"
#include "include/JoystickDriver.h"

#include "interface/KernelInterface.h"

task main()
{
    config();
    waitForStart();
    StartTask(run);

    while(true);
}
