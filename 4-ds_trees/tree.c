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
        printf("%i  -> Break\n", *(int *)data);
        root = binit(data);
        return (root);
    }

    if (*(int *)root->data >  *(int *)data)
        root->left = _binsertInt(root->left, data);
    else
        root->right = _binsertInt(root->right, data);
    return (root);

}


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