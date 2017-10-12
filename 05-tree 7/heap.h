#ifndef __HEAP_H__
#define __HEAP_H__

#include "comd_def.h"

struct MinHeap 
{
    int capacity;
    int heap_size;
    ElementType *HeapArr;
}

typedef struct MinHeap* MinHeapPtr;

#endif