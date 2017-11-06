#include <stdio.h>
#include <stdlib.h>
#include "sort_comm.h"


void print_sorted(int *arr, int num)
{
    int i = 0;
    if(num > 1)
        printf("%d", arr[i]);
    for(i = 1; i < num; i++)
        printf(" %d", arr[i]);
}

void test_main()
{
    int num = 0;
    int i = 0;
    FILE *fp = stdin;
    int *arr = NULL;

    fp = fopen(".\\test.txt","r");
    if(!fp)
        return;

    fscanf(fp, "%d", &num);

    arr = (int *)malloc(num*sizeof(int));
    if(!arr)  {
        if(fp != stdin)  fclose(fp);
        return;
    }

    for(i = 0; i < num; i++)
        fscanf(fp, "%d", &arr[i]);


    //bubble_sort(arr, num);
    //insertion_sort(arr, num);
	//shell_ins_sort(arr, num);
	//merge_sort(arr, num);
    heap_sort(arr, num);

    print_sorted(arr, num);

    if(fp != stdin)
        fclose(fp);
}
