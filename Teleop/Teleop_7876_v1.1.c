#pragma config(Hubs,  S1, HTMotor,  HTMotor,  HTMotor,  HTServo)
#pragma config(Sensor, S1,     ,               sensorI2CMuxController)
#pragma config(Sensor, S2,     ultra,          sensorSONAR)
#pragma config(Motor,  mtr_S1_C1_1,     left,          tmotorTetrix, openLoop, reversed, encoder)
#pragma config(Motor,  mtr_S1_C1_2,     right,         tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C2_1,     motorF,        tmotorTetrix, openLoop, encoder)
#pragma config(Motor,  mtr_S1_C2_2,     motorG,        tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C3_1,     motorH,        tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C3_2,     motorI,        tmotorTetrix, openLoop)
#pragma config(Servo,  srvo_S1_C4_1,    jack1,                tServoStandard)
#pragma config(Servo,  srvo_S1_C4_2,    jack2,                tServoStandard)
#pragma config(Servo,  srvo_S1_C4_3,    bucket,               tServoStandard)
#pragma config(Servo,  srvo_S1_C4_4,    servo4,               tServoNone)
#pragma config(Servo,  srvo_S1_C4_5,    servo5,               tServoNone)
#pragma config(Servo,  srvo_S1_C4_6,    servo6,               tServoNone)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

#define DOUBLE_JOYSTICK true
#define SINGLE_JOYSTICK false
/*Brandon Wang, Lilia Heinold
Teleop 3565 (Name pending)
1.0 10/3 First Teleop Test (robot base)
1.1 11/7 Robot base with rolling goal servos
*/
#include "JoystickDriver.c"
#include "Standard_Drive.c";
#include "nxtIO.h";

void initializeRobot()
{
	motor[left] = 0;
	motor[right] = 0;
	nMotorEncoder[left] = 0;
}

int adjustValue(int joystickValue)
{
	float value;
	int sign = 1;

	if(joystickValue < 0) sign *= -1;

	value = 100*pow(joystickValue,1.4)/pow(127,1.4);

	return (int) (value * sign);
}


task main()
{
	initializeRobot();
	bool joyStickMode = SINGLE_JOYSTICK;
	while (true)
	{
		getJoystickSettings(joystick);

		//two joysticks

		long y2 = joystick.joy1_y2;
		long x2 = joystick.joy1_x2;
		long y = joystick.joy1_y1;
		long x = joystick.joy1_x1;

		if(joyStickMode == SINGLE_JOYSTICK)
		{
			//one Joystick
			if(sqrt(x*x+y*y) > 10)
			{
				motor[left] =			(((y * y * y + x * x * x) * 100) >> 22);
				motor[right] =		(((y * y * y - x * x * x) * 100) >> 22);
			}
			else if (sqrt(x2*x2+y2*y2) > 10)
			{
				motor[left] =			(((y2 * y2 * y2 + x2 * x2 * x2) * 100) >> 22) / 2;
				motor[right] =		(((y2 * y2 * y2 - x2 * x2 * x2) * 100) >> 22) / 2;
			}
			else {
				motor[left] = 0;
				motor[right] = 0;
			}
		}
		else {
			//two joysticks
			if(sqrt(y2*y2+y*y) > 10)
			{
				motor[left] = y;
				motor[right] = y2;
			}
			else
			{
				motor[left] = 0;
				motor[right] = 0;
			}
		}
		//one button at a time
		//First Controller Buttons
		if(joy1Btn(9) == 1 || joy1Btn(10) == 1)
		{ //Switch between dual and single joystick
			PlayTone(1000,5);
			joyStickMode = !joyStickMode;
			wait1Msec(1000);
		}

		if (joy2Btn(4) == 1 && joy2Btn(2) == 0)
		{
			servo[jack1] = ServoValue[jack1] + 5;
			servo[jack2] = ServoValue[jack2] - 5;
		}
		else if(joy2Btn(2) == 1 && joy2Btn(4) == 0)
		{
			servo[jack1] = ServoValue[jack1] - 5;
			servo[jack2] = ServoValue[jack2] + 5;
		}


		if(joystick.joy2_TopHat == 0 && joystick.joy2_TopHat != 4)
		{
			servo[bucket] = ServoValue[bucket] + 4;
		}
		else if(joystick.joy2_TopHat == 4 && joystick.joy2_TopHat != 0)
		{
			servo[bucket] = ServoValue[bucket] - 4;
		}
	}
}
