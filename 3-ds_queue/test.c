#include "queue.h"

int main(void)
{
    //int data = 100;

    queue *q = qinit();


    //enqueue(q, &data);

    /* if (!isEmpty(q))
        ptr = (int *)deque(q);
    */
    printf("%p\n", peek(q));
    freeq(q);
    return (0);
}