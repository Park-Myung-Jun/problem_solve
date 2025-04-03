#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define QUEUE_MAX 1001

int queue[QUEUE_MAX], queue_front, queue_rear;

int main(void)
{
    int i;
    int N, K;

    scanf("%d %d", &N, &K);

    queue_front = 0;
    queue_rear = 0;
    memset(queue, 0x00, sizeof(int) * QUEUE_MAX);

    for(i = 0; i < N; i++)
    {
        queue[queue_rear] = i + 1;
        queue_rear = (queue_rear + 1) % QUEUE_MAX;
    }

    printf("<");
    while(true)
    {
        for(i = 0; i < K - 1; i++)
        {
            queue[queue_rear] = queue[queue_front];
            queue_front = (queue_front + 1) % QUEUE_MAX;
            queue_rear = (queue_rear + 1) % QUEUE_MAX;
        }

        printf("%d", queue[queue_front]);
        queue_front = (queue_front + 1) % QUEUE_MAX;

        if(queue_rear == queue_front)
        {
            break;
        }

        printf(", ");
    }
    printf(">\n");

    return 0;
}
