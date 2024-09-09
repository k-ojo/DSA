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

void _append(node *head, int x);
void _insert(node **head, int x);
void _printlist(node *head);
node *_reversels(node *head);
void _freelist(node *head);
int _deleten(node **hptr, int n);
void _rprint(node *h);
int _insertn(node **head, int x, int n);
node *_reversed(node *p);