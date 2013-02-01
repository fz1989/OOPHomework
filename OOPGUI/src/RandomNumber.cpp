#include "../include/RandomNumber.h"

RandomNumber::RandomNumber(int inLow = 0, int inHigh = 1)
{
	/**设置随机数参数**/
    low = inLow;
    high = inHigh;
    seed = (unsigned)time(NULL) + rand();
}

int RandomNumber::getRandomNumber()
{
	/**获得随机数**/
    srand(seed);
    return rand() % (high - low + 1) + low;
}

void RandomNumber::setRange(int inLow, int inHigh)
{
	/**设置随机数参数**/
    low = inLow;
    high = inHigh;
}
