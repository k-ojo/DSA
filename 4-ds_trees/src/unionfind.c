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
    nw->population = size;

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

    printf("\tSize\tPopulation\n\t%i\t%i\n", u->size, u->population);
    printf("\tID\tCount\n");
    for (int i = 0; i < u->size; i++)
    {
        printf("\t%i\t%i\n", u->id[i], u->count[i]);
    }
}

/**
* Find- Find the root of an element
* u: union find
* p: the id, mapped integer
*
* Return: the root id
*/
int Find(uFind *u, int p)
{
    int root = p;
    if (p == u->id[p])
        return (root);
    root = Find(u, u->id[root]);
    u->id[p] = root;
    return (root);
}

/**
* unify- groups two inputs
* @u: the union find ds
* @a: first input
* @b: second input
* Return: 1 on success, -1 on failure
*/
int unify(uFind* u, int a, int b)
{
    if (a >= u->size || b >= u->size || b < 0 || a < 0)
        return (-1);

    int r1 = Find(u, a), r2 = Find(u, b);
    if (r1 == r2)
        return (1);
    if (u->count[r1] >= u->count[r2])
    {
        u->id[r2] = r1;
        u->count[r1] += u->count[r2];
        u->count[r2] = 0;
    }
    else
    {
        u->id[r1] = r2;
        u->count[r2] += u->count[r1];
        u->count[r1] = 0;
    }
    u->population--;
    return (1);
}