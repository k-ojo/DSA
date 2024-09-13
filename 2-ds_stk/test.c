#include "stack.h"

int main()
{
    msnode *top = NULL;
    node *ls = NULL;
    _linsert(&ls, 90);
    _linsert(&ls, 84);
    _linsert(&ls, 75);
    _linsert(&ls, 43);

    int data[] = {91, 12, 192, 129, 67, 34};

    push(&top, &data[0], INT);
    push(&top, &data[1], INT);
    //push(&top, ls, NODE);
    //node *d = (node *)peek(top);
    //printf("The top is: %i\n", d->data);

    push(&top, &data[2], INT);
    push(&top, ls, NODE);
    push(&top, &data[3], INT);
    push(&top, &data[4], INT);

    pop(&top);

    //pop(&top);
    printf("The top is: %i\n", *(int *)peek(top));
    
    _freestack(&top);
    _lfreelist(ls);

    if (top)
        printf("The top is: %i\n", *(int *)peek(top));

    //APPLICATION
    //checkBalancedParenthesis("((hhggfv");

    printf("%i\n", _atoi("1209102"));

    //_cal("71928, 1829, 129,+,+", ',');

    char str[] = "67239,839,2389,+,-";
    parseDelim(str, ',');
}