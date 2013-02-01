#include "../include/Elevator.h"
#include <cstdio>

ElevatorInfo::ElevatorInfo(int inStart = 1,int inLow = 1,int inHigh = 40,int inAdder = 1)
{
    /**start为起始楼层**/
    start = inStart;
    /**除起始楼层以外的最低楼层**/
    low = inLow;
    /**电梯能到达的最高层**/
    high = inHigh;
    /**每次能向上走的步长**/
    adder = inAdder;
}

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

Elevator::Elevator(ElevatorInfo ineInfo):eInfo(ineInfo)
{
    /**初始时的时间计时清零，负载清零**/
    totalTime = 0;
    emptyTime = 0;
    /**设置电梯的行动方向，初始时为保持**/
    direction = 0;
    /**初始人员负载为0**/
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
    tmpStaytime = 0;
    /**设置电梯的初始位置**/
    nowFloor = num.getRandomNumber();
}

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
    /**如果有人上下则应该等待**/
    if (tmpStaytime != 0)
    {
        tmpStaytime--;
        if (tmpStaytime == 0)
        {
            /**上下人完毕则应开始启动，重新复制速度变量**/
            tmpSpeed = speed;
        }
        return;
    }
    /**电梯正常上下行进则应当计算何时上下楼**/
    tmpSpeed--;
    if (tmpSpeed == 0)
    {
        nowFloor += direction;
        tmpSpeed = speed;
    }
}

void Elevator::pushOrder(int destFloor)
{
    /**有人要上则应加上等待时间**/
    tmpStaytime += stayTime;
    /**加入电梯请求列表**/
    orderList.push_back(destFloor);
    /**负载人数自增**/
    nowLoad++;
    /**只有一个人则应该决定电梯运行的方向**/
    if (orderList.size() == 1)
    {
        if (orderList[0] > nowFloor)
        {
            /**向上走**/
            direction = UP;
        }
        else
        {
            /**向下走**/
            direction = DOWN;
        }
    }
}

void Elevator::popOrder(int destFloor)
{
    /**找到记录当前信息的位置**/
    vector<int> :: iterator  it = find(orderList.begin(), orderList.end(), destFloor);
    orderList.erase(it);
    nowLoad--;
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
        /**有人要下则应当加上等待时间**/
        tmpStaytime += stayTime;
    }
}

int Elevator::getNowFloor()
{
    return nowFloor;
}

bool Elevator::acceptRequest(int destFloor)
{
    /**如果能停并且非满载**/
    if (eInfo.checkStay(destFloor) && nowLoad < maxLoad)
        return true;
    return false;
}

int Elevator::getNowLoad()
{
    /**遍历所有空电梯**/
    return nowLoad;
}

void Elevator::setDirection(int inDirect)
{
    /**遍历所有空电梯**/
    direction = inDirect;
}

bool Elevator::canGo(int destFloor)
{
    /**返回相应信息**/
    return eInfo.checkStay(destFloor);
}

void ElevatorSystem::timeNotify()
{
    /**遍历所有电梯**/
	RandomNumber num(0,10);
	int start = 0;//num.getRandomNumber();
    for (int i = 0; i < elevatorNum; i++)
    {
        /**通知所有电梯进行下一步操作**/
        elevatorList[(start + i) % elevatorNum].goNextFloor();
    }
}

int ElevatorSystem::getFloor(int elevatorID)
{
    /**返回电梯当前所在楼层**/
    return elevatorList[elevatorID].getNowFloor();
}

int ElevatorSystem::postOrder(int nowFloor, int destFloor)
{
    /**遍历所有电梯**/
	RandomNumber num(0,elevatorNum);
	int start = 0;//num.getRandomNumber();
    for (int i = 0; i < elevatorNum; i++)
    {
        /**遍历所有manzu空电梯**/
        if (elevatorList[(start + i) % elevatorNum].getNowFloor() == nowFloor && elevatorList[(start + i) % elevatorNum].acceptRequest(destFloor))
        {
            /**遍历所有空电梯**/
            elevatorList[(start + i) % elevatorNum].pushOrder(destFloor);
            return (start + i) % elevatorNum;
        }
    }
    /**遍历所有空电梯**/
    return -1;
}

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

void ElevatorSystem::leaveElevator(int elevID, int destFloor)
{
    /**乘客离开电梯处理函数**/
    elevatorList[elevID].popOrder(destFloor);
}

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

int ElevatorSystem::getTotalTime(int inElevID) {
    return elevatorList[inElevID].getTotalTime();
}

int ElevatorSystem::getEmptyTime(int inElevID) {
    return elevatorList[inElevID].getEmptyTime();
}
