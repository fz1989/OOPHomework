#ifndef PEOPLE_H
#define PEOPLE_H

#include "../include/Elevator.h"
#include "../include/RandomNumber.h"
#include <vector>
#include <algorithm>
using namespace std;
#define NOTSTART        -1
#define WAITING         0
#define INUSING         1
class People
{
private:
    int state, needTime, takeTimes, ID;
    int destFloor, nowFloor, elevID;
    vector <int> requestTime;
	vector <int> acceptedTime;
	ElevatorSystem *pElevSys;
	// TODO (fz#1#): 此处变量修改为static
public:
    People();
	People(int, int);
    void setDestInfo();
    int getRemainTimes();
	void updateInfo(int);
	void setpElevSys(ElevatorSystem*);
};

class PeopleSystem
{
private:
    ElevatorSystem *pElevSys;
    vector <People> peopleList;
    int peopleNum;
public:
    PeopleSystem(){};
    void setPeopleSystemInfo(int, int, ElevatorSystem*);
    void timeNotify(int);
    bool checkEnd();
};

#endif // PEOPLE_H
