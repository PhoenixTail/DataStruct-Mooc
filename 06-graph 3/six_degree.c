#include <stdlib.h>
#include <stdio.h>
#include "graph.h"
#include "queue.h"

//返回6次BFS的个数

int OneNode_SixDegree_BFS(PtrGraphTbl p_graph, int V)
{
    int level = 1;
    int level_end_ref = 1;
    int level_end_mark = 1;
    int counter;
    int cur_V;
    int adj_V;
    PtrAdjNode p_adjnode = NULL;
    PtrQueue p_queue = NULL;

    p_queue = CreateQueue();

    if(!EnQueue(p_queue, V)) {
        printf("queue error\n");
        return -1;
    }

    p_graph->Vertex[V].data = 1;
    counter = 1;
    level_end_ref = V;

    while(level < 7 && !Queue_Empty(p_queue)) {
        DeQueue(p_queue,&cur_V);
        printf("%d ", cur_V);

        p_adjnode = p_graph->Vertex[cur_V].next;
        while(p_adjnode) {
            adj_V = p_adjnode->V_idx;
            if(p_graph->Vertex[adj_V].data == 0) {
                p_graph->Vertex[adj_V].data = 1;
                EnQueue(p_queue, adj_V);
                level_end_mark = adj_V;
                counter++;
            }
            p_adjnode = p_adjnode->next;
        }

        if(cur_V == level_end_ref) {
            level_end_ref = level_end_mark;
            level++;
        }

    }

    DeleteQueue(p_queue);
    return counter;

}
