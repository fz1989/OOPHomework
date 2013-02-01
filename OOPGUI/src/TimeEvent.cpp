#include "../include/TimeEvent.h"
#include <cstdio>
TimeEvent::TimeEvent()
{
	/**初始时间为0**/
    Time = 0;
}

void TimeEvent::setTimeEventInfo(PeopleSystem *ptr1, ElevatorSystem *ptr2) {
    /**设置相应参数**/
	pPeople = ptr1;
    pElevSys = ptr2;
}

void TimeEvent::TimeBeat() {
    /**触发相应事件**/
	Time++;
    pElevSys->timeNotify();
    pPeople->timeNotify(Time);
}
