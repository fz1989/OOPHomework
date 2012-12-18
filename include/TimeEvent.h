#ifndef TIMEEVENT_H
#define TIMEEVENT_H

#include "../include/People.h"
#include "../include/Elevator.h"


class TimeEvent
{
public:
    void TimeBeat();
    TimeEvent();
    void setTimeEventInfo(PeopleSystem *, ElevatorSystem *);
private:
    int Time;
    PeopleSystem *pPeople;
    ElevatorSystem *pElevSys;
};

#endif // TIMEEVENT_H
