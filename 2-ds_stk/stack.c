#include "stack.h"

/**
* pop- pops the the top of stack
* @top: top of stack
* Return: returns 0 on success, -1 on failure
*/
int pop(msnode **top)
{
    msnode *tmp;

    //printf("%p\n", *top);
    if (!top || *top == NULL)
        return (-1);

    tmp = *top;
    *top = (*top)->next;
    free(tmp);
    return (0);
}

/**
* push- pushes to the top of stack
* @top: top of stack
* @x: data
* Return: nothing
*/
void push(msnode **top, void *x, type T)
{
    //printf("Data: %i   Address: %p\n", *(int *)x, x);
    msnode *tmp = (msnode *)malloc(sizeof(msnode));
    switch(T)
    {
        case INT:
        tmp->data = (int *)x;
        break;

        case CHAR:
        tmp->data = (char *)x;
        case NODE:
        tmp->data = (node *)x;
        break;
    }
    
    tmp->flag = False;
    tmp->next = *top;
    *top = tmp;    
}

/**
* peek- get the top of stack
* @top: top of stack
* Return: Nothing
*/
void *peek(msnode *top)
{
    if (!top)
        return (NULL);

    return (top->data);
}

/**
* isEmpty- checks if stack is empty
* @top: top of stack
* Return: true(1) if empty 0 otherwise;
*/
bool isEmpty(msnode *top)
{
    if (!top)
    {
        return (True);
    }
    return (False);
}

/**
*_freestack- frees memory allocated to stack
* @top: top of stack
* Return: Nothing
*/
void _freestack(msnode **top)
{
    //printf("%p\n", top);
    while(top && !isEmpty(*top))
        pop(top);
}