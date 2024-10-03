#include "tree.h"

// DJB MURMUR and CRC32 hashes

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
* Return: nothing
*/
void addint(heap *h, int data)
{
    int c = h->len;
    //logic
    if (h->len >= h->size)
    {
        h->arr = (int *)realloc(h->arr, sizeof(int) * (h->size) * 2);
        h->size *= 2;
    }

    h->arr[h->len] = data;
    bubbleup(h, c);
    h->len += 1;
}

/**
* poll- removes root node
* @h: heap
* 
* Return: Data on root node
*/
int poll(heap *h)
{
    int data, i = 0;

    if (h->len == 0)
        return (MIN_INT);
    data = h->arr[0];
    h->arr[0] = h->arr[h->len - 1];
    h->len--;
    bubbledwn(h, i);
    return (data);
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
    int p, i = findData(h, _data);

    if (h->len == 0 || i == -1)
        return (0);
    
    if (i % 2 == 0)
        p = (i - 2) / 2;
    else
        p = (i - 1) / 2;

    h->arr[i] = h->arr[h->len - 1];
    h->len--;
    
    if (p >= 0 && h->arr[p] > h->arr[i])
        bubbleup(h, i);
    else
        bubbledwn(h, i);

    return (1);
}



// UTILITIES

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

/**
* bubbledup- bubbles up
* @h: heap
* @c: index of node
*
* Return: nothing
*/
void bubbleup(heap *h, int c)
{
    int tmp;

    while (1)
    {
        if (c <= 0)
            return;
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
            return;
    }
    
}

/**
* bubbledwn- bubbles down
* @h: heap
* @i: index of node
*
* Return: nothing
*/
void bubbledwn(heap *h, int i)
{
    int tmp, lc, rc;

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
            return;
    }
}

/**
* hprint- print heap
* @h: input heap
*
*/
void hprint(heap *h)
{
    int i, n = h->len;

    printf("Length of heap is: %i\n", n);
    for (i = 0; i < n; i++)
        printf("%i--> %i\n", i, h->arr[i]);
}

/**
* hdelete- deletes heap and frees allocated memory
* @h: heap
*/
void hdelete(heap *h)
{
    free (h->arr);
    free (h);
}