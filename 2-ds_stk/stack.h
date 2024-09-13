#include <stdio.h>
#include <stdlib.h>
#include "../0-ds_lnklst/lnklst.h"




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


typedef enum {
    False = 0,
    True = 1
}bool;

typedef enum DataType
{
    INT, NODE, CHAR
}type;

void pop(msnode **top);
void push(msnode **top, void *x, type);
void *peek(msnode *top);
bool isEmpty(msnode *top);

//APPLICATION
int _match(char c, msnode **top);
void checkBalancedParenthesis(char *str);
