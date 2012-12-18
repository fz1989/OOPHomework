#include "../include/TimeEvent.h"
#include <cstdio>
TimeEvent::TimeEvent()
{
    Time = 0;
}

void TimeEvent::setTimeEventInfo(PeopleSystem *ptr1, ElevatorSystem *ptr2) {
    pPeople = ptr1;
    pElevSys = ptr2;
}

void TimeEvent::TimeBeat() {
    Time++;
    printf("%d\n", Time);
    pElevSys->timeNotify();
    pPeople->timeNotify(Time);

}
