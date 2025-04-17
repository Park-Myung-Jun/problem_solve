#include <stdio.h>

long long factorial(int N)
{
    if(N == 0)
    {
        return 1;
    }

    return factorial(N - 1) * N;
}

int main(void)
{
    int N;

    scanf("%d", &N);

    printf("%lld\n", factorial(N));

    return 0;
}
