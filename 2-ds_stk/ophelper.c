#include "stack.h"

/**
* _popnadd- pop and multiply
* @top: top of stack
*
* Return- nothing
*/
void _popnmul(msnode **top)
{
    int a, b, c;
    
    if (!top || top == NULL)
        return;

    a = *(int *)peek(*top);
    pop(top);

    b = *(int *)peek(*top);
    pop(top);

    c = a * b;

    push(top, &c, INT);
}

/**
* _popnadd- pop and add
* @top: top of stack
*
* Return- nothing
*/
void _popnadd(msnode **top)
{
    int a, b, c;
    
    if (!top || top == NULL)
        return;

    a = *(int *)peek(*top);
    pop(top);

    b = *(int *)peek(*top);
    pop(top);

    c = a + b;

    push(top, &c, INT);
}

/**
* _popnadd- pop and subtract
* @top: top of stack
*
* Return- nothing
*/
void _popnsub(msnode **top)
{
    int a, b, c;
    
    if (!top || top == NULL)
        return;

    a = *(int *)peek(*top);
    pop(top);

    b = *(int *)peek(*top);
    pop(top);

    c = a - b;

    push(top, &c, INT);
}

/**
* _popnadd- pop and divide
* @top: top of stack
*
* Return- nothing
*/
void _popndiv(msnode **top)
{
    int a, b, c;
    
    if (!top || top == NULL)
        return;

    a = *(int *)peek(*top);
    pop(top);

    b = *(int *)peek(*top);
    pop(top);

    c = a / b;

    push(top, &c, INT);
}

/**
* _popnadd- pop and exponent
* @top: top of stack
*
* Return- nothing
*/
void _popnexp(msnode **top)
{
    int a, b, c;
    
    if (!top || top == NULL)
        return;

    a = *(int *)peek(*top);
    pop(top);

    b = *(int *)peek(*top);
    pop(top);

    c = a ^ b;

    push(top, &c, INT);
}