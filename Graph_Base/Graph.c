#include <stdio.h>
#include <stdlib.h>
#include "graph.h"
#include "queue.h"


PtrGphM Create_Graph_Matrix(int vertex_num)
{
    int row,col;
    PtrGphM p_graph = (PtrGphM)malloc(sizeof(struct Graph_Matrix));

    if(!p_graph) return NULL;

    p_graph->Num_V = vertex_num;
    p_graph->Num_E = 0;
    for(row = 0; row < p_graph->Num_V; row++) {
	    p_graph->V_Data[row] = 0;
        for(col = 0; col < p_graph->Num_V; col++)
            p_graph->G_Matrix[row][col] = 0;
    }
    return p_graph;
}

void Delete_Graph_Matrix(PtrGphM p_graph)
{
    if(p_graph)
        free(p_graph);
}

void Graph_Matrix_InsertEdge(PtrGphM p_graph, PtrEdge p_edge)
{
    p_graph->G_Matrix[p_edge->V1][p_edge->V2] = p_edge->weight;
    p_graph->G_Matrix[p_edge->V2][p_edge->V1] = p_edge->weight;
}

void Graph_Matrix_Clear_Visit(PtrGphM p_graph)
{
    int V = 0;
    for(V = 0; V < p_graph->Num_V; V++) {
        p_graph->V_Data[V] = 0;
    }
}

void Graph_Matrix_DFS(PtrGphM p_graph, int V)
{
    int i = 0;
    p_graph->V_Data[V] = 1;
    printf("%d ", V);

    for(i = 0 ; i < p_graph->Num_V; i++) {
	    if(p_graph->G_Matrix[V][i] != 0 && p_graph->V_Data[i] == 0) {
            Graph_Matrix_DFS(p_graph, i);
	    }
    }
}

void Graph_Matrix_DFS_Unlink(PtrGphM p_graph)
{
    int V = 0;
    for(V = 0; V < p_graph->Num_V;  V++) {
        if(p_graph->V_Data[V] == 0) {
            Graph_Matrix_DFS(p_graph, V);
            printf("\n");
        }
    }
}


void Graph_Matrix_BFS(PtrGphM p_graph, int V)
{
    int current;
    int link_V;
    PtrQueue p_queue = CreateQueue();
    
    if(!EnQueue(p_queue, V) )  {
        printf("Enqueue Error\n");
        DeleteQueue(p_queue);
        return;
    }
	p_graph->V_Data[V] = 1; 

	while(!Queue_Empty(p_queue)){
        DeQueue(p_queue, &current);
        printf("%d ", current);
        for(link_V = 0; link_V < p_graph->Num_V; link_V++)
			if(p_graph->G_Matrix[current][link_V]!=0 && p_graph->V_Data[link_V]==0) {
				EnQueue(p_queue, link_V);
				p_graph->V_Data[link_V] = 1;
			}
            
    }

    DeleteQueue(p_queue);
}

void Graph_Matrix_BFS_Unlink(PtrGphM p_graph)
{
    int V = 0;
    for(V = 0; V < p_graph->Num_V; V++) {
        if(p_graph->V_Data[V] == 0) {
            Graph_Matrix_BFS(p_graph,V);
            printf("\n");
        }
    }
}
