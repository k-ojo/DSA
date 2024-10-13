#include "hash.h"
/**
* _data: data
* @name: name
* @age: age
* @id: id
* 
*/
typedef struct _data
{
    char *name;
    int age;
    int id;
}data;

int main (void)
{
    void *data;
    map *m = Hinit(10, INT);
    mapit(m, 7, 0);
    mapit(m, 72, 1);
    mapit(m, 44, 2);


    mapit(m, 45, 3);
    //printf("\t%\n",  *(int *)m->arr[0]->data);
    prdata(m, 1);
    if (!(data = lookup(m, 1, 7)))
        return (1);
    printf("%i\n", *(int *)data);

    return (1);
}