#include <stdio.h>
#include <stdlib.h>
#include "graph.h"

void Print_GraphM(PtrGphM p_graph)
{
    int V, W;
    for(V = 0; V < p_graph->Num_V; V++) {
        for(W = 0; W < p_graph->Num_V; W++)
            printf("%d ",p_graph->G_Matrix[V][W]);
        printf("\n");
    }
}

void test_graph()
{
    PtrGphM p_graph = NULL;
    struct Edge E;
    int input_NEdge;
    int i;

    FILE *fp = stdin;

    p_graph = Create_Graph_Matrix(5);


    fscanf(fp, "%d", &input_NEdge);


    for(i = 0; i < input_NEdge; i++) {
        fscanf(fp, "%d", &E.V1);
        fscanf(fp, "%d", &E.V2);
        E.weight = 1;

        Graph_Matrix_InsertEdge(p_graph, &E);
    }

    Print_GraphM(p_graph);

    if(fp != stdin)
        fclose(fp);

}



