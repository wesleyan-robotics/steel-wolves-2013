#include "Config.c"

#include "Math.c"
#include "Joystick.c"

task main()
{
	waitForStart();
	StartTask(joystickListener);
	while(true) { continue; }
}
