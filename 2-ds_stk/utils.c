#include "stack.h"

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

/**
* _atoi- converts a string to integr
* @str: input string
* Return: Returns converted integer
*/
int _atoi(char *str)
{
    int tmp, n, p;
    
    if (!str || *str == '\0')
    {
        return (-1);
    }

    p = 1;
    tmp = 0;
    n = 0;

    while(str[n] != '\0')
        n++;
    
    for (n--; n >= 0; n--)
    {
        if (str[n] == ' ')
            continue;
        if (str[n] < 48 || str[n] > 48 + 9)
            return (-1);

        tmp += p * (0 + str[n] - 48);
        p *= 10; 
    }
    return (tmp);

}

/**
*isOperator- checks if character is an operator
* @c: character
* Return: True if opertaor, False if not
*/
bool isOperator(char c)
{
    if (c == '/' || c == '-' || c == '+' ||
    c == '*' ||c == '^')
    {
        return (True);
    }
    return (False);
}

int _handleDelim(msnode **top, char *str, char prev)
{
    int *c = (int *)malloc(sizeof(int));

    if (isOperator(prev))
        return (-1);

    *c = _atoi(str);

    push(top, c, INT);
    (*top)->flag = True;

    return (*c);
}

int _len(char *str)
{
    int i = 0;

    while (str[i] != '\0')
        i++;
    return (i);
}

void handleOp(msnode **top, char c)
{
    printf("##The top is: %i\n", *(int *)peek(*top));

    switch (c)
    {
        case '+':
        //pop(top);
        _popnadd(top);

        break;

        break;
        case '*':
        _popnmul(top);
        break;

        case '-':
        _popnsub(top);
        break;

        case '/':
        _popndiv(top);
        break;

        case '^':
        _popnexp(top);
        break;
    }
}