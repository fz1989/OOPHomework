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
#ifndef RANDOMNUMBER_H
#define RANDOMNUMBER_H


#include <cstdlib>
#include <ctime>
class RandomNumber
{
private:
    /**时间种子**/
    time_t seed;
    /**区间最低点**/
    int low;
    /**区间最大点**/
    int high;
public:
    /**
    * @brief	构造函数，初始化时间种子
    */
    RandomNumber(){seed = (unsigned)time(NULL) + rand();}
    /**
    * @brief	带low和high的构造函数
    * @param	inLow	low的输入
	* @param	inHigh	high的输入
    */
    RandomNumber(int, int);
    /**
    * @brief	设定low和high的值
    * @param	inLow	low的输入
	* @param	inHigh	high的输入
    */
    void setRange(int, int);
    /**
    * @brief	返回[low, high]区间上的随机值
    * @return	返回相应的随机值
    */
    int getRandomNumber();
};

#endif // RANDOMNUMBER_H
