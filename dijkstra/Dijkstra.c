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
       �ҳ�δ��¼����С���붥��V_next
           ����Ҳ���,break
        collect(V_next)     
        temp_V = V_next;
   
       for(temp_V���ڽӵ�) {
           �ɳڵ����ڽӵ�ľ��룬���������dist_for_vtx��
       }
   }

   
  
   
}
