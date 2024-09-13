#include "stack.h"

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
        if (str[n] < 48 || str[n] > 48 + 9)
            return (-1);
        if (str[n] == ' ')
            continue;

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

char *parseDelim(char *str, char c)
{
    int i = 0;
    printf("char: %c  i:  %i", 'v', i);

    if (str == NULL)
        return (NULL);
    

    while (str[i] != '\0')
    {
        
        if (str[i] == c)
        {
            str[i] = '$';
        } 
        i++;
    }
    return (str);

}
/**
_cal- calculates an input expression
* @expr: expression
* Return: the calculated expression
*/
int _cal(char *expr, char const delim)
{

    char *str = expr;
    int i = 0;
    int a, b, c;
    msnode *top = NULL;

    expr = parseDelim(expr, delim);

    while (expr[i] != '\0')
    {
        if (expr[i] == delim)
        {
            if (i != 0 && isOperator(expr[i-1]))
            {
                i++;
               continue;
            }

            str[i] = '\0';
            c = _atoi(str);
            push(&top, &c, INT);
            str = &expr[i + 1];
            i++;
            continue;
        }
        switch (expr[i])
        {
            case '*':
            a = *(int *)peek(top);
            pop(&top);
            b = *(int *)peek(top);
            c = a * b;
            push(&top, &c, INT);
            break;

            case '-':
            a = *(int *)peek(top);
            pop(&top);
            b = *(int *)peek(top);
            pop(&top);
            c = a - b;
            push(&top, &c, INT);

            break;

            case '+':
            a = *(int *)peek(top);
            pop(&top);
            b = *(int *)peek(top);
            pop(&top);
            c = a + b;
            push(&top, &c, INT);

            break;

            case '/':
            a = *(int *)peek(top);
            pop(&top);
            b = *(int *)peek(top);
            pop(&top);
            c = a / b;
            push(&top, &c, INT);

            case '^':
            a = *(int *)peek(top);
            pop(&top);
            b = *(int *)peek(top);
            pop(&top);
            c = a ^ b;
            push(&top, &c, INT);
            break;

            case '$':
        }
        i++;
    }

    _freestack(&top);
    return (0);
}