#pragma config(Sensor, in1,    lit,            sensorReflection)
#pragma config(Sensor, in2,    lit2,           sensorReflection)
#pragma config(Sensor, in3,    pot,            sensorPotentiometer)
#pragma config(Sensor, dgtl7,  sonarSensor,    sensorSONAR_mm)
#pragma config(Motor,  port1,           rightMotor,    tmotorVex393, openLoop)
#pragma config(Motor,  port6,           servoMotor,    tmotorServoStandard, openLoop)
#pragma config(Motor,  port10,          leftMotor,     tmotorVex393, openLoop)

task main()
{
wait1Msec(1000);
motor[leftMotor] = -127;
motor[rightMotor] = 0;
wait1Msec(650);
motor[leftMotor] = 0;
motor[rightMotor] = 127;
wait1Msec(650);
motor[leftMotor] = 0;
motor[rightMotor] = 0;
wait1Msec(1000);
}
