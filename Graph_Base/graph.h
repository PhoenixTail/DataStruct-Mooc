#ifndef __GRAPH_H__
#define __GRAPH_H__

#define GMAXSIZE 100 //图的最大节点数

#define G_DATATYPE int
#define G_WEIGHT int

struct Graph_Matrix
{
    int Num_V;
    int Num_E;
    G_WEIGHT G_Matrix[GMAXSIZE][GMAXSIZE];
    G_DATATYPE V_Data[GMAXSIZE];
};

typedef struct Graph_Matrix * PtrGphM;

struct Edge{
    int V1;
    int V2;
    G_WEIGHT weight;
};

typedef struct Edge* PtrEdge;

struct Graph_Node
{
    G_DATATYPE Data;
    struct Graph_Node * next;
};
struct Graph_Table
{
    int Num_V;
    int Num_E;
    struct Graph_Node V[GMAXSIZE];
};

typedef struct Graph_Table * PtrGphT;

PtrGphM Create_Graph_Matrix(int vertex_num);
void Delete_Graph_Matrix(PtrGphM p_graph);
void Graph_Matrix_InsertEdge(PtrGphM p_graph, PtrEdge p_edge);
void Graph_Matrix_DFS(PtrGphM p_graph, int V);
void Graph_Matrix_Clear_Visit(PtrGphM p_graph);
void Graph_Matrix_DFS_Unlink(PtrGphM p_graph);
void Graph_Matrix_BFS(PtrGphM p_graph, int V);
void Graph_Matrix_BFS_Unlink(PtrGphM p_graph);

#endif // __GRAPH_H__
