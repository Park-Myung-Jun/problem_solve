#include <stdio.h>
#include <stdbool.h>
#include <math.h>

bool is_prime(int num)
{
    int i, sqrt_num = (int)sqrt(num);

    if(num < 2)
    {
        return false;
    }

    for(i = 2; i <= sqrt_num; i++)
    {
        if(num % i == 0)
        {
            return false;
        }
    }

    return true;
}

int main(void)
{
    int i;
    int M, N;

    scanf("%d %d", &M, &N);

    for(i = M; i <= N; i++)
    {
        if(is_prime(i))
        {
            printf("%d\n", i);
        }
    }

    return 0;
}
