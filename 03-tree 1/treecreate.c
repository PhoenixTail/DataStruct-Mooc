#include <stdio.h>
#include <stdlib.h>

#include "AlikeTree.h"

extern int tree1_size;
extern char tree1[10][3];
extern int tree2_size;
extern char tree2[10][3];

/*假设：数据按照树的情况去做的
最多10组数据*/
int FindRoot(int size, char tree_arr[][3])
{
    int label[10] = {0};
    int i = 0;
 
    for(i = 0; i < size; i++) {
        label[i] = 1;
    }

    for(i = 0; i < size; i++) {
        int j = 0;
        int ch;
        for(j = 1; j < 3; j++) {
            if(tree_arr[i][j] != '-') {
                ch = tree_arr[i][j];
                label[ch-'0'] = 0;
            }
        }
        
    }
    
    for(i = 0; i < size; i++) {
        if(label[i] == 1)
            return i;
    }

    return -1;    
}


PtrTree CreateTree(int size, char tree_arr[][3], int root)
{

    PtrTree ThisNode = NULL;

	if(root == -1)
		return NULL;

    ThisNode = malloc(sizeof(struct tree));
    if(ThisNode == NULL) {
        return NULL;
    }
    
    ThisNode->data = tree_arr[root][0];
	ThisNode->leftchild = NULL;
	ThisNode->rightchild = NULL;
    
    if(tree_arr[root][1] != '-') {
        ThisNode->leftchild = CreateTree(size, tree_arr, tree_arr[root][1]-'0');
    }
	
    if(tree_arr[root][2] != '-') {
        ThisNode->rightchild = CreateTree(size, tree_arr, tree_arr[root][2]-'0');
    }
	
    return ThisNode;
}

void DeleteTree(PtrTree root)
{
    ;
}


