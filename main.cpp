#include <iostream>
#include "./include/ElevatorSimulateSystem.h"
using namespace std;

int main()
{
    int K, N, M, S, T;
    cin >> K >> N >> M >> S >> T;
    ElevatorSimulateSystem sys(K, N, M, S, T);
    sys.Start();
    return 0;
}
