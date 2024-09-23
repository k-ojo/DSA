#include "tree.h"


/**
* _max- returns maximum int
* @a: first integer
* @b: second integer

* Return: maximum of the a and b
*/
int _max(int a, int b)
{
    if (a >= b)
        return (a);
    return (b);
}

/**
* _min- returns maximum int
* @a: first integer
* @b: second integer

* Return: minimum of the a and b
*/
int _min(int a, int b)
{
    if (a <= b)
        return (a);
    return (b);
}

/**
* _isGtr- determines if s1(string) is greater than s2
* @s1: first string
* @s2: string 2
*
* Return: returns 1 if s1 is greater s2, 0 if not. -1 if they are equal,
* 99 if NY string is empty
*/
int _isGtr(char *s1, char *s2)
{
    if (!s1 || !s2)
        return (errno);
    
    int i = 0;
    while (s1[i] && s2[i])
    {
        if (s1[i] > s2[i])
            return (1);
        if (s1[i] < s2[i])
            return (0);
        i++;
    }
    if (!s1[i] && !s2[i])
        return (-1);
    if (s1[i] && !s2[i])
        return (1);
    return (0);
}