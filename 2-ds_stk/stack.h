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

/*
* _bool- Bolean type
* @False: Boolean False = 0
* @True: True = 1
*/
typedef enum _bool{
    False = 0,
    True = 1
}bool;

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

//stackapp.c
void checkBalancedParenthesis(char *str);
int _cal(char *expr, char const delim);

///ophelper.c
void _popnadd(msnode **top);
void _popnsub(msnode **top);
void _popnmul(msnode **top);
void _popndiv(msnode **top);
void _popnexp(msnode **top);
