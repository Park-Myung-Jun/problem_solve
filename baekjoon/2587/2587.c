#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define NUM_MAX 5

int qsort_function(const void* a, const void* b)
{
    int left = *(const int*)a;
    int right = *(const int*)b;

    return (left - right) - (right - left);
}

int main(void)
{
    int i, sum, avg;
    int num_array[NUM_MAX];

    memset(num_array, 0x00, NUM_MAX * sizeof(int));
    sum = 0;

    for(i = 0; i < NUM_MAX; i++)
    {
        scanf("%d", num_array + i);
        sum += num_array[i];
    }

    avg = sum / NUM_MAX;
    qsort(num_array, NUM_MAX, sizeof(int), qsort_function);

    printf("%d\n%d\n", avg, num_array[NUM_MAX / 2]);

    return 0;
}
