#include <iostream>

class Clock {
private:
    int position;
public:
    Clock();
    void Tick(int times);
    bool IsZero();
    void SetPos(int value);
    int GetPos();
};

class ClockMatrix{
private:
    int op_1[9] = {1,1,0,1,1,0,0,0,0};
    int op_2[9] = {1,1,1,0,0,0,0,0,0};
    int op_3[9] = {0,1,1,0,1,1,0,0,0};
    int op_4[9] = {1,0,0,1,0,0,1,0,0};
    int op_5[9] = {0,1,0,1,1,1,0,1,0};
    int op_6[9] = {0,0,1,0,0,1,0,0,1};
    int op_7[9] = {0,0,0,1,1,0,1,1,0};
    int op_8[9] = {0,0,0,0,0,0,1,1,1};
    int op_9[9] = {0,0,0,0,1,1,0,1,1};
    int *FindOperation(int op_index);

public:
    Clock clock[9];
    void DoOperation(int op_index, int times);
    void ClocksSet(int *SetArray);
};



