#include "sort_comm.h"

void bubble_sort(int *arr, int num)
{
    int i, j;
    int sort_ok;

    for(j = num-1; j >= 0; j--) {
        sort_ok = 0;

        for(i = 0; i < j; i++)
            if(arr[i] > arr[i+1]) {
                swap(&arr[i], &arr[i+1]);
                sort_ok = 1;
        }
        if(sort_ok == 0)
            break;
    }
}


