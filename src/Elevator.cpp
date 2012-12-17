#include "../include/Elevator.h"
/*****************************************
*电梯信息类的构造函数
*****************************************/
ElevatorInfo::ElevatorInfo(int inStart = 1,
                           int inLow = 1,
                           int inHigh = 40,
                           int inAdder = 1)
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
Elevator::Elevator(ElevatorInfo ineInfo):eInfo(ineInfo) {};

/*****************************************
*电梯走下一层
*****************************************/
void Elevator::goNextFloor()
{
    if (nowFloor == 1 && direction != 0)
    {
        /**底层向上走**/
        direction = 1;
    }
    else if (nowFloor == 40 && direction != 0)
    {
        /**顶层向下走**/
        direction = -1;
    }
    /**按原方向走**/
    nowFloor += direction * speed;
}

/*****************************************
*电梯接受请求
*****************************************/
void Elevator::pushOrder(int destFloor)
{
    /**加入电梯请求列表**/
    orderList.push_back(destFloor);
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
        if (nowFloor < orderList[0]) {
            /**高于当前则向上走**/
            direction = -1;
        }
        else {
            /**低于当前则向下走**/
            direction = 1;
        }
    }
}

/*****************************************
*返回当前算在楼层
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
    {
        /**加入行动列表**/
        orderList.push_back(destFloor);
        return true;
    }
    return false;
}

/*****************************************
*电梯信息类的构造函数
*****************************************/
int Elevator::getNowLoad()
{
    /**遍历所有空电梯**/
    return nowLoad;
}

/*****************************************
*电梯信息类的构造函数
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
*电梯信息类的构造函数
*****************************************/
int ElevatorSystem::getFloor(int elevatorID)
{
    /**遍历所有空电梯**/
    return elevatorList[elevatorID].getNowFloor();
}

/*****************************************
*用户发送请求
*****************************************/
int ElevatorSystem::postOrder(int nowFloor, int destFloor)
{
    /**遍历所有空电梯**/
    for (int i = 0; i < elevatorNum; i++)
    {
        /**遍历所有空电梯**/
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
void ElevatorSystem::selectElevator(int destFloor)
{
    /**遍历所有空电梯**/
    int maxDiffer = 0x7fffffff, loc = -1;
    for (int i = 0; i < elevatorNum; i++)
    {
        /**判断空电梯并选择能最快能到达电梯**/
        if (elevatorList[i].getNowLoad() == 0 && elevatorList[i].canGo(destFloor))
        {
            if (abs(elevatorList[i].getNowFloor() - destFloor) < maxDiffer)
            {
                /**更新维护最小值**/
                loc = i;
                maxDiffer = abs(elevatorList[i].getNowFloor() -destFloor);
            }
        }
    }
    /**非合法值直接返回**/
    if (loc == -1)  return;
    if (elevatorList[loc].getNowFloor() - destFloor < 0)
    {
        /**低于当前向下**/
        elevatorList[loc].setDirection(-1);
    }
    else
    {
        /**高于当前向上**/
        elevatorList[loc].setDirection(1);
    }
}


