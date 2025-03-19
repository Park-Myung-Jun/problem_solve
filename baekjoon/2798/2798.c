#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define USE_LOG 0

#define PICK_CARD_SIZE 3
#define CARD_MAX 100
#define CARD_SUM_MAX 300000

int diff_num(int a, int b)
{
    return (a > b)?(a - b):(b - a);
}

void find_sum_diff_min(int* p_card, bool* p_card_check, int* p_card_stack, int p_position, int p_level, int p_N, int p_M, int* p_card_sum_close)
{
    int i, sum = 0, diff;
#if USE_LOG
    int j;
#endif
    if(p_level == PICK_CARD_SIZE)
    {
        for(i = 0; i < PICK_CARD_SIZE; i++)
        {
            sum += p_card_stack[i];
        }

#if USE_LOG
        printf("%d ", sum);
        for(j = 0; j < p_N; j++)
        {
            printf("%d ", p_card_check[j]);
        }
        printf("\n");
        for(j = 0; j < PICK_CARD_SIZE; j++)
        {
            printf("%d ", p_card_stack[j]);
        }
        printf("\n");
#endif

        if(p_M < sum)
        {
            return;
        }

        diff = diff_num(p_M, sum);
        if(diff < diff_num(p_M, *p_card_sum_close))
        {
            *p_card_sum_close = sum;
        }

        return;
    }

    for(i = p_position; i < p_N; i++)
    {
        if(p_card_check[i] == false)
        {
            p_card_check[i] = true;
            p_card_stack[p_level] = p_card[i];
            //printf("%d %d\n", p_card_stack[p_level], p_card[i]);
            find_sum_diff_min(p_card, p_card_check, p_card_stack, i + 1, p_level + 1, p_N, p_M, p_card_sum_close);
            p_card_check[i] = false;
        }
    }
}

int main(void)
{
    int i;
    int N, M, card[CARD_MAX], card_stack[PICK_CARD_SIZE], card_sum_close;
    bool card_check[CARD_MAX];

    scanf("%d %d", &N, &M);
    memset(card, 0x00, CARD_MAX * sizeof(int));
    memset(card_stack, 0x00, PICK_CARD_SIZE * sizeof(int));
    memset(card_check, 0x00, CARD_MAX * sizeof(bool));
    card_sum_close = CARD_SUM_MAX;

    for(i = 0; i < N; i++)
    {
        scanf("%d", card + i);
    }

    find_sum_diff_min(card, card_check, card_stack, 0, 0, N, M, &card_sum_close);

    printf("%d\n", card_sum_close);

    return 0;
}
