#ifndef _LIST
#define _LIST

#include <stdio.h>
#include <stdlib.h>

/**
* Node- defined data structure that stores the node of a linked list
* @data: the data at each node
* @next: pointer to next node
*/
typedef struct Node
{
    int data;
    struct Node *next;

}node;

void _lappend(node *head, int x);
void _linsert(node **head, int x);
void _lprintlist(node *head);
node *_lreversels(node *head);
void _lfreelist(node *head);
int _ldeleten(node **hptr, int n);
void _lrprint(node *h);
int _linsertn(node **head, int x, int n);
node *_lreversed(node *p);

#endif