#ifndef __GRAPH_H__
#define __GRAPH_H__

#ifndef bool
#define bool int
#define true 1
#define false 0
#endif

#define MAXVERTIX 1001
#define VertexData int

struct Table_AdjNode  /*邻接节点*/
{
    int V_idx;
    int weight;
    struct Table_AdjNode *next;
};
typedef struct Table_AdjNode* PtrAdjNode;

struct Graph_Table_Vertex /*顶点*/
{
    struct Table_AdjNode * next;
    VertexData data;     /*是否访问*/
};
typedef struct Graph_Table_Vertex* PtrVertex;

struct Graph_Table /*图*/
{
    int Num_V;
    int Num_E;
    struct Graph_Table_Vertex Vertex[MAXVERTIX];
};

typedef struct Graph_Table * PtrGraphTbl;

struct Graph_Edge
{
    int V1;
    int V2;
    int Weight;
};
typedef struct Graph_Edge * PtrEdge;

PtrGraphTbl CreateGraphTable(int Vertex_Num);
void DeleteGraphTable(PtrGraphTbl p_graph);
void DeleteAdjLink(PtrVertex p_vertex);
bool GraphTable_AddEdge(PtrGraphTbl p_graph, PtrEdge p_edge);
void InsertAdjNode_To_Vertex(PtrVertex p_vertex, PtrAdjNode p_adjnode);
PtrAdjNode Create_AdjNode(int weight, int adj_vertex);
void Delete_AdjNode(PtrAdjNode p_adjnode);
void GraphTable_ClearVisit(PtrGraphTbl p_graph);

#endif