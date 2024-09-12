#include "dblnklst.h"

void _dinsert(dnode **head, int x)
{
    
    dnode *tmp = (dnode *)malloc(sizeof(dnode));
    tmp->data = x;
    tmp->next = *head;
    tmp->prev = NULL;
    if (*head == NULL)
    {
        *head = tmp;
        return;
    }
    (*head)->prev = tmp;
    *head = tmp;
}

void _dprintls(dnode *head)
{
    if (head == NULL)
    {
        printf("NULL\n");
        return;
    }
    printf("NULL<---");
    while(head->next != NULL)
    {
        printf("%i<--->", head->data);
        head = head->next;
    }
    printf("%i-->NULL\n", head->data);
    
}

void _dfreels(dnode *head)
{
    dnode *tmp;

    while(head != NULL)
    {
        tmp = head;
        head = head->next;
        free(tmp);
    }
}
