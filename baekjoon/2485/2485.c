#include <stdio.h>

#define POSITION_MAX 100000

int position[POSITION_MAX];
int diff[POSITION_MAX];

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
    int i;
    int N, gcd, sum;

    sum = 0;
    scanf("%d", &N);
    for(i = 0; i < N; i++)
    {
        scanf("%d", position + i);
    }

    for(i = 0; i < N - 1; i++)
    {
        diff[i] = position[i + 1] - position[i];
    }

    gcd = Get_GCD(diff[0], diff[1]);
    for(i = 2; i < N - 1; i++)
    {
        gcd = Get_GCD(diff[i], gcd);
    }

    for(i = 0; i < N - 1; i++)
    {
        sum += (diff[i] / gcd - 1);
    }

    printf("%d\n", sum);

    return 0;
}
