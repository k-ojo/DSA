#include "tree.h"


typedef struct _Heap
{
    int size;
    int len;
    int *arr;
}heap;

/**
* hinit- initializes a heap of length n
* @n: length of heap
*
* Return: pointer to heap
*/
heap *hinit(int n)
{
    heap *_newh = (heap *)malloc(sizeof(heap));
    _newh->arr = (int *)malloc(n * sizeof(int));
    _newh->size = n;
    _newh->len = 0;
    return (_newh);
}

/**
* addint- and an integer to heap
* @h: heap
* @data: input data
*
* Return: 1 on success 0 on failure
*/
int addint(heap *h, int data)
{
    int tmp, c = h->len;
    //logic
    if (h->len >= h->size)
        return (0);
    h->arr[h->len] = data;

    while (c >= 0)
    {
        if (c == 0)
        {
            h->len += 1;
            return (1);
        }
        else if (c % 2 == 0 && h->arr[c] < h->arr[(c - 2) / 2])   // if child index is even
        {
            tmp = h->arr[c];
            h->arr[c] = h->arr[(c - 2) / 2];
            h->arr[(c - 2) / 2] = tmp;          //save tmp to parent
            c = (c - 2) / 2;                    //make parent child
        }
        else if (c % 2 == 1 && h->arr[c] < h->arr[(c - 1) / 2])
        {
            tmp = h->arr[c];                        // swap
            h->arr[c] = h->arr[(c - 1) / 2];        // the parent
            h->arr[(c - 1) / 2] = tmp;              // and child
            c = (c - 1) / 2;
        }
        else
        {
            h->len += 1;
            return (1);
        }
    }
    return (1);
}


/**
* hprint- print heap
* @h: input heap
*/
void hprint(heap *h)
{
    int i, n = h->len;

    for (i = 0; i < n; i++)
        printf("%i--> %i\n", i, h->arr[i]);
}

/**
* poll- removes root node
* @h: heap
*/
int poll(heap *h)
{
    return (0);

}