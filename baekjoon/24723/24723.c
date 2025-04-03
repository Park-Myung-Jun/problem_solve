#include <stdio.h>

int two_power(int power)
{
    int i;
    int ret = 1;

    for(i = 0; i < power; i++)
    {
        ret *= 2;
    }

    return ret;
}

int main(void)
{
    int N;

    scanf("%d", &N);

    printf("%d\n", two_power(N));

    return 0;
}
