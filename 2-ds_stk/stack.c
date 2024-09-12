#include "stack.h"

/**
* pop- pops the the top of stack
* @top: top of stack
* Return: nothing
*/
void pop(msnode **top)
{
    msnode *tmp = *top;

    if (!top || *top == NULL)
    {
        return;
    }
    *top = tmp->next;
    free(tmp);
}

/**
* push- pushes to the top of stack
* @top: top of stack
* @x: data
* Return: nothing
*/
void push(msnode **top, void *x, type T)
{
    msnode *tmp = (msnode *)malloc(sizeof(msnode));
    switch(T)
    {
        case INT:
        tmp->data = (int *)x;
        break;

        case NODE:
        tmp->data = (node *)x;
        break;
    }
    
    tmp->next = *top;
    *top = tmp;
}

void *peek(msnode *top)
{
    if (!top)
    {
        return (NULL);
    }
    return (top->data);
}

bool isEmpty(msnode *top)
{
    if (!top)
    {
        return (True);
    }
    return (False);
}

//APPLICATION

/**
* _stackNode- stack definition
*
 */