#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#define DIVISOR_MAX 50

int algo_function(const void* a, const void* b)
{
    int l = *(const int*)a;
    int r = *(const int*)b;

    return (l > r) - (l < r);
}

int main(void)
{
    int i, j;
    int N;
    int divisor[DIVISOR_MAX];

    memset(divisor, 0x00, sizeof(int) * DIVISOR_MAX);
    scanf("%d\n", &N);
    for(i = 0; i < N; i++)
    {
        scanf("%d", divisor + i);
    }

    qsort(divisor, N, sizeof(int), algo_function);

    printf("%d\n", divisor[0] * divisor[N - 1]);

    return 0;
}
