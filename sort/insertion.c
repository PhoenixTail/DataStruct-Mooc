

void insertion_sort(int *arr, int num)
{
    int i = 0;
    int j = 0;
   
    for(i = 1; i < num; i++) {
        for(j = i; j >=1; j--) {
            if(arr[j] < arr[j-1]) {
                swap(&arr[j-1],&arr[j]);
                break;
            }
        } 
    }
}

/*
void insertion_sort(int *arr, int num)
{
    int i = 0;
    int j = 0;
    int *temp = NULL;

    int* temp = (int *)malloc(num * sizof(int));
    
    if(!temp) {
        //printf("malloc error!\n");
        return;
    }
    
    if(num > 1) 
        temp[i] = arr[i];
    
    for(i = 1; i < num; i++) {
        for(j = i; j >=0; j--) {
            if(arr[i] < temp[j]) {
                temp[j+1] = temp[j];
            } else {
                temp[j] = arr[i];
                break;
            }
        }        
    }

    for(i = 0; i < num; i++) {
        arr[i] = temp[i];
    }    

    free(temp);
    
}
*/