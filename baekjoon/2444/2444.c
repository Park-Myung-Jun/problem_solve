#include <stdio.h>

int main(void)
{
    int i, j;
    int N;
    scanf("%d", &N);

    for(i = 0; i < N; i++)
    {
        for(j = N - 1 - i; j > 0; j--)
        {
            printf(" ");
        }
        for(j = 0; j < i * 2 + 1; j++)
        {
            printf("*");
        }
        printf("\n");
    }

    for(i = N - 1; i > 0; i--)
    {
        for(j = N - i; j > 0 ; j--)
        {
            printf(" ");
        }
        for(j = 0; j < i * 2 - 1; j++)
        {
            printf("*");
        }
        printf("\n");
    }

    return 0;
}