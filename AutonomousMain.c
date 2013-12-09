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

#include "ProgramIncludes.h"

task main()
{
    globalMotorConfig();
    waitForStart();

    motor[motorWheelBackLeft] = motor[motorWheelBackRight] = motor[motorWheelFrontLeft] = motor[MotorWheelFrontRight] = -100;
    wait1Msec(6500);
    motor[motorWheelBackLeft] = motor[motorWheelBackRight] = motor[motorWheelFrontLeft] = motor[MotorWheelFrontRight] = 0;
}
