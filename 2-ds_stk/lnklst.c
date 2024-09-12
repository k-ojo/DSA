/**
* written by: k-ojo
* Date: 9/6/2024
*/

#include "../0-ds_lnklst/lnklst.h"



/**
* _append- inserts data at the end of list
* @head: head of linked list
* @x: input data
* Return: nothing;
*/
void _lappend(node *head, int x)
{
    node *nd = (node *)malloc(sizeof(node));
    nd->data = x;
    nd->next = NULL;
    
    while (head->next != NULL)
    {
        head = head->next;   
    }
    head->next = nd;   
}

/**
* _insert- inserts data at the beginning of list
* @head: head of linked list
* @x: input data
* Return: the new head of the linked list
*/
void _linsert(node **head, int x)
{
    //node *tmp;
    node *nd = (node *)malloc(sizeof(node));
    nd->data = x;
    nd->next = *head;
    *head = nd;
}


/**
* _insert- inserts data at the beginning of list
* @head: head of linked list
* @x: input data
* @n: index to insert
* Return: the new head of the linked list
*/
int _linsertn(node **head, int x, int n)
{
    if (n == 0)
    {
        _linsert(head, x);
        return (1);
    }

    int i = 0;
    node *hold;
    node *tmp = (node *)malloc(sizeof(node));
    
    tmp->data = x;
    hold = *head;

    while (hold != NULL)
    {
        if (i == n - 1)
        {
            tmp->next = hold->next;
            hold->next = tmp;
            return (1);
        }
        hold = hold->next;
        i++;
    }
    if (n > i)
    {
        printf("Error: %d is not a valid index\n", n);
    }
    free(tmp);
    return (0);
}

/**
* _printlist- prints linked list
* @head: head of linked list
*
* Return: nothing
*/
void _lprintlist(node *head)
{
    
    while (head != NULL)
    {

        printf("%i->", head->data);
        head = head->next;
    }
    printf("NULL\n");
     
}


/**
* _reversels-reverses linked list
* @head: this is linked list
* 
* Return: returns the reversed node
*/
node *_lreversels(node *head)
{
    node *prev = NULL;
    node *cur = head;
    node *nxt;

    while(cur != NULL)
    {
        nxt = cur->next;
        cur->next = prev;
        prev = cur;
        cur = nxt;
    }
    
    return prev;
}
/** 
* _freelist: frees the list from allocated memory
* @head- head of linked list
* Return: Nothing
*/
void _lfreelist(node *head)
{
    node *tmp;
    if (!head)
    {
        return;
    }
    while (head != NULL)
    {
        tmp = head;
        head = head->next;
        free(tmp);
    }
}

/** 
* _deleten: frees the list from allocated memory
* @hptr: pointer to head
* @n: nth position to delete from
* Return: 1 on success, 0 on failure
*/
int _ldeleten(node **hptr, int n)
{
    int i = 0;
    node *tmp;
    node *head = *hptr;

    if (n == 0)
    {
        *hptr = head->next;
        free(head);
        return (1);
    }

    while(head->next != NULL)
    {
        if (i == n - 1)
        {
            tmp = head->next;
            head->next = tmp->next;
            free(tmp);
            return (1);
        }
        i++;
        head = head->next;
    }
    printf("Invalid index\n");
    return (0);

}

/** 
* _rprint: frees the list from allocated memory
* @h- head of linked list
* Return: Nothing
*/
void _lrprint(node *h)
{
    if (h == NULL)
    {
        return;
    }
    _lrprint(h->next);
    printf("%i\n", h->data);

}

node *_lreversed(node *p)
{
    node *q;

    //printf("%i\n", p->data);
    if (p->next == NULL)
    {
        return (p);
        //
    }

    node *head = _lreversed(p->next);
    q = p->next;
    printf("q: %i p: %i\n", q->data, p->data);
    q->next = p;
    p->next = NULL;
    return (head);

}