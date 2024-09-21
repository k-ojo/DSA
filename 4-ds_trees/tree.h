#include <stdio.h>
#include <stdlib.h>

/**
* @data: node data
* @left: left child
* @right: right child
*/
typedef struct BSTNode 
{
    void *data;
    Node *left;
    Node *right;

}bnode;

bnode *binit(void *data);
void binsert(bnode *root, void *data);
bnode *search(bnode *root, void *data);
