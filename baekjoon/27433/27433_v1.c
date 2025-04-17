#include <stdio.h>

long long factorial(int N)
{
    int i;
    long long ret = 1;

    if(N == 0)
    {
        return 1;
    }

    for(i = 0; i < N; i++)
    {
        ret *= (i + 1);
    }

    return ret;
}

int main(void)
{
    int N;

    scanf("%d", &N);

    printf("%lld\n", factorial(N));

    return 0;
}
