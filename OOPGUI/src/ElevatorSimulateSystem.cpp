#include "../include/ElevatorSimulateSystem.h"
#include "../include/People.h"
#include "../include/Elevator.h"
#include "../include/RandomNumber.h"
#include <iostream>
#include <string>
using namespace std;

ElevatorSimulateSystem::ElevatorSimulateSystem(int K, int N, int M, int S,int T)
{
	/**初始化相应的参数**/
    maxPsaaangersPerElevator = K;
    passangersNum = N;
    passangerStartTime = M;
    secondPerFloor = S;
    secondPerBoardElevator = T;
    TE.setTimeEventInfo(&PS, &ES);
    PS.setPeopleSystemInfo(passangersNum, passangerStartTime, &ES);
    ES.setElevatorSysInfo(10, K, S, T);
    VS.setPeopleSystem(&PS);
}

bool ElevatorSimulateSystem::End()
{
	/**检测系统是否停止**/
    return PS.checkEnd();
}

void ElevatorSimulateSystem::Start()
{
	/**系统直接运行模式**/
    while (!End())
    {
        TE.TimeBeat();
    }
}

void ElevatorSimulateSystem::stepStart()
{
	/**单步运行模式**/
	TE.TimeBeat();
}
