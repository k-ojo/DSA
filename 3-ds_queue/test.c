#include "queue.h"

int main(void)
{
    int data = 100, *ptr;

    queue *q = qinit();

    enqueue(q, &data);

    if (!isEmpty(q))
        ptr = (int *)deque(q);

    printf("%i\n", *ptr);
    freeq(q);
    return (0);
}