#include "AlikeTree.h"
#include <stdio.h>

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
