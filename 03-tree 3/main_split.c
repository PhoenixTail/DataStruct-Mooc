#include <stdio.h>
#include <string.h>

#include "transerver.h"

extern int num;
extern char operator[8];
/*���±�1��ʼ������*/
extern int preorder[31];
extern int inorder[31];
extern int postorder[31];

int main()
{
	scaninput();
	fill_postorder(1, num, 1, num, 1, num) ;
}