#include "tree.h"

/**
* _bmin- returns node with minimum value
* @root: the tree root
* Return- The min node
*/
bnode *_bmin(bnode *r)
{
    if (r == NULL)
        return (NULL);
    if (r->left == NULL)
        return (r);
    return (_bmin(r->left)); 
}

/**
* _bmax- returns node with maximum value
* @root: the tree root
* Return- The maximum node
*/
bnode *_bmax(bnode *r)
{
    if (r == NULL)
        return (NULL);
    if (r->right == NULL)
        return (r);
    return (_bmax(r->right)); 
}

/**
* @_bheight- height of binary tree
* @r: the root of tree
* Return- height binary tree
*
* time complexity of O(n)
*/
int _bheight(bnode *r)
{
    if (!r)
        return (-1);
    int a = _bheight(r->left), b = _bheight(r->right);
    return (_max(a, b) + 1);
}

/**
* _isBst- checks if binary tree is binary search tree
* @root: root of tree
* Return: 1 if true, 0 if false,  -1 on failure
*/
int _isBst(bnode *root, void *data)
{
    if (!root)
        return (1);

    if (!_isBst(root->left, data))
        return (0);
    if (*(int *)root->data < *(int *)data)
        return (0);
    //printf("%i  %i\n",*(int *)root->data, *(int *)data);
    data = root->data;
    return (_isBst(root->right, data));
}
