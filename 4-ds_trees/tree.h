#include <stdio.h>
#include <stdlib.h>

/**
* BSTNode- Binary Search Tree Node
* @data: node data
* @left: left child
* @right: right child
*/
typedef struct BSTNode 
{
    void *data;
    struct BSTNode *left;
    struct BSTNode *right;

}bnode;

typedef enum _Type
{
    INT,
    FLT,
    NDE
}typ;

bnode *binit(void *data);
bnode *_binsertInt(bnode *root, void *data);
bnode *_searchInt(bnode *root, int data);
void _remove(bnode *root, void *data);
