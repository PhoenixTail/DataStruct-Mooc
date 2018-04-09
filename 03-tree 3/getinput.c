#include <string.h>
#include <stdio.h>
#include <stdlib.h>

//#define PATH stdin
#define PATH "./input.txt"

int num;
char operator[8];
/*从下标1开始，不做*/
int preorder[31] = {0};
int inorder[31] = {0};

void scaninput()
{
    int stack[30] = {0};
    int top = -1;

    int i = 0;    
    int value = -1;
 
    int preOrderIdx = 1;
    int inOrderIdx = 1;

	FILE *fp = NULL;

	fp = fopen(PATH, "r");

	if(fp == NULL)
		return;

    fscanf(fp, "%d", &num);
    
    for(i = 0; i < 2*num; i++) {

        fscanf(fp, "%s", &operator);
        
        if(strcmp(operator,"Push")==0) {
            fscanf(fp, "%d", &value);
            preorder[preOrderIdx++] = value;
            stack[++top] = value;
        } else if (strcmp(operator,"Pop")==0) {
            inorder[inOrderIdx++] = stack[top--];
        }

    }
}