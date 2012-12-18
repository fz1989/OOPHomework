#ifndef ELEVATOR_H
#define ELEVATOR_H

#include <vector>
#include <queue>
#include <list>
#include <algorithm>
using namespace std;

#define UP  1
#define DOWN -1
#define STAY 0
class ElevatorInfo
{
private:
    int start, low, high, adder;
public:
    ElevatorInfo(int, int, int, int);
    bool checkStay(int);
};

class Elevator{
private:
    ElevatorInfo eInfo;
    int nowFloor, nowLoad, maxLoad, direction, speed, totalTime, emptyTime;
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
};

class ElevatorSystem {
private:
	int elevatorNum;
	int elevatorMaxload;
	vector <Elevator> elevatorList;
public:
	void timeNotify();
	int getFloor(int);
	int postOrder(int, int);
	void leaveElevator(int, int);
	void selectElevator(int);
};

#endif // ELEVATOR_H
