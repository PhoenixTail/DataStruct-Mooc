distance[V][V] = INFINATIVE
path[V][V] = -1

void floyd(p_graph)
{
    int i,j,k
    //k�㼯�ϣ��ӿ�ʼ����ǰ
    //i ��ʼ��
    //j ��ֹ��
    for(k���ڶ���)
        for(i���ڶ���)
            for(j���ڶ���)
                if(distance[i][k]+distance[k][j] < distanc[i][j]) {
                    distance[i][j] = distance[i][k]+distance[k][j];
                    path[i][j] = k;
                } 
}