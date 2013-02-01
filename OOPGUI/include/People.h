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
#ifndef PEOPLE_H
#define PEOPLE_H

#include "../include/Elevator.h"
#include "../include/RandomNumber.h"
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
#define NOTSTART        -1
#define WAITING         0
#define INUSING         1
#define FINISHED		2
class People
{
private:
    /**乘客状态**/
    int state;
    /**到下一次开始的时间**/
    int needTime;
    /**乘坐次数**/
    int takeTimes;
    /**乘客ID**/
    int ID;
    /**目标楼层**/
    int destFloor;
    /**目前楼层**/
    int nowFloor;
    /**所在电梯**/
    int elevID;
public:
    /**请求时间戳**/
    vector <int> requestTime;
    /**接受时间戳**/
	vector <int> acceptedTime;
	/**电梯系统**/
	ElevatorSystem *pElevSys;
	/**总时间**/
	int totalTime;
public:
    /**
    * @brief	乘客构造函数
    */
    People();
    /**
    * @brief	乘客构造函数
    * @param	MOD		乘客到来时间
	* @param	inID	乘客ID
    */
	People(int, int);
	/**
    * @brief	设置目标楼层
    */
    void setDestInfo();
    /**
    * @brief	获得剩余行驶次数takeTimes
    * @return	takeTimes的值
    */
    int getRemainTimes();
    /**
    * @brief	更新乘客状态
    * @param	nowTime	目前系统时间
    */
	void updateInfo(int);
	/**
    * @brief	设置ElevatorSystem
    * @param	ptr	ElevatorSystem指针
    */
	void setpElevSys(ElevatorSystem*);
	/**
    * @brief	floorID楼层上人的信息
    * @param	inFloorID	楼层ID
    * @return	floorID楼层上人的信息
    */
	string meetFloor(int);
	/**
    * @brief	ElevID楼层上人的信息
    * @param	inElevID	电梯ID
    * @return	ElevID楼层上人的信息
    */
	string meetElevator(int);
	/**
    * @brief	当前人的信息
    * @return	当前人的信息
    */
	string currentInfo();
	/**
    * @brief	检测是否终结
    * @return	终结则为true，否则为false
    */
	bool checkEnd();
};

class PeopleSystem
{
private:
    /**电梯系统**/
    ElevatorSystem *pElevSys;
    /**乘客列表**/
    vector <People> peopleList;
    /**乘客人数**/
    int peopleNum;
public:
    /**
    * @brief	乘客系统构造函数
    */
    PeopleSystem(){};
    /**
    * @brief	设置乘客系统构参数
    * @param	inNum	Num乘客人数
	* @param	MOD		MOD到来时间段
	* @param	ptr		电梯系统指针ptr
    */
    void setPeopleSystemInfo(int, int, ElevatorSystem*);
    /**
    * @brief	时间通知事件
    * @param	nowTime	当前时间
    */
    void timeNotify(int);
    /**
    * @brief	检测是否结束
    * @return	终结则为true，否则为false
    */
    bool checkEnd();
    /**
    * @brief	获得乘客信息
    * @param	PeopleID	乘客ID
    * @return	乘客信息
    */
    string getPeopleInfo(int);
    /**
    * @brief	获得电梯信息
    * @param	ElevID		电梯ID
    * @return	电梯信息
    */
    string getElevatorInfo(int);
    /**
    * @brief	获得楼层信息
    * @param	FloorID		楼层ID
    * @return	楼层信息
    */
    string getFloorInfo(int);
};

#endif // PEOPLE_H
