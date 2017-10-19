#include <stdlib.h>
#include "graph.h"

//返回6次BFS的个数

int OneNode_SixDegree_BFS(PtrGraphTbl p_graph, int V)
{
    int level = 1;
    int level_end_idx = 1;
    int counter;
    int cur_V;
    int adj_V;
    PtrAdjNode p_adjnode = NULL;
    
    queue = Create_queue();
    Enqueue(queue, V);

    p_graph->Vertex[V].data = 1;
    counter = 1;

    while(level < 7 && !QueueIsEmpty(queue)) {
        cur_V = Dequeue(queue);
        printf("%d ", cur_V);
        p_adjnode = p_graph->Vertex[cur_V].next;
        while(p_adjnode) {
            adj_V = p_adjnode->V_idx;
            p_graph->Vertex[V].data = 1;
            p_adjnode = p_adjnode->next;
        }                

        if(cur_V = level_end_idx)
        
    }
    
    Delete_Queue(queue);
    return counter;
    
}