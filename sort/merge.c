#include <stdio.h>
#include <stdlib.h>

#include "sort_comm.h"


void merge(int *arr, int *temp, int L, int R, int R_end)
{
    int i = L;
    int j = R;
    int k = L;

    while(i < R && j<= R_end) {
        if(arr[i] <= arr[j]) {
            temp[k++] = arr[i++];
        }
        else { 
            temp[k++] = arr[j++];
        }
    }

    if(i<R)
        while(k<=R_end)
            temp[k++] = arr[i++];

    if(j <= R_end)
        while(k<=R_end)
            temp[k++] = arr[j++];


    for(i = L; i <= R_end; i++) {
        arr[i] = temp[i];
    }
    
}

/*************************************************/
void mergesort_seq(int *arr, int *temp, int num)
{
    int div_len = 2;
    int idx = 0;

    for(div_len = 2; div_len/2 < num ; div_len*=2) {
        for(idx = 0; idx < num-div_len; idx += div_len) {
            merge(arr,temp, idx, idx+div_len/2, idx+div_len-1); 
        }

        if(num - div_len/2 > 0) {
            merge(arr,temp, idx, idx+div_len/2, num-1);
        } 
    }
}


/*************************************************/
void mergesort_iter(int *arr, int *temp, int L, int R)
{
    int center = L+(R-L)/2;
    if(L<R) {
        mergesort_iter(arr,temp,L,center);
        mergesort_iter(arr,temp,center+1,R);
        merge(arr, temp, L, center+1, R);
    }
}

void merge_sort(int *arr, int num)
{
    
    int *temp = (int *)malloc(num*sizeof(int));
    
    if(!temp)  return;

    mergesort_iter(arr,temp,0,num-1);
    //mergesort_seq(arr, temp, num);

    free(temp);
}



