/**
* written by: k-ojo
* Date: 9/6/2024
*/

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

/**
* _append- inserts data at the end of list
* @head: head of linked list
* @x: input data
* Return: nothing;
*/
void _append(node *head, int x)
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
void _insert(node **head, int x)
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
int _insertn(node **head, int x, int n)
{
    if (n == 0)
    {
        _insert(head, x);
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
void _printlist(node *head)
{
    while (head->next != NULL)
    {
        printf("%i->", head->data);
        head = head->next;
    }
    printf("%i->NULL\n", head->data);
     
}

node *_reversels(node *head)
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
void _freelist(node *head)
{
    node *tmp;
    if (!head)
    {
        return;
    }
    while (head->next != NULL)
    {
        tmp = head;
        head = head->next;
        free(tmp);
    }
    free(head);
}

int _deleten(node **hptr, int n)
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

//test
int main(void)
{
    // Write C code here
    node *head = NULL;
    node *h2 = NULL;
    _insert(&head, 25);
    _insert(&head, 80);
    _append(head, 60);
    _append(head, 83);
    _append(head, 58);
    _insertn(&head, 85, 5);
    _deleten(&head, -1);
    h2 = _reversels(head);
    _printlist(head);
    _printlist(h2);
    _freelist(head);
    _freelist(h2);
    return 0;
}