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
    int data;
    struct MyStackNode *next;

}msnode;



/**
MyStackNode- node of stack
@ data: data, could be anything
@ top: top of stack
*/
void pop(msnode **top);
void push(msnode **top, int x);
int peek(msnode *top);
bool isEmpty(msnode *top);

