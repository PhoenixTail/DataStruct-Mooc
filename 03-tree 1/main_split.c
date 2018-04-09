#include <stdio.h>

#include "AlikeTree.h"

extern int tree1_size;
extern char tree1[10][3];
extern int tree2_size;
extern char tree2[10][3];

void scan_input();

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