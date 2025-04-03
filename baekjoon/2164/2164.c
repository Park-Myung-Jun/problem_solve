#include <stdio.h>
#include <string.h>

#define QUEUE_MAX_SIZE 500001

int queue[QUEUE_MAX_SIZE], front, rear, queue_size;

int main(void)
{
    int i;
    int N, tmp;

    front = 0;
    rear = 0;
    scanf("%d", &N);
    queue_size = N;
    for(i = 0; i < N; i++)
    {
        queue[rear] = i + 1;
        rear = (rear + 1) % QUEUE_MAX_SIZE;
    }

    while(queue_size != 1)
    {
        // dequeue
        front = (front + 1) % QUEUE_MAX_SIZE;
        queue_size--;

        //dequeue, enqueue
        queue[rear] = queue[front];
        rear = (rear + 1) % QUEUE_MAX_SIZE;
        front = (front + 1) % QUEUE_MAX_SIZE;
    }

    printf("%d\n", queue[front]);

    return 0;
}
