#include <stdio.h>

long long Fibonacci(int N)
{
    if(N == 0)
    {
        return 0;
    }
    else if(N == 1)
    {
        return 1;
    }

    return Fibonacci(N - 1) + Fibonacci(N - 2);
}

int main(void)
{
    int n;

    scanf("%d", &n);

    printf("%lld\n", Fibonacci(n));

    return 0;
}
