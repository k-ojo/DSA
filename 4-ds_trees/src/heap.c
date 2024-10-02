#include "tree.h"


typedef struct _Heap
{
    int size;
    int len;
    int *arr;
}heap;

/**
* hinit- initializes a heap of size n
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
    int c = h->len;
    //logic
    if (h->len >= h->size)
        return (0);
    h->arr[h->len] = data;

    return (bubbleup(h, c));
}


/**
* hprint- print heap
* @h: input heap
*/
void hprint(heap *h)
{
    int i, n = h->len;

    printf("Length of heap is: %i\n", n);
    for (i = 0; i < n; i++)
        printf("%i--> %i\n", i, h->arr[i]);
}

/**
* poll- removes root node
* @h: heap
* 
* Return: Data on root node
*/
int poll(heap *h)
{
    int data, tmp, lc, rc, i = 0;

    if (h->len == 0)
        return (MIN_INT);
    data = h->arr[0];
    h->arr[0] = h->arr[h->len - 1];
    h->len--;

    while (1)
    {
        tmp = h->arr[i];

        lc = 2 * i + 1;
        rc = 2 * i + 2;

        if (rc >= h->len)
            lc = i;
        if (rc >= h->len)
            rc = i;
        
        if (tmp > h->arr[lc] && h->arr[lc] <= h->arr[rc])
        {
            h->arr[i] = h->arr[lc];
            h->arr[lc] = tmp;
            i = lc;
        }
        else if (tmp > h->arr[rc] && h->arr[rc] < h->arr[lc])
        {
            h->arr[i] = h->arr[rc];
            h->arr[rc] = tmp;
            i = rc;
        }
        else
            return (data);
    }
}

/**
* hremove- removes node with _data
* @h: heap
* @_data: input data
*
* Return: Return 1 if found, 0 if not
*/
int hremove(heap *h, int _data)
{
    int tmp, lc, rc, i = findData(h, _data);

    if (h->len == 0 || i == -1)
        return (0);

    h->arr[i] = h->arr[h->len - 1];
    h->len--;

    while (1)
    {
        tmp = h->arr[i];

        lc = 2 * i + 1;
        rc = 2 * i + 2;

        if (rc >= h->len)
            lc = i;
        if (rc >= h->len)
            rc = i;
        
        if (tmp > h->arr[lc] && h->arr[lc] <= h->arr[rc])
        {
            h->arr[i] = h->arr[lc];
            h->arr[lc] = tmp;
            i = lc;
        }
        else if (tmp > h->arr[rc] && h->arr[rc] < h->arr[lc])
        {
            h->arr[i] = h->arr[rc];
            h->arr[rc] = tmp;
            i = rc;
        }
        else
            return (1);
    }
}

/**
* findData- finds the index input data
* @h: heap
* @d: data to be searched
* Return: index of data, -1 if nor found
*/
int findData(heap *h, int d)
{
    for (int i = 0; i < h->len; i++)
    {
        if (h->arr[i] == d)
            return (i);
    }
    return (-1);
}

int bubbleup(heap *h, int c)
{
    int tmp;

    while (1)
    {
        if (c <= 0)
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
    
}