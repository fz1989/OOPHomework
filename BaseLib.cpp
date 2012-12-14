#include "BaseLib.h"
RandomNumber::RandomNumber(int inLow = 0, int inHigh = 1) {
    low = inLow;
    high = inHigh;
    seed = (unsigned)time(NULL);
}

int RandomNumber::getRandomNumber() {
    srand(seed);
    return rand() % (high - low + 1) + low;
}

void RandomNumber::setRange(int inLow, int inHigh)
{
    low = inLow;
    high = inHigh;
}
