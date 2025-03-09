#include <stdio.h>

#define MUL_SIZE 9

int main(void)
{
    int N;
    int i;
    scanf("%d", &N);

    for(i = 0; i < MUL_SIZE; i++)
    {
        printf("%d * %d = %d\n", N, i + 1, N * (i + 1));
    }

    return 0;
}