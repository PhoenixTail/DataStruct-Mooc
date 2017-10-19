#include "queue.h"
#include <stdlib.h>
#include <stdio.h>

#ifndef bool
#define bool int
#endif
#define true 1
#define false 0

PtrQueue CreateQueue()
{
    PtrQueue p_queue = (PtrQueue)malloc(sizeof(struct Queue));

    if(!p_queue) return NULL;

    p_queue->rear = p_queue->front = NULL;
    return p_queue;
}

bool Queue_Empty(PtrQueue p_queue)
{
    return (p_queue->rear == NULL && p_queue->front == NULL);
}

void EnQueue_Node(PtrQueue p_queue, PtrQNode p_qnode)
{
    if(p_queue->rear == NULL) {
        p_queue->rear = p_qnode;
        if(p_queue->front == NULL) p_queue->front = p_qnode;
    }
    else {
        p_queue->rear->next = p_qnode;
        p_queue->rear = p_qnode;
    }
}

bool EnQueue(PtrQueue p_queue, QDATATYPE element_data)
{
    PtrQNode p_qnode = (PtrQNode)malloc(sizeof(struct Queue_Node));
    if(!p_qnode) return false;

    p_qnode->data = element_data;
    p_qnode->next = NULL;
    EnQueue_Node(p_queue,p_qnode);
    return true;
}

PtrQNode DeQueue_Node(PtrQueue p_queue)
{
    PtrQNode tmp = p_queue->front;
    if(p_queue->rear == p_queue->front)
        p_queue->rear = p_queue->front = NULL;
    else 
        p_queue->front = p_queue->front->next;

    return tmp;
}

bool DeQueue(PtrQueue p_queue, QDATATYPE *data)
{
    PtrQNode p_qnode = NULL;
    if(p_queue->front == NULL && p_queue->rear == NULL)
        return false;
    p_qnode = DeQueue_Node(p_queue);
    if(data) *data = p_qnode->data;
    free(p_qnode);
    return true;
}

void DeleteQueue(PtrQueue p_queue)
{
    while(!Queue_Empty(p_queue)) {
        DeQueue(p_queue, NULL);
    }
}