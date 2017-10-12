#include <stdio.h>
#include <stdlib.h>
#include "heap.h"

#define File_Name ".//test.txt"



void read_line(int arr[], int read_size, FILE *fp)
{
    int i = 0;
    if(fp) {
        for(i = 0; i < read_size; i++) {
            fscanf(fp, "%d", arr[i]);
        }
    }
    else {
        for(i = 0; i < read_size; i++) {
            fscanf(stdin, "%d", arr[i]);
        }
    }
}

void print_line(int arr[], int size)
{
    int i = 0;
    for(i = 0; i < size-1; i++) {
        printf("%d ", arr[i]);
    }
    printf("%d\n", arr[size-1]);
}

void test_main()
{
    FILE *fp = stdin;
    int ElementNum_N = 0;
    int PrintNum_M = 0;
    int i = 0;

    int *data_arr = NULL;
    int *index_arr = NULL;

    MinHeapPtr p_heap = NULL;

    fp = fopen(File_Name, "ro");

    if(!fp)    printf("No file\n");

    fscanf(fp, "%d", &ElementNum_N);
    fscanf(fp, "%d", PrintNum_M);

    data_arr = (int *)malloc(ElementNum_N * sizeof(int));
    index_arr = (int *)malloc(PrintNum_M * sizeof(int));

    readline(data_arr, ElementNum_N, fp);
    printline(data_arr, ElementNum_N);
    
    readline(index_arr, PrintNum_M, fp);
    printline(index_arr, PrintNum_M);

    /*完成功能*/

    p_heap = HeapInit(ElementNum_N);
    for(i = 0; i< ElementNum_N, i++) {
        HeapInsert(p_heap, data_arr[i]);
    }
    for(i = 0; i < printNum_M; i++) {
        printPath(p_heap, index_arr[i]);
    }

}

void print_path(MinHeapPtr p_heap, int index)
{
    int i = 0;
    
    for(i = index; i > 0 ; i = i/2) {
        printf("%d", p_heap->heapArr[i]);
        if(i > 1) printf(" ");
        else printf("\n");
    }
}