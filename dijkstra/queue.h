#ifndef __QUEUE_H__
#define __QUEUE_H__

//config defination
#define QDATATYPE int
//#define NOHEAD 1
#ifndef bool
#define bool int
#endif 


struct Queue_Node
{
    struct Queue_Node *next;
    QDATATYPE data;
};

typedef struct Queue_Node* PtrQNode;

struct Queue
{
    PtrQNode rear;
    PtrQNode front; 
};

typedef struct Queue* PtrQueue;

PtrQueue CreateQueue();
bool Queue_Empty(PtrQueue p_queue);
void EnQueue_Node(PtrQueue p_queue, PtrQNode p_qnode);
bool EnQueue(PtrQueue p_queue, QDATATYPE element_data);
PtrQNode DeQueue_Node(PtrQueue p_queue);
bool DeQueue(PtrQueue p_queue, QDATATYPE *data);
void DeleteQueue(PtrQueue p_queue);


#endif