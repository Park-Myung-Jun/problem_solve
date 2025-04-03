#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define DEQUE_MAX 1000

typedef struct _tsPair {
    int num;
    int move;
} tsPair;

int deque_front, deque_rear;
tsPair pair[DEQUE_MAX];

int main(void)
{
    int i;
    int N, get_num, move;

    scanf("%d", &N);

    memset(pair, 0x00, sizeof(tsPair) * DEQUE_MAX);

    for(i = 0; i < N; i++)
    {
        scanf("%d", &get_num);

        pair[deque_front].num = i + 1;
        pair[deque_front].move = get_num;
        deque_front = (deque_front + 1) % DEQUE_MAX;
    }

    while(true)
    {
        printf("%d ", pair[deque_rear].num);
        move = pair[deque_rear].move;

        deque_rear = (deque_rear + 1) % DEQUE_MAX;

        if(deque_front == deque_rear)
        {
            break;
        }

        if(0 < move)
        {
            move--;

            while(move--)
            {
                pair[deque_front].num = pair[deque_rear].num;
                pair[deque_front].move = pair[deque_rear].move;
                deque_rear = (deque_rear + 1) % DEQUE_MAX;
                deque_front = (deque_front + 1) % DEQUE_MAX;
            }
        }
        else
        {
            move = -move;

            while(move--)
            {
                pair[(deque_rear - 1 + DEQUE_MAX) % DEQUE_MAX].num = pair[(deque_front - 1 + DEQUE_MAX) % DEQUE_MAX].num;
                pair[(deque_rear - 1 + DEQUE_MAX) % DEQUE_MAX].move = pair[(deque_front - 1 + DEQUE_MAX) % DEQUE_MAX].move;
                deque_rear = (deque_rear - 1 + DEQUE_MAX) % DEQUE_MAX;
                deque_front = (deque_front - 1 + DEQUE_MAX) % DEQUE_MAX;
            }
        }
    }

    return 0;
}
