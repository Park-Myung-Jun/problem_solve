#include <stdio.h>

long long int binomial_coefficient(int p_M, int p_N)
{
    long long int i, result = 1;

    for(i = 0; i < p_N; i++)
    {
        result *= (p_M - i);
        result /= (i + 1);
    }

    return result;
}

int main(void)
{
    int T, N, M;

    scanf("%d", &T);
    while(T--)
    {
        scanf("%d %d", &N, &M);

        printf("%lld\n", binomial_coefficient(M, N));
    }

    return 0;
}
