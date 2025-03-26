#include <stdio.h>

long long int Get_GCD(long long int a, long long int b)
{
    long long int gcd;

    while(b != 0)
    {
        gcd = a % b;
        a = b;
        b = gcd;
    }

    return a;
}

int main(void)
{
    long long int A, B, GCD;

    scanf("%lld %lld", &A, &B);

    printf("%lld\n", A * B / Get_GCD(A, B));

    return 0;
}
