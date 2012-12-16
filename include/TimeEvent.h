#ifndef TIMEEVENT_H
#define TIMEEVENT_H

#include "../include/Elevator.h"

class TimeEvent
{
    public:
        void TimeBeat();
        TimeEvent();
        virtual ~TimeEvent();
    protected:
    private:
};

#endif // TIMEEVENT_H
