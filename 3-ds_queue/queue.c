#include "queue.h"

/**
* enqueue- inserts a member to queue
* @q: the queue
* @data: data to be queued
* Return: Nothing 
*/
void enqueue(queue *q, void *data)
{
    qnode *tmp = (qnode *)malloc(sizeof(qnode));
    tmp->data = data;
    tmp->next = NULL;

    if (q->front == NULL)
    {
        q->front = tmp;
        q->rear = tmp;
        return;
    }

    (q->rear)->next = tmp;
    q->rear = tmp;

    
}

/**
* qinit- initializes queue
* Return: Initiazed queue
*/
queue *qinit(void)
{
    queue *tmp = (queue *)malloc(sizeof(queue));
    tmp->front = NULL;
    tmp->rear = NULL;
    return (tmp);
}

/*
* deque- deletes and return data of the node at the front
* @q: Queue
* Return: Nothing
*/
void *deque(queue *q)
{
    qnode *tmp = NULL;
    void *data;

    if (!q)
        return NULL;

    tmp = q->front;
    q->front = (q->front)->next;

    data = tmp->data;

    free(tmp);
    return (data);
}

/**
* feeq- free allocated queue
* @q: queue
* Return: Nothing
*/
void freeq(queue *q)
{
    while (q->front != NULL)
        deque(q);
    free(q);
}