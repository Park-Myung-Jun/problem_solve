#include <stdio.h>
#include <string.h>

#define BASKET_MAX 100

void basket_reverse(int* p_basket, int p_left, int p_right)
{
    int i, tmp, middle = (p_left + p_right) / 2;
    for(i = p_left; i < middle; i++)
    {
        tmp = p_basket[i];
        p_basket[i] = p_basket[p_right + p_left - 1 - i];
        p_basket[p_right + p_left - 1 - i] = tmp;
    }
}

int main(void)
{
    int i, j;
    int N, M, basket[BASKET_MAX];
    int left, right;
    scanf("%d %d", &N, &M);

    memset(basket, 0x00, BASKET_MAX * sizeof(int));

    for(i = 0; i < BASKET_MAX; i++)
    {
        basket[i] = i + 1;
    }

    for(i = 0; i < M; i++)
    {
        scanf("%d %d", &left, &right);
        basket_reverse(basket, left - 1, right);
    }

    for(i = 0; i < N; i++)
    {
        printf("%d ", basket[i]);
    }
    printf("\n");

    return 0;
}
