#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>

#define NUM_MAX 10000000

bool prime_check[NUM_MAX + 1];

int main(void)
{
    int i, j, sqrt_num;
    int N;

    memset(prime_check, 0x00, sizeof(bool));
    sqrt_num = (int)sqrt(NUM_MAX);
    prime_check[0] = true;
    prime_check[1] = true;
    for(i = 2; i <= sqrt_num; i++)
    {
        for(j = i * i; j <= NUM_MAX; j += i)
        {
            prime_check[j] = true;
        }
    }

    scanf("%d", &N);
    for(int i = 2; i <= NUM_MAX; i++)
    {
#if 0
        if(prime_check[i] == true)
        {
            continue;
        }
#endif

        if(N % i == 0)
        {
            printf("%d\n", i);
            N /= i;
            i--;
        }
    }

    return 0;
}
