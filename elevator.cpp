#include "elevator.h"
ElevatorInfo::ElevatorInfo(int inStart = 1,
                           int inLow = 1,
                           int inHigh = 40,
                           int inAdder = 1)
{
    start = inStart;
    low = inLow;
    high = inHigh;
    adder = inAdder;
}

bool ElevatorInfo::checkStay(int floor) {
    if (floor == start) return true;
    else {
        if (floor >= low
            && floor <= high
            && (floor - low) % adder == 0)
            return true;
        return false;
    }
}

Elevator::Elevator(ElevatorInfo ineInfo):eInfo(ineInfo){};

Elevator::openDoor(int floor) {
    if (eInfo.checkStay(floor)) {
        if (existPassengerDown()) {
            for (int i = 0; i < 100; i++) {

            }
        }
    }
}

Elevator::acceptRequest(int floor) {

}

