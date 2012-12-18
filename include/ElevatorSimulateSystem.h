#ifndef BASELIB_H
#define BASELIB_H

#include "../include/TimeEvent.h"


class ElevatorSimulateSystem
{
private:
    int maxPsaaangersPerElevator;
    int passangersNum;
    int passangerStartTime;
    int secondPerFloor;
    int secondPerBoardElevator;
    PeopleSystem PS;
    TimeEvent TE;
    ElevatorSystem ES;
public:
    ElevatorSimulateSystem(int,int,int,int,int);
    void Start();
    bool End();
};

#endif // BASELIB_H
