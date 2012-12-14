#ifndef ELEVATOR_H_INCLUDED
#define ELEVATOR_H_INCLUDED
class ElevatorInfo {
private:
    int start, low, high, adder;
public:
    ElevatorInfo(int, int, int, int);
    bool checkStay(int);
};

class Elevator {
private:
    ElevatorInfo eInfo;
    int nowFloor, nowload, maxLoad;
    bool acceptRequest(int);
    bool openDoor(int);
public:
    Elevator(ElevatorInfo);
    void goNextFloor();
};
#endif // ELEVATOR_H_INCLUDED
