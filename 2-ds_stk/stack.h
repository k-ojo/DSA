#include <stdio.h>
#include <stdlib.h>
#include "../0-ds_lnklst/lnklst.h"


typedef enum {
    False = 0,
    True = 1
}bool;


/**
MyStackNode- node of stack
@ data: data, could be anything
@ next: next node
*/
typedef struct MyStackNode
{
    void* data;
    struct MyStackNode *next;

}msnode;

typedef enum DataType
{
    INT, NODE
}type;

void pop(msnode **top);
void push(msnode **top, void *x, type);
void *peek(msnode *top);
bool isEmpty(msnode *top);

//APPLICATION
