// For some reason, this thingy doesn't work. :-(

void sineMotor(int ticks);
float sineSpeed(float x);
float sineSpeed(float x) 
{
	//print(((sin(10 * x / PI) + 0.3) / 1.4), 1);
	//wait10Msec(100);
	return ((sin(10 * x / PI) + 0.3) / 1.4) * 100;
}
void sineMotor(int ticks) {
	nMotorEncoder[left] = 0;
	float sineSpeedCache;
	while (nMotorEncoder[left] <= ticks) 
	{
		sineSpeedCache = sineSpeed( (float) nMotorEncoder[left] / ticks);
		motor[left] = sineSpeedCache;
		motor[right] = sineSpeedCache;
		print(sineSpeedCache, 3);
			print(nMotorEncoder[left], 4);
			print(motor[right], 5);
			print(motor[left], 6);
	}
	motor[left] = 0;
	motor[right] = 0;
}
