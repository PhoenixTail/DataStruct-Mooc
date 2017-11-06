#include "sort_comm.h"

void shell_ins_sort(int *arr, int num)
{
    int i = 0;
    int j = 0;
    int k = 1;


    
    /*version 2*/
    while(k < num ) {
        k *= 2;
    }

	for(;k > 0; k = (k+1)/2-1) {
		for(i = k; i < num; i+=k) {
			int ins_data = arr[i];
			for(j = i-k; j>=0 && ins_data<arr[j] ; j-=k)
			    arr[j+k] = arr[j];
			arr[j+k] = ins_data;
		}
	}


	/*version 1*/
	/*
    while(k < num ) {
        k *= 2;
    }
    
    for(; k > 0 ; k = (k+1)/2-1) {
        for(i = k; i < num; i+=k) {
            for(j = i; j >=k ; j-=k) {
                if(arr[j-k] > arr[j]) {
                    swap(&arr[j-k], &arr[j]);
                }
				else
				{
					break;
				}
            } 
        }
    }
    */
}