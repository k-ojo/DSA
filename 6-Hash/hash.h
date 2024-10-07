#ifndef _HASH
#define _HASH

#include <stdio.h>
#include <stdlib.h>
#include "../4-ds_trees/src/tree.h"
#include <string.h>

typedef int tsize;
typedef int ksize;

//typedef struct _hashMap map;

typedef enum _type
{
    INT,
    STR
}type;

typedef struct _hashMap
{
    type Type;
    tsize size;
    bnode **arr;
    int (*H)(void *, tsize);    
}map;

//hash.c
ksize Hint(void *id, tsize);
ksize Hstr(void *id, tsize);
map *Hinit(tsize s, type);
int _mapit(map *m, void *data, void *id);
int mapit(map *m, int, int id);
int prdata(map *m, int);


#endif