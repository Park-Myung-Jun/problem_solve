#include <stdio.h>

int binomial_coefficient(int p_N, int p_K)
{
    int i, result = 1;

    for(i = 0; i < p_K; i++)
    {
        result *= (p_N - i);
    }
    for(i = 0; i < p_K; i++)
    {
        result /= (i + 1);
    }

    return result;
}

int main(void)
{
    int N, K;

    scanf("%d %d", &N, &K);

    printf("%d\n", binomial_coefficient(N, K));

    return 0;
}
