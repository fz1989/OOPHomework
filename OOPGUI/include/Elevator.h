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
#ifndef ELEVATOR_H
#define ELEVATOR_H

#include <vector>
#include <queue>
#include <list>
#include <algorithm>
#include "../include/RandomNumber.h"
using namespace std;

#define UP  1
#define DOWN -1
#define STAY 0
class ElevatorInfo
{
private:
    /**start为1**/
    int start;
    /**可行的最低楼层**/
    int low;
    /**可行的最高楼层**/
    int high;
    /**运行的间隔**/
    int adder;
public:
    /**
    * @brief	返回start的楼层
    * @return	start的值
    */
    int getStart(){return start;}
    /**
    * @brief	返回low的值
    * @return	low的值
    */
    int getLow(){return low;}
    /**
    * @brief	返回high的值
    * @return	high的值
    */
    int getHigh(){return high;}
    /**
    * @brief	ElevatorInfo的构造函数
    * @param	inStart 传入start
    * @param	inLow	传入low
    * @param	inHigh	传入high
    * @param	inAdder	传入adder
    */
    ElevatorInfo(int, int, int, int);
    /**
    * @brief	检测在某层是否可以停留
    * @param	floor	楼层号
    * @return	可以停留返回true,否则返回false
    */
    bool checkStay(int);
};

class Elevator{
private:

    /**电梯运行规则**/
    ElevatorInfo eInfo;
    /**电梯当前位置**/
    int nowFloor;
    /**电梯当前负载**/
    int nowLoad;
    /**电梯最大负载**/
    int maxLoad;
    /**电梯运行方向**/
	int	direction;
	/**电梯运行速度标示**/
    int speed;
	int tmpSpeed;
	/**电梯总体运行时间**/
	int totalTime;
	/**电梯空闲时间**/
	int emptyTime;
	/**电梯停留时间**/
	int stayTime;
	int tmpStaytime;
	/**电梯请求顺序列表**/
	vector <int> orderList;
public:
    /**
    * @brief	电梯构造函数
    * @param	ineInfo	ElevatorInfo传入规则
    */
    Elevator(ElevatorInfo);
    /**
    * @brief	接受目标destfloor请求
    * @param	destFloor 	目标楼层
    * @return	可以返回true，否则返回false
    */
    bool acceptRequest(int);
    /**
    * @brief	电梯将destfloor压入order运行队列中
    * @param	destFloor 	目标楼层
    */
    void pushOrder(int);
    /**
    * @brief	弹出到达destfloor的order
    * @param	destFloor 	目标楼层
    */
    void popOrder(int);
    /**
    * @brief	获得nowFloor的值
    * @return	nowFloor的值
    */
    int getNowFloor();
    /**
    * @brief	电梯走下一步动作，更新状态
    */
    void goNextFloor();
    /**
    * @brief	设置电梯运行方向
    * @param	inDirect	设置的运行方向
    */
    void setDirection(int);
    /**
    * @brief	获得当前负载nowLoad
    * @return	nowLoad的值
    */
    int getNowLoad();
    /**
    * @brief	判断destFloor是否可达
    * @param	destFloor 	目标楼层
    * @return	可以到达返回true，否则false
    */
    bool canGo(int);
    /**
    * @brief	设置电梯参数
    * @param	inMaxLoad	传入最大负载
    * @param	inSpeed		传入最大速度
    * @param	inStayTime	传入等待时间
    */
    void setElevatorInfo(int,int,int);
    /**
    * @brief	返回总时间
    * @return	totalTime的值
    */
    int getTotalTime(){return totalTime;};
    /**
    * @brief	返回空闲时间
    * @return	empty的值
    */
    int getEmptyTime(){return emptyTime;};
};

class ElevatorSystem {
private:
	/**电梯的格式**/
	int elevatorNum;
	/**电梯的最大负载**/
	int elevatorMaxload;
	/**电梯的运行速度**/
	int speed;
	/**电梯列表**/
	vector <Elevator> elevatorList;
public:
    /**
    * @brief	时间通知函数，更新状态
    */
    void timeNotify();
    /**
    * @brief	返回指定floorID的所在楼层
    * @param	elevatorID	电梯ID
    * @return	指定floorID的所在楼层
    */
    int getFloor(int);
    /**
    * @brief	发送请求
    * @param	nowFloor	所在的楼层
    * @param	destFloor	目标楼层
    * @return	如果成功返回相应ID，否则是-1
    */
    int postOrder(int, int);
    /**
    * @brief	离开电梯
    * @param	elevID		离开电梯ID
    * @param	destFloor	目标楼层
    */
    void leaveElevator(int, int);
    /**
    * @brief	选择空的电梯，并改变其运动状态
    * @param	srcFloor	起始楼层
    * @param	destFloor	目标楼层
    */
    void selectElevator(int, int);
    /**
    * @brief 	设置电梯的参数
    * @param	num				传入num参数
    * @param	maxLoad			传入maxLoad参数
    * @param	inSpeed			传入Speed参数
    * @param	instayTime		传入stayTime参数
    */
    void setElevatorSysInfo(int, int, int, int);
    /**
    * @brief	返回总时间
    * @param	inElevID		传入ElevID
    * @return	totalTime的值
    */
    int getTotalTime(int) ;
    /**
    * @brief	返回总时间
    * @param	inElevID		传入ElevID
    * @return	totalTime的值
    */
    int getEmptyTime(int);
};

#endif // ELEVATOR_H
