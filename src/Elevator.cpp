#include "../include/Elevator.h"
#include <cstdio>
/*****************************************
*电梯信息类的构造函数
*****************************************/
ElevatorInfo::ElevatorInfo(int inStart = 1,int inLow = 1,int inHigh = 40,int inAdder = 1)
{
    start = inStart;
    low = inLow;
    high = inHigh;
    adder = inAdder;
}

/*****************************************
*检测在某一楼层是能停留
*****************************************/
bool ElevatorInfo::checkStay(int floor)
{
    /**等于最底层可以**/
    if (floor == start) return true;
    else
    {
        /**检测中间状态的合法性**/
        if (floor >= low
                && floor <= high
                && (floor - low) % adder == 0)
            return true;
        /**否则错误**/
        return false;
    }
}

/*****************************************
*电梯类的构造函数
*****************************************/
Elevator::Elevator(ElevatorInfo ineInfo):eInfo(ineInfo)
{
    /**初始时的时间计时清零，负载清零**/
    totalTime = 0;
    emptyTime = 0;
    /**设置电梯的行动方向，初始时为保持**/
    direction = 0;
    nowLoad = 0;
};

void Elevator::setElevatorInfo(int inMaxLoad, int inSpeed, int inStayTime)
{
    /**设置满载量**/
    maxLoad = inMaxLoad;
    /**设置上升速度**/
    speed = inSpeed;
    tmpSpeed = speed;
    /**设置初始位置**/
    RandomNumber num(1, 40);
    /**设置电梯的停留时间**/
    stayTime = inStayTime;
    tmpStaytime = stayTime;
    /**设置电梯的初始位置**/
    nowFloor = num.getRandomNumber();
}

/*****************************************
*电梯走下一层
*****************************************/
void Elevator::goNextFloor()
{

    /**总时间自增**/
    totalTime++;
    /**如果负载为空则空闲时间自增**/
    if (nowLoad == 0)
    {
        emptyTime++;
    }
    if (nowFloor == eInfo.getStart() && direction != STAY)
    {
        /**如果在底层，则需向上走**/
        direction = UP;
    }
    else if (nowFloor == eInfo.getHigh() && direction != STAY)
    {
        /**如果在顶层，则需向下走**/
        direction = DOWN;
    }
    /**按原方向走**/
    if (tmpStaytime != 0)
    {
        tmpStaytime--;
        if (tmpStaytime == 0)
        {
            tmpSpeed = speed;
        }
        return;
    }
    tmpSpeed--;
    if (tmpSpeed == 0)
    {
        nowFloor += direction;
        tmpSpeed = speed;
    }
}

/*****************************************
*电梯接受请求
*****************************************/
void Elevator::pushOrder(int destFloor)
{
    /**加入电梯请求列表**/
    tmpStaytime = stayTime;
    orderList.push_back(destFloor);
    if (orderList.size() == 1)
    {
        if (orderList[0] > nowFloor)
        {
            direction = UP;
        }
        else
        {
            direction = DOWN;
        }
    }
}

/*****************************************
*电梯弹出请求
*****************************************/
void Elevator::popOrder(int destFloor)
{
    /**找到记录当前信息的位置**/
    vector<int> :: iterator  it = find(orderList.begin(), orderList.end(), destFloor);
    orderList.erase(it);
    /**变成空梯则停留**/
    if (orderList.size() == 0) direction = 0;
    else
    {
        if (nowFloor < orderList[0])
        {
            /**高于当前则向上走**/
            direction = UP;
        }
        else
        {
            /**低于当前则向下走**/
            direction = DOWN;
        }
        tmpStaytime = stayTime;
    }
}

/*****************************************
*返回当前所在楼层
*****************************************/
int Elevator::getNowFloor()
{
    return nowFloor;
}

/*****************************************
*接收用户上电梯请求
*****************************************/
bool Elevator::acceptRequest(int destFloor)
{
    /**如果能停并且非满载**/
    if (eInfo.checkStay(destFloor) && nowLoad < maxLoad)
        return true;
    return false;
}

/*****************************************
*获取电梯的当前载人情况
*****************************************/
int Elevator::getNowLoad()
{
    /**遍历所有空电梯**/
    return nowLoad;
}

/*****************************************
*设置电梯运行方向
*****************************************/
void Elevator::setDirection(int inDirect)
{
    /**遍历所有空电梯**/
    direction = inDirect;
}

/*****************************************
*判断能否到某曾
*****************************************/
bool Elevator::canGo(int destFloor)
{
    /**返回相应信息**/
    return eInfo.checkStay(destFloor);
}

/*****************************************
*向所有电梯通知时间事件
*****************************************/
void ElevatorSystem::timeNotify()
{
    /**遍历所有电梯**/
    for (int i = 0; i < elevatorNum; i++)
    {
        elevatorList[i].goNextFloor();
    }
}

/*****************************************
*获取指定电梯的楼层
*****************************************/
int ElevatorSystem::getFloor(int elevatorID)
{
    /**返回电梯当前所在楼层**/
    return elevatorList[elevatorID].getNowFloor();
}

/*****************************************
*用户发送请求
*****************************************/
int ElevatorSystem::postOrder(int nowFloor, int destFloor)
{
    /**遍历所有电梯**/
    for (int i = 0; i < elevatorNum; i++)
    {
        /**遍历所有manzu空电梯**/
        if (elevatorList[i].getNowFloor() == nowFloor && elevatorList[i].acceptRequest(destFloor))
        {
            /**遍历所有空电梯**/
            elevatorList[i].pushOrder(destFloor);
            return i;
        }
    }
    /**遍历所有空电梯**/
    return -1;
}

/************************************************
*为用户选择一个空的电梯，并改变被选择电梯的运行方向
************************************************/
void ElevatorSystem::selectElevator(int srcFloor, int destFloor)
{
    /**遍历所有空电梯**/
    int maxDiffer = 0x7fffffff, loc = -1;
    for (int i = 0; i < elevatorNum; i++)
    {
        /**判断空电梯并选择能最快能到达并且符合电梯的请求**/
        if (elevatorList[i].getNowLoad() == 0
                && elevatorList[i].canGo(destFloor)
                && elevatorList[i].canGo(srcFloor))
        {
            if (abs(elevatorList[i].getNowFloor() - srcFloor) < maxDiffer)
            {
                /**更新维护最小值**/
                loc = i;
                maxDiffer = abs(elevatorList[i].getNowFloor() - srcFloor);
            }
        }
    }
    /**非合法值直接返回**/
    if (loc == -1)  return;
    if (elevatorList[loc].getNowFloor() - srcFloor < 0)
    {
        /**应当向上走**/
        elevatorList[loc].setDirection(UP);
    }
    else
    {
        /**应当向下走**/
        elevatorList[loc].setDirection(DOWN);
    }
}

/**********************************************************
*乘客离开电梯
***********************************************************/
void ElevatorSystem::leaveElevator(int elevID, int destFloor)
{
    /**乘客离开电梯处理函数**/
    elevatorList[elevID].popOrder(destFloor);
}

/***********************************************************
*初始化电梯系统信息
************************************************************/
void ElevatorSystem::setElevatorSysInfo(int num, int maxLoad, int inSpeed, int instayTime)
{
    /**E0，E1的初始化**/
    elevatorList.push_back(Elevator(ElevatorInfo(1,1,40,1)));
    elevatorList.push_back(Elevator(ElevatorInfo(1,1,40,1)));
    /**E2，E3的初始化**/
    elevatorList.push_back(Elevator(ElevatorInfo(1,25,40,1)));
    elevatorList.push_back(Elevator(ElevatorInfo(1,25,40,1)));
    /**E4，E5的初始化**/
    elevatorList.push_back(Elevator(ElevatorInfo(1,1,25,1)));
    elevatorList.push_back(Elevator(ElevatorInfo(1,1,25,1)));
    /**E6，E7的初始化**/
    elevatorList.push_back(Elevator(ElevatorInfo(1,2,40,2)));
    elevatorList.push_back(Elevator(ElevatorInfo(1,2,40,2)));
    /**E8，E9的初始化**/
    elevatorList.push_back(Elevator(ElevatorInfo(1,1,39,2)));
    elevatorList.push_back(Elevator(ElevatorInfo(1,1,39,2)));
    /**s设置电梯的相应参数**/
    for (int i = 0; i < 10; i++)
    {
        elevatorList[i].setElevatorInfo(maxLoad, inSpeed, instayTime);
    }
    elevatorNum = num;
    elevatorMaxload = maxLoad;
    speed = inSpeed;
}

