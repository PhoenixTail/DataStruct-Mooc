#include <stdio.h>
#include <stdlib.h>
#include "sort_comm.h"

/*数据结构从1开始,heap_size插入前的size*/
/*
void add_to_heap(int data, int * heap, int heap_size)
{
    int idx = 0;

    if(heap_size == 0) {
        heap[heap_size+1] = data;
        return;
    }

    for(idx = heap_size+1;idx >= 1; idx = idx/2) {
        if(data > heap[idx/2]) 
            heap[idx] = heap[idx/2];
        else
            break;
    }

    heap[idx] = data;    
}
*/

/*heap数据结构从下标0开始*/
void add_to_heap(int data, int * heap, int heap_size)
{
    int idx = 0;

    if(heap_size == 0) {
        heap[heap_size] = data;
        return;
    }

    for(idx = heap_size;idx >0; idx = (idx-1)/2) {
        if(data > heap[(idx-1)/2]) 
            heap[idx] = heap[(idx-1)/2];
        else
            break;
    }

    heap[idx] = data;    
}

void create_heap(int *src, int *dst, int num)
{
    int i = 0;
    for(i = 0; i < num; i++) {
        dst[i] = 0;
    }

    //dst[0] = MAX; dst[0] = MIN;

    for(i = 0; i< num ;i++) {
        add_to_heap(src[i], dst, i);
    }
}

/*假设heap数据结构从下标0开始,heap_size 删除前的heap_size*/
void heap_del_sort(int *src, int *heap, int heap_size)
{
    int i = 0;
    int data = 0;
    int bigger_idx = 0;
    int idx = heap_size - 1;
     
    while(idx>0) {
        swap(&heap[0],&heap[idx]);
        idx--;

        data = heap[0];
        i = 0;

        while(i <= idx) {
            if((i+1)*2-1 > idx) {
                break;
            }
            else if ((i+1)*2 > idx) {
                bigger_idx = (i+1)*2-1;
            }
            else {
                bigger_idx = heap[(i+1)*2-1] > heap[(i+1)*2] ? (i+1)*2-1: (i+1)*2;
            }

            if(data < heap[bigger_idx]) {
                heap[i] = heap[bigger_idx];
                i = bigger_idx;
            } else {
                break;
            }
        }
        heap[i] = data;
    }
    for(i = 0; i < heap_size; i++) {
        src[i] = heap[i];
    }
}

void heap_sort(int *arr, int num)
{
    int *temp = (int *)malloc(num*sizeof(int));
    
    if(!temp)  return;

    create_heap(arr,temp,num);
    heap_del_sort(arr,temp,num);

    free(temp);
}







