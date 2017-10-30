#include <stdio.h>
#include <stdlib.h>

#define MAXN 100

struct coordinate
{
    float x;
    float y;
    int visit;
}

void test_main()
{
    FILE *fp = stdin;
    int PosNum_N;
    int jumpR_D;
    int i = 0;
    PtrPos PosArr = NULL;
    int first_set[MAXN];
 
    for(i = 0; i < MAXN; i++) {
        first_set[i] = 0;
    }

    fscanf(fp,"%d",&PosNum_N);
    fscanf(fp,"%d",&jumpR_D);

    PosArr = (PtrPos)malloc(PosNum_N*sizeof(struct Postion));
    
    if(!PosArr) return;

    for(i = 0; i < PosNum_N; i++) {
        fscanf(fp, "%d", &PosArr[i].x_pos);
        fscanf(fp, "%d", &PosArr[i].y_pos);
        PosArr[i].visited = 0;
        //printf("PosArr[%d]: %d %d\n", i, PosArr[i].x_pos, PosArr[i].y_pos);
    }

    free(PosArr);

    if(fp != stdin)
        fclose(fp);
}