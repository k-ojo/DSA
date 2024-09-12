#include "stack.h"

/**
* pop- pops the the top of stack
* @top: top of stack
* Return: Poped data
*/
int pop(msnode **top)
{
    int data;
    msnode *tmp = *top;

    if (!top || *top == NULL)
    {
        return(0);
    }
    *top = tmp->next;
    data = tmp->data;
    free(tmp);
    return (data);
}

/**
* push- pushes to the top of stack
* @top: top of stack
* @x: data
* Return: nothing
*/
void push(msnode **top, int x)
{
    msnode *tmp = (msnode *)malloc(sizeof(msnode));
    tmp->data = x;
    tmp->next = *top;
    *top = tmp;
}

void top()
{
    
}