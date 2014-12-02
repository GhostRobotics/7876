#include "nxtIO.h"

void print(char a, int line)
{
		nxtDisplayCenteredTextLine(line, "%c", a);
}
void print(int a, int line)
{
		nxtDisplayCenteredTextLine(line, "%i", a);
}
void print(float a, int line)
{
		nxtDisplayCenteredTextLine(line, "%f", a);
}
void print(string a, int line)
{
		nxtDisplayCenteredTextLine(line, "%s", a);
}
