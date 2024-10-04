#include "tree.h"

typedef struct _uFind
{
    int size;   //number of elements in unionfind ds
    int population;  //number of elements in array
    int *id;        // mapped ids
    int *count;

}uFind;

/**
* ufinit- initialize union find data structure
* @size: size
* Return: Initialized list
*/
uFind *ufinit(int size)
{
    if (!size)
        return (NULL);
    uFind *nw = (uFind *)malloc(sizeof(uFind));
    nw->size = size;
    nw->id = (int *)malloc(sizeof(int) * size);
    nw->count = (int *)malloc(sizeof(int) * size);

    for (int i = 0; i < nw->size; i++)
    {
        nw->id[i] = i;
        nw->count[i] = 1;
    }
    return (nw);    
}

void printuF(uFind *u)
{
    if (!u)
    {
        printf("NULL\n");
        return;
    }

    printf("\tID\tSize\n");
    for (int i = 0; i < u->size; i++)
    {
        printf("\t%i\t%i\n", u->id[i], u->count[i]);
    }
}
