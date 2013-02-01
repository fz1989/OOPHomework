/*
 * OOPHomework - fz1989's OOPHomework
 * Copyright (C) 2012-2012 fz1989.
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#ifndef VIEWSYSTEM_H
#define VIEWSYSTEM_H
#include "../include/People.h"
#include <string>
#include <cstring>
using namespace std;

class ViewSystem
{
private:
    /**电梯ID**/
    int ElevID;
    /**乘客ID**/
    int PeopleID;
    /**楼层ID**/
    int FloorID;
    /**乘客管理系统**/
    PeopleSystem *pPeople;
public:
    /**
    * @brief	构造函数	
    */
    ViewSystem() {};
    /**
    * @brief	设置乘客管理系统
    * @param	ptr	PeopleSystem指针
    */
    void setPeopleSystem(PeopleSystem *);
    /**
    * @brief	设置elevID
    * @param	inElevID	输入elevID
    */
    void setElevID(int);
    /**
    * @brief	设置PeopleID
    * @param	inPeopleID	输入PeopleID
    */
    void setPeopleID(int);
    /**
    * @brief	设置FloorID
    * @param	inFloorID	输入FloorID
    */
    void setFloorID(int);
    /**
    * @brief	获得电梯的信息
    * @return	电梯信息字符串
    */
    string getElevInfo();
    /**
    * @brief	获得乘客的信息
    * @return	乘客信息字符串
    */
    string getPeopelInfo();
    /**
    * @brief	获得楼层的信息
    * @return	楼层信息字符串
    */
    string getFloorInfo();
};

#endif // VIEWSYSTEM_H
