struct tree
{
    struct tree* leftchild;
    struct tree* rightchild;
    char data;    
};

typedef struct tree * PtrTree;


int FindRoot(int size, char tree_arr[][3]);
PtrTree CreateTree(int size, char tree_arr[][3], int root);
void DeleteTree(PtrTree root);

int TreeCompare(PtrTree tree1, PtrTree tree2);