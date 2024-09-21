#include "tree.h"

int  main(void)
{
    int d2 = 78, d4 = 0;
    bnode *root = NULL;

    root = _binsertInt(root, &d4);

    printf("##root adrr: %i\n", *(int *)(root->data));
    root = _binsertInt(root, &d2);
    printf("##root data: %i\n", *(int *)(root->data));

    bnode *tmp = _searchInt(root, 0);

    if (!tmp)
        printf("Not found\n");
    else
        printf("Found, data is: %i\n ", *(int *)(tmp->data));

    return (0);
}