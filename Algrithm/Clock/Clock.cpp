#include "Clock.h"
using namespace std;


Clock::Clock()
{
    position = 0;
}

void Clock::SetPos(int value)
{
    position = value%4;
}

int Clock::GetPos()
{
    return position;
}

void Clock::Tick(int times)
{
    position = position+times;
    position %= 4;
}

bool Clock::IsZero()
{
    return((position%4)==0);
}

//////////////////////////////////

int * ClockMatrix::FindOperation(int op_index)
{
    int * op = NULL;
    switch(op_index) {
        case 1: op = op_1; break;
        case 2: op = op_2; break;
        case 3: op = op_3; break;
        case 4: op = op_4; break;
        case 5: op = op_5; break;
        case 6: op = op_6; break;
        case 7: op = op_7; break;
        case 8: op = op_8; break;
        case 9: op = op_9; break;
    }
    return op;
}

void ClockMatrix::DoOperation(int op_index, int times)
{
    int *op_array = NULL;

    if(times == 0)
        return;

    op_array = FindOperation(op_index);

    for(int i = 0; i < 9; i++) {
        if(op_array[i] != 0 )
            clock[i].Tick(times);
    }
}

void ClockMatrix::ClocksSet(int *SetArray)
{
    for(int i = 0; i < 9 ; i++) {
        /* BUG,不为0可能为之前的clock残余，也要清除，不是默认状态
        if(SetArray[i]!=0) {
            clock[i].SetPos(SetArray[i]);
        }
        */
        clock[i].SetPos(SetArray[i]);
    }
}


