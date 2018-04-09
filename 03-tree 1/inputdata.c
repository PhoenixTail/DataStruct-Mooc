#include <stdio.h>
#include <direct.h>

int tree1_size;
char tree1[10][3];
int tree2_size;
char tree2[10][3];

#define PATH ".//input1.txt"

void scan_input()
{
	FILE * fp = NULL;

    int i = 0; 
    int j = 0;
	char curpath[80] = "";
		
	 _getcwd( curpath, 80);
	printf("%s\n",curpath);

	//fp = stdin;
	fp = fopen(PATH,"r+");

	if(fp == NULL)
		return;

    fscanf(fp, "%d", &tree1_size);
    for(i = 0; i < tree1_size; i++) {
        for(j = 0; j < 3; j++)
            fscanf(fp, "%s", &tree1[i][j]);
    }

    fscanf(fp, "%d", &tree2_size);
    for(i = 0; i < tree2_size; i++) {
        for(j = 0; j < 3; j++)
            fscanf(fp, "%s", &tree2[i][j]);
    }    
}