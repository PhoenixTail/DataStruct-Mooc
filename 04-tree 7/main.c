#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;
typedef struct TNode *Position;
typedef Position BinTree;
struct TNode{
    ElementType Data;
    BinTree Left;
    BinTree Right;
};

void PreorderTraversal( BinTree BT ); /* 先序遍历，由裁判实现，细节不表 */
void InorderTraversal( BinTree BT );  /* 中序遍历，由裁判实现，细节不表 */

BinTree Insert( BinTree BST, ElementType X );
BinTree Delete( BinTree BST, ElementType X );
Position Find( BinTree BST, ElementType X );
Position FindMin( BinTree BST );
Position FindMax( BinTree BST );

int main()
{
    BinTree BST, MinP, MaxP, Tmp;
    ElementType X;
    int N, i;

    BST = NULL;
    scanf("%d", &N);
    for ( i=0; i<N; i++ ) {
        scanf("%d", &X);
        BST = Insert(BST, X);
    }
    printf("Preorder:"); PreorderTraversal(BST); printf("\n");
    MinP = FindMin(BST);
    MaxP = FindMax(BST);
    scanf("%d", &N);
    for( i=0; i<N; i++ ) {
        scanf("%d", &X);
        Tmp = Find(BST, X);
        if (Tmp == NULL) printf("%d is not found\n", X);
        else {
            printf("%d is found\n", Tmp->Data);
            if (Tmp==MinP) printf("%d is the smallest key\n", Tmp->Data);
            if (Tmp==MaxP) printf("%d is the largest key\n", Tmp->Data);
        }
    }
    scanf("%d", &N);
    for( i=0; i<N; i++ ) {
        scanf("%d", &X);
        BST = Delete(BST, X);
    }
    printf("Inorder:"); InorderTraversal(BST); printf("\n");

    return 0;
}
/* 你的代码将被嵌在这里 */

BinTree Insert( BinTree BST, ElementType X )
{
    BinTree new_node = NULL;
    Position pos = BST;

    new_node = (BinTree) malloc(sizeof(struct TNode));
    new_node->Left = NULL;
    new_node->Right = NULL;
    new_node->Data = X;

    if(!BST) {
        return new_node;
    }

    while ( X != pos->Data ) {
        if(X > pos->Data) {
            if(pos->Right) {
                pos = pos->Right;
                continue;
            }
            else {
                pos->Right = new_node;
                break;
            }
        } else {
            if(pos->Left) {
                pos = pos->Left;
                continue;
            }
            else {
                pos->Left = new_node;
                break;
            }
        }
    }

    return BST;
    /*
        while (X > pos->Data) {
        if(pos->Left!= NULL)
            pos = pos->Left;
        else{
            pos->Left  = new_node;
            break;
        }
    }

    while (X < pos->Data) {
        if(pos->Right != NULL)
            pos = pos->Right;
        else {
            pos->Right = new_node;
            break;
        }
    }
    */
}

BinTree Delete( BinTree BST, ElementType X )
{
    Position pos = NULL;
    Position father = NULL;
    Position left_max = NULL;

    if(!BST) {
        printf("Not Found\n");
        return BST;
    }

    pos = BST;
    father = pos;

    while(pos->Data!=X) {
        if(X < pos->Data) {
            father = pos;
            pos = pos->Left;
        } else {
            father = pos;
            pos = pos->Right;
        }

        if(!pos)
            break;
    }

    if(!pos) {
        printf("Not Found\n");
        return BST;
    }

    /*叶节点*/
    if(pos->Left==NULL && pos->Right==NULL){

        /*只有一个节点*/
        if(pos == BST) {
            free(pos);
            return NULL;
        }

        if(pos->Data < father->Data)
            father->Left = NULL;
        else
            father->Right = NULL;
        free(pos);

        return BST;
    }

    /*单边树*/
    if(pos->Left == NULL || pos->Right == NULL) {

		/*树根*/
		if(pos == BST) {
			if(pos->Left) 
				BST = pos->Left;
			else
				BST = pos->Right;

			free(pos);
			return BST;
		}

        if(pos->Data < father->Data) {
             if(pos->Left) father->Left = pos->Left;
             else father->Left = pos->Right;
        }
		else {
             if(pos->Left) father->Right = pos->Left;
             else father->Right = pos->Right;
        }
        free(pos);
        return BST;
    }

    left_max = FindMax(pos->Left);
    pos->Data = left_max->Data;

    /*删去原来位置的*/
    Delete(pos->Left, pos->Data);
    return BST;
}

Position Find( BinTree BST, ElementType X )
{
    Position pos = BST;

    if(!pos) return NULL;

    while(pos->Data != X){
        if(X > pos->Data) {
            if(pos->Right){
                pos = pos->Right;
                continue;
            }else {
                return NULL;
            }
        }
        else {
            if(pos->Left){
                pos = pos->Left;
                continue;
            }else {
                return NULL;
            }
        }
    }
    return pos;
}

Position FindMin( BinTree BST )
{
    Position pos = BST;

    if(!pos) return NULL;

    while(pos->Left)
    {
        pos = pos->Left;
    }

    return pos;
}

Position FindMax( BinTree BST )
{
    Position pos = BST;

    if(!pos) return NULL;

    while(pos->Right)
    {
        pos = pos->Right;
    }

    return pos;
}


void PreorderTraversal( BinTree BT )/* 先序遍历，由裁判实现，细节不表 */
{
    if(BT) {
        printf("%d ",BT->Data);
        PreorderTraversal( BT->Left );
        PreorderTraversal( BT->Right );
    }
}


void InorderTraversal( BinTree BT ) /* 中序遍历，由裁判实现，细节不表 */
{
    if(BT) {
        InorderTraversal(BT->Left) ;
        printf("%d ", BT->Data);
        InorderTraversal( BT->Right );
    }
}
