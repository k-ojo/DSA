//author: Gideon Adjei
//Subject: DSA
//File: tree.c

#include "tree.h"

/**
* binit- binary node init; initializes a binary tree node
* @data: node data
*
* Return: the initialized node
*/
bnode *binit(void *data)
{
    bnode *tmp = (bnode *)malloc(sizeof(bnode));
    tmp->left = NULL;
    tmp->right = NULL;
    tmp->data = data;
    return (tmp);
}

/**
* binsert- inserts new node
* @root: root node
* @data: data to be inserted
*/
bnode *_binsertInt(bnode *root, void *data)
{
    if (!root)
    {
        root = binit(data);
        return (root);
    }

    if (*(int *)root->data >  *(int *)data)
        root->left = _binsertInt(root->left, data);
    else
        root->right = _binsertInt(root->right, data);
    return (root);

}

/**
* _searchInt- searches of integer is in the tree
* @root: the root of the tree to be searched
* @data: data to be searched
*/
bnode *_searchInt(bnode *root, int data)
{
    if (!root)
        return (NULL);
    if (*(int *)(root->data) == data)
        return (root);
    if (*(int *)(root->data) > data)
        return(_searchInt(root->left, data));
    else
        return (_searchInt(root->right, data));
    return (0);
}

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

int _bheight(bnode *r)
{
    if (!r)
        return (-1);
    int a = _bheight(r->left), b = _bheight(r->right);
    return (_max(a, b) + 1);

}

