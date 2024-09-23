#include "tree.h"

/**
* bltraverse- binary tree level-order traversal
* @root: root of tree
*/
void bltraverse(bnode *root)
{
    queue *q = NULL;

    if (!root)
        return;

    q = qinit();

    enqueue(q, root);
    while (!isEmpty(q))
    {
        root = (bnode *)peek(q);
        deque(q);

        printf("data: %i\n", *(int *)(root->data));
        if (root->left)
            enqueue(q, root->left);
        if (root->right)
            enqueue(q, root->right);
    }
}

/**
* bpreotr- binary tree predrder traversal
* @root: root of tree
*
*/
void bpreotr(bnode *root)
{
    if (!root)
        return;
    printf("Data at node: %i\n", *(int *)root->data);
    bpreotr(root->left);
    bpreotr(root->right);
}

/**
* binotr- binary tree inorder traversal
* @root: root of tree
*
*/
void binotr(bnode *root)
{
    if (!root)
        return;
    binotr(root->left);
    printf("Data at node: %i\n", *(int *)root->data);
    binotr(root->right);
}

/**
* bposrtr- binary tree postoder traversal
* @root: root of tree
*
*/
void bposrtr(bnode *root)
{
    if (!root)
        return;
    bposrtr(root->left);
    bposrtr(root->right);
    printf("Data at node: %i\n", *(int *)root->data);

}