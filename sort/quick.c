#include "sort_comm.h"

#define GATE 50

void quick_sort(int *arr, int num)
{
    qsort_iter(arr, 0, num-1);
}

void qsort_iter(int *arr, int L, int R)
{
    int pivot;
    int i = L;
    int j = R-1;

    if(R-L> GATE) {
        pivot = find_pivot(arr, L, R);
        while(i<j) {
            while(arr[i] < pivot) i++;
            while(arr[j] > pivot) j--;
            swap(&arr[i],&arr[j])
        }
        swap(&arr[R],&arr[i]);
        qsort(arr, L, i-1);
        qsort(arr,i+1,R);
    }

    else {
        insertion_sort(&arr[L], R-L+1);
    }
    
}