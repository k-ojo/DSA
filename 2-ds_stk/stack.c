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
    {
        return (-1);
    }

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

//APPLICATION

/**
* checkBalancedParenthesis- stack definition
* @str: input string to check
* Return: nothing
*/
void checkBalancedParenthesis(char *str)
{
    msnode *top = NULL;  //very important to initialize to prevent memory leaks
    int i = 0;

    while(str[i] != '\0')
    {
        if (str[i] == '{' || str[i] == '(' || str[i] == '[')
            push(&top, &(str[i]), CHAR);

        else if (str[i] == '}' || str[i] == ')' || str[i] == ']')
        {
            if((_match(str[i], &top) == 0))
            {
                printf("%s at character %i\n", str, i);
                _freestack(&top);
                return;
            }
        }
        i++;
    }
    if (!isEmpty(top))
    {
        printf("Missing parenthesis. %s at character %i\n", str, i);
        _freestack(&top);

        return;
    }
    printf("No issues\n");
}

/**
* _match- checks if character is used well using stack
* @c: input character to be checked
* @top: Top of stack
* Return: Nothing
*/
int _match(char c, msnode **top)
{

    if (!top || isEmpty(*top))  //if stack is not empty
    {
        //printf("%c\n", *(char *)(*top)->data);

        printf("Parenthesis \"%c\" has no match. ", c);
        return (0);
    }
    if (c == ')')
    {
        //ascii values are used to compare
        //) is 41 and ( is 40  
        if (c == *(char *)(*top)->data + 1)
        {
            pop(top);
            return(1);
        }
        
    }
    else if (c =='}' || c == ']')
    {
        //these characters are 2 units distance from their pair
        printf("%c\n", *(char *)(*top)->data);
        if (*top && c == *(char *)(*top)->data + 2)
        {
            pop(top);
            return(1);
        }
    }

    printf("Parenthesis \"%c\" has no match. ", c);
    return(0);
}


// Infix, Postfix, Prefix