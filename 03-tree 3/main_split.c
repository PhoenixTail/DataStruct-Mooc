#include <stdio.h>
#include <string.h>

#include "transerver.h"

extern int num;
extern char operator[8];
/*从下标1开始，不做*/
extern int preorder[31];
extern int inorder[31];
extern int postorder[31];

int main()
{
	scaninput();
	fill_postorder(1, num, 1, num, 1, num) ;
}