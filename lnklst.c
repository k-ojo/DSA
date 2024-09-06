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
node *_insert(node *head, int x)
{
    node *nd = (node *)malloc(sizeof(node));
    nd->data = x;
    nd->next = head;
    return nd;
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
    printf("%i->NULL", head->data);
    
}

/**
* _freelist: frees the list from allocated memory
* @head- head of linked list
* Return: Nothing
*/
void _freelist(node *head)
{
    node *tmp;
    while (head->next != NULL)
    {
        tmp = head;
        head = head->next;
        free(tmp);
    }
    free(head);
}

//test
int main() {
    // Write C code here
    node *head = NULL;
    head = _insert(head, 25);
    head = _insert(head, 80);
    _append(head, 60);
    _append(head, 80);
    _append(head, 58);
    _printlist(head);
    _freelist(head);
    return 0;
}
