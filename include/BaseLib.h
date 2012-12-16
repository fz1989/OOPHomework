#ifndef BASELIB_H
#define BASELIB_H
#include "../include/Elevator.h"
#include "../include/People.h"
#include "../include/RandomNumber.h"
#include "../include/TimeEvent.h"
class ElevatorSimulateSystem
{
private:
    int maxPsaaangersPerElevator;
    int passangersNum;
    int passangerStartTime;
    int secondPerFloor;
    int secondPerBoardElevator;

public:
    ElevatorSimulateSystem(int,int,int,int,int);
    void Start();
    bool End();
};

#endif // BASELIB_H
