#include <stdio.h>
#include <math.h>
#include <stdbool.h>

#define PRIME_MAX 10001

int main(void)
{
    int i, j;

    int sqrt_num = (int)sqrt(PRIME_MAX);
    bool prime_check[PRIME_MAX] = {true, true};

    int N, M;
    int sum, prime_min;

    for(i = 2; i <= sqrt_num; i++)
    {
        for(j = i * i; j <= PRIME_MAX - 1; j += i)
        {
            prime_check[j] = true;
        }
    }

    scanf("%d %d", &M, &N);

    sum = 0;
    prime_min = PRIME_MAX;

    for(i = M; i <= N; i++)
    {
        if(prime_check[i] == false)
        {
            sum += i;
            if(i < prime_min)
            {
                prime_min = i;
            }
        }
    }

    if(sum == 0)
    {
        printf("-1\n");
    }
    else
    {
        printf("%d\n%d\n", sum, prime_min);
    }

    return 0;
}
