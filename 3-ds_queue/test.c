#include "queue.h"

int main(void)
{
    int data = 100, *ptr;

    queue *q = qinit();

    enqueue(q, &data);
    ptr = (int *)deque(q);

    printf("%i\n", *ptr);
    freeq(q);
    return (0);
}