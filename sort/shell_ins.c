
void shell_ins_sort(int *arr, int num)
{
    int i = 0;
    int j = 0;
    int k = 1;

    while(k < num ) {
        k *= 2;
    }
    
    for(; k > 0 ; k = (k+1)/2-1) {
        for(i = k; i < num; i+=k) {
            for(j = i; j >=0; j-=k) {
                if(arr[j-k] > arr[j]) {
                    swap(&arr[j-k], &arr[j]);
                    break;
                }
            } 
        }
    }
   

}