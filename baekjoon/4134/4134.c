#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include <string.h>

#define PRIME_MAX 4200000000

int main(void)
{
    long long int i, j, n, sqrt_num, T;
    bool is_prime;

    scanf("%lld", &T);
    while(T--)
    {
        scanf("%lld", &n);

        if(n < 2)
        {
            printf("2\n");
            continue;
        }

        for(i = n; i <= PRIME_MAX; i++)
        {
            is_prime = true;
            sqrt_num = (long long)sqrt(i);

            for(j = 2; j <= sqrt_num; j++)
            {
                if(i % j == 0)
                {
                    is_prime = false;
                    break;
                }
            }

            if(is_prime)
            {
                printf("%lld\n", i);
                break;
            }
        }
    }

    return 0;
}
