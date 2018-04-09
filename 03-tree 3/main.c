#include <string.h>
#include <stdio.h>
#include <stdlib.h>


#define PATH "./input.txt"

int num;
char operator[8];
/*从下标1开始，不做*/
int preorder[31] = {0};
int inorder[31] = {0};
int postorder[31] = {0};

void scaninput()
{
    int stack[30] = {0};
    int top = -1;

    int i = 0;    
    int value = -1;
 
    int preOrderIdx = 1;
    int inOrderIdx = 1;

	FILE *fp = stdin;

	//fp = fopen(PATH, "r");

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



int findroot_position_in_inorder(int pre_root_idx, int in_start, int in_end)
{
	int i = 0;

	for(i = in_start; i <= in_end; i++) {
		if(inorder[i] == preorder[pre_root_idx]) break;
	}

	if(i > in_end)
		return -1;
	else
		return i;
	
}

void fill_postorder(int pre_start, int pre_end, int in_start, int in_end, int pre_root_idx, int post_root_pos) 
{
	int in_root_idx;
	int insert_pos;

    if(in_start > in_end || pre_start > pre_end)
		return;

    in_root_idx = findroot_position_in_inorder(pre_root_idx, in_start, in_end);

	if(in_root_idx == -1) {
		printf("-1 idx\n");
		return;
	}

	/*
	if(postorder[in_end] != 0) {
		printf("override\n");
		return;
	}
	*/

	/*
    insert_pos = in_end;
	while(postorder[insert_pos] != 0) {
		insert_pos--;
		if(insert_pos <= 0) {
			printf("wrong insert");
			return;
		}
	}
	*/

	//postorder[insert_pos] = inorder[in_root_idx];

	if(in_start == in_end) {
        postorder[post_root_pos] = inorder[in_root_idx];
	    return;
	}
	else if(in_start < in_end){
        int left_pre_start, left_pre_end, left_in_start, left_in_end, left_root_in_idx;
		int right_pre_start, right_pre_end, right_in_start, right_in_end, right_root_in_idx;
		left_pre_start = pre_start+1;
		left_pre_end = (pre_start+1)+((in_root_idx-1) - in_start );
		left_in_start = in_start;
		left_in_end = in_root_idx-1;
		left_root_in_idx = left_pre_start;

        right_pre_start = left_pre_end+1;
		right_pre_end = pre_end;
		right_in_start = in_root_idx+1;
		right_in_end = in_end;
		right_root_in_idx = right_pre_start;


        fill_postorder(left_pre_start, left_pre_end, left_in_start, left_in_end, left_root_in_idx,  (post_root_pos-1) - (right_in_end- right_in_start+1));
		fill_postorder(right_pre_start, right_pre_end, right_in_start , right_in_end, right_root_in_idx, post_root_pos-1);
		postorder[post_root_pos] = inorder[in_root_idx];
	    return;
	}

}


int main()
{
	int i = 0;

	scaninput();
	fill_postorder(1, num, 1, num, 1, num) ;
    
	if(num >= 1) {
		printf("%d", postorder[1]);
	}

	for(i = 2; i <= num; i++)
        printf(" %d",postorder[i]);
	return 0;
}