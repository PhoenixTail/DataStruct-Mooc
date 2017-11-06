#include <stdio.h>
#include "graph.h"
#define MAXV 101
#define bool int
#define true 1
#define false 0

typedef int distance_type;

struct path_data
{
    distance_type dist_for_idx[MAXV];
    int path_idx[MAXV];
};

struct min_heap
{
   int heap_size;
   int heap[MAXV];
};


void path_init(struct path_data * path)
{
    int V = 0;
    for(V = 0;  V < MAXV; V++) {
        path->dist_for_idx[V] = INFINITIVE;
        path->path_idx[V] = -1;
    }
}

bool find_min(struct path_data *path, PtrGphM p_graph, int *min_idx)
{
    int min = 0;
    int i = 0;

    min = path->dist_for_idx[0];
    *min_idx = 0;
    //´Ó1¿ªÊ¼
    p_graph->V_Data[0] = 1;
    for(i = 1; i <= p_graph->Num_V && p_graph->V_Data[i] == 0; i++) {
        if(min > path->dist_for_idx[i]) {
            min = path->dist_for_idx[i];
            *min_idx = i;
        }
    }

    if(*min_idx == 0)
        return false;
    else
        return true;
}


void Dijkstra(PtrGphM p_graph, int V)
{
    int temp_V = 0;
    int i = 0;
    struct path_data s_path;

    path_init(&s_path);
    s_path.dist_for_idx[V] = 0;

    while(1) {

        if(!find_min(&s_path,p_graph,&temp_V))
            break;
        p_graph->V_Data[temp_V] = 1;
        for(i = 1; i <= p_graph->Num_V; i++) {
            if(p_graph->V_Data[i] == 0 && p_graph->G_Matrix[temp_V][i] < INFINITIVE)
                if(s_path.dist_for_idx[i] > s_path.dist_for_idx[temp_V] + p_graph->G_Matrix[temp_V][i]) {
                    s_path.dist_for_idx[i] = s_path.dist_for_idx[temp_V] + p_graph->G_Matrix[temp_V][i];
                    s_path.path_idx[i] = temp_V;
                }
        }
    }

    for(i = 1; i <= p_graph->Num_V ;i++) {
        if(s_path.dist_for_idx[i]>=INFINITIVE)
            printf("not a link graph");
    }


    for(i = 1; i<= p_graph->Num_V; i++) {
        printf("dist[%d]: %d",i,s_path.dist_for_idx[i]);
    }
    for(i = 1; i<= p_graph->Num_V; i++) {
        printf("path[%d]: %d",i,s_path.path_idx[i]);
    }
}
