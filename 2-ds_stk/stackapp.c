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

int _cal(char *expr, char const delim)
{
    int i = 0, j = 0;
    char str[_len(expr)];  //list to temporarily
    msnode *top = NULL;

    while (expr[i] != '\0')
    {
        if (expr[i] == delim && i > 0)
        {
            str[j] = '\0';
            _handleDelim(&top, str, expr[i - 1]);
            j = 0;
            i++;
            continue;
        }
        else if (isOperator(expr[i]))
        {
            //printf("break\n");
            handleOp(&top, expr[i]);

            i++;
            continue;
        }

        str[j] = expr[i];
        i++;
        j++;
    }
    
    j = *(int *)(peek(top));
    return (j);
}