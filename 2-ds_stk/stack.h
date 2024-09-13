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

int pop(msnode **top);
void push(msnode **top, void *x, type);
void *peek(msnode *top);
bool isEmpty(msnode *top);
void _freestack(msnode **top);

//APPLICATION
int _match(char c, msnode **top);
void checkBalancedParenthesis(char *str);
int _atoi(char *str);
int _cal(char *expr, char const delim);
char *parseDelim(char *str, char c);