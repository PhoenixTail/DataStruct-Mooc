#include <stdio.h>
#include <stdlib.h>

#include "heap.h"

MinHeapPtr HeapInit(int heap_capacity)
{
    MinHeapPtr p_heap = (MinHeapPtr)malloc(sizeof(struct MinHeap));
    
    if(!p_heap) return NULL;
    
    p_heap->HeapArr = (ElementType *)malloc((heap_capacity+1)* sizeof(ElementType));
    p_heap->capacity = heap_capacity;
    p_heap->heapsize = 0;
    
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

}

ElementType HeapDelete(MinHeapPtr p_heap, result_t *res)
{

}