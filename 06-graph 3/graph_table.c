#include <stdio.h>
#include <stdlib.h>
#include "graph.h"

PtrGraphTbl CreateGraphTable(int Vertex_Num)
{
    int i = 0;
    PtrGraphTbl p_graph =(PtrGraphTbl)malloc(sizeof(struct Graph_Table));
    if(!p_graph) return NULL;

    p_graph->Num_V = Vertex_Num;
    p_graph->Num_E = 0;
    //for(i = 0; i < Vertex_Num; i++) {   //从0开始使用
	for(i = 1; i <= Vertex_Num; i++) {    //从1开始使用
        p_graph->Vertex[i].next = NULL;
        p_graph->Vertex[i].data = 0;
    }
    return p_graph;
}

void DeleteGraphTable(PtrGraphTbl p_graph)
{
    int i = 0;
    if(!p_graph) return;

    //for(i = 0; i < p_graph->Num_V; i++)  //从0开始使用
	for(i = 1; i<= p_graph->Num_V; i++)        //从1开始使用
        DeleteAdjLink(&p_graph->Vertex[i]);
    
    free(p_graph);
}

void DeleteAdjLink(PtrVertex p_vertex)
{
    PtrAdjNode tmp = NULL;
    while(p_vertex->next) {
        tmp = p_vertex->next;
        p_vertex->next = tmp->next;
        Delete_AdjNode(tmp);
    }
}

bool GraphTable_AddEdge(PtrGraphTbl p_graph, PtrEdge p_edge)
{
    PtrAdjNode p_s2d = NULL;    /*源到目的邻接节点*/
    PtrAdjNode p_d2s = NULL;    /*目的到源邻接节点*/

	//应增加判断，边对应的定点是存在的，否则可能会内存泄漏

    p_s2d = Create_AdjNode(p_edge->Weight,p_edge->V2);
    if(!p_s2d) return false;
    p_d2s = Create_AdjNode(p_edge->Weight,p_edge->V1);
    if(!p_d2s) {
        Delete_AdjNode(p_s2d);
        return false;
    }

    InsertAdjNode_To_Vertex(&p_graph->Vertex[p_edge->V1],p_s2d);
    InsertAdjNode_To_Vertex(&p_graph->Vertex[p_edge->V2],p_d2s);
    return true;
}

void InsertAdjNode_To_Vertex(PtrVertex p_vertex, PtrAdjNode p_adjnode)
{   
    if(p_vertex->next == NULL) {
        p_vertex->next = p_adjnode;
    }
    else {
        p_adjnode->next = p_vertex->next;
        p_vertex->next = p_adjnode;
    }
}

PtrAdjNode Create_AdjNode(int weight, int adj_vertex)
{
    PtrAdjNode p_adjnode = (PtrAdjNode)malloc(sizeof(struct Table_AdjNode));
    if(!p_adjnode) return NULL;

    p_adjnode->V_idx = adj_vertex;
    p_adjnode->weight = weight;
    p_adjnode->next = NULL;
    return p_adjnode;
}

void Delete_AdjNode(PtrAdjNode p_adjnode)
{
    if(p_adjnode) {
        free(p_adjnode);
        p_adjnode = NULL;
    }
}

void GraphTable_ClearVisit(PtrGraphTbl p_graph)
{
    int i = 0;
    for(i = 1; i <= p_graph->Num_V; i++)
        p_graph->Vertex[i].data = 0;
}