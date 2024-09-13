#include "stack.h"

int main()
{
    msnode *top = NULL;
    node *ls = NULL;
    _linsert(&ls, 90);
    _linsert(&ls, 84);
    _linsert(&ls, 75);
    _linsert(&ls, 43);

    int _data = 8;
    //void *data = &_data;

    push(&top, &_data, INT);
    _data = 42;
    push(&top, &_data, INT);
    _data = 12;
    push(&top, ls, NODE);
    node *data = (node *)peek(top);
    printf("The top is: %i\n", data->data);

    push(&top, &_data, INT);
    _data = 912;
    push(&top, &_data, INT);

    //pop(&top);
    //pop(&top);
    //pop(&top);


    printf("The top is: %i\n", *(int *)peek(top));

    checkBalancedParenthesis("isanic { dsdi} [sakkjj]]");

}