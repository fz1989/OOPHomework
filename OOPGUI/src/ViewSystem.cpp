#include "../include/ViewSystem.h"

void ViewSystem::setElevID(int inElevID)
{
	/**设置elevID**/
    ElevID = inElevID;
}

void ViewSystem::setFloorID(int inFloorID)
{
	/**设置FloorID**/
    FloorID = inFloorID;
}

void ViewSystem::setPeopleID(int inPeopleID)
{
	/**设置PeopleID**/
    PeopleID = inPeopleID;
}

void ViewSystem::setPeopleSystem(PeopleSystem * ptr) {
    /**设置pPeople**/
	pPeople = ptr;
}

string ViewSystem::getElevInfo()
{
   /**获得楼层的信息**/
   return pPeople->getElevatorInfo(ElevID);
}

string ViewSystem::getFloorInfo()
{
    /**获得电梯的信息**/
	return pPeople->getFloorInfo(FloorID);
}

string ViewSystem::getPeopelInfo()
{
    /**获得乘客的信息**/
	return pPeople->getPeopleInfo(PeopleID);
}
