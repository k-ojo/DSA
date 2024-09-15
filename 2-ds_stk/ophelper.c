#include "stack.h"

/**
* _popnadd- pop and multiply
* @top: top of stack
*
* Return: -1 on success, 0 on success
*/
int _popnmul(msnode **top)
{
    int a, b, *c;
    
    if (!top || top == NULL)
        return (-1);

    a = *(int *)peek(*top);
    pop(top);

    if (*top == NULL)
        return (-1);

    b = *(int *)peek(*top);
    pop(top);

    c = (int *)malloc(sizeof(int)); //allocate memory to c

    *c = a * b;
    push(top, c, INT);
    (*top)->flag = True;


    return (0);
}


/**
* _popnadd- pop and add
* @top: top of stack
*
* Return: -1 on failure, 0 for success
*/
int _popnadd(msnode **top)
{
    int a, b, *c;
    
    if (!top || top == NULL)
        return (-1);

    a = *(int *)peek(*top);
    pop(top);

    if (*top == NULL)
        return (-1);

    b = *(int *)peek(*top);
    pop(top);

    c = (int *)malloc(sizeof(int)); //allocate memory to c
    *c = a + b;
    push(top, c, INT);
    (*top)->flag = True;


    return (0);    
}

/**
* _popnadd- pop and subtract
* @top: top of stack
*
* Return: -1 on failure, 0 on success 
*/
int _popnsub(msnode **top)
{
    int a, b, *c;
    
    if (!top || top == NULL)
        return (-1);

    a = *(int *)peek(*top);
    pop(top);

    if (*top == NULL)
        return (-1);

    b = *(int *)peek(*top);
    pop(top);

    c = (int *)malloc(sizeof(int)); //allocate memory to c

    *c = b - a;
    push(top, c, INT);
    (*top)->flag = True;

    return (0);   
}

/**
* _popnadd- pop and divide
* @top: top of stack
*
* Return: -1 on failure 0 on success
*/
int _popndiv(msnode **top)
{
    int a, b, *c;
    
    if (!top || top == NULL)
        return (-1);

    a = *(int *)peek(*top);
    pop(top);

    if (*top == NULL)
        return (-1);

    b = *(int *)peek(*top);
    pop(top);

    c = (int *)malloc(sizeof(int)); //allocate memory to c

    *c = b / a;
    push(top, c, INT);
    (*top)->flag = True;


    return (0);
}


/**
* _popnadd- pop and exponent
* @top: top of stack
*
* Return: -1 on falure, 0 on success
*/
int _popnexp(msnode **top)
{
    int a, b, *c;
    
    if (!top || top == NULL)
        return (-1);

    a = *(int *)peek(*top);
    pop(top);

    if (*top == NULL)
        return (-1);

    b = *(int *)peek(*top);
    pop(top);

    c = (int *)malloc(sizeof(int)); //allocate memory to c

    *c = a ^ b;
    push(top, c, INT);
    (*top)->flag = True;

    
    return (0);
}
