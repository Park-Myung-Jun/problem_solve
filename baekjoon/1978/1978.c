#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>

#define PRIME_NUM_MAX 1001

int main(void)
{
    int i, j;
    int N, prime_count, num_get;
    bool prime_num[PRIME_NUM_MAX];

    memset(prime_num, 0x00, PRIME_NUM_MAX * sizeof(char));
    double base = sqrt(PRIME_NUM_MAX);
    for(i = 2; i <= base; i++)
    {
        j = i * i;
        while(j <= PRIME_NUM_MAX - 1)
        {
            prime_num[j] = true;
            j += i;
        }
    }

    scanf("%d", &N);
    prime_count = 0;
    for(i = 0; i < N; i++)
    {
        scanf("%d", &num_get);
        if(2 <= num_get && prime_num[num_get] == false)
        {
            prime_count++;
        }
    }

    printf("%d\n", prime_count);

    return 0;
}
