#ifndef __HEAP_H__
#define __HEAP_H__

#include "com_def.h"

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

#endif
