#include <stdio.h>

/**
* Node- defined data structure that stores the node of a linked list
* @data: the data at each node
* @next: pointer to next node
* @prev: pointer to previous node
*/
typedef struct Node
{
    int data;  //data can be any other type

    node *next;
    node *prev;
}node;

//dblnklst
void _dappend(node *head, int x);
void _dinsert(node **head, int x);
void _dprintls(node *head);
void _reversed(node )