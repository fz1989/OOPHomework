#ifndef RANDOMNUMBER_H
#define RANDOMNUMBER_H


#include <cstdlib>
#include <ctime>
class RandomNumber
{
private:
    time_t seed;
    int low, high;
public:
    RandomNumber(int, int);
    void setRange(int, int);
    int getRandomNumber();
};

#endif // RANDOMNUMBER_H
