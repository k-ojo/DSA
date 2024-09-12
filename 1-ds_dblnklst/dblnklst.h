#include <stdio.h>
#include <stdlib.h>
/**
* Node- defined data structure that stores the node of a linked list
* @data: the data at each node
* @next: pointer to next node
* @prev: pointer to previous node
*/
typedef struct dNode
{
    int data;  //data can be any other type

    struct dNode *next;
    struct dNode *prev;
}dnode;

//in dblnklst.c

void _dinsert(dnode **head, int x);
void _dinsertn(dnode **head, int x);
void _dprintls(dnode *head);
dnode *_dreversed(dnode *head);
void _dfreels(dnode *head);