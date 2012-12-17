#include "../include/Elevator.h"
/*****************************************
*������Ϣ��Ĺ��캯��
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
Elevator::Elevator(ElevatorInfo ineInfo):eInfo(ineInfo) {};

/*****************************************
*��������һ��
*****************************************/
void Elevator::goNextFloor()
{
    if (nowFloor == 1 && direction != 0)
    {
        /**�ײ�������**/
        direction = 1;
    }
    else if (nowFloor == 40 && direction != 0)
    {
        /**����������**/
        direction = -1;
    }
    /**��ԭ������**/
    nowFloor += direction * speed;
}

/*****************************************
*���ݽ�������
*****************************************/
void Elevator::pushOrder(int destFloor)
{
    /**������������б�**/
    orderList.push_back(destFloor);
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
        if (nowFloor < orderList[0]) {
            /**���ڵ�ǰ��������**/
            direction = -1;
        }
        else {
            /**���ڵ�ǰ��������**/
            direction = 1;
        }
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
    {
        /**�����ж��б�**/
        orderList.push_back(destFloor);
        return true;
    }
    return false;
}

/*****************************************
*������Ϣ��Ĺ��캯��
*****************************************/
int Elevator::getNowLoad()
{
    /**�������пյ���**/
    return nowLoad;
}

/*****************************************
*������Ϣ��Ĺ��캯��
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
*������Ϣ��Ĺ��캯��
*****************************************/
int ElevatorSystem::getFloor(int elevatorID)
{
    /**�������пյ���**/
    return elevatorList[elevatorID].getNowFloor();
}

/*****************************************
*�û���������
*****************************************/
int ElevatorSystem::postOrder(int nowFloor, int destFloor)
{
    /**�������пյ���**/
    for (int i = 0; i < elevatorNum; i++)
    {
        /**�������пյ���**/
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
void ElevatorSystem::selectElevator(int destFloor)
{
    /**�������пյ���**/
    int maxDiffer = 0x7fffffff, loc = -1;
    for (int i = 0; i < elevatorNum; i++)
    {
        /**�жϿյ��ݲ�ѡ��������ܵ������**/
        if (elevatorList[i].getNowLoad() == 0 && elevatorList[i].canGo(destFloor))
        {
            if (abs(elevatorList[i].getNowFloor() - destFloor) < maxDiffer)
            {
                /**����ά����Сֵ**/
                loc = i;
                maxDiffer = abs(elevatorList[i].getNowFloor() -destFloor);
            }
        }
    }
    /**�ǺϷ�ֱֵ�ӷ���**/
    if (loc == -1)  return;
    if (elevatorList[loc].getNowFloor() - destFloor < 0)
    {
        /**���ڵ�ǰ����**/
        elevatorList[loc].setDirection(-1);
    }
    else
    {
        /**���ڵ�ǰ����**/
        elevatorList[loc].setDirection(1);
    }
}


