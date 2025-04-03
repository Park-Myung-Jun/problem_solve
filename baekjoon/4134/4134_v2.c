#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include <string.h>

#define PRIME_MAX 4000000000

bool prime_check[PRIME_MAX + 1];

int main(void)
{
    long long i, j;
    int T, sqrt_num, n;
    bool prime_upper_check;

    memset(prime_check, 0x00, sizeof(bool) * PRIME_MAX);
    sqrt_num = (int)sqrt(PRIME_MAX);
    prime_check[0] = true;
    prime_check[1] = true;
    for(i = 2; i <= sqrt_num; i++)
    {
        for(j = i * i; j <= PRIME_MAX; j += i)
        {
            prime_check[j] = true;
        }
    }

    scanf("%d", &T);
    while(T--)
    {
        scanf("%d", &n);

        for(i = n; i <= PRIME_MAX; i++)
        {
            if(prime_check[i] == false)
            {
                printf("%d\n", i);
                break;
            }
        }
    }

    return 0;
}
