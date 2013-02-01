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
#ifndef BASELIB_H
#define BASELIB_H

#include "../include/TimeEvent.h"
#include "../include/ViewSystem.h"
#include <iostream>
#include <string>
using namespace std;

class ElevatorSimulateSystem
{
private:
    /**每个电梯的最大载客量**/
    int maxPsaaangersPerElevator;
    /**乘客数量**/
    int passangersNum;
    /**乘客到来区间**/
    int passangerStartTime;
    /**电梯速度**/
    int secondPerFloor;
    /**电梯停留时间**/
    int secondPerBoardElevator;
    /**start为起始楼层**/
    PeopleSystem PS;
    /**start为起始楼层**/
    TimeEvent TE;
    /**start为起始楼层**/
    ElevatorSystem ES;
public:
    /**start为起始楼层**/
	ViewSystem VS;
	/**
    * @brief	返回最底层的楼层，一般是1
    * @param	K	每个电梯的最大载客量
	* @param	N	乘客数量
	* @param	M	乘客到来区间
	* @param	S	电梯速度
	* @param	T	电梯停留时间
    */
    ElevatorSimulateSystem(int,int,int,int,int);
    /**
    * @brief	开始自动仿真模式	
    */
    void Start();
    /**
    * @brief	判断仿真是否结束
    * @return	结束返回true否则是false
    */
    bool End();
    /**
    * @brief	开始单步仿真模式	
    */
	void stepStart();
};

#endif // BASELIB_H
