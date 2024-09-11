#include "dblnklst.h"

void _dinsert(dnode **head, int x)
{
    dnode *tmp = (dnode *)malloc(sizeof(dnode));
    tmp->data = x;
    tmp->next = *head;
    tmp->prev = NULL;
    (*head)->prev = tmp;
    *head = tmp;
}
