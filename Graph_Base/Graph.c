#include <stdio.h>
#include <stdlib.h>
#include "graph.h"


PtrGphM Create_Graph_Matrix(int vertex_num)
{
    int row,col;
    PtrGphM p_graph = (PtrGphM)malloc(sizeof(struct Graph_Matrix));

    if(!p_graph) return NULL;

    p_graph->Num_V = vertex_num;
    p_graph->Num_E = 0;
    for(row = 0; row < p_graph->Num_V; row++)
        for(col = 0; col < p_graph->Num_V; col++)
            p_graph->G_Matrix[row][col] = 0;
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

void DFS(Vertex)
{
    visit vertex;
        for (Vertex adjcent)
            if(vertex not visited)
                DFS(Vertex Next);
    /*如果没有被访问过*/
}
