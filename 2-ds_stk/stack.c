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

        case CHAR:
        tmp->data = (char *)x;
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
* checkBalancedParenthesis- stack definition
*
*/
void checkBalancedParenthesis(char *str)
{
    msnode *top;
    int i = 0;

    while(str[i] != '\0')
    {
        if (str[i] == '{' || str[i] == '(' || str[i] == '[')
        {
            push(&top, &(str[i]), CHAR);
        }
        else if (str[i] == '}' || str[i] == ')' || str[i] == ']')
        {
            if(!(_match(str[i], &top)));
            {
                printf("%s at character %i\n", str, i);
            }
        }
        i++;
    }
    if (!top)
    {
        printf("Missing parenthesis. %s at character %i\n", str, i);
    }
}

int _match(char c, msnode **top)
{
    if (!(*top))
    {
        printf("Parenthesis has no match\n");
        return (0);
    }
    if (c == ')')
    {
        if (c == *(char *)(*top)->data + 1)
        {
            printf("c = %c,   data = %c\n", c, *(char *)(*top)->data);
            pop(top);
            return(1);
        }
        
    }
    else if (c =='}' || c == ']')
    {
        if (c == *(char *)(*top)->data + 2)
        {
            pop(top);
            return(1);
        }
    }

    printf("Parenthesis \"%c\" has no match. ", c);
    return(0);
}