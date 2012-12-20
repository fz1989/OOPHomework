#include "../include/People.h"
#include <cstdio>
/*******************************************
*人员信息的构造函数
*******************************************/
People::People(int MOD, int inID)
{
    /**设置人的ID**/
    ID = inID;
    /**初始时没有动作**/
    state = NOTSTART;
    /**设置到来时间**/
    RandomNumber num(1, MOD * 60);
    needTime = num.getRandomNumber();
    /**设置总共请求次数**/
    RandomNumber times(1, 10);
    takeTimes = times.getRandomNumber() + 1;
    /**设置初始所在楼层和目标楼层**/
    nowFloor = 1;
    destFloor = -1;
}

void People::setDestInfo()
{
    state = WAITING;
    RandomNumber num(2, 40);
    if (takeTimes == 1)
    {
        destFloor = 1;
        takeTimes--;
        return;
    }
    takeTimes--;
    destFloor = num.getRandomNumber();

}
int People::getRemainTimes()
{
    return takeTimes;
}
void People::updateInfo(int nowTime)
{
    if (takeTimes < 0)  return;
    if (needTime > 0)
    {
        needTime--;
    }
    if (needTime == 0)
    {
        if (state == NOTSTART)
        {
            state = WAITING;
            requestTime.push_back(nowTime);
            setDestInfo();
        }
        if (state == WAITING)
        {
            pElevSys->selectElevator(nowFloor, destFloor);
            elevID = pElevSys->postOrder(nowFloor, destFloor);
            if (elevID != -1)
            {
                state = INUSING;
                acceptedTime.push_back(nowTime);
            }
        }
        if (state == INUSING)
        {
            nowFloor = pElevSys->getFloor(elevID);
            if (nowFloor == destFloor)
            {
                pElevSys->leaveElevator(elevID, destFloor);
                state = NOTSTART;
                RandomNumber num(10, 120);
                needTime = num.getRandomNumber();
            }
        }
    }
    //printf("%d\n", nowTime);
    //fprintf(stderr, "People's ID id is %d\t nowtime is %d\t state is %d\t needTime is %d\t nowFloor is %d\t destFloor is %d\t takeTimes is %d\n", ID, nowTime,state, needTime,  nowFloor, destFloor, takeTimes);
}

void People::setpElevSys(ElevatorSystem *ptr)
{
    pElevSys = ptr;
}

void PeopleSystem::setPeopleSystemInfo(int inNum, int MOD, ElevatorSystem *ptr)
{
    peopleNum = inNum;
    for (int i = 0; i < peopleNum; i++)
    {
        peopleList.push_back(People(MOD, i));
    }
    pElevSys = ptr;
    for (int i = 0; i < peopleNum; i++)
    {
        //peopleList[i].setDestInfo();
        peopleList[i].setpElevSys(ptr);
    }
}

void PeopleSystem::timeNotify(int nowTime)
{
    for (int i = 0; i < peopleNum; i++)
    {
        peopleList[i].updateInfo(nowTime);
    }
}

bool PeopleSystem::checkEnd()
{
    for (int i = 0; i < peopleNum; i++)
    {
        if (peopleList[i].getRemainTimes() >= 0)    return false;
    }
    int ret = 0;
    freopen("test.out", "w", stdout);
    for (int i = 0; i < peopleNum; i++)
    {
        int sum = 0;
        //if (peopleList[i].requestTime.size() == peopleList[i].acceptedTime.size())
        //{
            printf("------------------people %d--------------\n", i);
            for (int j = 0; j < peopleList[i].acceptedTime.size(); j++)
            {
                printf("%d %d\n", peopleList[i].acceptedTime[j], peopleList[i].requestTime[j]);
                sum += (peopleList[i].acceptedTime[j] - peopleList[i].requestTime[j]);
            }
            ret += sum;
            printf("%d\n", sum);
       // }
    }
    printf("%d\n", ret / peopleNum);
    return true;
}

