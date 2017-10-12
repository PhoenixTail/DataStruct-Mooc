#include <stdio.h>
#include <stdlib.h>

#include "heap.h"

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
