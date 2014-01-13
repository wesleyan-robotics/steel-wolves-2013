#pragma once
#include "include/Kernel.h"
#include "include/JoystickDriver.h"

#include "interface/KernelInterface.h"

task main()
{
    SL_Config();
    waitForStart();
    StartTask(SL_Run);

    while(true);
}
