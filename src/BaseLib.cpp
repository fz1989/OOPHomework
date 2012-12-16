#include "../include/BaseLib.h"

ElevatorSimulateSystem::ElevatorSimulateSystem(int K,
        int N,
        int M,
        int S,
        int T)
{
    maxPsaaangersPerElevator = K;
    passangersNum = N;
    passangerStartTime = M;
    secondPerFloor = S;
    secondPerBoardElevator = T;
}

bool ElevatorSimulateSystem::End()
{
    return true;
}

void ElevatorSimulateSystem::Start()
{
    while (!End()) {

    }

}
