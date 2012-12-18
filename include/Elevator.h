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
    int getStart(){return start;}
    int getLow(){return low;}
    int getHigh(){return high;}
    ElevatorInfo(int, int, int, int);
    bool checkStay(int);
};

class Elevator{
private:
    ElevatorInfo eInfo;
    int nowFloor, nowLoad, maxLoad, direction;
    int speed, tmpSpeed, totalTime, emptyTime, stayTime, tmpStaytime;
	vector <int> orderList;
public:
    Elevator(ElevatorInfo);
    bool acceptRequest(int);
	void pushOrder(int);
	void popOrder(int);
	int getNowFloor();
    void goNextFloor();
    void setDirection(int);
    int getNowLoad();
    bool canGo(int);
    void setElevatorInfo(int,int,int);
};

class ElevatorSystem {
private:
	int elevatorNum;
	int elevatorMaxload;
	int speed;
	vector <Elevator> elevatorList;
public:
	void timeNotify();
	int getFloor(int);
	int postOrder(int, int);
	void leaveElevator(int, int);
	void selectElevator(int, int);
	void setElevatorSysInfo(int, int, int, int);
};

#endif // ELEVATOR_H
