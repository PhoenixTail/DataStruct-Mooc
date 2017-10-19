#include <stdio.h>
#include <stdlib.h>
#include "graph.h"

int OneNode_SixDegree_BFS(PtrGraphTbl p_graph, int V);

void Print_AdjNode(PtrVertex p_vertex)
{
    PtrAdjNode tmp = p_vertex->next;
    while(tmp) {
        printf("%d(w:%d)->",tmp->V_idx,tmp->weight);
        tmp = tmp->next;
    }
    printf("NULL");
}

void PrintGraph(PtrGraphTbl p_graph)
{
    int i = 0;
    //for(i = 0; i < p_graph->Num_V; i++) {  //从0开始使用
    for(i = 1; i <= p_graph->Num_V; i++) {
        printf("[%d]->",i);
        Print_AdjNode(&p_graph->Vertex[i]);
        printf("\n");
    }
}

void PrintVisit(PtrGraphTbl p_graph)
{
    int i = 0;
    for( i = 1; i <= p_graph->Num_V; i++)
        printf("Vertix[%d]:%d \n", i,p_graph->Vertex[i].data);
}

void test_main()
{
    FILE *fp = stdin;
    int vertex_num = 0;
    int edge_num = 0;
    int i = 0;
    int six_count = 0;
    struct Graph_Edge edge;
	PtrGraphTbl p_graph = NULL;

	fp = fopen(".//test.txt","r");
	if(!fp) return;

    fscanf(fp,"%d",&vertex_num);
    fscanf(fp,"%d",&edge_num);

	p_graph = CreateGraphTable(vertex_num);
	//没建成功，删除图，返回

    for(i = 0; i < edge_num; i++) {
        fscanf(fp,"%d",&edge.V1);
        fscanf(fp,"%d",&edge.V2);
        edge.Weight = 1;
        if(!GraphTable_AddEdge(p_graph, &edge)) {
            DeleteGraphTable(p_graph);
            if(fp != stdin) fclose(fp);
            return;
        }
    }

    PrintGraph(p_graph);
    PrintVisit(p_graph);

    six_count = OneNode_SixDegree_BFS(p_graph, 1);
    GraphTable_ClearVisit(p_graph);

    for( i = 1; i <= vertex_num; i++ ) {
        six_count = OneNode_SixDegree_BFS(p_graph, i);
        printf("\nVertex[%d]:%f\n", i, (double)six_count/(double)vertex_num);
        GraphTable_ClearVisit(p_graph);
    }


    DeleteGraphTable(p_graph);
    if(fp != stdin)
        fclose(fp);
}

