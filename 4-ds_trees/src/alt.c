#include "tree.h"

/**
*_altisBST
* @root: root of BT
* @min: lowest integer
* @max: highest integer
* Return: return 0 if not BST,1 if true
*/
int _altisBST(bnode *root, int min, int max)
{
    if (!root)
        return (1);

    if (*(int *)root->data >= min && *(int *)root->data <= max
        && _altisBST(root->left, min,*(int *)root->data)
        && _altisBST(root->right,*(int *)root->data, max))
        return (1);
    else    
        return (0);
}

/**
* altisBST
* @root: root of BT
* Return: return 0 if not BST,1 if true
*/
int altisBST(bnode *root)
{
    return (_altisBST(root, MIN_INT, MAX_INT));
}

/**
* getSuccessor
* @root: root of tree
* @data: input data
* Return: successor
*/
bnode *getSuccessor(bnode *root, int data)
{
    bnode *cur = _searchInt(root, data);
    if (!cur)
        return (NULL);

    if (cur->right)
        return (_bmin(cur->right));
    else
    {
        bnode *anctr = root, *sucr = NULL;
        while (anctr != cur)
        {
            if (*(int *)cur->data < *(int *)anctr->data)
            {
                sucr = anctr;
                anctr = anctr->left;
            }
            else
                anctr = anctr->right;
        }
        return (sucr);
    }
}