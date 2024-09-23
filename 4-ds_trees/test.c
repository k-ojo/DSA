#include "tree.h"

int  main(void)
{
    int d2 = 78, d4 = 190, d1 = 17, d3 = 540;
    int d5 = 90, d6 = 3;
    bnode *root = NULL;

    //populate tree
    root = _binsertInt(root, 80);
    root = _binsertInt(root, d6);
    root = _binsertInt(root, 920);
    root = _binsertInt(root, 6);
    root = _binsertInt(root, d5);
    root = _binsertInt(root, 67);
    root = _binsertInt(root, d5);
    root = _binsertInt(root, d2);
    root = _binsertInt(root, d4);
    root = _binsertInt(root, d1);
    root = _binsertInt(root, d3);



    //testing
    bnode *tmp = _bmax(root);

    if (!tmp)
        printf("Not found\n");
    else
        printf("Found, data is: %i\n", *(int *)(root->data));

    printf("height of tree is: %i\n", _bheight(root));

    if (_isGtr("who is this motherfucker?", "stra"))
        printf("It is greater\n");

    //bltraverse(root);
    //bpreotr(root);
    //bposrtr(root);
    //binotr(root);

    //*(int *)(root->data) = 80;
    if (isBst(root))
        binotr(root);

    return (0);
}