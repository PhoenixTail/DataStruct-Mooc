#include <iostream>
#include <fstream>


using namespace std;

void res_clear(int res[]) {
    int i;
	for(i = 0; i < 9; i++) {
		res[i] = 0;
	}
}


void status_copy(int *dest[3], int *src[3])
{
    int i,j;
	for(i = 0; i < 3; i++) {
		for(j = 0; j < 3; j++) {
			dest[i][j] = src[i][j];
		}
	}
}



void one_clock_tick(int row, int col, int (*cur_status)[3], int tick_times)
{
	int i = row-1;
	int j = col-1;

	cur_status[i][j] += tick_times;
	cur_status[i][j] %= 4;
}

void operation_1(int number, int times, int (*cur_status)[3])
{
    one_clock_tick(1,1,times,cur_status);
	one_clock_tick(1,2,times,cur_status);
	one_clock_tick(2,1,times,cur_status);
	one_clock_tick(2,2,times,cur_status);
}

void operation_2(int number, int times, int cur_status[3][3])
{
    one_clock_tick(1,1,times,cur_status);
	one_clock_tick(1,2,times,cur_status);
	one_clock_tick(1,3,times,cur_status);
}

void operation_3(int number, int times, int cur_status[3][3])
{
    one_clock_tick(1,2,times,cur_status);
	one_clock_tick(1,3,times,cur_status);
	one_clock_tick(2,2,times,cur_status);
	one_clock_tick(2,3,times,cur_status);
}

void operation_4(int number, int times, int cur_status[3][3])
{
    one_clock_tick(1,1,times,cur_status);
	one_clock_tick(2,1,times,cur_status);
	one_clock_tick(3,1,times,cur_status);
}

void operation_5(int number, int times, int cur_status[3][3])
{
    one_clock_tick(1,2,times,cur_status);
	one_clock_tick(2,1,times,cur_status);
	one_clock_tick(2,2,times,cur_status);
    one_clock_tick(2,3,times,cur_status);
	one_clock_tick(3,2,times,cur_status);
}

void operation_6(int number, int times, int cur_status[3][3])
{
    one_clock_tick(1,3,times,cur_status);
	one_clock_tick(2,3,times,cur_status);
	one_clock_tick(3,3,times,cur_status);
}

void operation_7(int number, int times, int cur_status[3][3])
{
	one_clock_tick(2,1,times,cur_status);
	one_clock_tick(2,2,times,cur_status);
    one_clock_tick(3,1,times,cur_status);
	one_clock_tick(3,2,times,cur_status);
}

void operation_8(int number, int times, int cur_status[3][3])
{
	one_clock_tick(3,1,times,cur_status);
	one_clock_tick(3,2,times,cur_status);
    one_clock_tick(3,3,times,cur_status);
}

void operation_9(int number, int times, int cur_status[3][3])
{
	one_clock_tick(2,2,times,cur_status);
	one_clock_tick(2,3,times,cur_status);
    one_clock_tick(3,2,times,cur_status);
	one_clock_tick(3,3,times,cur_status);
}


void operation(int number, int times, int cur_status[][3]) 
{
	switch (operation) {
		case 1: operation_1(number,times, cur_status[3][3]);
			break;
		case 2: operation_2(number,times, cur_status[3][3]);
			break;
		case 3: operation_3(number, times, cur_status[3][3]);
			break;
		case 4: operation_4(number, times, cur_status[3][3]);
			break;
		case 5: operation_5(number, times, cur_status[3][3]);
			break;
		case 6: operation_6(number, times, cur_status[3][3]);
			break;
		case 7: operation_7(number, times, ur_status[3][3]);
			break;
		case 8: operation_8(number, times, cur_status[3][3]);
			break;
		case 9: operation_9(number, times, cur_status[3][3]s);
			break;
	}
}



bool solve_problem(int status[3][3], int result[9]) 
{
	int i,j,k;
    int temp[3][3];
	int temp_res[9] = {0};
	for(i = 0; i < 4; i++)
		for(j = 0; j < 4; j++)
			for(k = 0; k < 4; k++) {
				status_copy(temp[3][3],status[3][3])
				res_clear(temp_res);

				int times = 0;

                operation(1,i,temp[3][3]);
				res[0] = i;
                operation(2,j,temp[3][3]);
                res[1] = j;
				operation(3,k, temp[3][3]);
				res[2] = k;
                
				times = (4-temp[0][0])%4;
				operation(4, times, temp[3][3]);
                res[3] = times;

                times = (4-temp[0][1])%4;
				operation(5, times, temp[3][3]);
                res[4] = times;

			}
}




int main(){

	int status[3][3];
	int operation_times[9] = {0};
	int i,j,k;

	for(i = 0; i < 3; i++) {
		for(j = 0; j < 3; j++) {
			cin>>status[i][j];
		}
	}

	for(i = 0; i < 3; i++) {
		for(j = 0; j < 3; j++) {
			cout<<status[i][j];
		}
		cout<<endl;
	}

    if(solve_problem())
		print_best();
	else
		cout>>"no result">>endl;

	return 0;
}