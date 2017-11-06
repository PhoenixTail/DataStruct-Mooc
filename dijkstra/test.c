#include <stdio.h>
#include <stdlib.h>
#include "graph.h"

void Dijkstra(PtrGphM p_graph, int V);

void Print_GraphM(PtrGphM p_graph)
{
    int V, W;
    for(V = 0; V <= p_graph->Num_V; V++) {
        for(W = 0; W <= p_graph->Num_V; W++)
            printf("%d ",p_graph->G_Matrix[V][W]);
        printf("\n");
    }
}

void Print_GraphM_Visit(PtrGphM p_graph)
{
	int V;
	for(V = 0; V <= p_graph->Num_V; V++)
		printf("%d ", p_graph->V_Data[V]);
	printf("\n");
}

void test_main()
{
    PtrGphM p_graph = NULL;
    struct Edge E;
	int input_NVertex;
    int input_NEdge;
    int i;

    FILE *fp = stdin;

    if(!(fp = fopen(".//test.txt","r"))) return;

	fscanf(fp, "%d", &input_NVertex);

    p_graph = Create_Graph_Matrix(input_NVertex);


    fscanf(fp, "%d", &input_NEdge);


    for(i = 0; i < input_NEdge; i++) {
        fscanf(fp, "%d", &E.V1);
        fscanf(fp, "%d", &E.V2);
        fscanf(fp, "%d", &E.weight);

        Graph_Matrix_InsertEdge(p_graph, &E);
    }

    Print_GraphM(p_graph);
    Print_GraphM_Visit(p_graph);

    Dijkstra(p_graph,4);

    Delete_Graph_Matrix(p_graph);

    if(fp != stdin)
        fclose(fp);

}



