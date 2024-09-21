#include "tree.h"

/**
* binit- initializes a node
* @data: node data
*
* Return: the initialized node
*/
bnode *binit(void *data)
{
    bnode *tmp = (bnode *)malloc(sizeof(bnode));
    tmp->left = NULL;
    tmp->right = NULL;
    tmp->data;
    return (tmp);
}