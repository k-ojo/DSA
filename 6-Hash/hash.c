#include "hash.h"


/**
*Hinit- initialize hash map
* @size: size of arr
*
* Return: Pointer to map
*/
map *Hinit(tsize s, type T)
{
    map *mptr = (map *)malloc(sizeof(map));
    mptr->size = s;
    mptr->arr = (bnode **)malloc(sizeof(bnode *) * s);
    for (int i = 0; i < s; i++)
        mptr->arr[i] = NULL;

    switch (T)
    {
        case INT:
        mptr->H = Hint;
        mptr->Type = INT;
        break;

        case STR:
        mptr->H = Hstr;
        mptr->Type =STR;
        break;
    }
    return (mptr);
}


/**
* Hstr- initializes has map
* @id: unique value
* @s: size of map
* Return: key generated. A unique index, ideally
*/
ksize Hstr(void *id, tsize s)
{
    int hash = 0;
    while(*(char *)id != '\0')
    {
        hash += *(char *)id;
        id++;
    }
    return (((hash % s) + s) %s); 
}

/**
 Hint- hashes int values
*/
ksize Hint(void *id, tsize s)
{
    int _id = *(int *)id;
    int hash = (_id * _id * _id) + (_id * _id) + 90;
    return (((hash % s) + s) %s); 

}

/**
* mapit- maps data to an index
* @m: the map
* @data: data input
* @id: id of data
* Return: Index of data 
*/
int _mapit(map *m, void *data, void *id)
{

    int index = -1; 
    switch (m->Type)
    {
        case INT:
        index = m->H(id, m->size);
        
        break;

        case STR:
        index = m->H(id, m->size);
        break;
    }
    if (index == -1)
        return (index);

    //this is only limited to int for learning purposes
    m->arr[index] = _binsertInt(m->arr[index], *(int *)data);

    return (index);
}

int mapit(map *m, int data, int key)
{
    return(_mapit(m, &data, &key));
}


int prdata(map *m, int key)
{
    int index = m->H(&key, m->size);

    printf("\tIndex\tID\n\t%i\t%i\n", index, key);
    bpreotr(m->arr[index]);
    return (index);
}

