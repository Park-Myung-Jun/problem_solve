#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include <string.h>

#define PRIME_MAX 1000000

bool prime_check[PRIME_MAX + 1];
int prime_save[PRIME_MAX + 1], prime_count;

int find_goldbah(int num)
{
    int i, j;
    int count = 0;

    for(i = 0; i < prime_count; i++)
    {
        if(num / 2 < prime_save[i])
        {
            break;
        }

        if(prime_check[num - prime_save[i]] == false)
        {
            count++;
        }
    }

    return count;
}

int main(void)
{
    int i, j;
    int T, N, sqrt_num = sqrt(PRIME_MAX);

    memset(prime_check, 0x00, sizeof(bool) * (PRIME_MAX + 1));
    memset(prime_save, 0x00, sizeof(int) * (PRIME_MAX + 1));
    prime_check[0] = true;
    prime_check[1] = true;
    for(i = 2; i <= sqrt_num; i++)
    {
        for(j = i * i; j <= PRIME_MAX; j += i)
        {
            prime_check[j] = true;
        }
    }

    prime_count = 0;
    for(i = 2; i <= PRIME_MAX; i++)
    {
        if(prime_check[i] == false)
        {
            prime_save[prime_count] = i;
            prime_count++;
        }
    }

    scanf("%d", &T);
    while(T--)
    {
        scanf("%d", &N);

        printf("%d\n", find_goldbah(N));
    }

    return 0;
}
