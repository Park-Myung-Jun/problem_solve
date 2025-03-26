#include <stdio.h>

int Get_GCD(int a, int b)
{
    int gcd;
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
    int T, A, B;

    scanf("%d", &T);

    while(T--)
    {
        scanf("%d %d", &A, &B);

        printf("%d\n", A * B / Get_GCD(A, B));
    }

    return 0;
}
