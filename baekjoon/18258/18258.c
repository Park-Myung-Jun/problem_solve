#include <stdio.h>
#include <string.h>

#define COMMAND_LENGTH 6
#define QUEUE_MAX_SIZE 2000000

int queue[QUEUE_MAX_SIZE], queue_front, queue_rear, queue_size;

int main(void)
{
    int i;
    int N, enqueue_value;
    char command[COMMAND_LENGTH];

    memset(command, 0x00, sizeof(char) * COMMAND_LENGTH);
    memset(queue, 0x00, sizeof(int) * QUEUE_MAX_SIZE);
    queue_front = 0;
    queue_rear = 0;
    queue_size = 0;

    scanf("%d", &N);
    for(i = 0; i < N; i++)
    {
        scanf("%s", command);

        if(!strcmp(command, "push"))
        {
            scanf("%d", &enqueue_value);

            queue[queue_rear] = enqueue_value;
            queue_rear = (queue_rear + 1) % QUEUE_MAX_SIZE;
            queue_size++;
        }
        else if(!strcmp(command, "pop"))
        {
            if(queue_rear == queue_front)
            {
                printf("-1\n");
            }
            else
            {
                printf("%d\n", queue[queue_front]);
                queue_front = (queue_front + 1) % QUEUE_MAX_SIZE;
                queue_size--;
            }
        }
        else if(!strcmp(command, "size"))
        {
            printf("%d\n", queue_size);
        }
        else if(!strcmp(command, "empty"))
        {
            if(queue_rear == queue_front)
            {
                printf("1\n");
            }
            else
            {
                printf("0\n");
            }
        }
        else if(!strcmp(command, "front"))
        {
            if(queue_rear == queue_front)
            {
                printf("-1\n");
            }
            else
            {
                printf("%d\n", queue[queue_front]);
            }
        }
        else if(!strcmp(command, "back"))
        {
            if(queue_rear == queue_front)
            {
                printf("-1\n");
            }
            else
            {
                printf("%d\n", queue[(queue_rear + QUEUE_MAX_SIZE - 1) % QUEUE_MAX_SIZE]);
            }
        }
    }

    return 0;
}
