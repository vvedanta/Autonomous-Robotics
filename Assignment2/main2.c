#pragma config(Sensor, in1,    lit,            sensorReflection)
#pragma config(Sensor, dgtl11, bump1,          sensorNone)
#pragma config(Sensor, dgtl12, bump2,          sensorNone)
#pragma config(Motor,  port1,           rightMotor,    tmotorVex393, openLoop)
#pragma config(Motor,  port10,          leftMotor,     tmotorVex393, openLoop)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

/*******************************************************************************
*
*  This file is meant as an introduction and as a template for developing
*  programs to run on the Vex controller.
*
*******************************************************************************/

/*******************************************************************************
*
*	main
*
*******************************************************************************/
task main() // define the main method
{
//  int bumper = 1;	              // normal bumper state = 1; when pressed = 0
int sensor_value; //created an instance variable for the sensor value

  wait1Msec(2000);    					// give stuff time to turn on

  while(true) //begins the loop
  {
    //Joystick control of the motors
    motor[leftMotor]   =  vexRT[Ch3];       // up = CW
    motor[rightMotor]  = -vexRT[Ch2];       // up = CCW

    //If the bumper is press, automatically backup
    while(!SensorValue[bump1]) //if the sensor is bumped
    {
	    writeDebugStreamLine("bumped-backing up");

    	motor[leftMotor] = -127; //fullspeed backwards
	    motor[rightMotor] = 127; //fullspeed backwards
	    wait1Msec(1000);  // keep backing up for 1000ms (1 sec)

	    motor[leftMotor]  = 0;  //stop motors
	    motor[rightMotor] = 0;  //stop motors
	    wait1Msec(1000);
     }
    		sensor_value = 1100 - SensorValue(lit); //reversed the polarity of the 
							// light sensor
    		motor[leftMotor] = sensor_value / 8; // 8 is produced via 1023/127 
						     // (range of sensor/range of motor)
						     // This provides an accurate scale 						     // for the motor to adjust
	    	motor[rightMotor] = - (sensor_value / 8); // right motor is negative when
							  // when the left is positive and 
							  // vice-versa
	    	wait1Msec(1000);



     writeDebugStreamLine("bumper is clear");
  }
}
