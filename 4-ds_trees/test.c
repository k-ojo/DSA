#include "tree.h"

int  main(void)
{
    /*
    printf ("%i\n", MAX_INT);
    int d2 = 78, d4 = 190, d1 = 17, d3 = 540;
    int d5 = 90, d6 = 3;
    bnode *root = NULL;

    //populate tree
    root = _binsertInt(root, 80);
    root = _binsertInt(root, d6);
    root = _binsertInt(root, 780);
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
    binotr(root);

    root = deleten(root, 80);
    printf("Is it binary? %i\n", altisBST(root));
    printf("Succer: %i\n", *(int *)getSuccessor(root, 67)->data);
    
    //t->arr[100] = 100;

    //printf("arr: %i\n", t->arr[100]);

    //binotr(root);
*/
    /*
    //heap tests
    heap *t = hinit(4);
    addint(t, 80);
    addint(t, 7);
    addint(t, 13);
    addint(t, 2);
    addint(t, 19);
    addint(t, 0);
    addint(t, 4);
    hprint(t);
    hremove(t, 80);
    //poll(t);
    hprint(t);
    hdelete(t);
*/
    //unionfind test
    uFind *u = ufinit(5);
    unify(u, 1, 4);
    unify(u, 1, 3);
    unify(u, 0, 2);

    printf("%i\n", Find(u, 0));
    printf("%i\n", unify(u, 0, 1));
    printf("%i\n", Find(u, 4));

<<<<<<< HEAD
    *(int *)(root->data) = 80;
    printf("Is it binary? %i\n", isBst(root));
    //binotr(root);
=======
    printuF(u);
>>>>>>> d050c4b35d951864ad7b24ae0b8578cf915a9fad

    return (0);
}