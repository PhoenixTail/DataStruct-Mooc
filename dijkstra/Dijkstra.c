#define MAXV 100

typedef distance_type int;

struct path_data
{
    distance_type dist_for_idx[MAXV];
    int path_idx[MAXV];
};

struct min_heap
{
   int heap_size;
   int heap[MAXV];
}


void dist_init()
{
   dist_for_vtx = matrix(INFINITIVE);
   paht_idx = matrix(-1);
}



void Dijkstra(PtrGraph p_graph, int V)
{
   collect(V);
   
   while(1)
       找出未收录的最小距离顶点V_next
           如果找不到,break
        collect(V_next)     
        temp_V = V_next;
   
       for(temp_V的邻接点) {
           松弛到达邻接点的距离，将距离记入dist_for_vtx；
       }
   }

   
  
   
}
