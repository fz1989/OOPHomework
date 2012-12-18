#include "../include/TimeEvent.h"

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
    pPeople->timeNotify(Time);
    pElevSys->timeNotify();
}
