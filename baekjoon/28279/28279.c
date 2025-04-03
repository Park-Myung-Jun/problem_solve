#include <stdio.h>
#include <string.h>

#define DEQUE_MAX 1000001

int deque[DEQUE_MAX], deque_front, deque_rear, deque_size;

int main(void)
{
    int i;
    int N, X;

    scanf("%d", &N);
    memset(deque, 0x00, sizeof(int) * DEQUE_MAX);
    deque_front = 0;
    deque_rear = 0;
    deque_size = 0;

    for(i = 0; i < N; i++)
    {
        scanf("%d", &X);

        switch (X)
        {
            case 1:
                scanf("%d", &X);
                deque[deque_front] = X;
                deque_front = (deque_front + 1) % DEQUE_MAX;
                deque_size++;
                break;

            case 2:
                scanf("%d", &X);
                deque[(deque_rear - 1 + DEQUE_MAX) % DEQUE_MAX] = X;
                deque_rear = (deque_rear - 1 + DEQUE_MAX) % DEQUE_MAX;
                deque_size++;
                break;

            case 3:
                if(deque_front == deque_rear)
                {
                    printf("-1\n");
                }
                else
                {
                    printf("%d\n", deque[(deque_front - 1 + DEQUE_MAX) % DEQUE_MAX]);
                    deque_front = (deque_front - 1 + DEQUE_MAX) % DEQUE_MAX;
                    deque_size--;
                }
                break;

            case 4:
                if(deque_front == deque_rear)
                {
                    printf("-1\n");
                }
                else
                {
                    printf("%d\n", deque[deque_rear]);
                    deque_rear = (deque_rear + 1) % DEQUE_MAX;
                    deque_size--;
                }
                break;

            case 5:
                printf("%d\n", deque_size);
                break;

            case 6:
                printf("%d\n", deque_front == deque_rear);
                break;

            case 7:
                if(deque_front == deque_rear)
                {
                    printf("-1\n");
                }
                else
                {
                    printf("%d\n", deque[(deque_front - 1 + DEQUE_MAX) % DEQUE_MAX]);
                }
                break;

            case 8:
                if(deque_front == deque_rear)
                {
                    printf("-1\n");
                }
                else
                {
                    printf("%d\n", deque[deque_rear]);
                }
                break;

            default:
                break;
        }
    }

    return 0;
}
