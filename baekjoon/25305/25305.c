#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SCORE_MAX 1000

int q_function(const void* a, const void* b)
{
    int left = *(const int*)a;
    int right = *(const int*)b;

    return (left < right) - (left > right);
}

int main(void)
{
    int i;
    int N, k;
    int score_array[SCORE_MAX];

    memset(score_array, 0x00, sizeof(int) * SCORE_MAX);

    scanf("%d %d", &N, &k);
    for(i = 0; i < N; i++)
    {
        scanf("%d", score_array + i);
    }

    qsort(score_array, N, sizeof(int), q_function);

    printf("%d\n", score_array[k - 1]);

    return 0;
}
