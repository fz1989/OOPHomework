#include "../include/Elevator.h"
#include <cstdio>
/*****************************************
*������Ϣ��Ĺ��캯��
*****************************************/
ElevatorInfo::ElevatorInfo(int inStart = 1,int inLow = 1,int inHigh = 40,int inAdder = 1)
{
    start = inStart;
    low = inLow;
    high = inHigh;
    adder = inAdder;
}

/*****************************************
*�����ĳһ¥������ͣ��
*****************************************/
bool ElevatorInfo::checkStay(int floor)
{
    /**������ײ����**/
    if (floor == start) return true;
    else
    {
        /**����м�״̬�ĺϷ���**/
        if (floor >= low
                && floor <= high
                && (floor - low) % adder == 0)
            return true;
        /**�������**/
        return false;
    }
}

/*****************************************
*������Ĺ��캯��
*****************************************/
Elevator::Elevator(ElevatorInfo ineInfo):eInfo(ineInfo)
{
    /**��ʼʱ��ʱ���ʱ���㣬��������**/
    totalTime = 0;
    emptyTime = 0;
    /**���õ��ݵ��ж����򣬳�ʼʱΪ����**/
    direction = 0;
    nowLoad = 0;
};

void Elevator::setElevatorInfo(int inMaxLoad, int inSpeed, int inStayTime)
{
    /**����������**/
    maxLoad = inMaxLoad;
    /**���������ٶ�**/
    speed = inSpeed;
    tmpSpeed = speed;
    /**���ó�ʼλ��**/
    RandomNumber num(1, 40);
    /**���õ��ݵ�ͣ��ʱ��**/
    stayTime = inStayTime;
    tmpStaytime = stayTime;
    /**���õ��ݵĳ�ʼλ��**/
    nowFloor = num.getRandomNumber();
}

/*****************************************
*��������һ��
*****************************************/
void Elevator::goNextFloor()
{

    /**��ʱ������**/
    totalTime++;
    /**�������Ϊ�������ʱ������**/
    if (nowLoad == 0)
    {
        emptyTime++;
    }
    if (nowFloor == eInfo.getStart() && direction != STAY)
    {
        /**����ڵײ㣬����������**/
        direction = UP;
    }
    else if (nowFloor == eInfo.getHigh() && direction != STAY)
    {
        /**����ڶ��㣬����������**/
        direction = DOWN;
    }
    /**��ԭ������**/
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
*���ݽ�������
*****************************************/
void Elevator::pushOrder(int destFloor)
{
    /**������������б�**/
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
*���ݵ�������
*****************************************/
void Elevator::popOrder(int destFloor)
{
    /**�ҵ���¼��ǰ��Ϣ��λ��**/
    vector<int> :: iterator  it = find(orderList.begin(), orderList.end(), destFloor);
    orderList.erase(it);
    /**��ɿ�����ͣ��**/
    if (orderList.size() == 0) direction = 0;
    else
    {
        if (nowFloor < orderList[0])
        {
            /**���ڵ�ǰ��������**/
            direction = UP;
        }
        else
        {
            /**���ڵ�ǰ��������**/
            direction = DOWN;
        }
        tmpStaytime = stayTime;
    }
}

/*****************************************
*���ص�ǰ����¥��
*****************************************/
int Elevator::getNowFloor()
{
    return nowFloor;
}

/*****************************************
*�����û��ϵ�������
*****************************************/
bool Elevator::acceptRequest(int destFloor)
{
    /**�����ͣ���ҷ�����**/
    if (eInfo.checkStay(destFloor) && nowLoad < maxLoad)
        return true;
    return false;
}

/*****************************************
*��ȡ���ݵĵ�ǰ�������
*****************************************/
int Elevator::getNowLoad()
{
    /**�������пյ���**/
    return nowLoad;
}

/*****************************************
*���õ������з���
*****************************************/
void Elevator::setDirection(int inDirect)
{
    /**�������пյ���**/
    direction = inDirect;
}

/*****************************************
*�ж��ܷ�ĳ��
*****************************************/
bool Elevator::canGo(int destFloor)
{
    /**������Ӧ��Ϣ**/
    return eInfo.checkStay(destFloor);
}

/*****************************************
*�����е���֪ͨʱ���¼�
*****************************************/
void ElevatorSystem::timeNotify()
{
    /**�������е���**/
    for (int i = 0; i < elevatorNum; i++)
    {
        elevatorList[i].goNextFloor();
    }
}

/*****************************************
*��ȡָ�����ݵ�¥��
*****************************************/
int ElevatorSystem::getFloor(int elevatorID)
{
    /**���ص��ݵ�ǰ����¥��**/
    return elevatorList[elevatorID].getNowFloor();
}

/*****************************************
*�û���������
*****************************************/
int ElevatorSystem::postOrder(int nowFloor, int destFloor)
{
    /**�������е���**/
    for (int i = 0; i < elevatorNum; i++)
    {
        /**��������manzu�յ���**/
        if (elevatorList[i].getNowFloor() == nowFloor && elevatorList[i].acceptRequest(destFloor))
        {
            /**�������пյ���**/
            elevatorList[i].pushOrder(destFloor);
            return i;
        }
    }
    /**�������пյ���**/
    return -1;
}

/************************************************
*Ϊ�û�ѡ��һ���յĵ��ݣ����ı䱻ѡ����ݵ����з���
************************************************/
void ElevatorSystem::selectElevator(int srcFloor, int destFloor)
{
    /**�������пյ���**/
    int maxDiffer = 0x7fffffff, loc = -1;
    for (int i = 0; i < elevatorNum; i++)
    {
        /**�жϿյ��ݲ�ѡ��������ܵ��ﲢ�ҷ��ϵ��ݵ�����**/
        if (elevatorList[i].getNowLoad() == 0
                && elevatorList[i].canGo(destFloor)
                && elevatorList[i].canGo(srcFloor))
        {
            if (abs(elevatorList[i].getNowFloor() - srcFloor) < maxDiffer)
            {
                /**����ά����Сֵ**/
                loc = i;
                maxDiffer = abs(elevatorList[i].getNowFloor() - srcFloor);
            }
        }
    }
    /**�ǺϷ�ֱֵ�ӷ���**/
    if (loc == -1)  return;
    if (elevatorList[loc].getNowFloor() - srcFloor < 0)
    {
        /**Ӧ��������**/
        elevatorList[loc].setDirection(UP);
    }
    else
    {
        /**Ӧ��������**/
        elevatorList[loc].setDirection(DOWN);
    }
}

/**********************************************************
*�˿��뿪����
***********************************************************/
void ElevatorSystem::leaveElevator(int elevID, int destFloor)
{
    /**�˿��뿪���ݴ�����**/
    elevatorList[elevID].popOrder(destFloor);
}

/***********************************************************
*��ʼ������ϵͳ��Ϣ
************************************************************/
void ElevatorSystem::setElevatorSysInfo(int num, int maxLoad, int inSpeed, int instayTime)
{
    /**E0��E1�ĳ�ʼ��**/
    elevatorList.push_back(Elevator(ElevatorInfo(1,1,40,1)));
    elevatorList.push_back(Elevator(ElevatorInfo(1,1,40,1)));
    /**E2��E3�ĳ�ʼ��**/
    elevatorList.push_back(Elevator(ElevatorInfo(1,25,40,1)));
    elevatorList.push_back(Elevator(ElevatorInfo(1,25,40,1)));
    /**E4��E5�ĳ�ʼ��**/
    elevatorList.push_back(Elevator(ElevatorInfo(1,1,25,1)));
    elevatorList.push_back(Elevator(ElevatorInfo(1,1,25,1)));
    /**E6��E7�ĳ�ʼ��**/
    elevatorList.push_back(Elevator(ElevatorInfo(1,2,40,2)));
    elevatorList.push_back(Elevator(ElevatorInfo(1,2,40,2)));
    /**E8��E9�ĳ�ʼ��**/
    elevatorList.push_back(Elevator(ElevatorInfo(1,1,39,2)));
    elevatorList.push_back(Elevator(ElevatorInfo(1,1,39,2)));
    /**s���õ��ݵ���Ӧ����**/
    for (int i = 0; i < 10; i++)
    {
        elevatorList[i].setElevatorInfo(maxLoad, inSpeed, instayTime);
    }
    elevatorNum = num;
    elevatorMaxload = maxLoad;
    speed = inSpeed;
}

