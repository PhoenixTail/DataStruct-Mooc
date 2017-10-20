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

    fscanf(fp,"%d",&PosNum_N);
    fscanf(fp,"%d",&jumpR_D);

    for(i = 0; i < PosNum_N; i++) {
        
    }

    if(fp != stdin)
        fclose(fp);
}