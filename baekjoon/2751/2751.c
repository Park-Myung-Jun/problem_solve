#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define NUM_MAX 1000000

int num_array[NUM_MAX];

int algo_function(const void* a, const void* b)
{
    int l = *(const int*)a;
    int r = *(const int*)b;

    return (l > r) - (l < r);
}

int main(void)
{
    int i;
    int N;

    scanf("%d", &N);
    memset(num_array, 0x00, sizeof(int) * NUM_MAX);
    for(i = 0; i < N; i++)
    {
        scanf("%d", num_array + i);
    }

    qsort(num_array, N, sizeof(int), algo_function);

    for(i = 0; i < N; i++)
    {
        printf("%d\n", num_array[i]);
    }

    return 0;
}
