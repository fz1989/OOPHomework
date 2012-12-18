#include "../include/ElevatorSimulateSystem.h"
#include "../include/People.h"
#include "../include/Elevator.h"
#include "../include/RandomNumber.h"

ElevatorSimulateSystem::ElevatorSimulateSystem(int K, int N, int M, int S,int T)
{
    maxPsaaangersPerElevator = K;
    passangersNum = N;
    passangerStartTime = M;
    secondPerFloor = S;
    secondPerBoardElevator = T;
    TE.setTimeEventInfo(&PS, &ES);
    PS.setPeopleSystemInfo(passangersNum, passangerStartTime, &ES);
    ES.setElevatorSysInfo(10, K, S, T);
}

bool ElevatorSimulateSystem::End()
{
    return PS.checkEnd();
}

void ElevatorSimulateSystem::Start()
{
    while (!End())
    {
        TE.TimeBeat();
    }
}
