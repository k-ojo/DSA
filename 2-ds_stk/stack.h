#include <stdio.h>
#include <stdlib.h>


/**
MyStackNode- node of stack
@ data: data, could be anything
@ top: top of stack
*/

typedef struct MyStackNode
{
    int data;
    struct MyStackNode *next;

}msnode;

int pop(msnode **top);
void push(msnode **top, int x);





