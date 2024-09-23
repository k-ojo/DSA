//author: Gideon Adjei
//Subject: DSA
//File: tree.c
//Ama
//0532510398
//0598929527 - whatsapp

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
bnode *_binsertInt(bnode *root, int d)
{
    if (!root)
    {
        int *data = malloc(sizeof(int));
        *data = d;
        root = binit(data);
        return (root);
    }

    if (*(int *)root->data >  d)
        root->left = _binsertInt(root->left, d);
    else
        root->right = _binsertInt(root->right, d);
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