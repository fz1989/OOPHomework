#include "../include/People.h"

People::People()
{
    state = NOTSTART;
    RandomNumber num(1, 600);
    needTime = num.getRandomNumber();
    RandomNumber times(1, 10);
    takeTimes = times.getRandomNumber() + 1;
    nowFloor = 1;
    destFloor = -1;
}

void People::setDestInfo()
{
    state = WAITING;
    RandomNumber num;
    if (takeTimes == 1)
    {
        destFloor = 1;
    }
    else
    {
        num.setRange(1, 40);
    }
    takeTimes--;
    destFloor = num.getRandomNumber();

}
int People::getRemainTimes() {
    return takeTimes;
}
void People::updateInfo(int nowTime)
{
    needTime--;
    if (needTime == 0) {
        if (state == NOTSTART) {
            state = WAITING;
            requestTime.push_back(nowTime);
            setDestInfo();
        }
        if (state == WAITING) {
            pElevSys->selectElevator(destFloor);
            elevID = pElevSys->postOrder(nowFloor, destFloor);
            if (elevID != -1) {
                state = INUSING;
                acceptedTime.push_back(nowTime);
            }
        }
        if (state == INUSING) {
            nowFloor = pElevSys->getFloor(elevID);
            if (nowFloor == destFloor) {
                pElevSys->leaveElevator(elevID, destFloor);
                state = NOTSTART;
                RandomNumber num(10, 120);
                needTime = num.getRandomNumber();
            }
        }
    }
}

void People::setpElevSys(ElevatorSystem *ptr) {
    pElevSys = ptr;
}

void PeopleSystem::setPeopleSystemInfo(int inNum, ElevatorSystem *ptr) {
    peopleNum = inNum;
    for (int i = 0; i < peopleNum; i++) {
        peopleList.push_back(People());
    }
    pElevSys = ptr;
    for (int i = 0; i < peopleNum; i++) {
        peopleList[i].setDestInfo();
        peopleList[i].setpElevSys(ptr);
    }
}

void PeopleSystem::timeNotify(int nowTime) {
    for (int i = 0; i < peopleNum; i++) {
        peopleList[i].updateInfo(nowTime);
    }
}

bool PeopleSystem::checkEnd() {
    for (int i = 0; i < peopleNum; i++) {
        if (peopleList[i].getRemainTimes() != 0)    return false;
    }
    return true;
}

