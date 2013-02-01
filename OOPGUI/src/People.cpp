#include "../include/People.h"
#include <cstdio>
#include <cstring>

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
    totalTime = takeTimes - 1;
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
		/**最后一册楼层目标为1**/
        destFloor = 1;
        takeTimes--;
		state = FINISHED;
        return;
    }
	/**否则在[2,40]内随机选取**/
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
    if (needTime == 0 && state != FINISHED)
    {
		/**状态未开始**/
        if (state == NOTSTART)
        {
			/**转到等待状态**/
            state = WAITING;
            requestTime.push_back(nowTime);
            setDestInfo();
        }
		/**状态为等待**/
        if (state == WAITING)
        {
			/**选择电梯**/
            pElevSys->selectElevator(nowFloor, destFloor);
            elevID = pElevSys->postOrder(nowFloor, destFloor);
            if (elevID != -1)
            {
				/**成功则改变相应状态**/
                state = INUSING;
                acceptedTime.push_back(nowTime);
            }
        }
		/**状态为使用**/
        if (state == INUSING)
        {
            nowFloor = pElevSys->getFloor(elevID);
            if (nowFloor == destFloor)
            {
				/**供下一次设置**/
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

string People::meetElevator(int inElevID) {
	/**打印电梯信息**/
    if (state == INUSING && elevID == inElevID) {
        char tmp[100];
        memset(tmp, '\0', sizeof(tmp));
        sprintf(tmp, "%d-%d\n", ID + 1, destFloor);
        return string(tmp);
    }
    return "";
}

string People::currentInfo() {
	/**打印乘客信息**/
    char tmp[100];
    memset(tmp, '\0', sizeof(tmp));
	if (state == FINISHED) {
		string ret = "";
		sprintf(tmp, "FINISHED\n");
		ret += tmp;
		for (int i = 0; i < (int)acceptedTime.size(); i++) {
			sprintf(tmp, "requireTime:%d acceptedTime:%d\n", requestTime[i], acceptedTime[i]);
			ret += tmp;
		}
		return ret;
	}
    else if (state == NOTSTART) {
        sprintf(tmp, "NOTSTART: %d\n", needTime);
    } else if (state == INUSING) {
        sprintf(tmp, "INUSING: %d-%d\n", ID + 1, destFloor);
    } else {
        sprintf(tmp, "WAITING: %d-%d\n", ID + 1, destFloor);
    }
    return string(tmp);
}

string People::meetFloor(int inFloorID) {
	/**打印楼层信息**/
    if (state == WAITING && inFloorID == nowFloor) {
        char tmp[100];
        memset(tmp, '\0', sizeof(tmp));
        sprintf(tmp, "WAITING: %d-%d\n", ID + 1, destFloor);
        return string(tmp);
    }
	/*else if (state == NOTSTART && inFloorID == nowFloor) {
        char tmp[100];
        memset(tmp, '\0', sizeof(tmp));
        sprintf(tmp, "NOTSTART: %d\n", ID);
        return string(tmp);

    }
	*/
    return "";
}

bool People::checkEnd()
{
	/**检测乘客是否结束**/
	return (state == FINISHED);

}

void PeopleSystem::setPeopleSystemInfo(int inNum, int MOD, ElevatorSystem *ptr)
{
	/**设置乘客系统信息**/
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
	/**通知各个乘客更新状态**/
	RandomNumber num(0, peopleNum);
	int start = 0;// num.getRandomNumber();
    for (int i = 0; i < peopleNum; i++)
    {
        peopleList[(start + i) % peopleNum].updateInfo(nowTime);
    }
}

bool PeopleSystem::checkEnd()
{
	/**检测活动是否结束**/
    for (int i = 0; i < peopleNum; i++)
    {
        if (!peopleList[i].checkEnd())    return false;
    }
    return true;
}

string PeopleSystem::getElevatorInfo(int ElevID) {
	/**获取电梯上乘客的信息**/
    string ret = "";
	char tmp[200];
	sprintf(tmp, "总时间:%d 空闲时间%d\n", pElevSys->getTotalTime(ElevID), pElevSys->getEmptyTime(ElevID));
	ret += tmp;
    for (int i = 0; i < peopleNum; i++) {
        ret += peopleList[i].meetElevator(ElevID);
    }
    return ret;
}

string PeopleSystem::getFloorInfo(int FloorID) {
	/**获取楼层上乘客的信息**/
    string ret = "";
    for (int i = 0; i < peopleNum; i++) {
        ret += peopleList[i].meetFloor(FloorID);
    }
    return ret;
}

string PeopleSystem::getPeopleInfo(int PeopleID) {
	/**获取乘客的信息**/
    string ret = "";
    ret += peopleList[PeopleID].currentInfo();
    return ret;
}

