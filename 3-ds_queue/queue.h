#ifndef _QUEUE
#define _QUEUE

#include <stdio.h>
#include <stdlib.h>

/**
* QueueNode- node
* @data: data
* @next: pointer to next node
* 
*/
typedef struct QueueNode
{
    void *data;
    struct QueueNode *next;
}qnode;


/**
* Queue- node
* @front: front node in queue
* @rear: rear node in queue
* 
*/
typedef struct Queue
{
    qnode *front; //front of queue
    qnode *rear;  //rear of queue

}queue;

/**
* _bool- node
* @False: front node in queue
* @True: rear node in queue
* 
*/
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