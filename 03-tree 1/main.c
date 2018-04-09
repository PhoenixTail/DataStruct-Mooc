#include <stdio.h>
#include <stdlib.h>

struct tree
{
    struct tree* leftchild;
    struct tree* rightchild;
    char data;    
};

typedef struct tree * PtrTree;

int tree1_size;
char tree1[10][3];
int tree2_size;
char tree2[10][3];

#define PATH ".//input.txt"

void scan_input()
{
	FILE * fp = NULL;

    int i = 0; 
    int j = 0;

	fp = stdin;
	//fp = fopen(PATH,"r+");

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

int TreeCompare(PtrTree tree1, PtrTree tree2)
{
    if(tree1 == NULL) {
        if(tree2 == NULL)
            return 1;
        else
            return 0;
    }

    if(tree2 == NULL)
        return 0;

    if(tree1->data == tree2->data) {

        if (
        (TreeCompare(tree1->leftchild, tree2->leftchild)&&TreeCompare(tree1->rightchild, tree2->rightchild))  ||
        (TreeCompare(tree1->leftchild, tree2->rightchild)&&TreeCompare(tree1->rightchild, tree2->leftchild))
        )    {
            return 1;
        }

    }

    return 0;
}


int main()
{
	int root = -1;
	int result = 0;

	PtrTree ptrTree1 = NULL;
	PtrTree ptrTree2 = NULL;

	scan_input();
	
	root = FindRoot(tree1_size, tree1);
	ptrTree1 = CreateTree(tree1_size, tree1, root);

	root = FindRoot(tree2_size, tree2);
	ptrTree2 =  CreateTree(tree2_size, tree2, root);

	result  = TreeCompare(ptrTree1, ptrTree2);

	if(result)  printf("Yes");
	else printf("No");
}
