#pragma config(Hubs,  S1, HTMotor,  HTMotor,  none,     none)
#pragma config(Sensor, S1,     ,               sensorI2CMuxController)
#pragma config(Motor,  mtr_S1_C1_1,     motorFrontLeft, tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C1_2,     motorBackLeft, tmotorTetrix, openLoop, reversed)
#pragma config(Motor,  mtr_S1_C2_1,     motorFrontRight, tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C2_2,     motorBackRight, tmotorTetrix, openLoop, reversed)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

#include "Math.c"
#include "Joystick.c"

task main()
{
	StartTask(joystickListener);
	while(true) { continue; }
}
