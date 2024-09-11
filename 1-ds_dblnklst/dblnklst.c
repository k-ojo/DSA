#include "dblnklst.h"

void _linsert(node **head, int x)
{
    dnode *tmp = (dnode *)malloc(sizeof(dnode));
    tmp->data = x;
    tmp->next = *head;
    tmp->prev = NULL;
    *head->prev = tmp;
    *head = tmp;
}