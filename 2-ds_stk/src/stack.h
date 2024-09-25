#ifndef _STACK
#define _STACK

#include <stdio.h>
#include <stdlib.h>
#include "../../0-ds_lnklst/lnklst.h"

extern int c1, c2;
/*
* _bool- Bolean type
* @False: Boolean False = 0
* @True: True = 1
*/
typedef enum _bool{
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
    bool flag;   //flag to determine if memory is allocated

}msnode;


/*
* DataType- type of data to be stacked
* @:INT = integer
* @NODE: linked list node type
* @CHAR: character
*/
typedef enum DataType
{
    INT, NODE, CHAR
}type;

//stack.c
int pop(msnode **top);
void push(msnode **top, void *x, type);
void *peek(msnode *top);
bool isEmpty(msnode *top);
void _freestack(msnode **top);

//APPLICATION

//utils.c
int _match(char c, msnode **top);
int _atoi(char *str);
bool isOperator(char c);
int _handleDelim(msnode **top, char *str, char prev);
int _len(char *str);
void handleOp(msnode **top, char c);

//stackapp.c
void checkBalancedParenthesis(char *str);
int _cal(char *expr, char const delim);

///ophelper.c
int _popnadd(msnode **top);
int _popnsub(msnode **top);
int _popnmul(msnode **top);
int _popndiv(msnode **top);
int _popnexp(msnode **top);

#endif