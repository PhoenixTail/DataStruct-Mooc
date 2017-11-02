distance[V][V] = INFINATIVE
path[V][V] = -1

void floyd(p_graph)
{
    int i,j,k
    //k点集合，从开始到当前
    //i 起始点
    //j 终止点
    for(k属于顶点)
        for(i属于顶点)
            for(j属于顶点)
                if(distance[i][k]+distance[k][j] < distanc[i][j]) {
                    distance[i][j] = distance[i][k]+distance[k][j];
                    path[i][j] = k;
                } 
}