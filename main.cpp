#include <iostream>
#include "./include/ElevatorSimulateSystem.h"
#include <cstdlib>
#include <cstdio>
using namespace std;

int main()
{
    int K, N, M, S, T;
    freopen("error.xls", "w", stderr);
    //freopen("people.log", "w", stdout);
    //10 1000 10 5 10
    cin >> K >> N >> M >> S >> T;
    ElevatorSimulateSystem sys(K, N, M, S, T);
    sys.Start();
    return 0;
}
