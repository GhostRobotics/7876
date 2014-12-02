/*
* Standard_Drive.c
* This file contains functions for any robot to use.
* Basic drive functions, such as driveInches and drive time
* are used to move the robot effeciatly around the field
*/

#include "Standard_Drive.h" //holds method headers and global variables
/*
* This method stops both motors, with a small waitTime.
* used to quickly stop the robot after a drive method
*/
void stopMotors()
{
	motor[motorD] = 0;
	motor[motorE] = 0;
	wait1Msec(200);
}
/*
* This method drives a specified number of inches, based upon inches
* the method converts inches into a motor encoder value, using inchesToEncoder.
* The robot then drives for that distance, comparing to nMotorEncoder[motorD].
* @param inches: the distance in inches, that the robot will travel
* @param int l power of left motor
* @param int r power of right motor
*/
void driveInches (float inches, int l, int r)
{
	//change to go backwards
	if(inches < 0)
	{
		l *= -1;
		r *= -1;
		inches *= -1;
	}
	//drive a certain amount of inches
	nMotorEncoder[motorD] = 0;
	while(abs(nMotorEncoder[motorD]) <= inchesToEncoder(inches))
	{
		motor[motorD] = l;
		motor[motorE] = r;
	}
	stopMotors();
}
/*
* The robot drives a certain amount of time before stoping
* NOTE: this method is very inaccurate, given that the robot
* wil go different distances with different battery powers
* @param waitTime: time for the robot to move, in milliseconds
* @param int l power of left motor
* @param int r power of right motor
*
*/
void driveTime (int waitTime, int l, int r)
{
	motor[motorD] = l;
	motor[motorE] = r;
	wait1Msec(waitTime);
	stopMotors();
}
/*
* Turns the robot in a direction for a number of degrees
* The robot will turn in place, one motor going forward and one backwards.
* The amount to be moved is the arc of the circle that the robot will turn
* @param direction is the direction to be turning (LEFT or RIGHT)
* @param degrees is the degrees to turn
* @param power is the motor power of the robot
*/
void turn(bool direction, int degrees, int power)
{
	float amount = ROBOT_RADIUS * degreesToRadians(degrees) * 2;
	if(direction == LEFT)
	{
		driveInches(amount, -1*power, power);
	}
	else
	{
		driveInches(amount, power, -1*power);
	}
}
/*
* This method takes inches and converts it to an encoder value
* 1 encoder value = 1/4 degree
* @param inches is a number of inches
* @return is the inches converted to encoder values
*/
int inchesToEncoder(int inches)
{
	float circumference = WHEEL_CIRCUMFERENCE;
	return inches / circumference * 1440;
}
/*
* This method takes encoder values and converts them to inches
* 1 encoder value = 1/4 degree
* @param encoder is the number of encoder values to be converted
* @return is the encoderValue converted to inches
*/
float encoderToInches(int encoder)
{
	float circumference = WHEEL_CIRCUMFERENCE;
	return encoder*circumference /1440;
}
