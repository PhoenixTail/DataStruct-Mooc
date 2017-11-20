#include <iostream>
#include <climits>

using namespace std;

/*
void test_main();

int main()
{
    test_main();
    return 0;
}
*/

class Clock {
private:
    int position;
public:

    Clock()
    {
        position = 0;
    }
    void Tick(int times)
    {
        position = position+times;
        position %= 4;
    }
    bool IsZero()
    {
        return((position%4)==0);
    }
    void SetPos(int value)
    {
        position = value%4;
    }

    int GetPos()
    {
        return position;
    }
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

    int *FindOperation(int op_index)
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

public:
    Clock clock[9];
    void DoOperation(int op_index, int times)
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
    void ClocksSet(int *SetArray)
    {
        for(int i = 0; i < 9 ; i++) {
            clock[i].SetPos(SetArray[i]);
        }
    }
};


int sum(int * arr)
{
    int res = 0;
    for(int i = 0; i < 9; i++)
        res+=arr[i];
    return res;
}

void print_result(int *arr) {

    int i;
    int j;

    for(i = 1 ; i<= 9; i++) {
        int times = arr[i-1];
        for(j = 0; j < times; j++) {
            cout<<i<<' ';
        }
    }
}

int main()
{
    int init_status[9] = {0};
    int result_op[9] = {0};
    int tmp_times = INT_MAX;
    int min_times = INT_MAX;
    int min_op[9] = {0};
    ClockMatrix clk_matrix;
    int i,j,k,cnt;

    clk_matrix.ClocksSet(init_status);

    for( i = 0; i < 9 ; i++)
    {
        cin>>init_status[i];
    }

    clk_matrix.ClocksSet(init_status);

    for(i = 0; i < 4; i++)
        for(j = 0; j < 4; j++)
            for(k = 0; k < 4; k++) {
                clk_matrix.ClocksSet(init_status);
                //枚举部分
                result_op[0] = i;
                clk_matrix.DoOperation(1,i);
                result_op[1] = j;
                clk_matrix.DoOperation(2,j);
                result_op[2] = k;
                clk_matrix.DoOperation(3,k);

                //枚举降维
                result_op[3] = (4-clk_matrix.clock[0].GetPos())%4;
                clk_matrix.DoOperation(4, result_op[3]);
                result_op[4] = (4-clk_matrix.clock[1].GetPos())%4;
                clk_matrix.DoOperation(5, result_op[4]);
                result_op[5] = (4-clk_matrix.clock[2].GetPos())%4;
                clk_matrix.DoOperation(6, result_op[5]);
                result_op[6] = (4-clk_matrix.clock[3].GetPos())%4;
                clk_matrix.DoOperation(7, result_op[6]);
                result_op[8] = (4-clk_matrix.clock[4].GetPos())%4;
                clk_matrix.DoOperation(9, result_op[8]);

                //检查是否为解，上面保证了A,B,C,D,E为整点
                if(clk_matrix.clock[5].GetPos() == 0) {
                    if(clk_matrix.clock[6].GetPos() == clk_matrix.clock[7].GetPos() &&
                    clk_matrix.clock[7].GetPos() == clk_matrix.clock[8].GetPos()) {
                        result_op[7] = (4-clk_matrix.clock[6].GetPos())%4;
                        tmp_times = sum(result_op);
                        if(tmp_times < min_times) {
                            min_times = tmp_times;
                            for(cnt = 0; cnt < 9; cnt++)
                                min_op[cnt] = result_op[cnt];
                        }
                    }
                }
            }

    if(tmp_times == INT_MAX)
        cout<<"no solution"<<endl;
    else
        print_result(min_op);

    return 0;
}

