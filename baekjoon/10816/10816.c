#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define CARD_MAX 500000

typedef struct _tsCardPair {
    int num;
    int count;
} tsCardPair;

int algo_function(const void* p_a, const void* p_b)
{
    int a = *(int*)p_a;
    int b = *(int*)p_b;

    return (a > b) - (a < b);
}

int algo_function_cardpair(const void* p_a, const void* p_b)
{
    tsCardPair a = *(tsCardPair*)p_a;
    tsCardPair b = *(tsCardPair*)p_b;

    return (a.num > b.num) - (a.num < b.num);
}

int card[CARD_MAX];
tsCardPair cardpair[CARD_MAX];

int main(void)
{
    int i;
    int N, M, get_num, cardpair_count, cardpair_base;
    tsCardPair cardpair_find, *cardpair_ptr;

    memset(card, 0x00, sizeof(int) * CARD_MAX);
    memset(cardpair, 0x00, sizeof(tsCardPair) * CARD_MAX);

    scanf("%d", &N);
    for(i = 0; i < N; i++)
    {
        scanf("%d", card + i);
    }

    qsort(card, N, sizeof(int), algo_function);

#if 0
    for(i = 0; i < N; i++)
    {
        printf("%d ", card[i]);
    }
    printf("\n");
#endif

    cardpair_count = 0;
    cardpair_base = card[0];
    cardpair[cardpair_count].num = card[0];
    cardpair[cardpair_count].count++;

    for(i = 1; i < N; i++)
    {
        //printf("%d %d %d\n", cardpair_base, card[i], cardpair_count);

        if(cardpair_base != card[i])
        {
            cardpair_count++;
            cardpair[cardpair_count].num = card[i];
            cardpair_base = card[i];
        }

        cardpair[cardpair_count].count++;
    }

    cardpair_count++;

#if 0
    for(i = 0; i < cardpair_count; i++)
    {
        printf("%d %d\n", cardpair[i].num, cardpair[i].count);
    }
    printf("\n");

    return 0;
#endif

    scanf("%d", &M);
    for(i = 0; i < M; i++)
    {
        scanf("%d", &get_num);
        cardpair_find.num = get_num;

        cardpair_ptr = bsearch(&cardpair_find, cardpair, cardpair_count, sizeof(tsCardPair), algo_function_cardpair);

        if(cardpair_ptr != NULL)
        {
            printf("%d ", cardpair_ptr->count);
        }
        else
        {
            printf("0 ");
        }
    }
    printf("\n");

    return 0;
}
