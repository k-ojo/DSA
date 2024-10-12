#include "hash.h"

typedef struct _data
{
    char *name;
    int age;
    int id;
}data;

int main (void)
{
    map *m = Hinit(10, INT);
    mapit(m, 7, 0);
    mapit(m, 72, 1);
    mapit(m, 44, 2);


    mapit(m, 45, 3);
    //printf("\t%\n",  *(int *)m->arr[0]->data);
    prdata(m, 1);

    return (1);
}