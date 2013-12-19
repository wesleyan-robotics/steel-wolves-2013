#pragma config(Hubs,  S1, HTMotor,  HTMotor,  HTMotor,  HTServo)
#pragma config(Sensor, S1,     ,               sensorI2CMuxController)
#pragma config(Motor,  mtr_S1_C1_1,     motorWheelBackRight, tmotorTetrix, openLoop, reversed)
#pragma config(Motor,  mtr_S1_C1_2,     motorWheelFrontRight, tmotorTetrix, openLoop, reversed, encoder)
#pragma config(Motor,  mtr_S1_C2_1,     motorWheelBackLeft, tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C2_2,     motorWheelFrontLeft, tmotorTetrix, openLoop, encoder)
#pragma config(Motor,  mtr_S1_C3_1,     motorLiftRight, tmotorTetrix, openLoop, encoder)
#pragma config(Motor,  mtr_S1_C3_2,     motorLiftLeft, tmotorTetrix, openLoop, reversed, encoder)
#pragma config(Servo,  srvo_S1_C4_1,    servoFlag,            tServoContinuousRotation)
#pragma config(Servo,  srvo_S1_C4_2,    servoAuxLift,         tServoContinuousRotation)
#pragma config(Servo,  srvo_S1_C4_3,    servoBucketRight,     tServoStandard)
#pragma config(Servo,  srvo_S1_C4_4,    servoBucketLeft,      tServoStandard)
#pragma config(Servo,  srvo_S1_C4_5,    servoSideAndSideMoveyThing, tServoContinuousRotation)
#pragma config(Servo,  srvo_S1_C4_6,    servo6,               tServoNone)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

#include "MotorConfig.h"

#include "Math.c"
#include "JoystickUtil.c"
#include "Joystick.c"
#include "DrivingModes.c"
#include "MotorUtil.c"
#include "ButtonConfig.c"
#include "MotorConfig.c"

void config()
{
	CONFIG_MOTOR(liftGroup[LEFT], motorLiftLeft, TYPE_MOTOR, true)
	CONFIG_MOTOR(liftGroup[RIGHT], motorLiftRight, TYPE_MOTOR, true)

	CONFIG_MOTOR(auxiliaryLift, servoAuxLift, TYPE_SERVO, true)

    CONFIG_MOTOR(wheelGroup[FRONT_LEFT], motorWheelFrontLeft, TYPE_MOTOR, true)
	CONFIG_MOTOR(wheelGroup[FRONT_RIGHT], motorWheelFrontRight, TYPE_MOTOR, true)
	CONFIG_MOTOR(wheelGroup[BACK_LEFT], motorWheelBackLeft, TYPE_MOTOR, true)
	CONFIG_MOTOR(wheelGroup[BACK_RIGHT], motorWheelBackRight, TYPE_MOTOR, true)

    CONFIG_MOTOR(flag, servoFlag, TYPE_SERVO, true)

    CONFIG_MOTOR(bucketGroup[LEFT], NO_MOTOR_ID, TYPE_INVALID, false)
    CONFIG_MOTOR(bucketGroup[RIGHT], servoBucketRight, TYPE_SERVO, true)
}

task main()
{
	config();
	waitForStart();

	return;
	StartTask(joystickListener);

	while (true);
}
