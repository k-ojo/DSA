#include "stack.h"

int main()
{
    msnode *top = NULL;

    push(&top, 78);
    push(&top, 28);
    push(&top, 90);
    push(&top, 10);
    //pop(&top);
    //pop(&top);
    //pop(&top);

    printf("The top is: %i\n", peek(top));
}