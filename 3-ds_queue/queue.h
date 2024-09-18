#ifndef _QUEUE
#define _QUEUE

#include <stdio.h>
#include <stdlib.h>

typedef struct QueueNode
{
    void *data;
    struct QueueNode *next;
}qnode;

typedef struct Queue
{
    qnode *front; //front of queue
    qnode *rear;  //rear of queue

}queue;

typedef enum _bool{
    False = 0,
    True = 1
}bool;

void enqueue(queue *q, void *data);
void *deque(queue *q);
queue *qinit(void);
void freeq(queue *q);
bool isEmpty(queue *q);
void *peek(queue *q);

#endif