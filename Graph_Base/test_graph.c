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

void Print_GraphM_Visit(PtrGphM p_graph)
{
	int V;
	for(V = 0; V < p_graph->Num_V; V++) 
		printf("%d ", p_graph->V_Data[V]);
	printf("\n");
}

void test_graph()
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
        E.weight = 1;

        Graph_Matrix_InsertEdge(p_graph, &E);
    }

    Print_GraphM(p_graph);
    Print_GraphM_Visit(p_graph);
    
    Graph_Matrix_DFS(p_graph,0);
    
    printf("\nDFS once end\n");
    Graph_Matrix_Clear_Visit(p_graph);
    
	Print_GraphM_Visit(p_graph);
    Graph_Matrix_DFS_Unlink(p_graph);
	printf("\nDFS end\n");

    
	Graph_Matrix_Clear_Visit(p_graph);
    Graph_Matrix_BFS(p_graph,0);
	printf("\nBFS once end\n");
    Graph_Matrix_Clear_Visit(p_graph);
	Graph_Matrix_BFS_Unlink(p_graph);
	printf("\nBFS end\n");


    Delete_Graph_Matrix(p_graph);

    if(fp != stdin)
        fclose(fp);

}



