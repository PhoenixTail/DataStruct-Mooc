void merge_sort(int *arr, int num)
{
    
    int *temp = (int *)malloc(num*sizeof(int));
    
    if(!temp)  return;

    

    free(temp);
}


void merge_array(int *arr, int *temp, int L, int R, int R_end) 
{
    if((R-1-L)/2 > L) {
        merge_array(arr, temp, L, (R-1)/2, R-1);
    }
    if((R_end-R)/2 > R) {
        merge_array(arr, temp, R, (R_end-R)/2, R-1);
    }
}

void merge(int *arr, int *temp, int L, int R, int R_end)
{
    int i = L;
    int j = R;
    int k = L;

    while(i < R && j<= (R_end-1)) {
        if(arr[i] <= arr[j]) {
            temp[k++] = arr[i++];
        }
        else { 
            temp[k++] = arr[j++];
        }
    }

    if(i<R)
        while(k<=R_end)
            temp[k++] = arr[i++];

    if(j < (R_end-1))
        while(k<=Rend)
            temp[k++] = arr[j++];


    for(i = L; i <= R_end; i++) {
        arr[i] = temp[i];
    }
    
}