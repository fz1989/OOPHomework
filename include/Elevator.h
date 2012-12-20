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
#ifndef ELEVATOR_H
#define ELEVATOR_H

#include <vector>
#include <queue>
#include <list>
#include <algorithm>
#include "../include/RandomNumber.h"
using namespace std;

#define UP  1
#define DOWN -1
#define STAY 0
class ElevatorInfo
{
private:
    int start, low, high, adder;
public:
    /**
    * @brief ������ײ��¥�㣬һ����1
    */
    int getStart(){return start;}
    /**
    * @brief ������ײ��¥�㣬һ����1
    */
    int getLow(){return low;}
    /**
    * @brief ������ײ��¥�㣬һ����1
    */
    int getHigh(){return high;}
    /**
    * @brief ������ײ��¥�㣬һ����1
    * @param error Error data
    */
    ElevatorInfo(int, int, int, int);
    /**
    * @brief ������ײ��¥�㣬һ����1
    */
    bool checkStay(int);
};

class Elevator{
private:
    ElevatorInfo eInfo;
    int nowFloor, nowLoad, maxLoad, direction;
    int speed, tmpSpeed, totalTime, emptyTime, stayTime, tmpStaytime;
	vector <int> orderList;
public:
    /**
    * @brief ������ײ��¥�㣬һ����1
    */
    Elevator(ElevatorInfo);
    /**
    * @brief ������ײ��¥�㣬һ����1
    */
    bool acceptRequest(int);
    /**
    * @brief ������ײ��¥�㣬һ����1
    */
	void pushOrder(int);
	/**
    * @brief ������ײ��¥�㣬һ����1
    */
	void popOrder(int);
	/**
    * @brief ������ײ��¥�㣬һ����1
    */
	int getNowFloor();
    /**
    * @brief ������ײ��¥�㣬һ����1
    */
    void goNextFloor();
    /**
    * @brief ������ײ��¥�㣬һ����1
    */
    void setDirection(int);
    /**
    * @brief ������ײ��¥�㣬һ����1
    */
    int getNowLoad();
    /**
    * @brief ������ײ��¥�㣬һ����1
    */
    bool canGo(int);
    /**
    * @brief ������ײ��¥�㣬һ����1
    */
    void setElevatorInfo(int,int,int);
};

class ElevatorSystem {
private:
	int elevatorNum;
	int elevatorMaxload;
	int speed;
	vector <Elevator> elevatorList;
public:
	/**
    * @brief ������ײ��¥�㣬һ����1
    */
	void timeNotify();
	/**
    * @brief ������ײ��¥�㣬һ����1
    */
	int getFloor(int);
	/**
    * @brief ������ײ��¥�㣬һ����1
    */
	int postOrder(int, int);
	/**
    * @brief ������ײ��¥�㣬һ����1
    */
	void leaveElevator(int, int);
	/**
    * @brief ������ײ��¥�㣬һ����1
    */
	void selectElevator(int, int);
	/**
    * @brief ������ײ��¥�㣬һ����1
    */
	void setElevatorSysInfo(int, int, int, int);
};

#endif // ELEVATOR_H
