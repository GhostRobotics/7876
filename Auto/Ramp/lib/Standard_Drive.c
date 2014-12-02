#include "Standard_Drive.h"
#include "nxtIO.c";
void stopMotors() //stop function
{
	motor[motorD] = 0;
	motor[motorE] = 0;
	wait1Msec(200);
}

void driveInches (float inches, int l, int r)
{
	if(inches < 0)
	{
		l *= -1;
		r *= -1;
		inches *= -1;
	}
	//drive a certain amount of inches, order: # of inches, power left, power right
	nMotorEncoder[left] = 0;
	while(abs(nMotorEncoder[motorD]) <= inchesToEncoder(inches))
	{
		motor[left] = l;
		motor[right] = r;
	}
	stopMotors();
}

void driveTime (int waitTime, int l, int r) //drive infinitely function, order: wait time, power s, power right
{
	motor[motorD] = l;
	motor[motorE] = r;
	wait1Msec(waitTime);
	stopMotors();
}

void find_line()//finds white line on dark surface
{
	int BLACK = SensorValue[S2];
	while(SensorValue[S2] < (BLACK + 25))
	{
		nxtDisplayCenteredTextLine(3, "%i, %i", BLACK, SensorValue[S2]);
		motor[left] = 45;
		motor[right] = 45;
	}
	stopMotors();
}
void turn(bool direction, int degrees, int power)
{
	float amount = ROBOT_RADIUS * degreesToRadians(degrees) * 2;
	if(direction == LEFT)
		driveInches(amount, -1*power, power);
	else
		driveInches(amount, power, -1*power);
}

void moveUntil(int sensor, int condition, int value, int power) {
	while(true) {
		motor[left] = power;
		motor[right] = power;
		int current = SensorValue[sensor];
		nxtDisplayCenteredTextLine(3,"%i",current);
		switch(condition) {
		case EQUAL_TO:
			if(current == value) {
				stopMotors();
				return;
			}
			else
				break;
		case NOT_EQUAL_TO:
			if(current != value) {
				stopMotors();
				return;
			}
			else
				break;
		case LESS_THAN:
			if(current < value) {
				stopMotors();
				return;
			}
			else
				break;
		case LESS_THAN_OR_EQUAL_TO:
			if(current <= value) {
				stopMotors();
				return;
			}
			else
				break;
		case GREATER_THAN:
			if(current > value) {
				stopMotors();
				return;
			}
			else
				break;
		case GREATER_THAN_OR_EQUAL_TO:
			if(current >= value) {
				stopMotors();
				return;
			}
			else
				break;
		}
	}
}
int inchesToEncoder(int inches)
{
	float circumference = WHEEL_CIRCUMFERENCE;
	return inches / circumference * 1440;

}
float encoderToInches(int encoder)
{
	float circumference = WHEEL_CIRCUMFERENCE;
	return encoder*circumference /1440;
}
