#include <stdio.h>
#include <string.h>

#define BASKET_MAX_SIZE 100

int main(void)
{
    int i, j;
    int N, M;
    int start, end, num, basket[BASKET_MAX_SIZE];

    scanf("%d %d", &N, &M);
    memset(basket, 0x00, BASKET_MAX_SIZE * sizeof(int));
    for(i = 0; i < M; i++)
    {
        scanf("%d %d %d", &start, &end, &num);
        for(j = start - 1; j <= end - 1; j++)
        {
            basket[j] = num;
        }
    }

    for(i = 0; i < N; i++)
    {
        printf("%d ", basket[i]);
    }
    printf("\n");

    return 0;
}