#include "tree.h"

int  main(void)
{
    int d2 = 78, d4 = 0;
    bnode *root = NULL;

    root = _binsertInt(root, &d4);

    printf("##root adrr: %i\n", *(int *)(root->data));
    root = _binsertInt(root, &d2);
    printf("##root data: %i\n", *(int *)(root->data));



    return (0);
}