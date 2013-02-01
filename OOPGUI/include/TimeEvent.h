/*
 * OOPHomework - fz1989's OOPHomework
 * Copyright (C) 2012-2012 fz1989.
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#ifndef TIMEEVENT_H
#define TIMEEVENT_H

#include "../include/People.h"
#include "../include/Elevator.h"


class TimeEvent
{
public:
    /**
    * @brief	时间阶跃函数，触发系统时间响应事件
    */
    void TimeBeat();
    /**
    * @brief	时间事件的构造函数
    */
    TimeEvent();
    /**
    * @brief	设定时间时间的成员变量
    * @param	ptr1	指向同一系统下PeopleSystem的指针
	* @param	ptr2	指向同一系统下ElevatorSystem的指针
    */
    void setTimeEventInfo(PeopleSystem *, ElevatorSystem *);
private:
    /**系统当前累积时间**/
    int Time;
    /**PeopleSystem的指针**/
    PeopleSystem *pPeople;
    /**ElevatorSystem的指针**/
    ElevatorSystem *pElevSys;
};

#endif // TIMEEVENT_H
