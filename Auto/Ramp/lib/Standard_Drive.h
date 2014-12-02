#define USING_ROBOT_B
#ifdef USING_ROBOT_A //Robot A parameters
	#define WHEEL_CIRCUMFERENCE (2.661 * PI)
	#define ROBOT_RADIUS 4
#endif
#ifdef USING_ROBOT_B //Robot B parameters
	const float WHEEL_CIRCUMFERENCE =(3.3428904 * PI);
	#define ROBOT_RADIUS 6.6056
#endif
#ifdef USING_TEST_BOT //Test Bot parameters
	const float WHEEL_CIRCUMFERENCE =(2.75 * PI)/4;
	#define ROBOT_RADIUS 4.5
#endif
#define DEFAULT_SPEED 30
#define LEFT true
#define RIGHT false
#define EQUAL_TO 0
#define NOT_EQUAL_TO 1
#define LESS_THAN 2
#define LESS_THAN_OR_EQUAL_TO 3
#define GREATER_THAN 4
#define GREATER_THAN_OR_EQUAL_TO 5

void stopMotors(); //stop function
void driveInches (float inches, int l = DEFAULT_SPEED, int r= DEFAULT_SPEED);
void driveTime (int waitTime, int l = DEFAULT_SPEED, int r = DEFAULT_SPEED);
void find_line();
void turn(bool direction, int degrees, int power = DEFAULT_SPEED);
void moveUntil(int sensor, int condition, int value, int power = DEFAULT_SPEED);
int inchesToEncoder(int inches);
float encoderToInches(int encoder);
