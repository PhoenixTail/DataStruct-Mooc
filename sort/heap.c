void heap_sort(int *arr, int num)
{
    int *temp = (int *)malloc(num*sizeof(int));
    
    if(!temp)  return;

    create_heap(arr,temp,num);
    heap_del_sort(arr,temp,num);

    free(temp);
}

void create_heap(int *src, int *dst, num)
{
    int i = 0;
    for(i = 0; i < num; i++) {
        dst[i] = 0;
    }

    //dst[0] = MAX; dst[0] = MIN;

    for(i = 0; i< num ;i++) {
        add_to_heap(src[i], dst, i);
    }
}

/*���ݽṹ��1��ʼ,heap_size����ǰ��size*/
/*
void add_to_heap(int data, int * heap, int heap_size)
{
    int idx = 0;

    if(heap_size == 0) {
        heap[heap_size+1] = data;
        return;
    }

    for(idx = heap_size+1;idx >= 1; idx = idx/2) {
        if(data > heap[idx/2]) 
            heap[idx] = heap[idx/2];
        else
            break;
    }

    heap[idx] = data;    
}
*/

/*heap���ݽṹ���±�0��ʼ*/
void add_to_heap(int data, int * heap, int heap_size)
{
    int idx = 0;

    if(heap_size == 0) {
        heap[heap_size] = data;
        return;
    }

    for(idx = heap_size;idx >0; idx = (idx-1)/2) {
        if(data > heap[(idx-1)/2]) 
            heap[idx] = heap[(idx-1)/2];
        else
            break;
    }

    heap[idx] = data;    
}

/*����heap���ݽṹ���±�0��ʼ,heap_size ɾ��ǰ��heap_size*/
void heap_del_sort(int *src, int *heap, int heap_size)
{
    int i = 0;
    idx = heap_size - 1;
     
    while(idx>0) {
        swap(&heap[0],&heap[idx]);
        idx--;

        for(i = 0; i <= idx; i = (i+1)*2-1) {
           
            heap[(i+1)*2-1])
                if(heap[i]<hea)
        }

        
    }
}

