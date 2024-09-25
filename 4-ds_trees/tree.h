#ifndef _TREE_
#define _TREE_
#include <stdio.h>
#include <stdlib.h>
#include "../3-ds_queue/queue.h"


#define errno 99
#define MAX_INT (-(1 << (sizeof(int) * 8 - 1)))
#define MIN_INT (1 << (sizeof(int) * 8 - 1))
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

/*
* _bool- Bolean type
* @False: Boolean False = 0
* @True: True = 1
*/

/*
typedef enum _myBool
{
    False = 0,
    True = 1
}mbool;
*/

//tree.c
bnode *binit(void *data);
bnode *_binsertInt(bnode *root, int data);
bnode *_searchInt(bnode *root, int data);
void _remove(bnode *root, void *data);

//butils.c
bnode *_bmax(bnode *root);
bnode *_bmin(bnode *root);
int _bheight(bnode *);
int _isBst(bnode *root, void *data);
int isBst(bnode *root);

//traverse.c  
void bltraverse(bnode *root);
void bpreotr(bnode *root);
void binotr(bnode *root);
void bposrtr(bnode *root);

//utils.c
int _max(int a, int b);
int _min(int a, int b);
int _isGtr(char *s1, char *s2);

#endif