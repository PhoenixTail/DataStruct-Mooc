#include <stdio.h>
#include <stdlib.h>
/*
#define bool int
#define true 1
#define false 0
#define ERROR -1

#define ElementType int

#define result_t int

struct MinHeap
{
    int capacity;
    int heap_size;
    ElementType *HeapArr;
};

typedef struct MinHeap* MinHeapPtr;

MinHeapPtr HeapInit(int heap_capacity);
bool HeapInsert(MinHeapPtr p_heap, ElementType element);
ElementType HeapDelete(MinHeapPtr p_heap, result_t *res);

MinHeapPtr HeapInit(int heap_capacity)
{
    MinHeapPtr p_heap = (MinHeapPtr)malloc(sizeof(struct MinHeap));

    if(!p_heap) return NULL;

    p_heap->HeapArr = (ElementType *)malloc((heap_capacity+1)* sizeof(ElementType));
    p_heap->capacity = heap_capacity;
    p_heap->heap_size = 0;

    if(!p_heap->HeapArr) {
        free(p_heap);
        return NULL;
    }
    else {
        p_heap->HeapArr[0] = -1;
    }

    return p_heap;
}

bool HeapInsert(MinHeapPtr p_heap, ElementType element)
{
    int i = 0;

    if(p_heap->heap_size >= p_heap->capacity) {
        return false;
    }

    p_heap->heap_size++;

    if(p_heap->heap_size == 1) {
        p_heap->HeapArr[1] = element;
        return true;
    }

    for(i = p_heap->heap_size; i > 1 && element < p_heap->HeapArr[i/2]; i = i/2) {
        p_heap->HeapArr[i] = p_heap->HeapArr[i/2];
    }

    p_heap->HeapArr[i] = element;

    return true;
}

ElementType HeapDelete(MinHeapPtr p_heap, result_t *res)
{
    return 0;
}

void print_path(MinHeapPtr p_heap, int index)
{
    int i = 0;

    for(i = index; i > 0 ; i = i/2) {
        printf("%d", p_heap->HeapArr[i]);
        if(i > 1) printf(" ");
        else printf("\n");
    }
}

void read_line(int arr[], int read_size, FILE *fp)
{
    int i = 0;
    for(i = 0; i < read_size; i++) {
        fscanf(fp, "%d", &arr[i]);
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

int main()
{
    FILE *fp = stdin;
    int ElementNum_N = 0;
    int PrintNum_M = 0;
    int i = 0;

    int *data_arr = NULL;
    int *index_arr = NULL;

    MinHeapPtr p_heap = NULL;

    fp = fopen(".\\test.txt", "r");

    if(!fp)  {
        printf("No file\n");
        return -1;
    }

    fscanf(fp, "%d", &ElementNum_N);
    fscanf(fp, "%d", &PrintNum_M);

    data_arr = (int *)malloc(ElementNum_N * sizeof(int));
    index_arr = (int *)malloc(PrintNum_M * sizeof(int));

    read_line(data_arr, ElementNum_N, fp);
    print_line(data_arr, ElementNum_N);

    read_line(index_arr, PrintNum_M, fp);
    print_line(index_arr, PrintNum_M);



    p_heap = HeapInit(ElementNum_N);
    for(i = 0; i< ElementNum_N; i++) {
        HeapInsert(p_heap, data_arr[i]);
    }

    print_line(p_heap->HeapArr, p_heap->heap_size);

    for(i = 0; i < PrintNum_M; i++) {
        print_path(p_heap, index_arr[i]);
    }

    free(data_arr);
    free(index_arr);
    free(p_heap->HeapArr);
    free(p_heap);

    p_heap = NULL;
    data_arr = NULL;
    index_arr = NULL;

    return 0;
}
*/
