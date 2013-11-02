#include "Math.c"
#include "Joystick.c"

task main()
{
	writeDebugStreamLine("JoystickExp with 0: %i", joystickExp(0));
	writeDebugStreamLine("JoystickExp with 5: %i", joystickExp(5));
	writeDebugStreamLine("JoystickExp with -5: %i", joystickExp(-5));
	writeDebugStreamLine("JoystickExp with 50: %i", joystickExp(50));
	writeDebugStreamLine("JoystickExp with -50: %i", joystickExp(-50));
	writeDebugStreamLine("JoystickExp with 127: %i", joystickExp(127));
	writeDebugStreamLine("JoystickExp with -127: %i", joystickExp(-127));
}
