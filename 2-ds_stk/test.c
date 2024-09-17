#include "stack.h"

int c1 = 0;  //used in debugging
int c2 = 0; //used in debugging
int main(void)
{
    msnode *top = NULL;
    node *ls = NULL;
    _linsert(&ls, 90);
    _linsert(&ls, 84);
    _linsert(&ls, 75);
    _linsert(&ls, 43);

    int data[] = {1, 1, 1, 1, 1, 1};

    push(&top, &data[0], INT);
    push(&top, &data[1], INT);

    //push(&top, ls, NODE);
    //node *d = (node *)peek(top);
    //printf("The top is: %i\n", d->data);

    push(&top, &data[2], INT);
    push(&top, ls, NODE);
    push(&top, &data[3], INT);
    push(&top, &data[4], INT);

    _popnadd(&top);
    //_popnmul(&top);
    //pop(&top);
    //printf("The top is: %i\n", *(int *)peek(top));
    
    _freestack(&top);
    _lfreelist(ls);

    //if (top)
    //    printf("The top is: %i\n", *(int *)peek(top));
    

    //APPLICATION
    //checkBalancedParenthesis("((hhggfv");

    printf("%i\n", _cal("2 , 3, *, 5, 4, *, +, 9, -", ','));
    printf("c1 = %i   c2 = %i\n", c1, c2);

}