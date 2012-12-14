#ifndef BASELIB_H_INCLUDED
#define BASELIB_H_INCLUDED
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
#endif // BASELIB_H_INCLUDED
