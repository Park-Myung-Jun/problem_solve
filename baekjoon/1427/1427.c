#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define DIGIT_MAX 11

int algo_function(void const* a, void const* b)
{
    char l = *(char const*)a;
    char r = *(char const*)b;

    return (l < r) - (l > r);
}

int main(void)
{
    int N, digit_length;
    char digit_array[DIGIT_MAX];

    memset(digit_array, 0x00, sizeof(char) * DIGIT_MAX);
    scanf("%d", &N);

    sprintf(digit_array, "%d", N);

    digit_length = strlen(digit_array);
    qsort(digit_array, digit_length, sizeof(char), algo_function);

    printf("%s\n", digit_array);

    return 0;
}
