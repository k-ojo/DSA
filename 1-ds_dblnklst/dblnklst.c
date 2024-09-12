#include "dblnklst.h"


/**
* _dinsert- inserts node to at the head doubly linked list
* @head: head of list
* @x: input data
* Return: nothing
 */
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

/**
* _dprintls- prints the doubly linked list
* @head: head of list
* Return: nothing
 */
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

/**
* _dfreels- free the doubly linked list from heap
* @head: head of list
* Return: nothing
 */
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


/**
* _dreversed- reverses the doubly linked list
* @head: head of list
* Return: reverse linked list
 */
dnode *_dreversed(dnode *head)
{
    dnode *nxt;
    if (!head)
        return NULL;
    while (head->next != NULL)
    {
        nxt = head->next;
        head->next = head->prev;
        head->prev = nxt;
        head = head->prev;
    }

    head->next = head->prev;
    head->prev = NULL;
    return head;
}