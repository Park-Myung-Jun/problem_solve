#include <stdio.h>

int main(void)
{
    int i;
    int N, result;

    scanf("%d", &N);
    result = 1;

    for(i = 0; i < N; i++)
    {
        result *= (i + 1);
    }

    printf("%d\n", result);

    return 0;
}
